; empty asm file

wages  macro  rate,hour,wag
       mov   al, hour
       mov   bl, rate
       mul   bl
       mov   wag, ax
       mov   al, hour
       mov   ah, 0
       mov   bl, 10
       div   bl
       mov   bl, 3
       mul   bl
       add   wag, ax
       endm

data segmentt
    X  db  11
    sum  dw ?
data ends

code segment
    assume cs:code, ds:data
    main    proc
        ; assign the data segment base address to DS
        mov   ax, data
        mov   ds, ax
        
        wages x,42,sum

        mov   ax, 4c00h
        int   21h
    main    endp
code ends
end main 