; empty asm file

title I love asm

data segment
    M dw 22H,23H,31H,22H,02H
    len equ ($-M)/2
    maxx dw 0
    maxi dw ?
data ends
code segment
    assume cs:code, ds:data
    main    proc
        ; assign the data segment base address to DS
        mov   ax, data
        mov   ds, ax
        mov   cx,len-1
        lea   di,M
lop:    mov   bx,[di]
        cmp   bx,0
        jnc   comp
        neg   bx
comp:   cmp   maxx,bx
        jae   jump
        mov   maxx,bx
        mov   maxi,di
jump:   add   di,2
        cmp   cx,0
        je    l1
        loop  lop
l1:     mov   ax, 4c00h
        int   21h
    main    endp
code ends
end main 


