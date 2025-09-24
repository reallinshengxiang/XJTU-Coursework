; empty asm file

title I love asm

data segment
    
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
        sub   al, 20h
        mov   dl, al
        mov   ah, 2h
        int   21h

exit:   mov   ax, 4c00h
        int   21h
    main    endp
code ends
end main 