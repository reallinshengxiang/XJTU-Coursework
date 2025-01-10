; empty asm file

title I love asm

data segment
    ID db '2223312202'
    array db 76,69,84,90,73,88,99,63,100,80
    s6 db 0
    s7 db 0
    s8 db 0
    s9 db 0
    s10 db 0
data ends

code segment
    assume cs:code, ds:data
    main    proc far
        ; assign the data segment base address to DS
        mov   ax, data
        mov   ds, ax
        mov   cx,10
        call  calc
        mov   ax, 4c00h
        int   21h
    main    endp
    calc     proc  near
        mov  si, 0
  lop:  mov  ax, 0
        mov  al, array[si]
        mov  bx, 10
        div  bl
        mov  bl, al
        sub  bx, 6
        inc  s6[bx]
        add  si, 1
        loop lop
        ret
    calc    endp
code ends
end main 