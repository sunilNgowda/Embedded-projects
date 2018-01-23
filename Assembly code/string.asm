        
        segment .data
msg1 db "the world is amazing",0
msg1len equ $-msg1
msg2 times 100 db 0
find db "amazing",0
strlenfind equ $-find
replace db "incredible",0
strlenreplace equ $-replace
           segment .text
           global main
main:

        xor r8, r8 
        xor r9, r9
dolp1:  mov al, [msg1+r8] 
        mov ah, [find] 

        cmp al, ah 
        jne elselp2 
        jmp wordmatch 

elselp2:
        mov [msg2+r9], al 
        inc r8 
        inc r9 
while:
        cmp byte [msg1 + r8], 0 
        jne dolp1 
done:
        nop
        ret
wordmatch:
        mov rcx, strlenfind
        lea rsi, [msg1]
        add rsi, r8 
        lea rdi, [find]
        rep cmpsb 
        cmp rcx, 0
        jne elselp2 

        mov rcx, strlenreplace
        lea rsi, [replace]
        lea rdi, [msg2]
        add rdi, r9 
        rep movsb 
        add r8, strlenfind - 1
        add r9, strlenreplace - 1
        jmp while
