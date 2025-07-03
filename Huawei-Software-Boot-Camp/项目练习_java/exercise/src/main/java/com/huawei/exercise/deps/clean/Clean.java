package com.huawei.exercise.deps.clean;

/**
 * 清扫
 */
public interface Clean {

    /**
     * 清扫坐标x,y点
     *
     * @param x x坐标点
     * @param y y坐标点
     */
    default public void clean(int x, int y) {
    }
}
