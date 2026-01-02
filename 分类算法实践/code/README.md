# DM分类算法实现
环境配置
```
conda create -n DM python=3.10
conda activate DM
pip install -r requirements.txt
```
运行示例
```
python run.py --algorithm c4.5 --dataset autos
python run.py --algorithm knn --dataset autos
python run.py --algorithm naivebayes --dataset autos
python run.py --algorithm cart --dataset autos
python run.py --algorithm kmeans --dataset autos
python run.py --algorithm svm --dataset autos
python run.py --algorithm adaboost --dataset autos
python run.py --algorithm randomforest --dataset autos
```
自定义实现
```
python run.py --algorithm custom_knn --dataset autos
python run.py --algorithm custom_naivebayes --dataset autos
python run.py --algorithm custom_randomforest --dataset autos
```
运行后，result文件夹将包含类似以下结构的文件：
```
result/
├── summary.csv
├── svm/
│   ├── svm_autos_20240520_153045.txt
│   ├── svm_autos_20240520_153045.json
│   ├── cross_val_accuracy_svm_autos_20250930_153045.png
│   └── ... (其他文件)
├── c4.5/
│   ├── c4.5_autos_20240520_153125.txt
│   ├── c4.5_autos_20240520_153125.json
│   ├── cross_val_accuracy_c4.5_autos_20250930_153125.png
│   └── ... (其他文件)
├── knn/
│   ├── knn_autos_20240520_153205.txt
│   ├── knn_autos_20240520_153205.json
│   ├── cross_val_accuracy_knn_autos_20250930_153205.png
│   └── ... (其他文件)
└── ... (其他算法文件夹)
```