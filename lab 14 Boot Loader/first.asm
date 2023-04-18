[BITS 16];tell the assemblem that its a 16 bit code
[ORG 0x7C00];origin tell the assembler that where the code will be in the memeory after its been loaded
JMP $;infinite loop
TIMES 510 -($ - $$) db 0;fill the rest of sector with 0
DW 0xAA55;add boot signature at the end of bootloader

