grammar Calamity;

program
   : (line ((';'|',') line)* (';'|',')?)?
   ;

line
   : assignment
   | pair
   | expression
   ;

comparable
   : string
   | word
   | group
   | array
   | call
   | number
   | member
   | product
   | addedList
   | function
   ;

logicable
   : comparison
   | negation
   | word
   | group
   | call
   | 'true'
   | 'false'
   ;

addable
   : group
   | call
   | number
   | word
   | product
   | string
   | negative
   ;

mutliplyable
   : group
   | call
   | number
   | word
   ;

evaluable
   : string
   | word
   | array
   | group
   | function
   ;

expression
   : string
   | word
   | group
   | array
   | call
   | number
   | member
   | product
   | addedList
   | function
   | negative
   | comparison
   | logicable
   | conjunction
   | negation
   ;

function
   : '{' program '}'
   ;

group
   : '(' program ')'
   ;

comparison
   : comparable ('<' | '>' | '<=' | '>=' | '==' | '!=') comparable
   ;

negation
   : 'not' logicable
   ;

conjunction
   : logicable (('and' | 'or') logicable)+
   ;

negative
   : '-' addable
   ;

addedList
   : addable (('+' | '-') addable)+
   ;

product
   : mutliplyable (('*' | '/' | '%') mutliplyable)+
   ;

call
   : evaluable expression+
   ;

pair
   : expression ':' expression
   | '*' ':' expression
   ;

reference
   : word
   | call
   ;

assignment
   : reference ('='|'+='|'-='|'*='|'/=') expression
   ;

array
   : '[' expression (',' expression)* ','? ']'
   | '[' ']'
   ;

member
   : MEMBER
   ;

MEMBER
   : '.' WORD
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

STRING
   : '"' (ESC | ~ ["\\])* '"'
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
