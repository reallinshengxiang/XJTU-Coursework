title I love asm
data segment
    ID db '2223312202'
    NUM  dw  0
data ends
code segment
    assume cs:code, ds:data
    main    proc      
    mov     ax, data
    mov     ds, ax  
    mov     al, 1ch
    mov     ah, 35h
    int     21h
    push    es
    push    bx
    push    ds
    mov     ax, seg COUNT
    mov     ds,ax
    mov     dx, offset COUNT
    mov     al, 1ch
    mov     ah, 25h
    int     21h
    pop     ds
InputLoop:
    mov   ah, 1h
    int   21h
    sti
    cmp   al, 'Q'   
    je    ExitProgram
    jmp   InputLoop
    pop    dx
    pop    ds
    mov    al,  1ch
    mov    ah,  25h
    int    21h
    ret
ExitProgram:
        mov   dl, 10
        mov   ah, 2
        int   21h
        mov   bx, NUM
        mov   cx, 16     
        call  BIN_HEX
        mov   dl, 'h'
        mov   ah, 2
        int   21h
        mov   ax,4c00h
        int   21h
BIN_HEX PROC NEAR
       mov    ch, 4
ROTATE:mov    cl, 4
       rol    bx, cl
       mov    al, bl
       and    al, 0fh
       add    al, 30h
       cmp    al, 3ah
       jl     DISPLAY
       add    al, 7h
DISPLAY:mov   dl, al
        mov   ah, 2
        int   21h
        dec   ch
        jne   ROTATE
        ret
BIN_HEX ENDP   
    main endp
COUNT proc
    add NUM,1       
    iret        
COUNT endp
code ends
end main