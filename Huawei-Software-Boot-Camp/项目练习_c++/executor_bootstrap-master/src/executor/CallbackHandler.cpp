#include "executor/CallbackHandler.h"
#include <sstream>
#include "../deps/wifi/wifi.h"

CallbackHandler::CallbackHandler(Executor::MessageFormat& messageFormat, std::function<void(const char*)>& jsonCallback, std::function<void(const WifiMsg*)>& msgCallback, const Executor::Position& position)
    : messageFormat(messageFormat), jsonCallback(jsonCallback), msgCallback(msgCallback), position(position) {}

void CallbackHandler::setMessageFormat(Executor::MessageFormat format) {
    messageFormat = format;
}

void CallbackHandler::setJsonCallback(std::function<void(const char*)> callback) {
    jsonCallback = callback;
}

void CallbackHandler::setMsgCallback(std::function<void(const WifiMsg*)> callback) {
    msgCallback = callback;
}

void CallbackHandler::sendStatus(int actionCode) {
    if (messageFormat == Executor::MessageFormat::JSON) {
        if (jsonCallback) {
            // 构造 JSON 字符串
            std::string actionStr;
            switch (actionCode) {
            case 1: actionStr = "alert"; break;
            case 2: actionStr = "clean"; break;
            default: actionStr = "none";
            }

            std::ostringstream oss;
            oss << "{ \"x\": " << position.x
                << ", \"y\": " << position.y
                << ", \"action\": \"" << actionStr << "\" }";

            jsonCallback(oss.str().c_str());
        }
    } else { // BINARY 格式
        if (msgCallback) {
            WifiMsg msg = { 0, position.x, position.y, actionCode };
            msgCallback(&msg);
        }
    }
}