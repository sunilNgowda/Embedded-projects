                segment .data
a               dq 0
b               dq 0 
gcd_value       dq 0


msg1      db "Enter Number:",0
fmt1      db "%lld",0
msg2      db "gcd( %lld, %lld ) = %lld",10,0

                segment .text
                global main
                extern printf
                extern scanf


main: 
         lea rcx, [msg1]
         ;xor rax, rax
         call printf

         lea rcx, [fmt1]
         lea rdx, [a]
         ;xor rax, rax
         call scanf

         lea rcx, [msg1]
         ;xor rax, rax
         call printf

         lea rcx, [fmt1]
         lea rdx, [b]
         ;xor rax, rax
         call scanf

;gcd(a,b)
;rdi = a
;rsi = b

         mov rcx, [a]
         mov rdx, [b]
         ;xor rax, rax
         call gcd
         mov [gcd_value], rax

         lea rcx, [msg2]
         ;mov rcx,[a]
         mov rdx, [a]
         ;mov rdx,[b]
         mov r8, [b]
         mov r9, [gcd_value]
         ;mov r8,[gcd_value]
         ;xor rax, rax
         call printf
         
done:
         ;xor rax, rax
         ret

gcd:
         push rbp
         mov rbp, rsp

;rdi = a
;rsi = b
         push rcx
         push rdx

         mov r10, [rbp - 16]        ;b
         cmp r10, 0         ;b = 0?
         jne else 
         mov rax, [rbp-8]               ;return a

done1:
         mov rsp, rbp
         pop rbp
         ret


else:
         xor rdx, rdx                   ;rdx=0
         mov rax, [rbp-8]       ;rax=a
         mov rbx, [rbp-16]              ;rbx=b
         div rbx                        ;a/b remainder in rdx

         mov rcx, [rbp-16]              ;gcd(b, a mod b)
         mov rdx, rdx
         ;xor rax, rax
         call gcd
         jmp done1 
