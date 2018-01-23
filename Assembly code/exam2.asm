        segment     .data
x dq 1
y dq 2
z dq 3
result dq 0
        segment     .text
        global main
main:   mov rax,[z]
        imul rax
        mov r8,rax
        mov rcx,[x]
        mov rdx,[y]
        xor rax,rax
        call function
function:
        push rbp
        mov rbp,rsp
        push rcx
        push rdx
        mov rax,[rbp-8]
        mov rbx,[rbp-16]
        imul rax,rax
        imul rbx,rbx
        add rax,rbx
        add rax,r8
done:   mov [result],rax
        ret
        nop
        
