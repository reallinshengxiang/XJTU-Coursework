title I love asm
NAMELIST STRUC
    MAXLEN DB 100
    ACTLEN DB ?
    NAMEIN DB 100 DUP (?)
NAMELIST ENDS
data segment
    DISPDILE NAMELIST <>
data ends
code segment
    assume cs:code, ds:data
    main    proc
        ; assign the data segment base address to DS
        mov   ax, data
        mov   ds, ax
        lea   bx, DISPDILE.NAMEIN
        mov   cx, 0
input:        
        mov   ah, 1h
        int   21h
        mov   [bx], al       
        inc   cl
        mov   DISPDILE.ACTLEN, cl
        inc   bx
        cmp   cl,100
        je    exit
        jmp   input
exit:
        mov   ax, 4c00h
        int   21h
    main    endp
code ends
end main 