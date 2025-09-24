; empty asm file
title I love asm
data segment
    ID  db  '2223312202'
    X   db  '12202'
    ;X   db  '2223312202'
    len equ $-X
data ends
code segment
    assume cs:code, ds:data
    main    proc
        ; assign the data segment base address to DS
        mov   ax, data
        mov   ds, ax
        if    len gt 5
            rept 6
               add  ax, ax
            endm
        else  
            rept len
               add  ax, ax
            endm
        endif
        mov   ax, 4c00h
        int   21h
    main    endp
code ends
end main 
