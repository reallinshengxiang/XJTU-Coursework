; empty asm file

title I love asm

data segment
    stu db "2223312202"
    x db 22H
    y db 23H
    z db ?
    w db 27H
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
        mov al,w
        sub al,x
        imul y  
        mov bx,5
        idiv bl
        shr ax,1
        mov z,al
        ; ^ ---------------------------- ^
		; |          The END             |
        
        ; method 2: return to dos
        mov   ax, 4c00h
        int   21h
    main    endp
code ends
end main 