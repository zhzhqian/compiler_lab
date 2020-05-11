%{
    #include<stdio.h>
    void yyerror(const char* msg);
    int yylex();
    int line=0;
    int enter_while=0;
%}
%union {
    char* name;
    int int_value;
    char bool_value;
    float float_value;
}
%token<name> TYPE
%token<name> ID
%left<name> OPERATOR
%token<int_value> INT_VALUE
%token<float_value> FLOAT_VALUE
%token<name> T_SEPERATOR 
%nonassoc  LOWER_THAN_ELSE
%nonassoc<name> ELSE
%token<name> IF
%token<name> WHILE
%token<name> BREAK
%token<name> FOR 
%token<name> STRING
%token<bool_value> BOOL_VALUE
%left<name> EQUAL
%token<name> T_BOOL_OPERATOR
%token<name> T_BIT_OPERATOR
%token<name> RETURN 
%token T_INCRDECR
%%

LANGUIGE : LANGUIGE  PARTITION
            |
PARTITION : DECLARATION ';'
            | DEFINITION ';'
            |FUNCTIONDEF

FUNCTIONDEF: TYPE ID '(' PARAS ')' '{' STATEMENTS RETURN_STAT '}' {
                    printf("\n*********recognize a function**********\n\n");
                    func_sym_look(ID);

                    }
PARAS: PARAS ',' PARA  {printf(" 0.1 ");}
        | PARA    
PARA:  TYPE ID     
       |           
STATEMENTS : STATEMENTS  STATEMENT   {}
            | STATEMENT               {printf(" 1.0 ");}
            |
STATEMENT : DECLARATION ';' {printf(" ***DECLARATION*** ");}
            |DEFINITION  ';' {printf(" ***DEFINITION*** ");}
            |EXPRESSION  ';' {printf(" ***EXPRESSION*** ");}
            |IF_BLOCK        {printf(" ***if_block*** ");}
            |WHILE_BLOCK  {printf(" while_block acc ");}
            |STAT_BODY {printf(" {} ");}
            |BREAK ';'  {if(!enter_while) perror("break should in while or switch");}
            |FOR_BLOCK {printf(" FOR_block acc ");}
STAT_BODY : '{' STATEMENTS '}'
RETURN_STAT:  RETURN BOOL_EXPRESSION ';' {$$.val;}
            | RETURN ';'
            |   {printf("return_empty ACC\n");}
DECLARATION : TYPE IDS   {printf(" 7 ");}
MIDS : MIDS ',' IDS {printf(" 8 ");}
    | IDS
IDS : BOOL_EXPRESSION
    |VALUE
    |
DEFINITION : TYPE ID EQUAL EXPRESSION  {printf(" 9 ");}
            | TYPE ID '[' INT_VALUE ']'  {printf(" arr ");}
EXPRESSION  :FUNCTIONCALL   {printf(" ***FUNCTIONCALL*** ");}
            |ID EQUAL EXPRESSION
            |EXPRESSION OPERATOR EXPRESSION {printf(" e op e ");}
            |OPERATOR EXPRESSION
            |T_BOOL_OPERATOR EXPRESSION
            |VALUE
            |ID
            |ID T_INCRDECR
            |T_INCRDECR ID
            |'(' EXPRESSION ')'
BOOL_EXPRESSION : EXPRESSION T_BOOL_OPERATOR  BOOL_EXPRESSION {printf(" BOOL_EXPRESSION ");}
            | EXPRESSION
VALUE : INT_VALUE  {printf(" 13 ");}
        |FLOAT_VALUE {printf(" 14 ");}
        |BOOL_VALUE
        |STRING
FUNCTIONCALL: ID '(' MIDS ')'  {printf(" 15 ");}
IF_BLOCK : IF '(' BOOL_EXPRESSION ')' STATEMENT %prec LOWER_THAN_ELSE {printf(" if acc");}
            | IF '(' BOOL_EXPRESSION ')' STATEMENT ELSE STATEMENT    {printf(" if acc");}
WHILE_BLOCK: WHILE '(' BOOL_EXPRESSION ')' STATEMENT  {enter_while--;} {printf(" while acc");}
FOR_BLOCK : FOR '(' FOR_INITIAL ';' BOOL_EXPRESSION ';' FOR_ITERATE ')' STATEMENT {printf(" for acc");}
FOR_INITIAL: EXPRESSION 
            |
FOR_ITERATE :  EXPRESSION
            |
%%
void yyerror(const char* msg)
{
    printf("line:%d %s\n",line,msg);
}

int main()
{
    return yyparse();
}