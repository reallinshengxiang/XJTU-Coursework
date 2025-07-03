## class01  
```bash
cd class01  
g++ -g -o main.exe main.c    
./main.exe  
```
运行结果
```bash
call main
```
## class02  
```bash
cd class02   
g++ -o main.exe main.c func1.c  
./main.exe  
```
运行结果
```bash
call main.
call func1.   
```
## class03  
```bash
cd class03   
g++ -o main.exe main.c func/func.c -I.
./main.exe
```
运行结果
```bash
call main.
call func.
```
## class04  
```bash
cd class04   
g++ -x c -I. -I./func1 -I./func2 -c main.c -o main.o   
g++ -x c -I. -I./func1 -I./func2 -c func1/func1.c -o func1.o   
g++ -x c -I. -I./func1 -I./func2 -c func2/func2.c -o func2.o    
g++ -x c -I. -I./func1 -I./func2 -c func3.c -o func3.o    
g++ main.o func1.o func2.o func3.o -o program
```
运行结果
```bash
call main.
call func1.
call func2.
call func3.
```
## class05   
```bash
cd class05     
gcc -I./inc -I./comm src/func1.c src/main.c -o program   
./program  
```
运行结果
```bash
call main.
call func1.
```