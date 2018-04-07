grammar trier;

program
   : (line ((';'|',') line)* (';'|',')?)?
   ;

line
   : expression
   ;

expression
   : word
   ;

call
   : word expression
   ;

array
   : '[' expression (',' expression)* ','? ']'
   | '[' ']'
   ;

word
   : WORD
   ;

WORD
   : [a-zA-Z_] [0-9a-zA-Z_]*
   ;

string
   : STRING
   ;

fragment ESC
   : '\\' (["\\/bfnrt] | UNICODE)
   ;

fragment UNICODE
   : 'u' HEX HEX HEX HEX
   ;

fragment HEX
   : [0-9a-fA-F]
   ;

number
   : NUMBER
   ;

NUMBER
   : INT ('.' [0-9] +)? EXP?
   ;

fragment INT
   : '0' | [1-9] [0-9]*
   ;

fragment EXP
   : [Ee] [+\-]? INT
   ;

fragment SEP
   : ';' | ','
   ;

WS
   : [ \t\n\r] + -> skip
   ;
