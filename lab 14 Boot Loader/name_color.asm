[bits 16]
[org 7c00h]
jmp main
main:
xor ax,ax ;ds=0
mov ds,ax
cld ;df=0 because our lodsb requires it
mov ax,0012h
int 10h
mov si,string
mov bl,5 ;red
call printstr
jmp $
printstr:
mov bh,0 ;display page
print:
lodsb
cmp al,0
je done
mov ah,0Eh ;BIOS teltype
int 10h
jmp print
done:
ret
string db "21BCE5095 Chillara V L N S Pavana Vamsi",13,10,0
times 510 -($ -$$) db 0
dw 0AA55h
