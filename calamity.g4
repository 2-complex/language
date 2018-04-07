grammar calamity;

program
   : (line ((';'|',') line)* (';'|',')?)?
   ;

line
   : assignment
   | pair
   | expression
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
   : mutliplyable (('*' | '/') mutliplyable)+
   ;

addable
   : product
   | group
   | call
   | number
   | word
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
   | array
   | group
   | call
   | number
   | member
   | product
   | addedList
   | negative
   | function
   | comparison
   | logicable
   | conjunction
   | negation
   ;

call
   : evaluable expression
   ;

pair
   : expression ':' expression
   ;

reference
   : word
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
