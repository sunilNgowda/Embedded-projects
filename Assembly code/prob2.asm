        segment     .data
a dq 10
b dq 5
msg db "sum=%lld",10,0
result dq 0
        segment     .text
        global main
        extern printf
main:   mov rcx,[a]
        mov rdx,[b]
        xor rax,rax
        call sum
        jmp done
sum:    push rbp
        mov rbp,rsp
        push rcx
        push rdx
        mov rax,rdx
        mov rbx,rcx
        imul rax,2
        add rax,rbx
        mov r15,rax
        mov rcx,[b]
        mov rdx,[a]
        call function
function:
        push rbp
        mov rbp,rsp
        push rcx
        push rdx
        mov r8,[rbp-8]
        mov r9,[rbp-16]
        mov rax,r9
loop1:
        cmp r9,r8
        je done1
        inc r9
        add rax,r9
        jmp loop1
done1:  
        pop rdx
        pop rcx
        pop rbp
        ret
done:   add rax,r15
        mov [result],rax
        lea rcx,[msg]
        mov rdx,[result]
        call printf
        ret
        nop

