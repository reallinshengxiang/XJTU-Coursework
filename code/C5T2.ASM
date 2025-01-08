; empty asm file

title I love asm

data segment
    X  db  1h
data ends

code segment
    assume cs:code, ds:data
    main    proc
        ; assign the data segment base address to DS
        mov   ax, data
        mov   ds, ax
        
        mov   ah, 1h
        int   21h
        cmp   al, 'a'
        jb    exit
        cmp   al, 'z'
        ja    exit
        mov   ah, 2h
        sub   al, 1
        mov   dl, al
        int   21h
        inc   dl
        int   21h
        inc   dl
        int   21h



 exit:  mov   ax, 4c00h
        int   21h
    main    endp
code ends
end main 