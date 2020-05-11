%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include<stdarg.h>
    #include"parser.tab.h"
// error line location
int line=0;
//is enter while or for?
int enter_while=0;
//stack to store envirment 
stack* st;
struct envirement* current_env;
//current temp variable tag such as:t10
int temp_add_value=0;
//current location 1: 2:
int temp_lab_value=0;
//poiont Empty
char* Empty="";
//Point Wait
char* Wait="wait";
char* NO_STMT=" ";
char* Void="void";
char* waitpatch="waitpatch";
%}
%union {
    struct variable_type type;
    struct values_def{
        char* value;
    }values;
    struct value_def{
        char* value;
        char* value_type;
    }value;
    struct arr_def{
        int cont;
    }arr;
    struct type_base_def{
        char* value_type;
    }base_type;
    struct arrary_def{
        char* base;
        struct variable_type* var_type;
        char* var;
        addr_type* addr;
        addr_type* next_addr;
    }arrary;
    struct exp_value_def {
        struct variable_type* var_type;
        char* value;
        char* var;
        addr_type* addr;
        addr_type* next_addr;
    }exp_value;
    struct bool_exp_value_def{
        char bool_value;
        char* var;
        addr_type* addr;
        addr_type* next_addr;
        addr_type* true_addr;
        addr_type* false_addr;
    }bool_exp_value;
    struct id_def{
        char* var;
        char* value;        
    }id;
    struct stmt_value_def{
        addr_type* addr;
        addr_type* next_addr;
    }stmt_value;
    struct actual_para_def{
        struct variable_type* var_type;
        char* var;
    }actual_para;
    struct actual_paras_def{
        int para_cont;
        struct variable_type** paras_type;
        char** paras_name;
    }actual_paras;
    struct form_paras_def{
        int para_cont;
        struct variable_type** paras_type;
        char** paras_name;
    }form_paras;
    struct func_prefix_paras_def{
        func_symtab_type* func_tab;
       struct variable_type* return_type;
    }func_prefix;
    struct form_para_def{
        struct variable_type* var_type;
        char* name;
    }form_para;
    struct variable_def{
        var_symtab_type* var_tab;
    }variable;
    struct variables_def{
        int cont;
        var_symtab_type** var_tabs;
    }variables;
    struct function_call_def{
        addr_type* addr;
        addr_type* next_addr;
        char* name;
        struct variable_type* return_type;
    }function_call;
    struct operator_def{
        char* name; 
    }operator;
}
%type<actual_paras> ACT_PARAS
%type<actual_para>ACT_PARA
%type<form_paras>PARAS PARAMETERS  
%type<form_para>PARA
%type<bool_exp_value> BOOL_EXPRESSION IF_PREFIX FOR_PREFIX WHILE_PREFIX
%type<exp_value> EXPRESSION  IF_BLOCK FOR_INITIAL FOR_ITERATE  WHILE_BLOCK  RETURN_STAT FOR_INITIALS FOR_ITERATES
%type<variables> VARIABLES  
%type<func_prefix>FUNC_DEF_PREFIX
%type<variable>VARIABLE
%type<arr> ARRS
%type<value>VALUE
%type<function_call> FUNCTIONCALL
%type<arrary> L
%type<stmt_value> STATEMENT STATEMENTS  DECLARATION DEFINITION DEFINITIONS  FOR_BLOCK  FUNCTIONDEF STAT_BODY
%type<type>TYPE
%nonassoc  LOWER_THAN_ELSE
%nonassoc ELSE

%token<id> ID 

%left EQUAL
%left<operator>T_BOOL_OPERATOR
%left<operator>T_RELATION 
%left<operator> OPERATOR2
%left<operator> OPERATOR1  T_BIT_OPERATOR    
%token<base_type>TYPE_BASE
%token<values> INT_VALUE STRING FLOAT_VALUE BOOL_VALUE 
%token T_INCRDECR IF STRUCT WHILE BREAK FOR  RETURN  T_SEPERATOR CONTINUE
%%
Program : Program  PARTITION
            |
PARTITION :  DEFINITIONS 
            |FUNCTIONDEF
            |FUNCTIONDEC
            |DECLARATION
FUNCTIONDEC :TYPE ID '(' PARAMETERS ')' ';' {
    func_symtab_type* temp=creat_func_env();
    temp->name=$2.var;
    temp->para_cont=$4.para_cont;
    temp->paras_type=$4.paras_type;
    temp->paras_name=$4.paras_name;
    temp->return_type=creat_variable_type();
    temp->return_type->base=$1.base;
    temp->return_type->exten=$1.exten;
    temp->addr=Wait;
    if(func_sym_look($2.var,temp)==ALREAY_EXIST)
    {
        yyerror("function redeclaration");
        return 1;
    }
}
FUNCTIONDEF:  FUNC_DEF_PREFIX  STATEMENTS RETURN_STAT '}' {
                    printf("\n*********recognize a function**********\n\n");
                    backPatch($2.next_addr,$3.addr);
                    if(typecmp($3.var_type,$1.return_type)!=0)
                    {
                        yyerror("return Type mismatch ");
                        return 1;
                    }
                    if(func_sym_look($1.func_tab->name,$1.func_tab)==ALREAY_EXIST)
                    {
                        yyerror("function redefinition");
                        return 1;
                    }
                    current_env=creat_envirement();
                    while(!queue_isEmpty(stmt_queue) )
                        emit_stm_head();
                }
FUNC_DEF_PREFIX : TYPE ID '(' PARAMETERS ')' '{' {
    $$.return_type=creat_variable_type();
    $$.return_type->base=$1.base;
    $$.return_type->exten=$1.exten;
    int i=0,once=1;
    func_symtab_type* temp=creat_func_env();
    temp->paras_name=$4.paras_name;
    temp->paras_type=$4.paras_type;
    temp->name=$2.var;
    temp->para_cont=$4.para_cont;
    temp->env=current_env;
    for(i=0;i<$4.para_cont;i++)
    {
        if(var_sym_look(creat_symtab($4.paras_name[i],$4.paras_type[i]))!=ERRO_NONE)
        {
            yyerror("parameter error");

        }
        if(once)
        {
            temp->addr=emit_stm(3,$4.paras_name[i],"=","pop()"); 
            once=0;
        }    
        else
           emit_stm(3,$4.paras_name[i],"=","pop()");  
    }
    $$.func_tab=temp;
}

PARAMETERS : PARAS {
                int i=0;
                if($1.para_cont>MAX_PARA_CONT)
                {
                    yyerror("para num over flow");
                }
  
                    $$.paras_type=$1.paras_type;
                    $$.paras_name=$1.paras_name;
                $$.para_cont=$1.para_cont;          
            }
        | {
            $$.paras_type=(struct variable_type**)malloc(sizeof(struct variable_type*)*MAX_PARA_CONT);
            $$.paras_name=(char**)malloc(sizeof(char*)*MAX_PARA_CONT);
           $$.paras_type[0]=void_type;
           $$.para_cont=0;
        }  
PARAS: PARAS ',' PARA  {
                
                $$.paras_name=$1.paras_name;
                $$.paras_type=$1.paras_type;
                $$.paras_type[$$.para_cont]=$3.var_type;
                $$.paras_name[$$.para_cont]=$3.name;
                $$.para_cont=$1.para_cont+1;
                }
        | PARA   {
                $$.para_cont=1;
                $$.paras_type=(struct variable_type**)malloc(sizeof(struct variable_type*)*MAX_PARA_CONT);
                $$.paras_name=(char**)malloc(sizeof(char*)*MAX_PARA_CONT);
                $$.paras_type[0]=$1.var_type;
                $$.paras_name[0]=$1.name;
        }
PARA:  TYPE ID {
            $$.var_type=creat_variable_type();
            $$.var_type->base=$1.base;
            $$.var_type->exten=$1.exten;
            $$.name=$2.var;
        }   
                
TYPE: TYPE_BASE '*' {
    $$.base=$1.value_type;
    $$.exten=strdup("pointer");
}
    | TYPE_BASE {
        $$.base=$1.value_type;
        $$.exten=strdup("void");
    }        
STATEMENTS : STATEMENTS  STATEMENT   {
            $$.addr=$1.addr;
            $$.next_addr=$2.next_addr;
            backPatch($1.next_addr,$2.addr);
}
            | STATEMENT   {
                $$.addr=$1.addr;
                $$.next_addr=$1.next_addr;
                //merge($1.next_addr,&$$.next_addr);
            }
            | {
                $$.next_addr=make_list(Wait);
                $$.addr=$$.next_addr;
            }
STATEMENT : DEFINITION   {
            $$.addr=$1.addr;
            $$.next_addr=$1.next_addr;
            }
            |EXPRESSION  ';' {
            $$.addr=$1.addr;              
            $$.next_addr=$1.next_addr;
            printf("EXPRESSION:%s\n",get_value($$.addr));
            
            }
            |IF_BLOCK        {
            $$.addr=$1.addr;               
            $$.next_addr=$1.next_addr;
            }
            |WHILE_BLOCK  {
             $$.addr=$1.addr;
            // merge($1.next_addr,$$.next_addr);               
             $$.next_addr=$1.next_addr;
            }
            |STAT_BODY {
                $$.addr=$1.addr;
                 $$.next_addr=$1.next_addr;              
            }
            |BREAK ';'  {
                if(!enter_while) 
                    yyerror("break should in while or switch");

                $$.next_addr=make_list(Wait);
                $$.addr=make_list(emit_stm(2,"goto",get_value(break_addr))) ;
            }
            |CONTINUE ';' {
                if(!enter_while) 
                    yyerror("CONTINUE should in while or switch");
                $$.next_addr=make_list(Wait);
                $$.addr=make_list(emit_stm(2,"goto",get_value(continue_addr))) ;
            }
            |FOR_BLOCK {
                $$.addr=$1.addr;
                //merge($1.next_addr,$$.next_addr) ;     
                $$.next_addr=$1.next_addr;
                printf(" FOR_block acc ");
                }
STAT_BODY : '{' TEMP_M STATEMENTS '}' {
                $$.addr=$3.addr;
                $$.next_addr=$3.next_addr;
                current_env=pop(st);
            }
TEMP_M: {
    push(st,current_env);
    current_env=creat_envirement();
}
RETURN_STAT:  RETURN EXPRESSION ';' {
                $$.addr=$2.addr;
                assign_addr($2.next_addr,emit_stm(2,"ret",$2.var));
                //merge($2.next_addr,$$.next_addr);
                $$.next_addr=make_list(Wait);
                $$.var_type=$2.var_type;
            }
            | RETURN ';'    {
                $$.addr=make_list(emit_stm(1,"ret"));
                $$.next_addr=make_list(Wait);
                $$.var_type=void_type;
            }
            |   {
                $$.addr=make_list(emit_stm(1,"ret"));
                $$.next_addr=make_list(Wait);
                $$.var_type=void_type;
                printf("return_empty ACC\n");}
DECLARATION : STRUCT ID '{' TEMP_M DEFINITIONS  '}' {
                    // $$.addr=$5.addr;
                    // $$.next_addr=$5.next_addr;
                    str_symtab_type* temp=(str_symtab_type*)malloc(sizeof(str_symtab_type));
                    temp->var=$2.var;
                    temp->width=0;
                    temp->env=current_env;
                    current_env=pop(st);
                    if(str_sym_look($2.var,temp)==ALREAY_EXIST)
                    {
                        yyerror("variable redefinition");
                        return 1;
                    }
            }
DEFINITIONS : DEFINITIONS  DEFINITION {
            $$.addr=$1.addr;
            backPatch($1.next_addr,$2.addr);
            $$.next_addr=$2.next_addr;
}
            | DEFINITION {
                $$.addr=$1.addr;
                $$.next_addr=$1.next_addr;
            }
DEFINITION :TYPE VARIABLES  ';' {
            int i;
            for(i=0;i<$2.cont;i++)
            {
                if(strcmp($2.var_tabs[i]->var_type->exten,"arrary")==0)
                {
                    $2.var_tabs[i]->elem_type=creat_variable_type();
                    $2.var_tabs[i]->elem_type->base=$1.base;
                    $2.var_tabs[i]->elem_type->exten=$1.exten;
                }
                else if(strcmp($2.var_tabs[i]->var_type->base,Void)==0)
                {
                    $2.var_tabs[i]->var_type->base=$1.base;
                }    
                else
                {
                    if(typecmp($2.var_tabs[i]->var_type,&$1)!=0)
                        yyerror("type definition  dismatch");
                }
                if(var_sym_look($2.var_tabs[i])==ALREAY_EXIST)
                {
                    yyerror("variable redefinition");
                }
                $2.var_tabs[i]->width*=get_width_by_type(&$1);
            }
            $$.addr=make_list(emit_stm(3,$2.var_tabs[0]->var_type->base,$2.var_tabs[0]->var_type->exten,$2.var_tabs[0]->var));
            for(i=1;i<$2.cont;i++)
                emit_stm(3,$2.var_tabs[i]->var_type->base,$2.var_tabs[i]->var_type->exten,$2.var_tabs[i]->var);
            $$.next_addr=make_list(Wait);
            }
VARIABLES : VARIABLES ',' VARIABLE {
            int i;
            $$.var_tabs=$1.var_tabs;
            if($1.cont>=MAX_PARA_CONT)
            {
                yyerror("define variable too much");
            }
            $$.var_tabs[$1.cont]=$3.var_tab;
            $$.cont=$1.cont+1;
}
            |VARIABLE     {
                $$.var_tabs=(var_symtab_type**)malloc(sizeof(var_symtab_type*)*MAX_PARA_CONT);
                $$.var_tabs[0]=$1.var_tab;
                $$.cont=1;
            }
VARIABLE : ID {
            struct variable_type* temp_type=creat_variable_type(); 
            var_symtab_type* temp=creat_symtab($1.var,temp_type);
            temp->width=1;
            $$.var_tab=temp;
        }
         | ID  EQUAL EXPRESSION {
            var_symtab_type* temp=creat_symtab($1.var,$3.var_type);
            if(strcmp(temp->var_type->exten,$3.var_type->exten)!=0)
            {
                yyerror("EXPRESSION retrun type dismatch");
            }
            temp->var_type->base=$3.var_type->base;
            temp->value=$3.var;
            temp->width=1;
            $$.var_tab=temp;
            
         }
         | '*' ID EQUAL EXPRESSION{
            var_symtab_type* temp=creat_symtab($2.var,$4.var_type);
            if(strcmp(temp->var_type->exten,$4.var_type->exten)!=0)
            {
                yyerror("EXPRESSION retrun type dismatch");
            }
            temp->var_type->base=$4.var_type->base;
            temp->value=$4.var;
            temp->width=1; 
            $$.var_tab=temp;
         }
         | ID ARRS EQUAL LIST{

         }
         |'*' ID EQUAL LIST{

         }
         |ID ARRS {
            struct variable_type* temp_type=creat_variable_type(); 
            temp_type->exten=strdup("arrary");
            var_symtab_type* temp=creat_symtab($1.var,temp_type);
            temp->width=$2.cont;
            $$.var_tab=temp;
         }
         | '*' ID {   
            struct variable_type* temp_type=creat_variable_type(); 
            temp_type->exten=strdup("pointer");
            var_symtab_type* temp=creat_symtab($2.var,temp_type);
            temp->width=MACHINE_BIT/8;
            $$.var_tab=temp;
         }
LIST : '{' ACT_PARAS '}' { 


}

ARRS : ARRS '[' INT_VALUE ']' {
            $$.cont=$1.cont*atoi($3.value);
            }
        | '[' INT_VALUE ']' {
            $$.cont=atoi($2.value);
        }



EXPRESSION  :FUNCTIONCALL   {
            $$.addr=$1.addr;
            $$.next_addr=$1.next_addr;
            $$.var=$1.name;
            $$.var_type=$1.return_type;
            printf(" ***FUNCTIONCALL*** ");
            }
            |ID EQUAL EXPRESSION {
                struct var_symtab* temp_id=query_var_sym($1.var);
                if(!temp_id)
                {
                    yyerror("not such variable");
                }
                if(typecmp(temp_id->var_type,$3.var_type)!=0)
                {
                    yyerror("can not assign such type ");
                }
                assign_addr($3.next_addr,emit_stm(3,temp_id->var,"=",$3.var));
                $$.addr=$3.addr;
                $$.next_addr=make_list(Wait);
                $$.var=$1.var;
                $$.var_type=$3.var_type;
                printf("ID EQUAL EXPRESSION:%s\n",get_value($$.addr));
            }
            |VALUE{
                $$.var=$1.value;
                $$.next_addr=make_list(Wait);
                $$.addr=$$.next_addr;
                $$.var_type=creat_variable_type();
                $$.var_type->base=$1.value_type;
            }
            |EXPRESSION OPERATOR1 EXPRESSION {
                $$.var=creat_temp_add();
                backPatch($1.next_addr,$3.addr);
                $$.addr=$1.addr;
                assign_addr($3.next_addr,emit_stm(5,$$.var,"=",$1.var,$2.name,$3.var));
                $$.next_addr=make_list(Wait);
                $$.var_type=handle_type($1.var_type,$3.var_type);
                printf("EXPRESSION OPERATOR1 EXPRESSION:%s\n",get_value($$.addr));
            }
            |EXPRESSION OPERATOR2 EXPRESSION {
                printf("EXPRESSION OPERATOR2 EXPRESSION\n");
                $$.var=creat_temp_add();
                $$.addr=$1.addr;
                backPatch($1.next_addr,$3.addr);
                assign_addr($3.next_addr,emit_stm(5,$$.var,"=",$1.var,$2.name,$3.var));
                $$.next_addr=make_list(Wait);
                $$.var_type=handle_type($1.var_type,$3.var_type);
                printf("EXPRESSION OPERATOR1 EXPRESSION:%s\n",get_value($$.addr));
            }
            |OPERATOR2 EXPRESSION{
                $$.var=creat_temp_add();
                $$.addr=make_list(emit_stm(4,$$.var,"=",$1.name,$2.var));
                backPatch($2.next_addr,$$.addr);
                $$.next_addr=make_list(Wait);
                $$.var_type=$2.var_type;
            }
            |T_BOOL_OPERATOR EXPRESSION{
                $$.var=creat_temp_add();
                $$.addr=make_list(emit_stm(4,$$.var,"=",$1.name,$2.var)); 
                backPatch($2.next_addr,$$.addr);
                $$.next_addr=make_list(Wait);
                $$.var_type=creat_variable_type();
                $$.var_type->base="bool";
            }
            |L {
                $$.var_type=$1.var_type;
                $$.var=creat_temp_add();
                $$.addr=make_list(emit_stm(6,$$.var,"=",$1.base,"[",$1.var,"]"));
                $$.next_addr=make_list(Wait);
            }
            |ID T_INCRDECR {
                $$.var_type=creat_variable_type();
                $$.var_type->base="int";
                $$.next_addr=make_list(Wait);
                $$.var=creat_temp_add();
                $$.addr=make_list(emit_stm(3,$$.var,"=",$1.var));
                emit_stm(5,$1.var,"=",$1.var,"-","1"); 
            }
            |T_INCRDECR ID {
                $$.var_type=creat_variable_type();
                $$.var_type->base="int";
                $$.next_addr=make_list(Wait);
                $$.var=creat_temp_add();
                $$.addr= make_list(emit_stm(5,$$.var,"=",$2.var,"-","1")); 
               
            }    
            |'(' EXPRESSION ')' {
                $$.var_type=$2.var_type;
                $$.var=creat_temp_add();
                $$.addr=make_list(emit_stm(3,$$.var,"=",$2.var));
                $$.next_addr=make_list(Wait);    
            }
            | ID {
                printf("ID\n");
                var_symtab_type* temp=query_var_sym($1.var);
                printf("ID\n");
                if(temp==(var_symtab_type*)0)
                {
                    yyerror("no such id:");
                    printf("%s\n",$1.var);
                }    
                $$.var=$1.var;
                $$.next_addr=make_list(Wait);
                $$.addr=$$.next_addr;
                $$.var_type=temp->var_type;
                
            }
L :L '[' EXPRESSION ']' {
        backPatch($1.next_addr,$3.addr);
        $$.var=creat_temp_add();
        struct var_symtab* temp=query_var_sym($1.var); 
        $$.var_type=$1.var_type;
        $$.addr=make_list(emit_stm(5,$$.var,"=",$3.var,"*",itoa(temp->width)));
        emit_stm(5,$$.var,"=",$1.var,"+",$$.var);
        backPatch($3.next_addr,$$.addr);
        $$.next_addr=make_list(Wait);
        }
    | ID '[' EXPRESSION ']'{
        $$.base=$1.var;
        $$.var=creat_temp_add();
        $$.next_addr=make_list(Wait);
        if(strcmp($3.var_type->base,"int")!=0)
        {
            yyerror("index erro type");
        }
        struct var_symtab* temp=query_var_sym($1.var); 
        printf("L:base:%s %s\n",temp->var_type->base,temp->var_type->exten);
        if(temp==(var_symtab_type*)0||strcmp(temp->var_type->exten,"arrary")!=0)
        {
            yyerror("such id is not array");
        }
        $$.var_type=temp->var_type;
        $$.addr=make_list(emit_stm(5,$$.var,"=",$3.var,"*",itoa(get_width_by_type(temp->elem_type))));
        backPatch($3.next_addr,$$.addr);
    }

BOOL_EXPRESSION :BOOL_EXPRESSION T_BOOL_OPERATOR BOOL_EXPRESSION    {                 
                if(strcmp($2.name,"&&")==0)
                { 
                    $$.false_addr=$1.false_addr;
                    backPatch($1.true_addr,$3.addr);
                    merge($3.false_addr,$1.false_addr);
                    $$.true_addr=$3.true_addr;
                }
                else if(strcmp($2.name,"||")==0)
                {
                    backPatch($1.false_addr,$3.addr);
                    merge($1.true_addr,$3.true_addr);
                    $$.true_addr=$3.true_addr;
                    $$.false_addr=$3.false_addr;
                }
                $$.var=creat_temp_add();
                $$.addr=$1.addr;
                assign_addr($3.next_addr,emit_stm(5,$$.var,"=",$1.var,$2.name,$3.var));
            }
            |EXPRESSION {
                $$.addr=$1.addr;
                $$.var=creat_temp_add();
                assign_addr($1.next_addr,emit_stm(3,$$.var,"=",$1.var));
                $$.true_addr=make_list(Wait);
                $$.false_addr=make_list(Wait);
            }
            |EXPRESSION T_RELATION EXPRESSION {
                $$.var=creat_temp_add();
                $$.addr=$1.addr;
                assign_addr($3.next_addr,emit_stm(5,$$.var,"=",$1.var,$2.name,$3.var));
                backPatch($1.next_addr,$3.addr);
                $$.true_addr=make_list(Wait);
                $$.false_addr=make_list(Wait);
            } 
            | T_BOOL_OPERATOR BOOL_EXPRESSION{
                $$.var=creat_temp_add();
                $$.addr=$2.addr;
                emit_stm(4,$$.var,"=",$1.name,$2.var);
                $$.true_addr=make_list(Wait);
                $$.false_addr=make_list(Wait);
                //$$.next_addr=make_list(Wait);

                if(strcmp($1.name,"!")==0){
                    $$.true_addr=$2.false_addr;
                    $$.false_addr=$2.true_addr;
                }
                else{
                    yyerror("wrong bool operator");
                }
            }

          
VALUE : INT_VALUE      {$$.value=$1.value;$$.value_type="int";}
        |FLOAT_VALUE   {$$.value=$1.value;$$.value_type="float";}
        |BOOL_VALUE    {$$.value=$1.value;$$.value_type="bool";}
        |STRING        {$$.value=$1.value;$$.value_type="string";}
        
FUNCTIONCALL: ID '(' ACT_PARAS ')' {
                    printf("1");
                    printf(":%s\n",func_env->name);
                    func_symtab_type* temp_func=query_fuc_sym($1.var);
                    if(temp_func==(func_symtab_type*)0)
                    {
                        yyerror("no such function");
                    }
                    else
                    {
                        $$.return_type=temp_func->return_type;
                        printf("1");
                        int i;
                        if($3.para_cont>0)
                        {
                            if(typecmp(temp_func->paras_type[0],$3.paras_type[0])!=0)
                                yyerror("para type dismatch");
                            else
                                $$.addr=make_list(emit_stm(2,"push",$3.paras_name[0])) ;
                            for(i=1;i<temp_func->para_cont;i++)
                            {
                                if(typecmp(temp_func->paras_type[i],$3.paras_type[i])!=0)
                                    yyerror("para type dismatch");
                                emit_stm(2,"push",$3.paras_name[i]);
                            }
                            emit_stm(2,"goto",temp_func->addr);
                        }
                        else
                            $$.addr=make_list(emit_stm(2,"goto",temp_func->addr));
                        $$.name=strdup("eax");
                        $$.next_addr=make_list(Wait);
                    }
                }

ACT_PARAS : ACT_PARAS ',' ACT_PARA {
            if($1.para_cont==0)
                yyerror("void follow no void");
            $$.paras_name=$1.paras_name;
            $$.paras_type=$1.paras_type;
            $$.paras_type[$1.para_cont]=$3.var_type;
            $$.paras_name[$1.para_cont]=$3.var;
            $$.para_cont=$1.para_cont+1;
            }
            | ACT_PARA   {
                $$.paras_type=(struct variable_type**)malloc(sizeof(struct variable_type*)*MAX_PARA_CONT);
                $$.paras_name=(char**)malloc(sizeof(char*)*MAX_PARA_CONT);
                $$.para_cont=1;
                $$.paras_type[0]=$1.var_type;
                $$.paras_name[0]=$1.var;
            }
            |   {   
                    $$.para_cont=0;
                }
    
ACT_PARA :BOOL_EXPRESSION {
                    $$.var=$1.var;
                    $$.var_type=creat_variable_type();
                    $$.var_type->base="bool";
           }
         
IF_BLOCK :  IF_PREFIX STATEMENT %prec LOWER_THAN_ELSE {
                $$.addr=$1.addr;
                if(strcmp(get_value($2.addr),Wait)==0)
                {
                    printf("come yes");
                    merge($1.false_addr,$1.true_addr);
                    merge($2.next_addr,$1.false_addr);
                }
                else
                {
                    backPatch($1.true_addr,$2.addr);
                    merge($2.next_addr,$1.false_addr);
                }
                $$.next_addr=$2.next_addr;
                printf("_____if acc_____");
                }
            | IF_PREFIX STATEMENT  ELSE STATEMENT     {
                $$.addr=$1.addr;
                if(strcmp(get_value($2.addr),Wait)==0&&strcmp(get_value($4.addr),Wait)==0)
                {
                    merge($2.addr,$1.true_addr);
                    merge($4.next_addr,$1.false_addr);
                    merge($1.true_addr,$4.next_addr);
                    $$.next_addr=$1.true_addr; 
                }
                else if(strcmp(get_value($2.addr),Wait)==0)
                {

                    merge($2.addr,$1.true_addr);
                    merge($4.next_addr,$2.next_addr);
                    backPatch($1.false_addr,$4.addr);
                    $$.next_addr=$4.next_addr;       
                }
                else if(strcmp(get_value($4.addr),Wait)==0)
                {
                    backPatch($1.true_addr,$2.addr);
                    merge($4.next_addr,$1.false_addr);
                    merge($2.next_addr,$4.next_addr);
                    $$.next_addr=$2.addr;
                }
                else
                {
                    backPatch($1.true_addr,$2.addr);
                    backPatch($1.false_addr,$4.addr);
                    merge($2.next_addr,$4.next_addr);
                    $$.next_addr=$2.next_addr;
                }

                printf("_____if acc_____");
            }
IF_PREFIX: IF '(' BOOL_EXPRESSION ')' {
                $$.addr=$3.addr;
                $$.true_addr=$3.true_addr;
                $$.false_addr=$3.false_addr;
                emit_stm(4,"if",$3.var,"goto ",emit_stm_ready($3.true_addr));
                emit_stm(2,"goto ",emit_stm_ready($3.false_addr));     
        }
WHILE_BLOCK: WHILE_PREFIX  STATEMENT  {
                enter_while--;
                backPatch($1.true_addr,$2.addr);
                backPatch($2.next_addr,$1.addr);
                $$.next_addr=$1.false_addr;
                $$.addr=$1.addr;
                emit_stm(2,"goto ",get_value($1.addr));
                printf("_______while acc________");
                }
WHILE_PREFIX : WHILE '(' BOOL_EXPRESSION ')' {
        enter_while++;
        $$.addr=$3.addr;
        continue_addr=$3.addr;
        $$.true_addr=$3.true_addr;
        $$.false_addr=$3.false_addr;
        emit_stm(4,"if",$3.var,"goto ",emit_stm_ready($3.true_addr));
        emit_stm(2,"goto ",emit_stm_ready($3.false_addr)); 
        break_addr=$3.false_addr;
        printf("*****WHILE_PREFIX:%s****\n",get_value(break_addr));
}
FOR_BLOCK : FOR_PREFIX  FOR_ITERATES ')' STATEMENT {
                    enter_while--;
                    backPatch($1.true_addr,$2.addr);
                    backPatch($4.next_addr,$1.addr);
                    backPatch($2.next_addr,$4.addr);
                    $$.addr=$1.addr;
                    $$.next_addr=$1.false_addr;
                    printf("____for acc_____");
                    emit_stm(2,"goto ",get_value($1.next_addr)); 
}
FOR_PREFIX : FOR '(' FOR_INITIALS ';' BOOL_EXPRESSION ';' {
            $$.addr=$3.addr;
            backPatch($3.next_addr,$5.addr);
            $$.next_addr=$5.addr;
            continue_addr=$5.addr;
            $$.true_addr=$5.true_addr;
            $$.false_addr=$5.false_addr;
            emit_stm(4,"if",$5.var,"goto ",emit_stm_ready($5.true_addr));
            emit_stm(2,"goto ",emit_stm_ready($5.false_addr)); 
            break_addr=$5.false_addr;
}
FOR_INITIALS: FOR_INITIAL  {
            $$.addr=$1.addr;
            $$.next_addr=$1.next_addr;
} 
            | {
                $$.next_addr=make_list(Wait);
                $$.addr=$$.next_addr;
            }
FOR_INITIAL:  FOR_INITIAL ',' EXPRESSION {
            $$.addr=$1.addr;
            backPatch($1.next_addr,$3.addr);
            $$.next_addr=$3.next_addr;
            }
            | EXPRESSION {
                $$.addr=$1.addr;
                $$.next_addr=$1.next_addr;
            }
FOR_ITERATES: FOR_ITERATE {
            $$.addr=$1.addr;
            $$.next_addr=$1.next_addr;     
}
            | {
                $$.next_addr=make_list(Wait);
                $$.addr=$$.next_addr;
            }

FOR_ITERATE :FOR_ITERATE ','  EXPRESSION {
            $$.addr=$1.addr;
            backPatch($1.next_addr,$3.addr);
            $$.next_addr=$3.next_addr;  
}
            |EXPRESSION  {
                $$.addr=$1.addr;
                $$.next_addr=$1.next_addr;
            }
%%
void yyerror(const char* msg)
{
    printf("line:%d %s\n",line,msg);
}

int get_width_by_type(struct variable_type* type)
{
    if(strcmp(type->exten,"pointer")==0)
        return MACHINE_BIT/8;
    else if(strcmp(type->base,"int")==0)
        return INT_BYTE;
    else if(strcmp(type->base,"float")==0)
        return FLOAT_BYTE;
    else if(strcmp(type->base,"bool")==0)
        return BOOL_VALUE;
    else if(strcmp(type->base,"string")==0)
        return STRING_BYTE;
    else if(strcmp(type->base,"double")==0)
        return DOUBLE_BYTE;
    else
        return 0;
}
int var_sym_look(var_symtab_type* var_sym)
{
    var_symtab_type* var_tab=current_env->var_tab; 
    while(var_tab!=(var_symtab_type*)0) {  
        if(strcmp(var_tab->var,var_sym->var)==0) 
            return ALREAY_EXIST;
        var_tab=var_tab->next;
        }
    var_sym->next=current_env->var_tab;
    current_env->var_tab=var_sym;
    return ERRO_NONE;
}
void iterate_env()
{
    var_symtab_type* var_tab=current_env->var_tab; 
    while(var_tab!=(var_symtab_type*)0) {  
        printf("name:%s base:%s  exten:%s\n",var_tab->var,var_tab->var_type->base,var_tab->var_type->exten);
        var_tab=var_tab->next;
    }
}
int str_sym_look(char* sym_name,str_symtab_type* str_tab)
{
    str_symtab_type* str_tab_pointer=current_env->str_tab; 
    while(str_tab_pointer!=(str_symtab_type*)0) {  
        if(str_tab_pointer->var==str_tab->var) 
            return ALREAY_EXIST;
        str_tab_pointer=str_tab_pointer->next;
        }
    str_tab->next=current_env->str_tab;
    current_env->str_tab=str_tab;
    return ERRO_NONE;
}
int func_sym_look(char* sym_name,func_symtab_type* func_tab_para)
{
    if(!func_tab_para)
    {
        yyerror("erro func_tab_para is null ");
    }
    func_symtab_type* func_tab=func_env; 
    while(func_tab!=(func_symtab_type*)0) {  
        if(func_tab->name==func_tab_para->name) 
            return ALREAY_EXIST;
        func_tab=func_tab->next;
        }
    func_tab_para->next=func_env;
    func_env=func_tab_para;
    return ERRO_NONE;
}
func_symtab_type* query_fuc_sym(char* sym_name)
{
    func_symtab_type* func_tab=func_env; 
    while(func_tab!=(func_symtab_type*)0) { 
         printf("query_fuc_sym:  %s  \n",func_tab->name); 
        if(strcmp(func_tab->name,sym_name)==0) 
        {
            printf("yes");
            return func_tab;
        }    
        func_tab=func_tab->next;
    }
    return (func_symtab_type*)0;
}
var_symtab_type* query_var_sym(char* sym_name)
{
    printf("query_var_sym:%s\n",sym_name);
    var_symtab_type* var_tab=current_env->var_tab;
    if(!var_tab)
        yyerror("current_env null");
    while(var_tab!=(var_symtab_type*)0) {  
        if(strcmp(var_tab->var,sym_name)==0) 
        {
            printf("find end\n");
            return var_tab;
        }
        var_tab=var_tab->next;
        }
    stack* temp_st=creatStack();
    struct envirement* temp_env=current_env;
    while(!stack_isEmpty(st))
    {
        temp_env=pop(st);
        push(temp_st,temp_env);
        var_tab=temp_env->var_tab;
        while(var_tab!=(struct var_symtab*)0) {  
            if(strcmp(var_tab->var,sym_name)==0)
            {
                while(!stack_isEmpty(temp_st))
                    push(st,pop(temp_st));
                free(temp_st);
                return var_tab;
            }       
            var_tab=var_tab->next;
        }
    }
    while(!stack_isEmpty(temp_st))
        push(st,pop(temp_st));
    free(temp_st);
    printf("nofound end\n");
    return (struct var_symtab*)0;
}

char* emit_stm(int num,...)
{
    printf("emit_stm: ");
    if(num>MAX_STMT_LENGTH)
    {
        yyerror("too much stmt");
    }
    va_list args;
    int i;
    va_start(args,num);
    char has_wait=0;
    char** res=(char**)malloc(sizeof(char*)*MAX_STMT_LENGTH);
    for(i=0;i<MAX_STMT_LENGTH;i++)
        res[i]=NO_STMT;
    res[0]=strdup(itoa(temp_lab_value));
    temp_lab_value++; 
    for(i=1;i<=num;i++)
    {
        res[i]=va_arg(args,char*);
        printf("%s ",res[i]);
        if(strcmp(res[i],waitpatch)==0)
        {
            has_wait=1;
        }
        else
           res[i]=strdup(res[i]);     
    }
    if(has_wait||!queue_isEmpty(stmt_queue))
    {
        enqueue(stmt_queue,res);
    }
    else
    {
        fprintf(file,"%s:",res[0]);
        for(i=1;i<=num;i++)
        {
            fprintf(file,"%s ",res[i]);
            free(res[i]);
        }    
        fputs("\n",file);
    }
    printf("end\n");
    return res[0];
}
bool check_stmt_ready()
{
    if(queue_isEmpty(stmt_queue))
    {
        return false;
    }
    printf("check_stmt_ready\n");    
    char** stmt_head=getHead(stmt_queue);

    int i;
    for(i=0;i<MAX_STMT_LENGTH&&stmt_head[i]!=NO_STMT;i++)
    {
        if(strcmp(stmt_head[i],waitpatch)==0)
            return false;
    }
     printf("end\n");
    return true;
}
void emit_stm_head()
{
    printf("emit_stm_head\n");
    if(queue_isEmpty(stmt_queue))
        yyerror("queue is Empty");
    char** stmt_head=dequeue(stmt_queue);
    int i;
    for(i=0;i<MAX_STMT_LENGTH&&stmt_head[i]!=NO_STMT;i++)
        fprintf(file,"%s ",stmt_head[i]);
    fputs("\n",file);
    printf("end\n");
}
char* strcat_int(char* str,int start,int num)
{
    int local_num=num;
    if(num==0)
    {
        str[start++]='0';
        str[start]='\0';
        return str;
    }
    int i=0;
    int num_bit[10];
    while(num!=0)
    {
        num_bit[i++]=abs(num%10);
        num=num/10;
    }
    if(local_num<0)
        str[start++]='-';
    while(i>0)
    {
        str[start++]=num_bit[--i]+'0';
    }
    str[start]='\0';
    return str;
}
char* creat_temp_lab()
{
    char* temp=(char*)malloc(sizeof(char)*5);
    temp[0]='l';
    temp=strcat_int(temp,1,temp_lab_value);
    return temp;
}
char* creat_temp_add()
{
    char* temp=(char*)malloc(sizeof(char)*5);
    temp[0]='t';
    temp=strcat_int(temp,1,temp_add_value);
    temp_add_value++;
    return temp;
}
int main()
{
    file=fopen("output.o","w");
    func_env=(func_symtab_type*)0;
    stmt_queue=creatQueue();
    current_env=creat_envirement();
    st=creatStack();
    void_type=creat_variable_type();
    return yyparse();
}
addr_type* make_list(char* content)
{
	addr_type* temp=(addr_type*)malloc(sizeof(addr_type));
    temp->is_top=1;
    temp->content=content;
    temp->upper=(addr_type*)0;
    return temp;    
}
addr_type* find_top(addr_type* list)
{
    if(!list)
    {
        printf("list empty");
    }
    while(list->upper!=(addr_type*)0)
        list=list->upper;
    return list;
}
void assign_addr(addr_type* list,char* instr)
{
    printf("assign_addr");
    addr_type* list_temp=find_top(list);
    list_temp->content=instr;
    printf("end");
}
void merge(addr_type* list1,addr_type* list2)
{
    printf("merge:%s  %s\n",get_value(list1),get_value(list2));
    // addr_type* left =find_top(list1);
    // addr_type* right=find_top(list2);
    list1->upper=list2;
	//left->upper=right;
}
char* get_value(addr_type* list)
{
	return find_top(list)->content;
}
void backPatch(addr_type* list,addr_type* instr)
{
    printf("backPatch:%s %s %s\n",list->content,get_value(list),get_value(instr));
    addr_type* list_temp=find_top(list);
    addr_type* instr_temp=find_top(instr);
    list_temp->upper=instr_temp;
    while(list!=(addr_type*)0)
    {
        if(strcmp(list->content,waitpatch)==0&&strcmp(get_value(instr),Wait)!=0)
            strcpy(list->content,get_value(instr));
        printf("strcmp:%s \n",list->content);
        list=list->upper;
    }    
    while(check_stmt_ready())
        emit_stm_head();
    printf("end\n");
}
struct variable_type* creat_variable_type()
{
    struct variable_type* temp_type=(struct variable_type*)malloc(sizeof(struct variable_type));
    temp_type->exten=Void;
    temp_type->base=Void;
    return temp_type;
}
var_symtab_type*  creat_symtab(char* name,struct variable_type* temp_type)
{
    var_symtab_type* temp=(var_symtab_type*)malloc(sizeof(var_symtab_type)); 
    temp->var_type=temp_type;
    temp->var=name;
    temp->elem_type=void_type;
    temp->addr=Empty;
    temp->width=1;
    temp->next=(var_symtab_type*)0;
    return temp;
}
struct variable_type* handle_type(struct variable_type* a,struct variable_type* b)
{
    return a;
}
char typecmp(struct variable_type* one,struct variable_type* other)
{
    if(!one||!other)
        yyerror("typecmp: one or other is Empty");
    if(get_width_by_type(one)<get_width_by_type(other))
        return 1;
    return 0;
}
func_symtab_type* creat_func_env()
{

    func_symtab_type* temp=(func_symtab_type* )malloc(sizeof(func_symtab_type));
    return temp;
}
char* emit_stm_ready(addr_type* addr)
{
    printf("emit_stm_ready\n");
    if(!addr)
    {
        yyerror("addr is null");
    }
    addr->content =(char*)malloc(sizeof(char)*10);
    addr->content[0]='w';
    addr->content[1]='a';
    addr->content[2]='i';
    addr->content[3]='t';
    addr->content[4]='p';
    addr->content[5]='a';
    addr->content[6]='t';
    addr->content[7]='c';
    addr->content[8]='h';
    addr->content[9]='\0';
    printf("end\n");
    return  addr->content;
}