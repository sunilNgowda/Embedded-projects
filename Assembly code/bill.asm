segmant.data
	name times 65 db 0
	kwh dq 0
	cost dq 0
	cost_dollars dq 0
	cost_pennies dq 0
	n dq 5
	fmt1: db '%s %lld ',10/0
	msg1: db 'customer: %s \t \t --kwh=%ud--',0
	msg2: db 'bill =$%lld.%02lld\n',0
	
segment.text
	global main
	extern printf
	extern scanf
	
main:
		xor r15,r15
		
loop1:
		cmp r15,[n]
		jge done
		lea rcx,[fmt1]
		lea rdx,[name]
		lea r8,[kwh]
		call scanf
		lea rcx,[msg1]
		lea rdx,[name]
		lea r8,[kwh]
		call printf
		mov qword[cost],2000
		cmp qword[kwh],1000
		jng skip1
		mov rax,[kwh]
		sub rax,1000
		add rax,[cost]
		mov [cost],rax
skip1:
		mov rdi,[cost]
		call dollars
		mov [cost-dollars],rax
		mov rdi,[cost]
		call pennies
		mov [cost_pennies],rax
		lea rcx,[msg2]
		mov rdx,[cost-dollars]
		mov r8,[cost_pennies]
		xor rax,rax
		call printf
done:
		nop
		ret
dollars:
		mov rax,rdi
		mov rbx,100
		div rbx
		ret
pennies:
		mov rax,rdi
		mov rbx,100
		div rbx
		mov rax,rdx
		ret
		
