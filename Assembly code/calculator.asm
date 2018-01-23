                segment .data
                


op              dq 0



operandA        dq 10


operandB        dq 5


operandresult_h dq 0



operandresult_l dq 0
    
                

segment .text
               
 
global main
                


main:
           
 
mov rax,[operandA]
           
 
mov rbx,[operandB]
            
                

mov rcx,[op]
                 

cmp rcx,0
                 

JZ plus
             
                
               
                

cmp rcx,1
                

JE subtract
                
                
                

cmp rcx,2
                

JE multiply
                
                
                

cmp rcx,3
                

JE division
   
   

plus:        
                

add rax,rbx
               
 
mov [operandresult_l],rax
                

jmp exit
                
                
  

subtract:
                

sub rax,rbx
               
 
mov [operandresult_l],rax
               
 
jmp exit
 

multiply:
                
                
 
imul rbx
                 

mov [operandresult_l],rax
                
 
mov [operandresult_h],rdx
                 

jmp exit
 

division:      
              
  
cqo 
                

idiv rbx
                

mov [operandresult_l],rax
                

mov [operandresult_h],rdx
                

jmp exit                 
 

exit: 
                nop
                          
