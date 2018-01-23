        segment.data
        msg db "hello world"
        src db "world"
        dest db "human"
        len equ $-msg
        
        
        
        segment.text
        global main
main:
        xor rcx,rcx
        xor rdx,rdx
        xor r8,r8

one:    inc r8
        cmp r8,len 
        je done
        movzx rax,byte[msg+rcx*1]
        movzx rbx,byte[src+rdx*1]
        cmp rax,rbx
        je two
        inc rcx
        jmp one
two:    mov r9,[dest+rdx*1]
        mov [msg+rcx*1],r9
        inc rcx
        inc rdx
        jmp one
done:   nop
        ret
        
        
