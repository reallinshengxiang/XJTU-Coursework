#ifndef CONFIG_POINT_MANAGER_H
#define CONFIG_POINT_MANAGER_H

#include "executor/Executor.h"
#include <map>
#include <utility>

class ConfigPointManager {
public:
    ConfigPointManager(std::map<std::pair<int, int>, Executor::PointType>& configPoints);
    bool addConfigPoint(int x, int y, Executor::PointType type);
    bool removeConfigPoint(int x, int y);
    size_t getConfigPointCount() const;
    int checkPoints(const Executor::Position& position, std::function<void(int, int)>& cleanCallback, std::function<void(int, int, int)>& alertCallback);

private:
    std::map<std::pair<int, int>, Executor::PointType>& configPoints;
    static const size_t MAX_POINTS = 16;
};

#endif // CONFIG_POINT_MANAGER_H