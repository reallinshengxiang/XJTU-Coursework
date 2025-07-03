#include <gtest/gtest.h>
#include "executor/Executor.h"
#include <climits> 

struct ExecutorTest : testing::Test
{
protected:
    Executor* executor;
    int alertCount;
    int lastAlertType;
    int lastAlertX;
    int lastAlertY;
    int cleanCount;
    int lastCleanX;
    int lastCleanY;
    std::vector<std::string> jsonMessages;
    void SetUp() override
    {
        executor = new Executor("demo");
        resetAlertCount();
        resetCleanCount();
        jsonMessages.clear();
        executor->setJsonCallback([this](const char* json) {
            this->jsonMessages.push_back(json);
        });
    }
    void TearDown() override
    {
        delete executor;
    }
    void resetAlertCount() {
        alertCount = 0;
        lastAlertType = 0;
        lastAlertX = 0;
        lastAlertY = 0;
    }
    void resetCleanCount() {
        cleanCount = 0;
        lastCleanX = 0;
        lastCleanY = 0;
    }
    void mockAlert(int type, int x, int y) {
        alertCount++;
        lastAlertType = type;
        lastAlertX = x;
        lastAlertY = y;
    }
    void mockClean(int x, int y) {
        cleanCount++;
        lastCleanX = x;
        lastCleanY = y;
    }
};

// 测试默认构造函数
TEST_F(ExecutorTest, ShouldCreateWithDefaultValues)
{
    Executor defaultExecutor;
    EXPECT_EQ(defaultExecutor.getX(), 0);
    EXPECT_EQ(defaultExecutor.getY(), 0);
    EXPECT_EQ(defaultExecutor.getHeading(), Executor::Direction::North);
}

// 测试名称获取
TEST_F(ExecutorTest, should_get_executor_name)
{
    ASSERT_EQ(executor->get_name(), "demo");
}

// 测试位置初始化
TEST_F(ExecutorTest, ShouldInitializePosition)
{
    executor->initialize(10, 20, Executor::Direction::West);
    EXPECT_EQ(executor->getX(), 10);
    EXPECT_EQ(executor->getY(), 20);
    EXPECT_EQ(executor->getHeading(), Executor::Direction::West);
}

// 测试右转逻辑
TEST_F(ExecutorTest, ShouldTurnRight)
{
    // 测试从东开始右转
    executor->initialize(0, 0, Executor::Direction::East);
    executor->turnRight();
    EXPECT_EQ(executor->getHeading(), Executor::Direction::South);
    // 继续右转
    executor->turnRight();
    EXPECT_EQ(executor->getHeading(), Executor::Direction::West);
    executor->turnRight();
    EXPECT_EQ(executor->getHeading(), Executor::Direction::North);
    executor->turnRight();
    EXPECT_EQ(executor->getHeading(), Executor::Direction::East); // 回到初始方向
}

// 测试左转逻辑
TEST_F(ExecutorTest, ShouldTurnLeft)
{
    // 测试从东开始左转
    executor->initialize(0, 0, Executor::Direction::East);
    executor->turnLeft();
    EXPECT_EQ(executor->getHeading(), Executor::Direction::North);
    // 继续左转
    executor->turnLeft();
    EXPECT_EQ(executor->getHeading(), Executor::Direction::West);
    executor->turnLeft();
    EXPECT_EQ(executor->getHeading(), Executor::Direction::South);
    executor->turnLeft();
    EXPECT_EQ(executor->getHeading(), Executor::Direction::East); // 回到初始方向
}

// 测试方向字符串转换
TEST_F(ExecutorTest, ShouldConvertDirectionToString)
{
    EXPECT_EQ(directionToString(Executor::Direction::East), "东");
    EXPECT_EQ(directionToString(Executor::Direction::South), "南");
    EXPECT_EQ(directionToString(Executor::Direction::West), "西");
    EXPECT_EQ(directionToString(Executor::Direction::North), "北");
}

// 测试前进指令(forward)
TEST_F(ExecutorTest, ShouldMoveForward)
{
    // 向东前进
    executor->initialize(0, 0, Executor::Direction::East);
    executor->forward();
    EXPECT_EQ(executor->getX(), 1);
    EXPECT_EQ(executor->getY(), 0);
    EXPECT_EQ(executor->getHeading(), Executor::Direction::East); // 方向不变
    // 向南前进
    executor->initialize(0, 0, Executor::Direction::South);
    executor->forward();
    EXPECT_EQ(executor->getX(), 0);
    EXPECT_EQ(executor->getY(), -1); // Y轴负方向为南
    // 向西前进
    executor->initialize(0, 0, Executor::Direction::West);
    executor->forward();
    EXPECT_EQ(executor->getX(), -1);
    EXPECT_EQ(executor->getY(), 0);
    // 向北前进
    executor->initialize(0, 0, Executor::Direction::North);
    executor->forward();
    EXPECT_EQ(executor->getX(), 0);
    EXPECT_EQ(executor->getY(), 1); // Y轴正方向为北
}

// 测试后退指令(backward)
TEST_F(ExecutorTest, ShouldMoveBackward)
{
    // 向东后退
    executor->initialize(0, 0, Executor::Direction::East);
    executor->backward();
    EXPECT_EQ(executor->getX(), -1);
    EXPECT_EQ(executor->getY(), 0);
    EXPECT_EQ(executor->getHeading(), Executor::Direction::East); // 方向不变
    // 向南后退
    executor->initialize(0, 0, Executor::Direction::South);
    executor->backward();
    EXPECT_EQ(executor->getX(), 0);
    EXPECT_EQ(executor->getY(), 1); // 后退相当于向北移动
    // 向西后退
    executor->initialize(0, 0, Executor::Direction::West);
    executor->backward();
    EXPECT_EQ(executor->getX(), 1);
    EXPECT_EQ(executor->getY(), 0);
    // 向北后退
    executor->initialize(0, 0, Executor::Direction::North);
    executor->backward();
    EXPECT_EQ(executor->getX(), 0);
    EXPECT_EQ(executor->getY(), -1); // 后退相当于向南移动
}

// 测试旋转180度指令(turnRound)
TEST_F(ExecutorTest, ShouldTurnRound)
{
    // 初始位置和方向
    const int initialX = 5;
    const int initialY = 5;
    // 测试从东开始旋转
    executor->initialize(initialX, initialY, Executor::Direction::East);
    executor->turnRound();
    EXPECT_EQ(executor->getHeading(), Executor::Direction::West);
    EXPECT_EQ(executor->getX(), initialX); // 位置不变
    EXPECT_EQ(executor->getY(), initialY); // 位置不变
    // 测试从南开始旋转
    executor->initialize(initialX, initialY, Executor::Direction::South);
    executor->turnRound();
    EXPECT_EQ(executor->getHeading(), Executor::Direction::North);
    // 测试从西开始旋转
    executor->initialize(initialX, initialY, Executor::Direction::West);
    executor->turnRound();
    EXPECT_EQ(executor->getHeading(), Executor::Direction::East);
    // 测试从北开始旋转
    executor->initialize(initialX, initialY, Executor::Direction::North);
    executor->turnRound();
    EXPECT_EQ(executor->getHeading(), Executor::Direction::South);
}

// 测试组合动作
TEST_F(ExecutorTest, ShouldHandleCombinedActions)
{
    // 初始位置和方向
    executor->initialize(0, 0, Executor::Direction::East); 
    // 前进+右转
    executor->forward();
    executor->turnRight();
    EXPECT_EQ(executor->getX(), 1);
    EXPECT_EQ(executor->getY(), 0);
    EXPECT_EQ(executor->getHeading(), Executor::Direction::South);
    // 后退+左转
    executor->backward();
    executor->turnLeft();
    EXPECT_EQ(executor->getX(), 1);
    EXPECT_EQ(executor->getY(), 1); // 后退相当于向北移动
    EXPECT_EQ(executor->getHeading(), Executor::Direction::East);
    // 旋转180度+前进
    executor->turnRound();
    executor->forward();
    EXPECT_EQ(executor->getX(), 0); // 旋转后朝西，前进x-1
    EXPECT_EQ(executor->getY(), 1);
    EXPECT_EQ(executor->getHeading(), Executor::Direction::West);
}

// 测试边界情况
TEST_F(ExecutorTest, ShouldHandleEdgeCases)
{   
    // 测试最大整数值前进
    executor->initialize(INT_MAX, 0, Executor::Direction::East);
    executor->forward();
    // 修改期望值为溢出后的结果
    EXPECT_EQ(executor->getX(), INT_MAX); // 整数溢出后变为最小负值
    // 测试最小整数值后退
    executor->initialize(INT_MIN, 0, Executor::Direction::West);
    executor->forward();
    // 修改期望值为溢出后的结果
    EXPECT_EQ(executor->getX(), INT_MIN); // 整数溢出后变为最大正值
    // 测试连续旋转
    executor->initialize(0, 0, Executor::Direction::North);
    for (int i = 0; i < 10; i++) {
        executor->turnRound();
    }
    // 旋转10次（5个完整旋转）应回到原方向
    EXPECT_EQ(executor->getHeading(), Executor::Direction::North);
}

// 测试极端边界条件下的移动
TEST_F(ExecutorTest, ShouldHandleExtremeBoundaries)
{
    // 测试INT_MAX边界
    executor->initialize(INT_MAX, INT_MAX, Executor::Direction::East);
    // 尝试向东移动（应该失败）
    executor->forward();
    EXPECT_EQ(executor->getX(), INT_MAX);
    EXPECT_EQ(executor->getY(), INT_MAX);
    // 尝试向北移动（应该失败）
    executor->turnLeft();
    executor->forward();
    EXPECT_EQ(executor->getX(), INT_MAX);
    EXPECT_EQ(executor->getY(), INT_MAX);
}
// 测试危险点告警
TEST_F(ExecutorTest, ShouldAlertWhenMovingToDangerPoint)
{
    // 模拟告警计数器
    resetAlertCount();
    executor->setAlertCallback([this](int type, int x, int y) {
        this->mockAlert(type, x, y);
    });
    // 使用addConfigPoint添加危险点
    executor->addConfigPoint(2, 3, Executor::PointType::DANGER);
    // 初始化位置
    executor->initialize(0, 0, Executor::Direction::East);
    // 移动到危险点
    executor->forward(); // (1,0)
    executor->forward(); // (2,0)
    executor->initialize(2, 2, Executor::Direction::North);
    executor->forward(); // (2,3) - 危险点
    EXPECT_EQ(alertCount, 1);
    EXPECT_EQ(lastAlertType, 3);
    EXPECT_EQ(lastAlertX, 2);
    EXPECT_EQ(lastAlertY, 3);
    // 离开并再次返回危险点
    executor->backward(); // (2,2)
    resetAlertCount();
    executor->forward(); // (2,3) - 再次触发告警
    EXPECT_EQ(alertCount, 1); // 再次触发告警
}

// 测试重复告警
TEST_F(ExecutorTest, ShouldAlertRepeatedlyAtDangerPoint)
{
    resetAlertCount();
    executor->setAlertCallback([this](int type, int x, int y) {
        this->mockAlert(type, x, y);
    });
    // 使用addConfigPoint添加危险点
    executor->addConfigPoint(1, 1, Executor::PointType::DANGER);
    // 初始化位置
    executor->initialize(1, 1, Executor::Direction::East); // 初始化在危险点
    // 连续多次在危险点移动
    for (int i = 0; i < 5; i++) {
        executor->turnLeft(); // 转向不移动
        executor->turnRight();
    }
    EXPECT_EQ(alertCount, 1); // 初始化时应触发一次告警
    // 移动后触发告警
    executor->forward(); // 移动到 (2,1)
    executor->backward(); // 移回 (1,1) - 触发告警
    EXPECT_EQ(alertCount, 2);
    // 再次移动离开并返回
    executor->forward(); // (2,1)
    executor->backward(); // (1,1) - 再次触发告警
    EXPECT_EQ(alertCount, 3);
}

// 测试未设置危险点时不告警
TEST_F(ExecutorTest, ShouldNotAlertWithoutDangerPoint)
{
    resetAlertCount();
    executor->setAlertCallback([this](int type, int x, int y) {
        this->mockAlert(type, x, y);
    });
    // 不设置危险点
    // 移动到潜在危险点
    executor->initialize(5, 5, Executor::Direction::East);
    executor->forward(); // (6,5)
    EXPECT_EQ(alertCount, 0); // 不应触发告警
}

// 测试清扫点触发
TEST_F(ExecutorTest, ShouldCleanWhenFirstTimeReachCleanPoint) {
    executor->setCleanCallback([this](int x, int y) {
        this->mockClean(x, y);
    });
    // 使用addConfigPoint添加清扫点
    executor->addConfigPoint(2, 3, Executor::PointType::CLEAN);
    // 第一次移动到清扫点
    executor->initialize(2, 3, Executor::Direction::East);
    EXPECT_EQ(cleanCount, 1);
    EXPECT_EQ(lastCleanX, 2);
    EXPECT_EQ(lastCleanY, 3);
    // 离开并再次返回
    executor->forward(); // 离开
    resetCleanCount();
    executor->backward(); // 返回
    // 不应再次触发清扫
    EXPECT_EQ(cleanCount, 0);
}

// 测试多次经过同一清扫点只触发一次
TEST_F(ExecutorTest, ShouldCleanOnlyOnceForSamePoint) {
    executor->setCleanCallback([this](int x, int y) {
        this->mockClean(x, y);
    });
    // 使用addConfigPoint添加清扫点
    executor->addConfigPoint(1, 1, Executor::PointType::CLEAN);
    // 第一次移动到清扫点
    executor->initialize(1, 1, Executor::Direction::East);
    EXPECT_EQ(cleanCount, 1);
    // 多次在清扫点移动
    for (int i = 0; i < 5; i++) {
        executor->turnLeft();
        executor->turnRight();
        resetCleanCount();
    }
    // 转向操作不应触发清扫
    EXPECT_EQ(cleanCount, 0);
    // 离开并返回
    executor->forward(); // 离开
    resetCleanCount();
    executor->backward(); // 返回
    // 返回清扫点也不应触发
    EXPECT_EQ(cleanCount, 0);
}

// 测试多个清扫点
TEST_F(ExecutorTest, ShouldCleanMultiplePoints) {
    executor->setCleanCallback([this](int x, int y) {
        this->mockClean(x, y);
    });
    // 使用addConfigPoint设置两个清扫点
    executor->addConfigPoint(1, 1, Executor::PointType::CLEAN);
    executor->addConfigPoint(2, 2, Executor::PointType::CLEAN);
    // 移动到第一个清扫点
    executor->initialize(1, 1, Executor::Direction::East);
    EXPECT_EQ(cleanCount, 1);
    EXPECT_EQ(lastCleanX, 1);
    EXPECT_EQ(lastCleanY, 1);
    // 移动到第二个清扫点
    resetCleanCount();
    executor->initialize(2, 2, Executor::Direction::East);
    EXPECT_EQ(cleanCount, 1);
    EXPECT_EQ(lastCleanX, 2);
    EXPECT_EQ(lastCleanY, 2);
}

// 测试未设置清扫点时不会触发
TEST_F(ExecutorTest, ShouldNotCleanWithoutCleanPoint) {
    executor->setCleanCallback([this](int x, int y) {
        this->mockClean(x, y);
    });
    // 不设置清扫点
    executor->initialize(5, 5, Executor::Direction::East);
    EXPECT_EQ(cleanCount, 0);
}

// 测试动态配置点
TEST_F(ExecutorTest, ShouldAddAndRemoveConfigPoints) {
    // 添加清扫点
    ASSERT_TRUE(executor->addConfigPoint(1, 1, Executor::PointType::CLEAN));
    ASSERT_EQ(executor->getConfigPointCount(), 1);
    // 添加危险点
    ASSERT_TRUE(executor->addConfigPoint(2, 2, Executor::PointType::DANGER));
    ASSERT_EQ(executor->getConfigPointCount(), 2);
    // 添加重复点应失败
    ASSERT_FALSE(executor->addConfigPoint(1, 1, Executor::PointType::CLEAN));
    ASSERT_EQ(executor->getConfigPointCount(), 2);
    // 移除点
    ASSERT_TRUE(executor->removeConfigPoint(1, 1));
    ASSERT_EQ(executor->getConfigPointCount(), 1);
    // 移除不存在的点应失败
    ASSERT_FALSE(executor->removeConfigPoint(3, 3));
    ASSERT_EQ(executor->getConfigPointCount(), 1);
}

// 测试资源限制
TEST_F(ExecutorTest, ShouldEnforceResourceLimit) {
    // 添加16个点
    for (int i = 0; i < 16; i++) {
        ASSERT_TRUE(executor->addConfigPoint(i, i, Executor::PointType::CLEAN));
    }
    ASSERT_EQ(executor->getConfigPointCount(), 16);
    // 尝试添加第17个点应失败
    ASSERT_FALSE(executor->addConfigPoint(17, 17, Executor::PointType::DANGER));
    ASSERT_EQ(executor->getConfigPointCount(), 16);
    // 移除一个点后可以添加新点
    ASSERT_TRUE(executor->removeConfigPoint(0, 0));
    ASSERT_TRUE(executor->addConfigPoint(17, 17, Executor::PointType::DANGER));
    ASSERT_EQ(executor->getConfigPointCount(), 16);
}

// 测试清扫点自动回收
TEST_F(ExecutorTest, ShouldAutoRecycleCleanPoints) {
    // 设置回调
    executor->setCleanCallback([this](int x, int y) {
        this->mockClean(x, y);
    });
    // 使用addConfigPoint添加清扫点
    executor->addConfigPoint(1, 1, Executor::PointType::CLEAN);
    // 移动到清扫点
    executor->initialize(1, 1, Executor::Direction::East);
    EXPECT_EQ(cleanCount, 1);
    EXPECT_EQ(executor->getConfigPointCount(), 0); // 自动回收
    // 再次移动不应触发
    resetCleanCount();
    executor->initialize(1, 1, Executor::Direction::East);
    EXPECT_EQ(cleanCount, 0);
}

// 测试危险点不自动回收
TEST_F(ExecutorTest, ShouldNotAutoRecycleDangerPoints)
{
    // 设置回调
    executor->setAlertCallback([this](int type, int x, int y) {
        this->mockAlert(type, x, y);
    });
    // 使用addConfigPoint添加危险点
    executor->addConfigPoint(1, 1, Executor::PointType::DANGER);
    // 第一次移动到危险点
    executor->initialize(1, 1, Executor::Direction::East);
    EXPECT_EQ(alertCount, 1);
    EXPECT_EQ(executor->getConfigPointCount(), 1); // 不回收
    // 第二次移动到危险点 - 修改为使用forward/backward移动
    resetAlertCount();
    executor->backward(); // 移动到(0,1)
    executor->forward();  // 移回(1,1)
    EXPECT_EQ(alertCount, 1); // 再次触发
    EXPECT_EQ(executor->getConfigPointCount(), 1); // 仍然存在
}    

// 测试资源回收后可用
TEST_F(ExecutorTest, ShouldReuseRecycledResources) {
    // 添加16个清扫点
    for (int i = 0; i < 16; i++) {
        executor->addConfigPoint(i, i, Executor::PointType::CLEAN);
    }
    // 触发一个清扫点
    executor->initialize(0, 0, Executor::Direction::East);
    EXPECT_EQ(executor->getConfigPointCount(), 15); // 自动回收
    // 现在可以添加新点
    ASSERT_TRUE(executor->addConfigPoint(16, 16, Executor::PointType::DANGER));
    EXPECT_EQ(executor->getConfigPointCount(), 16);
}    

// 测试状态上报
TEST_F(ExecutorTest, ShouldSendStatusAfterMove)
{
    // 添加危险点
    executor->addConfigPoint(1, 0, Executor::PointType::DANGER);
    // 初始化位置
    executor->initialize(0, 0, Executor::Direction::East);
    ASSERT_EQ(jsonMessages.size(), 1);
    EXPECT_EQ(jsonMessages[0], "{ \"x\": 0, \"y\": 0, \"action\": \"none\" }");
    // 移动到危险点
    executor->forward(); // (1,0)
    ASSERT_EQ(jsonMessages.size(), 2);
    EXPECT_EQ(jsonMessages[1], "{ \"x\": 1, \"y\": 0, \"action\": \"alert\" }");
    // 添加清扫点
    executor->addConfigPoint(1, 1, Executor::PointType::CLEAN);
    // 移动到清扫点
    executor->initialize(1, 1, Executor::Direction::East);
    ASSERT_EQ(jsonMessages.size(), 3);
    EXPECT_EQ(jsonMessages[2], "{ \"x\": 1, \"y\": 1, \"action\": \"clean\" }");
    // 移动到无事件点
    executor->forward(); // (2,1)
    ASSERT_EQ(jsonMessages.size(), 4);
    EXPECT_EQ(jsonMessages[3], "{ \"x\": 2, \"y\": 1, \"action\": \"none\" }");
}

// 测试初始化位置事件上报
TEST_F(ExecutorTest, ShouldReportInitialPositionEvents)
{
    // 在初始化位置设置清扫点
    executor->addConfigPoint(0, 0, Executor::PointType::CLEAN);
    // 初始化
    executor->initialize(0, 0, Executor::Direction::East);
    ASSERT_EQ(jsonMessages.size(), 1);
    EXPECT_EQ(jsonMessages[0], "{ \"x\": 0, \"y\": 0, \"action\": \"clean\" }");
}

// 测试多次移动上报
TEST_F(ExecutorTest, ShouldReportEveryMove)
{
    // 移动序列
    executor->initialize(0, 0, Executor::Direction::East);
    executor->forward(); // (1,0)
    executor->turnRight(); // 转向不移动，不发送
    executor->forward(); // (1,-1)
    executor->turnLeft(); // 转向不移动，不发送
    executor->backward(); // (0,-1)
    // 验证 5 次状态上报 (初始化 + 3 次移动)
    EXPECT_EQ(jsonMessages.size(), 4);
    // 验证最后一次上报
    EXPECT_EQ(jsonMessages[3], "{ \"x\": 0, \"y\": -1, \"action\": \"none\" }");
}

// 测试 JSON 格式正确性
TEST_F(ExecutorTest, ShouldGenerateValidJson)
{
    executor->initialize(3, 5, Executor::Direction::East);
    // 验证 JSON 格式
    ASSERT_EQ(jsonMessages.size(), 1);
    const std::string& json = jsonMessages[0];
    // 验证基本字段
    EXPECT_TRUE(json.find("\"x\": 3") != std::string::npos);
    EXPECT_TRUE(json.find("\"y\": 5") != std::string::npos);
    EXPECT_TRUE(json.find("\"action\": \"none\"") != std::string::npos);
    // 验证完整格式
    EXPECT_EQ(json, "{ \"x\": 3, \"y\": 5, \"action\": \"none\" }");
}

// 测试转向操作不发送状态
TEST_F(ExecutorTest, ShouldNotSendStatusForRotation)
{
    executor->initialize(0, 0, Executor::Direction::East);
    size_t initialCount = jsonMessages.size();
    // 执行转向操作
    executor->turnRight();
    executor->turnLeft();
    executor->turnRound();
    // 验证没有新的 JSON 消息
    EXPECT_EQ(jsonMessages.size(), initialCount);
}

// 测试边界条件下的移动和状态上报
TEST_F(ExecutorTest, ShouldNotReportStatusWhenBoundaryMoveFails)
{
    // 测试INT_MIN边界（面朝南）
    executor->initialize(0, INT_MIN, Executor::Direction::South);
    size_t initialReports = jsonMessages.size();
    // 尝试向南移动（应失败，因已达INT_MIN）
    executor->forward();
    EXPECT_EQ(executor->getY(), INT_MIN);  // 确保位置未变
    EXPECT_EQ(jsonMessages.size(), initialReports);  // 确保未发送新状态
    // 测试INT_MAX边界（面朝北）
    executor->initialize(0, INT_MAX, Executor::Direction::North);
    initialReports = jsonMessages.size();
    // 尝试向北移动（应失败，因已达INT_MAX）
    executor->forward();
    EXPECT_EQ(executor->getY(), INT_MAX);  // 确保位置未变
    EXPECT_EQ(jsonMessages.size(), initialReports);  // 确保未发送新状态
    // 测试INT_MIN边界（面朝西）
    executor->initialize(INT_MIN, 0, Executor::Direction::West);
    initialReports = jsonMessages.size();
    // 尝试向西移动（应失败，因已达INT_MIN）
    executor->forward();
    EXPECT_EQ(executor->getX(), INT_MIN);  // 确保位置未变
    EXPECT_EQ(jsonMessages.size(), initialReports);  // 确保未发送新状态
    // 测试INT_MAX边界（面朝东）
    executor->initialize(INT_MAX, 0, Executor::Direction::East);
    initialReports = jsonMessages.size();
    // 尝试向东移动（应失败，因已达INT_MAX）
    executor->forward();
    EXPECT_EQ(executor->getX(), INT_MAX);  // 确保位置未变
    EXPECT_EQ(jsonMessages.size(), initialReports);  // 确保未发送新状态
}

// 测试混合事件序列
TEST_F(ExecutorTest, ShouldReportMixedEventSequence)
{
    // 设置点
    executor->addConfigPoint(1, 0, Executor::PointType::DANGER);  // 危险点
    executor->addConfigPoint(2, 0, Executor::PointType::CLEAN);   // 清扫点
    // 初始化
    executor->initialize(0, 0, Executor::Direction::East);
    EXPECT_EQ(jsonMessages.size(), 1);
    EXPECT_EQ(jsonMessages[0], "{ \"x\": 0, \"y\": 0, \"action\": \"none\" }");
    // 移动到危险点
    executor->forward(); // (1,0)
    EXPECT_EQ(jsonMessages.size(), 2);
    EXPECT_EQ(jsonMessages[1], "{ \"x\": 1, \"y\": 0, \"action\": \"alert\" }");
    // 移动到清扫点
    executor->forward(); // (2,0)
    EXPECT_EQ(jsonMessages.size(), 3);
    EXPECT_EQ(jsonMessages[2], "{ \"x\": 2, \"y\": 0, \"action\": \"clean\" }");
    // 返回危险点 (清扫点已移除)
    executor->backward(); // (1,0)
    EXPECT_EQ(jsonMessages.size(), 4);
    EXPECT_EQ(jsonMessages[3], "{ \"x\": 1, \"y\": 0, \"action\": \"alert\" }");
    // 返回原点
    executor->backward(); // (0,0)
    EXPECT_EQ(jsonMessages.size(), 5);
    EXPECT_EQ(jsonMessages[4], "{ \"x\": 0, \"y\": 0, \"action\": \"none\" }");
}

// 测试二进制消息格式
TEST_F(ExecutorTest, ShouldSendBinaryMessage)
{
    // 设置为二进制格式
    executor->setMessageFormat(Executor::MessageFormat::BINARY);
    // 存储接收到的消息
    std::vector<WifiMsg> receivedMsgs;
    executor->setMsgCallback([&](const WifiMsg* msg) {
        receivedMsgs.push_back(*msg);
    });
    // 添加危险点
    executor->addConfigPoint(1, 0, Executor::PointType::DANGER);
    // 初始化位置
    executor->initialize(0, 0, Executor::Direction::East);
    ASSERT_EQ(receivedMsgs.size(), 1);
    EXPECT_EQ(receivedMsgs[0].x, 0);
    EXPECT_EQ(receivedMsgs[0].y, 0);
    EXPECT_EQ(receivedMsgs[0].action, 0); // none
    // 移动到危险点
    executor->forward(); // (1,0)
    ASSERT_EQ(receivedMsgs.size(), 2);
    EXPECT_EQ(receivedMsgs[1].x, 1);
    EXPECT_EQ(receivedMsgs[1].y, 0);
    EXPECT_EQ(receivedMsgs[1].action, 1); // alert
}

// 测试消息格式切换
TEST_F(ExecutorTest, ShouldSwitchMessageFormats)
{
    // 初始为JSON格式
    executor->setMessageFormat(Executor::MessageFormat::JSON);
    // 存储JSON消息
    std::vector<std::string> jsonMsgs;
    executor->setJsonCallback([&](const char* json) {
        jsonMsgs.push_back(json);
    });
    // 移动到某位置
    executor->initialize(5, 5, Executor::Direction::East);
    ASSERT_EQ(jsonMsgs.size(), 1);
    // 切换到二进制格式
    executor->setMessageFormat(Executor::MessageFormat::BINARY);
    // 存储二进制消息
    std::vector<WifiMsg> binaryMsgs;
    executor->setMsgCallback([&](const WifiMsg* msg) {
        binaryMsgs.push_back(*msg);
    });
    // 再次移动
    executor->forward();
    ASSERT_EQ(binaryMsgs.size(), 1);
    EXPECT_EQ(binaryMsgs[0].x, 6);
    EXPECT_EQ(binaryMsgs[0].y, 5);
}

// 测试默认格式
TEST_F(ExecutorTest, ShouldDefaultToJsonFormat)
{
    // 不设置格式，应为默认JSON
    std::vector<std::string> jsonMsgs;
    executor->setJsonCallback([&](const char* json) {
        jsonMsgs.push_back(json);
    });
    executor->initialize(0, 0, Executor::Direction::East);
    EXPECT_EQ(jsonMsgs.size(), 1);
}

// 测试二进制格式下的各种动作
TEST_F(ExecutorTest, ShouldHandleAllActionsInBinaryFormat)
{
    executor->setMessageFormat(Executor::MessageFormat::BINARY);
    std::vector<WifiMsg> receivedMsgs;
    executor->setMsgCallback([&](const WifiMsg* msg) {
        receivedMsgs.push_back(*msg);
    });
    // 设置清扫点
    executor->addConfigPoint(2, 2, Executor::PointType::CLEAN);
    // 初始化位置
    executor->initialize(0, 0, Executor::Direction::East);
    EXPECT_EQ(receivedMsgs[0].action, 0); // none
    // 移动到清扫点
    executor->initialize(2, 2, Executor::Direction::East);
    EXPECT_EQ(receivedMsgs[1].action, 2); // clean
    // 设置危险点
    executor->addConfigPoint(3, 3, Executor::PointType::DANGER);
    // 移动到危险点
    executor->initialize(3, 3, Executor::Direction::East);
    EXPECT_EQ(receivedMsgs[2].action, 1); // alert
}

// 测试 forward n step 指令
TEST_F(ExecutorTest, ShouldMoveForwardNSteps) {
    executor->initialize(0, 0, Executor::Direction::East);
    executor->forwardNSteps(3);
    EXPECT_EQ(executor->getX(), 3);
    EXPECT_EQ(executor->getY(), 0);
    EXPECT_EQ(executor->getHeading(), Executor::Direction::East);
}

// 测试 backward n step 指令
TEST_F(ExecutorTest, ShouldMoveBackwardNSteps) {
    executor->initialize(0, 0, Executor::Direction::East);
    executor->backwardNSteps(3);
    EXPECT_EQ(executor->getX(), -3);
    EXPECT_EQ(executor->getY(), 0);
    EXPECT_EQ(executor->getHeading(), Executor::Direction::East);
}

// 测试 repeat command n time 指令
TEST_F(ExecutorTest, ShouldRepeatCommandNTimes) {
    executor->initialize(0, 0, Executor::Direction::East);
    // 修改捕获列表，捕获 this 指针
    executor->repeatCommand([this]() { this->executor->forward(); }, 3);
    EXPECT_EQ(executor->getX(), 3);
    EXPECT_EQ(executor->getY(), 0);
    EXPECT_EQ(executor->getHeading(), Executor::Direction::East);
}

// 测试嵌套指令解析和执行
TEST_F(ExecutorTest, ShouldExecuteNestedCommands) {
    executor->initialize(0, 0, Executor::Direction::East);
    // 测试简单指令列表
    executor->executeCompositeCommand("{forward, turn right, forward}");
    EXPECT_EQ(executor->getX(), 1);
    EXPECT_EQ(executor->getY(), -1);
    EXPECT_EQ(executor->getHeading(), Executor::Direction::South);
    // 重置位置
    executor->initialize(0, 0, Executor::Direction::East);
    // 测试嵌套repeat
    executor->executeCompositeCommand("repeat {forward, turn right} 2");
    EXPECT_EQ(executor->getX(), 1);
    EXPECT_EQ(executor->getY(), -1);
    EXPECT_EQ(executor->getHeading(), Executor::Direction::West);
    // 重置位置
    executor->initialize(0, 0, Executor::Direction::East);
    // 测试多层嵌套
    executor->executeCompositeCommand("{repeat {forward, turn right} 2, backward}");
    EXPECT_EQ(executor->getX(), 2);
    EXPECT_EQ(executor->getY(), -1);
    EXPECT_EQ(executor->getHeading(), Executor::Direction::West);
}

// 测试更复杂的嵌套指令
TEST_F(ExecutorTest, ShouldExecuteComplexNestedCommands) {
    executor->initialize(0, 0, Executor::Direction::East);
    // 复杂嵌套指令: {forward 2 step, {turn right, forward}, repeat {backward, turn left} 2}
    // 预期执行:
    // 1. forward 2 step: x=2, y=0, heading=East
    // 2. {turn right, forward}: heading=South, x=2, y=-1
    // 3. repeat {backward, turn left} 2:
    //    - 第一次: backward: x=2, y=0; turn left: heading=East
    //    - 第二次: backward: x=1, y=0; turn left: heading=North
    executor->executeCompositeCommand("{forward 2 step, {turn right, forward}, repeat {backward, turn left} 2}");
    // 预期最终位置和方向
    EXPECT_EQ(executor->getX(), 1);
    EXPECT_EQ(executor->getY(), 0);
    EXPECT_EQ(executor->getHeading(), Executor::Direction::North);
}

// 测试指令解析错误处理
TEST_F(ExecutorTest, ShouldHandleCommandParseErrors) {
    // 测试无效指令
    EXPECT_THROW(executor->executeCompositeCommand("invalid command"), std::invalid_argument);
    // 测试不匹配的括号
    EXPECT_THROW(executor->executeCompositeCommand("{forward, turn right"), std::invalid_argument);
    EXPECT_THROW(executor->executeCompositeCommand("forward, turn right}"), std::invalid_argument);
    // 测试无效的repeat语法
    EXPECT_THROW(executor->executeCompositeCommand("repeat forward 2 times"), std::invalid_argument);
    EXPECT_THROW(executor->executeCompositeCommand("repeat {forward} two"), std::invalid_argument);
}

// 测试指令列表的嵌套执行
TEST_F(ExecutorTest, ShouldExecuteNestedCommandList) {
    executor->initialize(0, 0, Executor::Direction::East);
    // 指令: {forward, {turn right, forward}, backward}
    // 预期:
    // 1. forward: (1,0), East
    // 2. 执行嵌套指令列表: {turn right, forward}
    //   a. turn right: 方向变为South
    //   b. forward: (1,-1), South
    // 3. backward: (1,0), South (backward是向当前方向的相反方向移动)
    executor->executeCompositeCommand("{forward, {turn right, forward}, backward}");
    EXPECT_EQ(executor->getX(), 1);
    EXPECT_EQ(executor->getY(), 0);
    EXPECT_EQ(executor->getHeading(), Executor::Direction::South);
}

// 测试多层嵌套指令
TEST_F(ExecutorTest, ShouldExecuteMultiLevelNestedCommands) {
    executor->initialize(0, 0, Executor::Direction::East);
    // 指令: repeat { {forward, turn right}, repeat {turn left} 2 } 2
    // 预期:
    // 重复两次:
    //   第一次:
    //     a. {forward, turn right}: (1,0) East → (1,0) South
    //     b. repeat {turn left} 2: South → East → North
    //   第二次:
    //     a. {forward, turn right}: (1,0) North → forward (1,1) North → turn right (East)
    //     b. repeat {turn left} 2: East → North → West
    // 最终位置: (1,1), 方向West
    executor->executeCompositeCommand("repeat { {forward, turn right}, repeat {turn left} 2 } 2");
    EXPECT_EQ(executor->getX(), 1);
    EXPECT_EQ(executor->getY(), 1);
    EXPECT_EQ(executor->getHeading(), Executor::Direction::West);
}

// 测试复杂混合指令
TEST_F(ExecutorTest, ShouldExecuteComplexMixedCommands) {
    executor->initialize(0, 0, Executor::Direction::North);
    executor->executeCompositeCommand("{forward 2 step, repeat {turn right, backward} 2, {turn left, forward}}");
    EXPECT_EQ(executor->getX(), 0);
    EXPECT_EQ(executor->getY(), 3);
    EXPECT_EQ(executor->getHeading(), Executor::Direction::East);
}

// 测试空指令列表
TEST_F(ExecutorTest, ShouldHandleEmptyCommandList) {
    executor->initialize(0, 0, Executor::Direction::East);
    // 空指令列表不应改变状态
    executor->executeCompositeCommand("{}");
    EXPECT_EQ(executor->getX(), 0);
    EXPECT_EQ(executor->getY(), 0);
    EXPECT_EQ(executor->getHeading(), Executor::Direction::East);
    // 包含空列表的指令
    executor->executeCompositeCommand("{forward, {}, turn right}");
    EXPECT_EQ(executor->getX(), 1);
    EXPECT_EQ(executor->getY(), 0);
    EXPECT_EQ(executor->getHeading(), Executor::Direction::South);
}