; empty asm file

title I love asm

CALCULATE MACRO A, B, RESULT 
         MOV AX, A 
         SHL AX, 1 
         ADD AX, B 
         MOV RESULT, AX 
         ENDM 
FINSUM MACRO X, Y, SUM 
        IF X GT Y 
            CALCULATE Y, X, SUM
        ELSE 
             CALCULATE X, Y, SUM 
        ENDIF 
        ENDM

data segment
    x  dw  11H
data ends

code segment
    assume cs:code, ds:data
    main    proc
        ; assign the data segment base address to DS
        mov   ax, data
        mov   ds, ax
        
        FINSUM 1,2,x
        
        ; method 2: return to dos
        mov   ax, 4c00h
        int   21h
    main    endp
code ends
end main 