#include "executor/ConfigPointManager.h"

ConfigPointManager::ConfigPointManager(std::map<std::pair<int, int>, Executor::PointType>& configPoints)
    : configPoints(configPoints) {}

bool ConfigPointManager::addConfigPoint(int x, int y, Executor::PointType type) {
    auto point = std::make_pair(x, y);
    if (configPoints.find(point) != configPoints.end()) {
        return false;
    }
    if (configPoints.size() >= MAX_POINTS) {
        return false;
    }
    configPoints[point] = type;
    return true;
}

bool ConfigPointManager::removeConfigPoint(int x, int y) {
    auto point = std::make_pair(x, y);
    auto it = configPoints.find(point);
    if (it != configPoints.end()) {
        configPoints.erase(it);
        return true;
    }
    return false;
}

size_t ConfigPointManager::getConfigPointCount() const {
    return configPoints.size();
}

int ConfigPointManager::checkPoints(const Executor::Position& position, std::function<void(int, int)>& cleanCallback, std::function<void(int, int, int)>& alertCallback) {
    auto currentPos = std::make_pair(position.x, position.y);
    auto it = configPoints.find(currentPos);
    if (it != configPoints.end()) {
        Executor::PointType type = it->second;
        if (type == Executor::PointType::CLEAN) {
            if (cleanCallback) {
                cleanCallback(position.x, position.y);
            }
            configPoints.erase(it);
            return 2; // clean
        } else if (type == Executor::PointType::DANGER) {
            if (alertCallback) {
                alertCallback(3, position.x, position.y);
            }
            return 1; // alert
        }
    }
    return 0; // none
}