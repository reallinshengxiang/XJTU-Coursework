package com.huawei.exercise.executor;

import org.junit.After;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class ExecutorTest {

    Executor executor;

    @Before
    public void setUp() {
        executor = new Executor("test");
    }

    @After
    public void tearDown() {
        executor = null;
    }


    @Test
    public void getName() {
        Assert.assertEquals("test", executor.getName());
    }

}