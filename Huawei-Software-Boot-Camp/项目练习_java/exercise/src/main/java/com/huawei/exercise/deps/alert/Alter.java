package com.huawei.exercise.deps.alert;

/**
 * 告警接口
 */
public interface Alter {
    /**
     * 发送警告，默认不做任何操作，可通过覆写该方法实现告警行为
     *
     * @param type 告警类型
     * @param x    坐标x
     * @param y    坐标y
     */
    default public void alert(AlterType type, int x, int y) {
    }

}
