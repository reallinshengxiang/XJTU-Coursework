#ifndef INITIALIZATION_HANDLER_H
#define INITIALIZATION_HANDLER_H

#include "executor/Executor.h"

class InitializationHandler {
public:
    InitializationHandler(Executor::Position& position, std::function<int()>& checkPoints, std::function<void(int)>& sendStatus);
    void initialize(int x_pos, int y_pos, Executor::Direction new_heading);

private:
    Executor::Position& position;
    std::function<int()>& checkPoints;
    std::function<void(int)>& sendStatus;
};

#endif // INITIALIZATION_HANDLER_H