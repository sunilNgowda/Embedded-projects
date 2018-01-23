        segment  .data
a dw 10
b dw 5
c dw 7
add1 dw 0
add2 dw 0
sub1 dw 0
sub2 dw 0
        segment   .text
        global main
main:   
        mov ax,[a]
        mov bx,[b]
        mov cx,[c]
        add ax,bx
        mov [add1],ax
        mov ax,[a]
        sub ax,bx
        mov [sub1],ax
        mov ax,[a]
        add ax,cx
        mov [add2],ax
        mov ax,[a]
        sub ax,cx
        mov [sub2],ax
