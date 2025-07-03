## 确保环境已配置    
确保系统中已经安装了`CMake`、`GCC`、`GTest`必要的编译工具和依赖库  
```bash
sudo apt-get update     
sudo apt-get install cmake g++ libgtest-dev   
```
## 构建 GTest 库      
libgtest-dev只提供了 `GTest` 的源代码，需要手动构建：  
```bash
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make   
sudo cp lib/*.a /usr/lib   
```
## 编译面向对象设计项目    
进入面向对象设计目录，创建一个构建目录，然后使用 `CMake` 和 `make` 进行编译： 
```bash 
cd Huawei-Software-Boot-Camp/面向对象设计
mkdir build
cd build
cmake ..
make
```
## 运行测试   
编译成功之后，可以运行生成的可执行文件来进行测试：   
```bash 
./test/oo_test
```
输出结果如下
```bash    
Running main() from /home/linshengxiang/Huawei-Software-Boot-Camp/面向对象设计/thirdparty/googletest/src/gtest_main.cc
[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from PersonTest
[ RUN      ] PersonTest.Case001
[       OK ] PersonTest.Case001 (0 ms)
[----------] 1 test from PersonTest (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (0 ms total)
[  PASSED  ] 1 test.
```