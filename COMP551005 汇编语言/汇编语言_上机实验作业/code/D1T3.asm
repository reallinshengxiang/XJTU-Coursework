; empty asm file

title I love asm

data segment
    X  db  2H
data ends

code segment
   assume cs:code, ds:data
    main    proc
        ; assign the data segment base address to DS
        mov   ax, data
        mov   ds, ax
        
        ; TODO ...
		; | add your code between arrows |
		; v ---------------------------- v
        mov bl,20
        mov cl,10
        mov al,bl
        cbw
        idiv cl
        imul X
        mov dx,ax
        
        ; ^ ---------------------------- ^
		; |          The END             |
        
        ; method 2: return to dos
        mov   ax, 4c00h
        int   21h
    main    endp
code ends
end main 