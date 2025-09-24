; empty asm file

title I love asm

data segment
    string db '2223312202134536743523433768585752527327437'
    len equ ($-string)
    count  db 10 dup(?)
    maxx db ?
    maxi db ?
    number db 16 dup(?)
data ends
code segment
    assume cs:code, ds:data
    main    proc
        ; assign the data segment base address to DS
        mov   ax, data
        mov   ds, ax
        lea   di, byte ptr string
lop:    mov   bx, [di]
        sub   bx, 30h
        xor   bh, bh
        add   count[bx],1
        mov   al, count[bx]
        cmp   maxx, al
        ja    l1
        mov   maxx, al
        mov   maxi, bl
l1:     add   di, 1
        cmp   di, len
        je    print
        loop  lop    
print: 
        add   maxi, 48
        mov   ah, 2h
        mov   dl, maxi
        int   21h
        mov   ah, 2h
        mov   dl, 44
        int   21h 
l2:     mov   al, maxx
        mov   ah, 0
        xor   dx, dx
        mov   bx, 0
        xor   cx, cx
        mov   bx, 10
div_next: 
        div   bx
        push  dx
        xor   dx, dx
        inc   cx
        cmp   ax, 0
        jz    display_begin
        jmp   div_next
display_begin:
        pop   dx
        add   dl, 48
        mov   ah,  2
        int   21h
        loop display_begin
        mov   ax, 4c00h
        int   21h
    main    endp
code ends
end main 

