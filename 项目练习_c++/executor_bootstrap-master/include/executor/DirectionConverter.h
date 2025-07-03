#ifndef DIRECTION_CONVERTER_H
#define DIRECTION_CONVERTER_H

#include "executor/Executor.h"
#include <string>
#include <unordered_map>

class DirectionConverter {
public:
    static const std::string& directionToString(Executor::Direction dir);
};

#endif // DIRECTION_CONVERTER_H