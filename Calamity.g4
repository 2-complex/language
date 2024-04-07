grammar Calamity;

program
   : (line ((';'|',') line)* (';'|',')?)?
   ;

line
   : assignment
   | pair
   | expression
   | defaultPair
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
   | impart
   ;

logicable
   : comparison
   | negation
   | word
   | group
   | call
   | boolean
   ;

boolean
   : 'true'
   | 'false'
   ;

addable
   : group
   | call
   | number
   | array
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
   | impart
   ;

expression
   : group
   | word
   | string
   | member
   | number
   | array
   | function
   | impart
   | product
   | negative
   | addedList
   | comparison
   | logicable
   | conjunction
   | negation
   | call
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

call
   : evaluable expression+
   ;

impartLeft
   : group
   | word
   ;

impartRight
   : group
   | function
   | word
   ;

impart
   : impartLeft '::' impartRight
   ;

product
   : mutliplyable (('*' | '/' | '%') mutliplyable)+
   ;

pair
   : expression ':' expression
   ;

defaultPair
   : '*' ':' expression
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
