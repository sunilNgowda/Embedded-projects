segment .data
    a dq 0
    b dq 0
    result dq 0
    scanf_format: db  ' %ld ',0
segment .text
    global main
    extern scanf
main:
        push rbp
        mov rbp,rsp
        sub rsp,32
        lea rcx, [scanf_format] 
        lea rdx, [a]
        call scanf
        mov rax,[a]
        push rbp
        mov rbp,rsp
        sub rsp,32
        lea rcx, [scanf_format] 
        lea rdx, [b]
        call scanf
        mov rbx,[b]
one:
        cmp rbx,0
        je zero
        
two:    idiv rbx
        cmp rdx,0
        je gcd
        mov rax,rbx
        mov rbx,rdx
        jmp two
zero:
        mov [result],rax
        jmp done
        
gcd:
        mov [result],rax
done:
        nop
        
        

