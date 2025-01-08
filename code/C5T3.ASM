; empty asm file

title I love asm

data segment
    store  db  4 dup(?)
data ends

code segment
    assume cs:code, ds:data
    main    proc
        ; assign the data segment base address to DS
        mov   ax, data
        mov   ds, ax
        
        mov   cl, 4h
        mov   ch, 4h
        mov   ax, 0f234h
        lea   bx, store
lop:    mov   dx, ax
        and   dx, 0fh
        mov   [bx], dx
        shr   ax, cl
        inc   bx
        dec   ch
        jnz   lop
        mov   al, store
        mov   bl, store+1
        mov   cl, store+2
        mov   dl, store+3


        mov   ax, 4c00h
        int   21h
    main    endp
code ends
end main 