#ifndef CALLBACK_HANDLER_H
#define CALLBACK_HANDLER_H

#include "executor/Executor.h"
#include <functional>

class CallbackHandler {
public:
    CallbackHandler(Executor::MessageFormat& messageFormat, std::function<void(const char*)>& jsonCallback, std::function<void(const WifiMsg*)>& msgCallback, const Executor::Position& position);
    void setMessageFormat(Executor::MessageFormat format);
    void setJsonCallback(std::function<void(const char*)> callback);
    void setMsgCallback(std::function<void(const WifiMsg*)> callback);
    void sendStatus(int actionCode);

private:
    Executor::MessageFormat& messageFormat;
    std::function<void(const char*)>& jsonCallback;
    std::function<void(const WifiMsg*)>& msgCallback;
    const Executor::Position& position;
};

#endif // CALLBACK_HANDLER_H