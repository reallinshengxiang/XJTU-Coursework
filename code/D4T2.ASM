; empty asm file
title I love asm
data segment
    ID  db  '2223312202'
    BUFFER  db  10 dup (?)
    JM  db  7,5,9,1,3,6,8,0,2,4
data ends
code segment
    assume cs:code, ds:data
    main    proc
        ; assign the data segment base address to DS
        mov   ax, data
        mov   ds, ax
        mov   si, 0
        mov   cx, 10
        lea   bx, JM
input:  mov   ah, 1
        int   21h
        cmp   al,0dh
        jz    exit
        sub   al, 30h
        jb    input
        cmp   al, 9h
        ja    input
        xlat
        mov   BUFFER[si],al
        inc   si
        loop  input
exit:   mov   ax, 4c00h
        int   21h
    main    endp
code ends
end main 
