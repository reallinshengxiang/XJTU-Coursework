#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include<bits/stdc++.h>
// 定义MIPS指令类型
enum class InstructionType {
    LOAD, STORE, ADD, BEQZ, NOP, UNKNOWN
};

// 指令结构体
struct Instruction {
    InstructionType type;
    std::string raw;    // 原始指令字符串
    int rd;             // 目标寄存器
    int rs;             // 源寄存器1
    int rt;             // 源寄存器2/立即数
    int imm;            // 立即数偏移量
    int address;        // 内存地址
};

// 流水线寄存器
struct PipelineRegister {
    Instruction instruction;
    int pc;
    int result;
    bool stall;
    bool bubble;
};

// 模拟器核心类
class MIPSSimulator {
private:
    // 处理器状态
    std::vector<int> registers;     // 32个通用寄存器
    std::vector<int> memory;        // 内存
    int pc;                         // 程序计数器
    
    // 流水线寄存器
    PipelineRegister IF_ID, ID_EX, EX_MEM, MEM_WB;
    
    // 控制标志
    bool useForwarding;             // 是否使用定向路径
    bool running;                   // 模拟器运行状态
    bool singleStep;                // 单步执行模式
    int breakpoint;                 // 断点地址
    
    // 统计数据
    int cycleCount;                 // 总时钟周期
    int instructionCount;           // 执行指令数
    int stallCount;                 // 停顿周期数
    
    // 程序存储
    std::vector<Instruction> program;
    std::map<int, Instruction> instructionMemory;

public:
    MIPSSimulator(bool forwarding = true) 
        : registers(32, 0), memory(1024, 0), pc(0),
          useForwarding(forwarding), running(false),
          singleStep(false), breakpoint(-1),
          cycleCount(0), instructionCount(0), stallCount(0) {
        // 初始化流水线寄存器
        IF_ID = ID_EX = EX_MEM = MEM_WB = PipelineRegister();
    }
    
    // 加载程序
    void loadProgram(const std::string& filename);
    void loadProgramFromInput(const std::string& programText);
    
    // 模拟执行控制
    void run();
    void runToBreakpoint();
    void runToCompletion();
    void step();
    void reset();
    
    // 状态查看
    void printPipelineStatus() const;
    void printRegisterStatus() const;
    void printMemoryStatus() const;
    void printStatistics() const;
    
    // 流水线各阶段
    void instructionFetch();
    void instructionDecode();
    void execute();
    void memoryAccess();
    void writeBack();
    
    // 辅助函数
    Instruction parseInstruction(const std::string& line);
    void detectHazards();
    void forwardData();
    void handleStalls();
    void insertBubble();
};

// 指令解析实现
Instruction MIPSSimulator::parseInstruction(const std::string& line) {
    Instruction instr;
    instr.raw = line;
    // 简化的指令解析逻辑
    // 实际实现需要完整解析MIPS指令格式
    if (line.find("lw") != std::string::npos) {
        instr.type = InstructionType::LOAD;
        // 解析寄存器等操作数
    } else if (line.find("sw") != std::string::npos) {
        instr.type = InstructionType::STORE;
        // 解析寄存器等操作数
    } else if (line.find("add") != std::string::npos) {
        instr.type = InstructionType::ADD;
        // 解析寄存器等操作数
    } else if (line.find("beqz") != std::string::npos) {
        instr.type = InstructionType::BEQZ;
        // 解析寄存器等操作数
    } else {
        instr.type = InstructionType::UNKNOWN;
    }
    return instr;
}

// 加载程序文件
void MIPSSimulator::loadProgram(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("无法打开程序文件");
    }
    
    program.clear();
    instructionMemory.clear();
    std::string line;
    int address = 0;
    
    while (std::getline(file, line)) {
        Instruction instr = parseInstruction(line);
        program.push_back(instr);
        instructionMemory[address] = instr;
        address += 4;  // MIPS指令为4字节对齐
    }
}

// 从输入加载程序
void MIPSSimulator::loadProgramFromInput(const std::string& programText) {
    program.clear();
    instructionMemory.clear();
    
    std::istringstream iss(programText);
    std::string line;
    int address = 0;
    
    while (std::getline(iss, line)) {
        Instruction instr = parseInstruction(line);
        program.push_back(instr);
        instructionMemory[address] = instr;
        address += 4;
    }
}

// 单步执行
void MIPSSimulator::step() {
    // 流水线推进顺序: WB -> MEM -> EX -> ID -> IF
    writeBack();
    memoryAccess();
    execute();
    instructionDecode();
    instructionFetch();
    
    // 检测和处理冒险
    detectHazards();
    if (useForwarding) {
        forwardData();
    }
    handleStalls();
    
    cycleCount++;
}

// 指令取指阶段
void MIPSSimulator::instructionFetch() {
    if (IF_ID.stall) {
        return;  // 保持当前IF_ID内容
    }
    
    if (instructionMemory.find(pc) != instructionMemory.end()) {
        IF_ID.instruction = instructionMemory[pc];
        IF_ID.pc = pc;
        pc += 4;  // 默认下一条指令地址
    } else {
        // 无有效指令，插入NOP
        IF_ID.instruction.type = InstructionType::NOP;
    }
    
    IF_ID.bubble = false;
}

// 指令译码阶段
void MIPSSimulator::instructionDecode() {
    if (ID_EX.stall) {
        return;  // 保持当前ID_EX内容
    }
    
    if (IF_ID.bubble) {
        ID_EX.instruction.type = InstructionType::NOP;
        return;
    }
    
    ID_EX = IF_ID;  // 传递指令和PC
    
    // 实际实现中需要:
    // 1. 读取寄存器值
    // 2. 符号扩展立即数
    // 3. 控制信号生成
}

// 执行阶段
void MIPSSimulator::execute() {
    if (EX_MEM.stall) {
        return;
    }
    
    if (ID_EX.bubble) {
        EX_MEM.instruction.type = InstructionType::NOP;
        return;
    }
    
    EX_MEM = ID_EX;
    
    switch (EX_MEM.instruction.type) {
        case InstructionType::ADD:
            EX_MEM.result = registers[EX_MEM.instruction.rs] + registers[EX_MEM.instruction.rt];
            break;
        case InstructionType::BEQZ:
            if (registers[EX_MEM.instruction.rs] == 0) {
                pc = EX_MEM.pc + (EX_MEM.instruction.imm << 2);  // 分支偏移计算
                // 需要清空流水线
            }
            break;
        // 其他指令处理...
    }
}

// 内存访问阶段
void MIPSSimulator::memoryAccess() {
    if (MEM_WB.stall) {
        return;
    }
    
    MEM_WB = EX_MEM;
    
    switch (MEM_WB.instruction.type) {
        case InstructionType::LOAD:
            MEM_WB.result = memory[MEM_WB.instruction.address / 4];
            break;
        case InstructionType::STORE:
            memory[MEM_WB.instruction.address / 4] = registers[MEM_WB.instruction.rt];
            break;
        // 其他指令处理...
    }
}

// 写回阶段
void MIPSSimulator::writeBack() {
    switch (MEM_WB.instruction.type) {
        case InstructionType::ADD:
        case InstructionType::LOAD:
            registers[MEM_WB.instruction.rd] = MEM_WB.result;
            instructionCount++;
            break;
        // 其他指令处理...
    }
}

// 冒险检测
void MIPSSimulator::detectHazards() {
    // 检测数据冒险
    // 检测控制冒险
    // 检测结构冒险
}

// 数据前推
void MIPSSimulator::forwardData() {
    // 实现数据前推逻辑
}

// 处理停顿
void MIPSSimulator::handleStalls() {
    // 根据需要设置stall标志
}

// 打印流水线状态
void MIPSSimulator::printPipelineStatus() const {
    std::cout << "=== 流水线状态 ===" << std::endl;
    std::cout << "IF: " << IF_ID.instruction.raw << std::endl;
    std::cout << "ID: " << ID_EX.instruction.raw << std::endl;
    std::cout << "EX: " << EX_MEM.instruction.raw << std::endl;
    std::cout << "MEM: " << MEM_WB.instruction.raw << std::endl;
    std::cout << "WB: " << "已完成" << std::endl;
}

// 主函数 - 模拟交互界面
int main() {
    MIPSSimulator simulator(true);  // 启用数据前推
    
    std::cout << "MIPS 5段流水线模拟器" << std::endl;
    std::cout << "1. 从文件加载程序" << std::endl;
    std::cout << "2. 直接输入程序" << std::endl;
    std::cout << "选择操作: ";
    
    int choice;
    std::cin >> choice;
    
    if (choice == 1) {
        std::string filename;
        std::cout << "输入程序文件名: ";
        std::cin >> filename;
        simulator.loadProgram(filename);
    } else {
        std::cout << "输入程序(空行结束):" << std::endl;
        std::string programText, line;
        while (std::getline(std::cin, line) && !line.empty()) {
            programText += line + "\n";
        }
        simulator.loadProgramFromInput(programText);
    }
    
    // 模拟器交互循环
    while (true) {
        std::cout << "\n选项:\n";
        std::cout << "1. 单步执行\n";
        std::cout << "2. 执行到断点\n";
        std::cout << "3. 执行到结束\n";
        std::cout << "4. 查看流水线状态\n";
        std::cout << "5. 查看寄存器状态\n";
        std::cout << "6. 查看内存状态\n";
        std::cout << "7. 查看统计信息\n";
        std::cout << "8. 退出\n";
        std::cout << "选择: ";
        
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                simulator.step();
                simulator.printPipelineStatus();
                break;
            case 2:
                // 设置断点并执行
                break;
            case 3:
                // 执行到程序结束
                break;
            case 4:
                simulator.printPipelineStatus();
                break;
            case 5:
                simulator.printRegisterStatus();
                break;
            case 6:
                simulator.printMemoryStatus();
                break;
            case 7:
                simulator.printStatistics();
                break;
            case 8:
                return 0;
            default:
                std::cout << "无效选项\n";
        }
    }
    
    return 0;
}
