        segment.data
        num dd 100,50,55,23,32
        n dd 5
        swap dd 0
        segemtn.text
        global main
main    nop
lp1:    mov dword[swap],0
        xor edx,edx
        mov ecx,[n]
        dec ecx
        
lp2: cmp edx,ecx
     jnl exit
     mov eax,[num+edx*4]
     mov ebx,[num+4+edx*4]
     cmp eax,ebx
     jle no
     mov [num+4+edx*4],eax
     mov [num+ecx*4],ebx
     mov dword[swap],1
no: inc edx
    jmp lp2
    
exit: cmp dword[swap],1
        je lp1
done: nop
      ret
