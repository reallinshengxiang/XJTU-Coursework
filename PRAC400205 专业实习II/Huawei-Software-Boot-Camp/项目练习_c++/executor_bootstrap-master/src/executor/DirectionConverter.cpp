#include "executor/DirectionConverter.h"

const std::string& DirectionConverter::directionToString(Executor::Direction dir) {
    static const std::string unknown = "未知";
    static const std::unordered_map<Executor::Direction, std::string> directionMap = {
        {Executor::Direction::East, "东"},
        {Executor::Direction::South, "南"},
        {Executor::Direction::West, "西"},
        {Executor::Direction::North, "北"}
    };
    auto it = directionMap.find(dir);
    if (it != directionMap.end()) {
        return it->second;
    }
    return unknown;
}