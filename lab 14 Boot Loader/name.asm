bits 16
org 0x7c00
boot:
mov si,hello
mov ah,0x0e
.loop:
lodsb
or al,al
jz halt
int 0x10
jmp .loop
halt:
cli
hlt
hello: db "21BCE5095 Chillara V L N S Pavana Vamsi",0
times 510 -($ -$$) db 0
dw 0xaa55
