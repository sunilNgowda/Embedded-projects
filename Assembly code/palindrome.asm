        segment.data
m1 db "refer"
n dq 4


        segment.text
        global main
main:
        xor rcx,rcx
        xor rdx,rdx
        mov rdx,[n]
lp1: 
        movzx rax,byte[m1+rcx]
        movzx rbx,byte[m1+rdx]
        cmp rax ,rbx 
        jne done
        inc rcx 
       
        cmp rcx,5
        je done
        dec dx 
        jmp lp1
done:
        nop
        
