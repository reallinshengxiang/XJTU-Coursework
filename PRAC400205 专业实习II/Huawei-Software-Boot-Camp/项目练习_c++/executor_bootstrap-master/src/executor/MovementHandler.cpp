#include "executor/MovementHandler.h"
#include <climits>
#include <sstream> 

MovementHandler::MovementHandler(Executor::Position& position, std::function<int()>& checkPoints, std::function<void(int)>& sendStatus)
    : position(position), checkPoints(checkPoints), sendStatus(sendStatus) {}

void MovementHandler::turnRight() {
    position.heading = static_cast<Executor::Direction>((static_cast<int>(position.heading) + 1) % 4);
}

void MovementHandler::turnLeft() {
    position.heading = static_cast<Executor::Direction>((static_cast<int>(position.heading) + 3) % 4);
}

void MovementHandler::forward() {
    Executor::Position oldPos = position;
    switch (position.heading) {
    case Executor::Direction::East:
        if (position.x < INT_MAX) position.x++;
        break;
    case Executor::Direction::West:
        if (position.x > INT_MIN) position.x--;
        break;
    case Executor::Direction::North:
        if (position.y < INT_MAX) position.y++;
        break;
    case Executor::Direction::South:
        if (position.y > INT_MIN) position.y--;
        break;
    }
    if (oldPos.x != position.x || oldPos.y != position.y) {
        int actionCode = checkPoints();
        sendStatus(actionCode);
    }
}

void MovementHandler::backward() {
    Executor::Position oldPos = position;
    switch (position.heading) {
    case Executor::Direction::East:
        if (position.x > INT_MIN) position.x--;
        break;
    case Executor::Direction::West:
        if (position.x < INT_MAX) position.x++;
        break;
    case Executor::Direction::North:
        if (position.y > INT_MIN) position.y--;
        break;
    case Executor::Direction::South:
        if (position.y < INT_MAX) position.y++;
        break;
    }
    if (oldPos.x != position.x || oldPos.y != position.y) {
        int actionCode = checkPoints();
        sendStatus(actionCode);
    }
}

void MovementHandler::turnRound() {
    turnRight();
    turnRight();
}
