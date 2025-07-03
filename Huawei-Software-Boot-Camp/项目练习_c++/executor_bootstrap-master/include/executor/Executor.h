#ifndef FE0C20F3603C4B6B9DBF2214C001D90A
#define FE0C20F3603C4B6B9DBF2214C001D90A

#include <string>
#include <utility>
#include <functional>
#include <map>
#include "../deps/wifi/wifi.h"
#include <vector>
class MovementHandler;
class InitializationHandler;
class ConfigPointManager;
class CallbackHandler;

class Executor {
public:
    enum class MessageFormat {
        JSON, 
        BINARY
    };
    enum class Direction {
        East, South, West, North
    };
    struct Position {
        int x;
        int y;
        Direction heading;
        bool operator<(const Position& other) const {
            if (x != other.x) return x < other.x;
            if (y != other.y) return y < other.y;
            return static_cast<int>(heading) < static_cast<int>(other.heading);
        }
    };
    enum class PointType {
        DANGER,
        CLEAN
    };
    enum class CommandType {
        FORWARD,
        BACKWARD,
        TURN_RIGHT,
        TURN_LEFT,
        TURN_ROUND,
        FORWARD_N,
        BACKWARD_N,
        REPEAT,
        COMMAND_LIST
    };
    struct Command {
        CommandType type;
        int param;
        std::vector<Command> subCommands;
        Command(CommandType t, int p = 0) : type(t), param(p) {}
    };
    explicit Executor(std::string name = "Executor");
    void initialize(int x_pos, int y_pos, Direction new_heading);
    void turnRight();
    void turnLeft();
    void forward();
    void backward();
    void turnRound();
    void forwardNSteps(int n);
    void backwardNSteps(int n);
    void repeatCommand(const std::function<void()>& command, int n);
    void setCleanPoint(int cleanX, int cleanY);
    void setCleanCallback(std::function<void(int, int)> callback);
    int getX() const;
    int getY() const;
    Direction getHeading() const;
    const std::string& get_name() const;
    void setAlertCallback(std::function<void(int, int, int)> callback);
    bool addConfigPoint(int x, int y, PointType type);
    bool removeConfigPoint(int x, int y);
    size_t getConfigPointCount() const;
    void setMessageFormat(MessageFormat format);
    void setJsonCallback(std::function<void(const char*)> callback);
    void setMsgCallback(std::function<void(const WifiMsg*)> callback);
    Command parseCommand(const std::string& commandStr);
    void executeCommand(const Command& cmd);
    void executeCommandList(const std::vector<Command>& commands);
    void executeCompositeCommand(const std::string& compositeCommand);

private:
    std::string name;
    Position position;
    std::function<void(int, int)> cleanCallback;
    std::function<void(int, int, int)> alertCallback;
    std::map<std::pair<int, int>, PointType> configPoints;
    std::function<int()> checkPointsWrapper;
    std::function<void(int)> sendStatusWrapper;
    MessageFormat messageFormat;
    std::function<void(const char*)> jsonCallback;
    std::function<void(const WifiMsg*)> msgCallback;
    MovementHandler* movementHandler;
    InitializationHandler* initializationHandler;
    ConfigPointManager* configPointManager;
    CallbackHandler* callbackHandler;
    std::vector<Command> parseCommandList(const std::string& cmdListStr);
};

const std::string& directionToString(Executor::Direction dir);

#endif //FE0C20F3603C4B6B9DBF2214C001D90A