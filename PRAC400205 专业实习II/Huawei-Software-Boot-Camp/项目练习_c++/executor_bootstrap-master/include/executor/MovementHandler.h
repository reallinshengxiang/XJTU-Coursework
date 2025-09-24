#ifndef MOVEMENT_HANDLER_H
#define MOVEMENT_HANDLER_H

#include "executor/Executor.h"

class MovementHandler {
public:
    MovementHandler(Executor::Position& position, std::function<int()>& checkPoints, std::function<void(int)>& sendStatus);
    void turnRight();
    void turnLeft();
    void forward();
    void backward();
    void turnRound();
    void handleCommand(const std::string& command);

private:
    Executor::Position& position;
    std::function<int()>& checkPoints;
    std::function<void(int)>& sendStatus;
    std::string lastCommand;
};

#endif // MOVEMENT_HANDLER_H