# -*- coding: utf-8 -*-
import linkage as lk
import kmeans as km
import dbscan as db
import features as ft
import sklearn.metrics as skm
import sklearn.preprocessing as skp
import time
import numpy as np
import os, sys, getopt
import pandas as pd
import matplotlib.pyplot as plt


# 载入时序文本数据
def loadTimeSeries(path, separator=","):
    print("开始读入数据...")
    startT = time.time()
    # 读入数据
    df = pd.read_table(path, header=None, sep=separator)
    data = df.to_numpy()
    # 进行归一化处理
    ss = skp.StandardScaler()
    # 如果第0列是标签，不用归一化。
    data[:, 1:] = ss.fit_transform(data[:, 1:])
    endT = time.time()
    print("数据读入结束。共耗时%.3f秒。" % (endT-startT))
    return data[:, 1:], data[:, 0]
# end of loadTimeSeries


# 载入散点数据
def loadDots(path, separator=" "):
    print("开始读入数据...")
    startT = time.time()
    # 读入数据
    df = pd.read_table(path, header=None, sep=separator)
    data = df.to_numpy()
    endT = time.time()
    print("数据读入结束。共耗时%.3f秒。" % (endT-startT))
    return data
# end of loadDots


# 载入数据并进行特征抽取
def loadData(path, dataType):
    x_train = y_train = None
    if dataType == "dot":
        x_train = loadDots(path)
        x_train, t = ft.dotFeature(x_train, None)
    elif dataType == "timeseries":
        x_train, y_train = loadTimeSeries(path)
        x_train, t = ft.timeSeriesFeature(x_train, None)
    else:
        print("%s是未知数据类型。" % dataType)
        sys.exit()
    return x_train, y_train
# end of loadData


# 聚类结果度量指标
def NMI(y_true, y_pred):
    y_true = np.squeeze(y_true)
    return skm.normalized_mutual_info_score(y_true, y_pred)


# 聚类结果度量指标
def ARI(y_true, y_pred):
    y_true = np.squeeze(y_true)
    return skm.adjusted_rand_score(y_true, y_pred)


def showDots(x, label, outputName):
    '''get the number of clusters'''
    num_cluster = np.unique(label).size
    fig, ax = plt.subplots(1)
    for i in range(num_cluster):
        ax.scatter(x[label==i,0], x[label==i,1], s=2)
    plt.savefig(outputName)


def test(x, y, cluster, modelName):
    print("-" * 60)
    if y is None or len(y)==0:
        showDots(x, cluster.labels_, modelName+"-dots.png")
        print("%s聚类结果见输出图片。" % modelName)
    else:
        print("%s聚类结果：" % modelName)
        pred_label = cluster.labels_
        ari = ARI(y, pred_label)
        nmi = NMI(y, pred_label)
        print("ARI=%.3f, NMI=%.3f" % (ari, nmi))
# end of test


def usage():
    print("This is a machine learning experiment program. \nIts command line parameters are:")
    print("-d dataPath: The path with file name of the data file.")
    print("-m modelName: The name of the machine learning model is one of {linkage, kmeans, dbscan}.")
    print("-s settings: The tuple of the model settings, such as [10,5].")
    print("-t dataType: The type of the data is one of {dot, timeSeries}.")
# end of usage


if __name__ == '__main__':
    # 解析命令行
    try:
        opts, args = getopt.getopt(sys.argv[1:], 'd:m:s:t:')
    except getopt.GetoptError:
        usage()
        sys.exit()

    dataName = None
    dataType = None
    modelName = None
    settings = None
    for opt, arg in opts:
        if opt == '-d':
            dataName = arg
        elif opt == '-m':
            modelName = arg.lower()
        elif opt == '-s':
            settings = tuple(eval(arg))
        elif opt == '-t':
            dataType = arg.lower()
        else:
            usage()
            sys.exit()
    if not modelName:
        print("Please indicate the model name.")
        usage()
        sys.exit()

    # 载入数据
    xTrain, yTrain = loadData(dataName, dataType)
    clst = None
    if modelName == "linkage":
        # 凝聚法层次聚类
        if settings is None: settings = (5, "single")
        clst = lk.train(xTrain, *settings)
        modelName = lk.ModelName
    elif modelName == "kmeans":
        if settings is None: settings = (5, "random")
        clst = km.train(xTrain, *settings)
        modelName = km.ModelName
    elif modelName == "dbscan":
        if settings is None: settings = (8, 10)
        clst = db.train(xTrain, *settings)
        modelName = db.ModelName
    else:
        print("\"%s\"是未知模型，本程序无法识别。" % modelName)
        sys.exit()

    # 报告聚类结果
    test(xTrain, yTrain, clst, modelName)
# end of main
