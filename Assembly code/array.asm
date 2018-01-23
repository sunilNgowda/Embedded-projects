        segment .data
        a times 20 dq 0
        b dq 0
        c dq 20
    
        segment  .bss
        array resq 20
    
        segment .text
        global main
        extern rand
    
main: 
        xor r10,r10
    
loop1:

        push rbp
        mov rbp,rsp
        call rand
        mov [array+r10*8],rax
        inc r10
        cmp r10,[c]
        jle loop1
        xor r11,r11
    
bubble_sort:
        cmp r11,[c]
        jnl exit
        mov rax,[array+r11*8]
        mov rbx,[array+8+r11*8]
        cmp rax,rbx
        jle no
        mov [a+8+r11*8],rax
        mov [a+r11*8],rbx
        mov dword[b],1

no:
        inc r11
        jmp bubble_sort
exit:
        cmp dword[b],1
        je loop1
done:
        nop
        ret
    
