[BITS 16]
[ORG 0x7C00]
MOV AL,50
CALL Printcharacter
MOV AL,49
CALL Printcharacter
MOV AL,66
CALL Printcharacter
MOV AL,67
CALL Printcharacter
MOV AL,69
CALL Printcharacter

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
hello: db "5095",0
JMP $

Printcharacter: ;Procedure to print character on screen
MOV AH,0x0E	;Tell the BIOS that we need to print one character on screen
MOV BH,0x00	;page no
MOV BL,0x07	;tell attribute 0x07 is lightgrey font on black background
INT 0x10	;call vedio interrupt
RET ;return to calling procedure

TIMES 510 -($ -$$) db 0
DW 0xAA55




