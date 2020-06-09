%{
    #include <math.h>
    #include "parser.tab.h"
    #define IDMAXLENGTH 25
    /* when recognize signed int we only recognize operator(+/-) and a unsigned int*/
    extern int line;
    int control_match(char* yytext);
    extern int enter_while;
    extern  char agent_value_type[15];
    extern int agent_value_width;
    int reserve_match(char* yytext);
    int bool_match(char* yytext);
    #define ECHO printf("%s\n",yytext)
%}
%x COMMENTCONT
%x EXP
%s START
%x STRINGING
DIGIT [0-9]
DIGITEXC0 [1-9]
CHAR [a-zA-Z]|"_"
SPACE [ ]
SIGN "+"|"-"
TYPE "int"|"double"|"float"|"char"|"short"|"void"|"string"|"bool"
T_ID {CHAR}({CHAR}|{DIGIT}){0,25}
OPERATOR1 "*"|"/"|"%"
OPERATOR2 "+"|"-"
RELATION "<"|">"|"<="|">="|"=="|"!="
BOOL_OPERATOR "||"|"&&"|"!"
BIT_OPERATOR "~"|"&"|"|"
BOOL true|false
COMMENT1 \/\/.*\n
COMMENTCONT1 [^*{END}]+
COMMENTCONT2 "*"+[^*/]*
COMMENTSTART \/\*
COMMENTEND \*\/
INTEGER (0|(0x0)|(0X0)|({DIGITEXC0}{DIGIT}*)|(0(x|X)[0-9a-fA-F]*))
FLOAT ((0|({DIGITEXC0}{DIGIT}*))"."{DIGIT}+)
CONTROL "if"|"else"|"while"|"break"|"for"
RESERVE {CONTROL}|"this"|"class"|"public"|"protected"|"private"|"PrintString"|"newArray"|"interface"|"return"|"return"|"struct"|"continue"
STRINGSTART "\""
EMPTY_STRING "\"\""
SEPERATOR ";"
EMPTY [\t\r\a]+
INCRDECR "++"|"--"
%%
{EMPTY_STRING} {printf("get a empty string\n");}
{STRINGSTART} {BEGIN(STRINGING);}
<STRINGING>[^\"]* {printf("get a string:%s\n",yytext);yylval.value.value=strdup(yytext);return STRING;}
<STRINGING>\" {BEGIN(INITIAL);}
{TYPE} {printf("type:");ECHO;yylval.base_type.value_type=strdup(yytext);return TYPE_BASE;}
{BOOL} {return bool_match(yytext);}
{COMMENTSTART} {BEGIN(COMMENTCONT);printf("start match comment");}
{COMMENT1} {printf("found a comment1\n");}
{OPERATOR1} {ECHO;yylval.operator.name=strdup(yytext);return OPERATOR1;}
{OPERATOR2} {ECHO;yylval.operator.name=strdup(yytext);return OPERATOR2;}
{RELATION} {yylval.operator.name=strdup(yytext);return T_RELATION;}
{RESERVE} {ECHO;return reserve_match(yytext);}
{T_ID} {ECHO;if(strlen(yytext)>IDMAXLENGTH) perror("id is too long");yylval.id.var=strdup(yytext);return ID;}
{INTEGER} {ECHO;yylval.value.value=strdup(yytext);return INT_VALUE;}
{FLOAT} {ECHO;yylval.value.value=strdup(yytext);return FLOAT_VALUE;BEGIN(EXP);}
{BIT_OPERATOR} {ECHO;printf("found bit_operator:%s\n",yytext);yylval.operator.name=strdup(yytext);return T_BIT_OPERATOR;}
{BOOL_OPERATOR} {ECHO;yylval.operator.name=strdup(yytext);return T_BOOL_OPERATOR;}
<COMMENTCONT>{COMMENTEND} {BEGIN(INITIAL);printf("found a comment \n");}
<COMMENTCONT><<EOF>> {perror("EOF in comment\n");return 0;}
<COMMENTCONT>{COMMENTCONT1} {printf(" 1 ");}
<COMMENTCONT>{COMMENTCONT2} {printf(" 2 ");}
<EXP>"E"("+"|"-"){DIGIT}+ {printf("found a float EXP");BEGIN(INITIAL);}
<EXP>. {BEGIN(INITIAL);}
"=" {printf("=\n");return EQUAL;}

{EMPTY}|{SPACE} { }
{INCRDECR} {printf("found: %s\n",yytext);yylval.operator.name=strdup(yytext);return T_INCRDECR;}
[\n] {line++;}

 . {printf("%s\n",yytext);return yytext[0];}
%%
int yywrap()
{
    return 1;
}
int reserve_match(char* yytext)
{
    if(strcmp(yytext,"if")==0)
        return IF;
    else if (strcmp(yytext,"while")==0)
    {
        return WHILE;
    }
    else if(strcmp(yytext,"else")==0)
        return ELSE;
    else if(strcmp(yytext,"break")==0)
        return BREAK;
    else if(strcmp(yytext,"for")==0)
        return FOR;
    else if(strcmp(yytext,"return")==0)
        return RETURN;  
    else if(strcmp(yytext,"struct")==0||strcmp(yytext,"class")==0)
        return STRUCT;   
    else if(strcmp(yytext,"continue")==0)
        return CONTINUE;       
}
int bool_match(char* yytext)
{
    if(strcmp(yytext,"true"))
        yylval.values.value=strdup("1");
    else
        yylval.values.value=strdup("0");
    return BOOL_VALUE;
}
