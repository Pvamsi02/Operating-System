[BITS 16]
[ORG 0x7C00]
MOV AL,86
CALL Printcharacter
MOV AL,65
CALL Printcharacter
MOV AL,77
CALL Printcharacter
MOV AL,83
CALL Printcharacter
MOV AL,73
CALL Printcharacter
JMP $

Printcharacter: ;Procedure to print character on screen
MOV AH,0x0E	;Tell the BIOS that we need to print one character on screen
MOV BH,0x00	;page no
MOV BL,0x07	;tell attribute 0x07 is lightgrey font on black background
INT 0x10	;call vedio interrupt
RET		;return to calling procedure

TIMES 510 -($ -$$) db 0
DW 0xAA55
