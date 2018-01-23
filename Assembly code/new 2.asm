        segment.data
        c dq 25
        a dq 1,2,3,4
        b dq 1,2,3,4
        
        segment.text
        global main
main:   xor rcx,rcx
        xor r8,r8
        xor r9,r9
        xor r10,r10
        mov r10,[c]
        xor r11,r11
        mov r8,[a]
        mov r9,[b]
        

l1: 
        mov rax,r8
        inc rcx
        cmp rcx,5
        je done
        jmp l2
        
        
l2:     imul rax
        mov rdx,rax
        mov rax,r9
        imul rax
        add  rdx,rax
        cmp r10,rdx
        je done
        mov r9,[b+rcx*8]
        
        inc r11
        cmp r11,5
        jne l2
        mov r8,[a+rcx*8]
        jmp l1
        
done:nop
        
        
        
        
        
        
