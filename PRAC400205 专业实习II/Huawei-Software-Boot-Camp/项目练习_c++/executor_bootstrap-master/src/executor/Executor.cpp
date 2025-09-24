#include "executor/Executor.h"
#include "executor/DirectionConverter.h"
#include "executor/MovementHandler.h"
#include "executor/InitializationHandler.h"
#include "executor/ConfigPointManager.h"
#include "executor/CallbackHandler.h"
#include <regex> 

const std::string& directionToString(Executor::Direction dir) {
    return DirectionConverter::directionToString(dir);
}

Executor::Executor(std::string name) 
    : name(std::move(name)), position{0, 0, Direction::North},messageFormat(MessageFormat::JSON),
      checkPointsWrapper([this]() { return configPointManager->checkPoints(position, cleanCallback, alertCallback); }),
      sendStatusWrapper([this](int actionCode) { callbackHandler->sendStatus(actionCode); }),
      movementHandler(new MovementHandler(position, checkPointsWrapper, sendStatusWrapper)),
      initializationHandler(new InitializationHandler(position, checkPointsWrapper, sendStatusWrapper)),
      configPointManager(new ConfigPointManager(configPoints)),
      callbackHandler(new CallbackHandler(messageFormat, jsonCallback, msgCallback, position)) {}

void Executor::initialize(int x_pos, int y_pos, Direction new_heading) {
    initializationHandler->initialize(x_pos, y_pos, new_heading);
}

void Executor::turnRight() {
    movementHandler->turnRight();
}

void Executor::turnLeft() {
    movementHandler->turnLeft();
}

void Executor::forward() {
    movementHandler->forward();
}

void Executor::backward() {
    movementHandler->backward();
}

void Executor::turnRound() {
    movementHandler->turnRound();
}

int Executor::getX() const { return position.x; }
int Executor::getY() const { return position.y; }
Executor::Direction Executor::getHeading() const { return position.heading; }
const std::string& Executor::get_name() const { return name; }

void Executor::setCleanPoint(int cleanX, int cleanY) {
    configPointManager->addConfigPoint(cleanX, cleanY, PointType::CLEAN);
}

void Executor::setCleanCallback(std::function<void(int, int)> callback) {
    cleanCallback = callback;
}

void Executor::setAlertCallback(std::function<void(int, int, int)> callback) {
    alertCallback = callback;
}

bool Executor::addConfigPoint(int x, int y, PointType type) {
    return configPointManager->addConfigPoint(x, y, type);
}

bool Executor::removeConfigPoint(int x, int y) {
    return configPointManager->removeConfigPoint(x, y);
}

size_t Executor::getConfigPointCount() const {
    return configPointManager->getConfigPointCount();
}

void Executor::setMessageFormat(MessageFormat format) {
    callbackHandler->setMessageFormat(format);
}

void Executor::setJsonCallback(std::function<void(const char*)> callback) {
    callbackHandler->setJsonCallback(callback);
}

void Executor::setMsgCallback(std::function<void(const WifiMsg*)> callback) {
    callbackHandler->setMsgCallback(callback);
}

void Executor::forwardNSteps(int n) {
    for (int i = 0; i < n; ++i) {
        forward();
    }
}

void Executor::backwardNSteps(int n) {
    for (int i = 0; i < n; ++i) {
        backward();
    }
}

void Executor::repeatCommand(const std::function<void()>& command, int n) {
    for (int i = 0; i < n; ++i) {
        command();
    }
}

std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, last - first + 1);
}

std::vector<Executor::Command> Executor::parseCommandList(const std::string& cmdListStr) {
    std::vector<Command> commands;
    std::stringstream ss(trim(cmdListStr));
    std::string token;
    int bracketLevel = 0;
    std::string currentCmd;
    
    for (size_t i = 0; i < cmdListStr.length(); ++i) {
        char c = cmdListStr[i];
        currentCmd += c;
        if (c == '{') bracketLevel++;
        if (c == '}') bracketLevel--;
        if (bracketLevel < 0) {
            throw std::invalid_argument("括号不匹配: " + cmdListStr);
        }
        if (c == ',' && bracketLevel == 0) {
            currentCmd.pop_back();
            commands.push_back(parseCommand(trim(currentCmd)));
            currentCmd.clear();
        }
    }
    if (!currentCmd.empty()) {
        commands.push_back(parseCommand(trim(currentCmd)));
    }
    if (bracketLevel != 0) {
        throw std::invalid_argument("括号不匹配: " + cmdListStr);
    }
    return commands;
}

Executor::Command Executor::parseCommand(const std::string& commandStr) {
    std::string cmd = trim(commandStr);
    if (cmd.empty()) throw std::invalid_argument("空指令");
    if (cmd == "forward") return Command(CommandType::FORWARD);
    if (cmd == "backward") return Command(CommandType::BACKWARD);
    if (cmd == "turn right") return Command(CommandType::TURN_RIGHT);
    if (cmd == "turn left") return Command(CommandType::TURN_LEFT);
    if (cmd == "turn round") return Command(CommandType::TURN_ROUND);
    std::smatch match;
    if (std::regex_match(cmd, match, std::regex(R"(forward (\d+) step)"))) {
        return Command(CommandType::FORWARD_N, std::stoi(match[1]));
    }
    if (std::regex_match(cmd, match, std::regex(R"(backward (\d+) step)"))) {
        return Command(CommandType::BACKWARD_N, std::stoi(match[1]));
    }
    if (std::regex_match(cmd, match, std::regex(R"(repeat\s+\{(.*)\}\s+(\d+))"))) {
        std::string innerCmds = match[1];
        int times = std::stoi(match[2]);
        Command repeatCmd(CommandType::REPEAT, times);
        repeatCmd.subCommands = parseCommandList(innerCmds);
        return repeatCmd;
    }
    if (cmd[0] == '{' && cmd[cmd.size()-1] == '}') {
        std::string innerCmds = cmd.substr(1, cmd.size()-2);
        Command listCmd(CommandType::COMMAND_LIST);
        listCmd.subCommands = parseCommandList(innerCmds);
        return listCmd;
    }
    throw std::invalid_argument("未知指令: " + cmd);
}

void Executor::executeCommand(const Command& cmd) {
    switch (cmd.type) {
        case CommandType::FORWARD:
            forward();
            break;
        case CommandType::BACKWARD:
            backward();
            break;
        case CommandType::TURN_RIGHT:
            turnRight();
            break;
        case CommandType::TURN_LEFT:
            turnLeft();
            break;
        case CommandType::TURN_ROUND:
            turnRound();
            break;
        case CommandType::FORWARD_N:
            forwardNSteps(cmd.param);
            break;
        case CommandType::BACKWARD_N:
            backwardNSteps(cmd.param);
            break;
        case CommandType::REPEAT:
            for (int i = 0; i < cmd.param; ++i) {
                executeCommandList(cmd.subCommands);
            }
            break;
        case CommandType::COMMAND_LIST:
            executeCommandList(cmd.subCommands);
            break;
    }
}

void Executor::executeCommandList(const std::vector<Command>& commands) {
    for (const auto& cmd : commands) {
        executeCommand(cmd);
    }
}

void Executor::executeCompositeCommand(const std::string& compositeCommand) {
    Command cmd = parseCommand(compositeCommand);
    executeCommand(cmd);
}