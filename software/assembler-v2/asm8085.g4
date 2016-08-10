// based on asm6502 grammar by Tom Everett, https://github.com/antlr/grammars-v4/blob/master/asm6502/asm6502.g4

grammar asm8085;

prog
   : (line? EOL) +
   ;

line
   : comment
   | instruction
   | label
   ;

instruction
   : label? operation comment?
   ;

label
   : LABEL ':'
   ;

comment
   : COMMENT
   ;

operation
   : ('CALL' immediate) # Call
   | 'HLT' # Hlt
   | ('JMP' immediate) # Jmp
   | ('LXI' REGISTER ',' immediate) # Lxi
   | ('MOV' REGISTER ',' REGISTER) # Mov
   | ('MVI' REGISTER ',' immediate) # Mvi
   | 'NOP' # Nop
   | 'SIM' # Sim
   ;


REGISTER
   : 'A' | 'B' | 'C' | 'D' | 'H' | 'L' | 'M' | 'SP'
   ;

labeloperand
   : LABEL
   ;

locationcounteroperand
   : '$'
   ;

immediate
   : hex
   | oct
   | bin
   | dec
   | chr
   | labeloperand
   | locationcounteroperand
   ;

hex
   : HEX
   ;

HEX
   : [0-9A-F]+ 'H'
   ;

oct
   : OCT
   ;

OCT
   : [0-7]+ 'Q'
   ;

bin
   : BIN
   ;

BIN
   : [01]+ 'B'
   ;

dec
   : DEC
   ;

DEC
   : ([0-9]+ 'D')
   | [0-9]+
   ;

chr
   : CHR
   ;

CHR
   : '\'' . '\''
   ;

EOL
   : '\r'? '\n'
   ;

LABEL
   : [A-Z] [A-Z0-9]*
   ;

COMMENT
   : ';' ~ [\r\n]* -> skip
   ;

WS
   : [ \t] -> skip
   ;
