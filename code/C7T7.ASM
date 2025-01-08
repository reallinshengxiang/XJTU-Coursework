
cnt  macro a,b
     a&b  dw  ?
     endm

inc1 macro a,b
     cnt  a, % b
     b=b+1
     endm


data segment
    
data ends

code segment
    assume cs:code, ds:data
    main    proc
        ; assign the data segment base address to DS
        mov   ax, data
        mov   ds, ax
        
        
        c=0
        inc1  data,c
        inc1  data,c



        mov   ax, 4c00h
        int   21h
    main    endp
code ends
end main 