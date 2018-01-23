segment .data
        a times 500 dq 0
        b times 500 dq 0
    
segment .text
        global main
    
main:
        mov r8,2
        mov r9,1
        mov r10,1
        xor rcx,rcx
        
one:    inc r8
        cmp r8,500
        je done
        imul r8,r8
        
two:
        inc r9
        cmp r9,500
        je done
        mov rax,r9
        imul r9,r9
        
three:
        cmp r10,500 
        je done
        mov rbx,r10
        imul r10,r10
        add r10,r9
        cmp r10,r8
        je equal
        inc r10
        jmp three
        
equal:
        mov [a+rcx*8],rax
        mov [b+rcx*8],rbx
        inc rcx
        jmp one
        
done:   nop
        ret
        
        
        
        
        
