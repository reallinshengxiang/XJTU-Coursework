package com.huawei.exercise.deps.wifi;

/**
 * wifi msg 实体类
 */
public class WifiMsg {
    /**
     * 消息
     */
    int command;
    /**
     * 动作x坐标点
     */
    int x;
    /**
     * 动作y坐标点
     */
    int y;

    /**
     * 动作类型，0表示没有触发活动，1表示触发告警，2表示触发清扫
     */
    int action;

    public WifiMsg() {
    }

    public WifiMsg(int command, int x, int y, int action) {
        this.command = command;
        this.x = x;
        this.y = y;
        this.action = action;
    }

    public int getCommand() {
        return command;
    }

    public void setCommand(int command) {
        this.command = command;
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    public int getAction() {
        return action;
    }

    public void setAction(int action) {
        this.action = action;
    }
}
