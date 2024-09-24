; empty asm file

title I love asm

data segment
    inarea  db  80
    actlen  db  ?
    buffer  db  80 dup(?)
data ends

code segment
    assume cs:code, ds:data
    main    proc
        ; assign the data segment base address to DS
        mov   ax, data
        mov   ds, ax
        
input:  lea   dx, inarea
        mov   ah, 0ah
        int   21h
        cmp   actlen, 0
        je    exit
        mov   bx, 0
        mov   ch, 0
        mov   cl, actlen
print:  mov   ah, 5
        mov   dl, buffer[bx]
        int   21h
        inc   bx
        loop  print
        mov   ah, 5
        mov   dl, 0ah
        int   21h
        mov   dl, 0dh
        int   21h
        jmp   input

 exit:  mov   ax, 4c00h
        int   21h
    main    endp
code ends
end main 