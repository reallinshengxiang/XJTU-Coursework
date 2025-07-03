package com.huawei.exercise.deps.alert;

/**
 * 告警类型
 */
public enum AlterType {
    /**
     * 危险状态
     */
    IN_DANGEROUS(3);
    private int type;

    AlterType(int type) {
        this.type = type;
    }

    /**
     * 获取告警类型值
     *
     * @return 告警类型值
     */
    public int getType() {
        return this.type;
    }
}
