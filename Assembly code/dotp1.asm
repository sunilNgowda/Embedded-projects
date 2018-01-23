        segment.data
        opa dd 1,2,3,4,5
        opb dd 1,2,3,4,5
        result dd 0
        
        segment.text
        global main
 main:
        xor ecx,ecx
        xor edx,edx
       
loop1:
        mov eax,[opa + ecx * 4]
        mov ebx,[opb + edx * 4]
        imul ebx
        add [result],eax
        inc ecx
        inc edx
        cmp ecx,5
        jne loop1
        
done:  mov eax,[result]
        nop

