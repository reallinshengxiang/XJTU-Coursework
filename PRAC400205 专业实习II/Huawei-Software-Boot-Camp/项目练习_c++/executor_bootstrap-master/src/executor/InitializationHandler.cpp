#include "executor/InitializationHandler.h"

InitializationHandler::InitializationHandler(Executor::Position& position, std::function<int()>& checkPoints, std::function<void(int)>& sendStatus)
    : position(position), checkPoints(checkPoints), sendStatus(sendStatus) {}

void InitializationHandler::initialize(int x_pos, int y_pos, Executor::Direction new_heading) {
    position.x = x_pos;
    position.y = y_pos;
    position.heading = new_heading;
    int actionCode = checkPoints();
    sendStatus(actionCode);
}