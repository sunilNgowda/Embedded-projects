        segment .dat
        a dq 0
        segment .text
        
        global main
        
main: mov rax,5
      mov [a],rax
      nop
