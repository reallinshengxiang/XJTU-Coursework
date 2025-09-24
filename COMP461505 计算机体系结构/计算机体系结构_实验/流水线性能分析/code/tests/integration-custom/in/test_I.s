addi t0, x0, 5        #t0 = x0 + 5
addi t1, x1, 6        #t1 = x1 + 6
slli t2, t0, 2        #t2 = t0 << 2
slti a0, t1, 42       #a0 = (t1 < 42)
xori s0, t0, 7        #s0 = t0 ^ 7
srli t2, t0, 1        #t2 = t0 >> 1
addi s1, x0, -3       #s1 = x0 + (-3)
srai s1, s1, 2        #s1 = s1 >> 2（算术右移）
ori  s0, t0, 3        #s0 = t0 | 3
andi t1, t0, 6        #t1 = t0 & 6
addi x0, x0, 0        #无意义指令，输入格式需求
addi x0, x0, 0        #无意义指令，输入格式需求