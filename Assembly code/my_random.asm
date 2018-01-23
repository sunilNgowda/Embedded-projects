              segment .data

N          dq 10
msg1       db "A1[%lld] = %lld",10,0


;A1         times 10 dq 0


              segment .bss

A1            resq 10

 
              segment .text
              global main
              extern rand
              extern srand
              extern printf
              extern exit
main:

;seed srand
              mov rdi, 7
              xor rax, rax
;              call srand

;get N random numbers into array A1

              xor r15, r15      ;i = 0

lp10:          cmp r15, [N]              ;i<N
              jge done1

              xor rax, rax
              call rand

              mov [A1+r15*8], rax

              inc r15
              jmp lp10

done1:

;print array
             lea rdi, [A1]
             mov rsi, [N]
             call printarray

             xor rax, rax
             call exit


;function printarray(array,N)

printarray: 
             push rbp
             mov rbp,rsp

             push rdi       ;address of A1
             push rsi           ;N

             xor r15, r15
lp1:         cmp r15, [rbp-16]   ;i<N
             jge done11

             lea rdi, [msg1]
             mov rsi, r15
             mov rbx, [rbp-8]     ;address of A1
             mov rdx, [rbx + r15*8] ;A1[i]
             xor rax, rax
             call printf

             inc r15
             jmp lp1

done11:
             mov rsp, rbp
             pop rbp
             xor rax, rax
             ret
























