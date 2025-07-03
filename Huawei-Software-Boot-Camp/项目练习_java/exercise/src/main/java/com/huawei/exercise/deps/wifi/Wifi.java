package com.huawei.exercise.deps.wifi;

public interface Wifi {

    default public void sendJson(String json) {
    }
    default public void sendMsg(WifiMsg msg) {
    }
}
