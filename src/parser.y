%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include<stdarg.h>
    #include"parser.tab.h"
//标记翻译当前行
int line=1;
//判断是否进入wihle循环,enter_while>0表示进入了while循环
int enter_while=0;
//用来保存环境的栈 
stack* st;
//标记生成代码的行数
int temp_add_value=0;
//临时变量的标签
int temp_lab_value=0;
//用来初始化指针
char* Empty="";
char* Wait="wait";
char* NO_STMT=" ";
char* Void="void";
//某个表示地址的指针指向这里，表示这个地址还没有被填充
char* waitpatch="waitpatch";
//是否输出调试信息
#define DEBUG 1
%}
%union {
    /*用于表示某一特定的类型*/
    struct variable_type type;
    /*表示某一特定类型的值*/
    struct values_def{
        char* value;
    }values;
    /*当不太明确该值的类型时用这表示*/
    struct value_def{
        char* value;
        char* value_type;
    }value;
    /*定义数组时*/
    struct arr_def{
        int cont;
    }arr;
    /*表示基本类型*/
    struct type_base_def{
        char* value_type;
    }base_type;
    /*表达式引用数组时*/
    struct arrary_def{
        char* base;
        struct variable_type* var_type;
        char* var;
        addr_type* addr;
        addr_type* next_addr;
    }arrary;
/*表示表达式的非终结符的类型*/
    struct exp_value_def {
        struct variable_type* var_type;
        char* value;
        char* var;
        addr_type* addr;
        addr_type* next_addr;
        addr_type* true_addr;
        addr_type* false_addr;
    }exp_value;
/*表示变量类型*/
    struct id_def{
        char* var;
        char* value;        
    }id;
/*表示句子的类型*/
    struct stmt_value_def{
        addr_type* addr;
        addr_type* next_addr;
        //保存return 的返回值类型
        struct variable_type* var_type;
    }stmt_value;
/*一个实参*/
    struct actual_para_def{
        struct variable_type* var_type;
        char* var;
    }actual_para;
//多个实参
    struct actual_paras_def{
        int para_cont;
        struct variable_type** paras_type;
        char** paras_name;
    }actual_paras;
 //多个形参
    struct form_paras_def{
        int para_cont;
        struct variable_type** paras_type;
        char** paras_name;
    }form_paras;
   //函数定义的前缀
    struct func_prefix_paras_def{
        func_symtab_type* func_tab;
       struct variable_type* return_type;
    }func_prefix;
 //一个形参
    struct form_para_def{
        struct variable_type* var_type;
        char* name;
    }form_para;
  //支持同时时定义多个变量
    struct variable_def{
        var_symtab_type* var_tab;
    }variable;
   //函数调用
    struct variables_def{
        int cont;
        var_symtab_type** var_tabs;
    }variables;
    //函数调用
    struct function_call_def{
        addr_type* addr;
        addr_type* next_addr;
        char* name;
        struct variable_type* return_type;
    }function_call;
    //运算符
    struct operator_def{
        char* name; 
    }operator;
}
%type<actual_paras> ACT_PARAS
%type<actual_para>ACT_PARA
%type<form_paras>PARAS PARAMETERS  
%type<form_para>PARA
%type<exp_value> EXPRESSION  IF_BLOCK FOR_INITIAL FOR_ITERATE  WHILE_BLOCK   FOR_INITIALS FOR_ITERATES IF_PREFIX FOR_PREFIX WHILE_PREFIX
%type<variables> VARIABLES  
%type<func_prefix>FUNC_DEF_PREFIX
%type<variable>VARIABLE
%type<arr> ARRS
%type<value>VALUE
%type<function_call> FUNCTIONCALL
%type<arrary> L
%type<stmt_value> STATEMENT STATEMENTS  DECLARATION DEFINITION DEFINITIONS  FOR_BLOCK  FUNCTIONDEF STAT_BODY RETURN_STAT
%type<type>TYPE
%nonassoc  LOWER_THAN_ELSE
%nonassoc ELSE

%token<id> ID 

%left EQUAL
%left<operator>T_BOOL_OPERATOR
%left<operator>T_RELATION 
%left<operator> OPERATOR2
%left<operator> OPERATOR1  T_BIT_OPERATOR  T_INCRDECR  
%token<base_type>TYPE_BASE
%token<values> INT_VALUE STRING FLOAT_VALUE BOOL_VALUE 
%token  IF STRUCT WHILE BREAK FOR  RETURN  T_SEPERATOR CONTINUE
%%
Program : PARTITION Program  
            |
PARTITION :  DEFINITION 
            |FUNCTIONDEF
            |FUNCTIONDEC
            |DECLARATION
FUNCTIONDEC :TYPE ID '(' PARAMETERS ')' ';' {
     //函数的定义，为了减少与函数声明的规约冲突，将函数的定义分为两部分，同样，函数的定义也会在函数符号表添加一项
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
        my_yyerror(1,"function redeclaration");
        return 1;
    }
}
FUNCTIONDEF:  FUNC_DEF_PREFIX  STATEMENTS  '}' {
                    debug(1,"\n*********recognize a function**********\n\n");
                    if($2.var_type==(struct variable_type*)0)
                    {
                        assign_addr($2.next_addr,emit_stm(1,"ret")) ;
                        $2.var_type=void_type;
                    }
                    //如果函数声明的返回值和函数实际的返回值类型不同。
                    if(typecmp($2.var_type,$1.return_type)!=0)
                    {
                        my_warrning(2,$1.func_tab->name,"function return Type mismatch ");
                    }

                    //如果函数声明的参数和实际的参数不同
                    if(func_sym_look($1.func_tab->name,$1.func_tab)==ALREAY_EXIST)
                    {
                        my_yyerror(1,"function redefinition");
                        return 1;
                    }
                    //每一个函数体都对应了一个环境/内部变量，所以每一个函数识别完，就将环境保存,并创建新的环境
                    var_env=(var_symtab_type*)0;
                    //如果还有未回填的地址，则应该是出错了，将未回填的地址打印出来
                    while(!queue_isEmpty(stmt_queue) )
                        emit_stm_head();
                }
FUNC_DEF_PREFIX : TYPE ID '(' PARAMETERS ')' '{' {
    $$.return_type=creat_variable_type();
    $$.return_type->base=$1.base;
    $$.return_type->exten=$1.exten;
    int i=0,once=1;
    //创建函数符号表的一项，并填充内容
    func_symtab_type* temp=creat_func_env();
    temp->paras_name=$4.paras_name;
    temp->paras_type=$4.paras_type;
    temp->name=$2.var;
    temp->para_cont=$4.para_cont;
    temp->var_tab=var_env;
    for(i=0;i<$4.para_cont;i++)
    {
         //在识别出参数后，为函数的环境内部创建参数的符号表项，并将参数定义为局部变量
        if(var_sym_look(creat_symtab($4.paras_name[i],$4.paras_type[i]))!=ERRO_NONE)
        {
            my_yyerror(1,"parameter error");
        }
        //第一个局部变量定义的的地址就是函数的地址
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
                //如果参数太多
                if($1.para_cont>MAX_PARA_CONT)
                {
                    my_yyerror(1,"para num over flow");
                }
  
                    $$.paras_type=$1.paras_type;
                    $$.paras_name=$1.paras_name;
                $$.para_cont=$1.para_cont;          
            }
        | {
            //如果没有参数，只需分配内存，然后设置参数数量为0
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
    //变量返回的类型只支持指针和基本类型
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
            if($2.var_type!=(struct variable_type*)0)
                $$.var_type=$2.var_type;
            else
                $$.var_type=$1.var_type;
}
            | STATEMENT   {
                $$.addr=$1.addr;
                $$.next_addr=$1.next_addr;
                $$.var_type=$1.var_type;
            }
            | {
                $$.next_addr=make_list(Wait);
                $$.addr=$$.next_addr;
                $$.var_type=(struct variable_type*)0;
            }
STATEMENT : DEFINITION   {
    //一个stament可以被推出变量的定义，一个表达式，if，while，break等
            $$.addr=$1.addr;
            $$.next_addr=$1.next_addr;
            $$.var_type=(struct variable_type*)0;
            }
            |EXPRESSION  ';' {
                debug(1,"EXPRESSION;");
            $$.addr=$1.addr;              
            $$.next_addr=$1.next_addr;
            $$.var_type=(struct variable_type*)0;
            debug(2,"EXPRESSION",get_value($$.addr));
            
            }
            |IF_BLOCK        {
            $$.addr=$1.addr;               
            $$.next_addr=$1.next_addr;
            $$.var_type=$1.var_type; 
            }
            |WHILE_BLOCK  {
             $$.addr=$1.addr;
            // merge($1.next_addr,$$.next_addr);               
             $$.next_addr=$1.next_addr;
            $$.var_type=$1.var_type; 
            }
            |STAT_BODY {
                $$.addr=$1.addr;
                $$.next_addr=$1.next_addr;
                $$.var_type=$1.var_type;              
            }
            |BREAK ';'  {
                if(!enter_while) 
                    my_yyerror(1,"break should in while or switch");

                $$.next_addr=make_list(Wait);
                $$.addr=make_list(emit_stm(2,"goto",get_value(break_addr))) ;
                $$.var_type=(struct variable_type*)0;
            }
            |CONTINUE ';' {
                if(!enter_while) 
                    my_yyerror(1,"CONTINUE should in while or switch");
                $$.next_addr=make_list(Wait);
                $$.addr=make_list(emit_stm(2,"goto",get_value(continue_addr))) ;
                 $$.var_type=(struct variable_type*)0;
            }
            |FOR_BLOCK {
                $$.addr=$1.addr;   
                $$.next_addr=$1.next_addr;
                $$.var_type=(struct variable_type*)0;
                debug(1," FOR_block acc ");
                $$.var_type=$1.var_type; 
                }
            |RETURN_STAT {
                $$.addr=$1.addr;
                $$.next_addr=$1.next_addr;
                $$.var_type=$1.var_type;
                
            }
STAT_BODY : '{' TEMP_M STATEMENTS '}' {
    //STAT_BODY可以是if,while,for内部的一部分，也可以直接在语句中做嵌套
                $$.addr=$3.addr;
                $$.next_addr=$3.next_addr;
                var_env=pop(st);
            }
TEMP_M: {
     //在识别到'{'后需要重新创建环境，这样在'{'内定义的变量与外部的变量才不会混淆
    push(st,var_env);
    var_env=(var_symtab_type*)0;
}
RETURN_STAT:  RETURN EXPRESSION ';' {
            //返回语句既可以返回一个表达式，也可以就是一个return，也可以没有。
            //return句子的地址就是expressin的地址
                $$.addr=$2.addr;
            //直接生成表达式ret，并且可以回填表达式的next地址
                assign_addr($2.next_addr,emit_stm(2,"ret",$2.var));
                $$.next_addr=make_list(Wait);
                $$.var_type=$2.var_type;
            }
            | RETURN ';'    {
                    //由于只有return,直接翻译为ret，此时return的地址就是ret的地址
                $$.addr=make_list(emit_stm(1,"ret"));
                $$.next_addr=make_list(Wait);
                $$.var_type=void_type;
            }
DECLARATION : STRUCT ID '{' TEMP_STR DEFINITIONS  FUNCTIONDEF '}' {
                //结构体/类的声明
                    str_symtab_type* temp=creat_str_env();
                    temp->var=$2.var;
                    temp->width=0;
                    temp->var_tab=var_env;
                    temp->func_tab=func_env;
                    var_env=pop(st);
                    func_env=(func_symtab_type*)pop(st);
                    if(str_sym_look($2.var,temp)==ALREAY_EXIST)
                    {
                        my_yyerror(2,$2.var,"struct/class redefinition");
                        exit(1);
                    }
            }
TEMP_STR : {
    debug(1,"TEMP_STR");
        push(st,(var_symtab_type*)func_env);
        push(st,var_env);
        var_env=(var_symtab_type*)0;
        func_env=(func_symtab_type*)0;
        debug(1,"TEMP_STR end");
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
                //创建变量对应的符号表项
                //如果创建的变量是数组类型
                if(strcmp($2.var_tabs[i]->var_type->exten,"arrary")==0)
                {
                    $2.var_tabs[i]->elem_type=creat_variable_type();
                    $2.var_tabs[i]->elem_type->base=$1.base;
                    $2.var_tabs[i]->elem_type->exten=$1.exten;
                }
                else if(strcmp($2.var_tabs[i]->var_type->base,Void)==0)
                {
                    //如果定义的变量创建时没有赋初始值。
                    $2.var_tabs[i]->var_type->base=$1.base;
                }    
                else
                {
                    if(typecmp($2.var_tabs[i]->var_type,&$1)!=0)
                        my_yyerror(3,"type definition  dismatch:",$2.var_tabs[i]->var_type->base,$1.base);
                }
                if(var_sym_look($2.var_tabs[i])==ALREAY_EXIST)
                {
                    my_yyerror(1,"variable redefinition");
                }
                $2.var_tabs[i]->width*=get_width_by_type(&$1);
            }
            //变量定义语句的地址就是第一个变量定义生成代码的地址
            $$.addr=make_list(emit_stm(2,$2.var_tabs[0]->var_type->base,$2.var_tabs[0]->var));
            for(i=1;i<$2.cont;i++)
                emit_stm(2,$2.var_tabs[i]->var_type->base,$2.var_tabs[i]->var);
            $$.next_addr=make_list(Wait);
            }
VARIABLES : VARIABLES ',' VARIABLE {
            int i;
            $$.var_tabs=$1.var_tabs;
            if($1.cont>=MAX_PARA_CONT)
            {
                my_yyerror(1,"define variable too much");
            }
            $$.var_tabs[$1.cont]=$3.var_tab;
            $$.cont=$1.cont+1;
}
            |VARIABLE     {
                //最多支持一行定义10个变量
                $$.var_tabs=(var_symtab_type**)malloc(sizeof(var_symtab_type*)*MAX_PARA_CONT);
                $$.var_tabs[0]=$1.var_tab;
                $$.cont=1;
            }
VARIABLE : ID {
    //变量定义时未赋初始值
            struct variable_type* temp_type=creat_variable_type(); 
            var_symtab_type* temp=creat_symtab($1.var,temp_type);
            temp->width=1;
            $$.var_tab=temp;
        }
         | ID  EQUAL EXPRESSION {
             //变量定义时赋予了初始值
            var_symtab_type* temp=creat_symtab($1.var,$3.var_type);
            if(strcmp(temp->var_type->exten,$3.var_type->exten)!=0)
            {
                my_yyerror(1,"EXPRESSION retrun type dismatch");
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
                my_yyerror(1,"EXPRESSION retrun type dismatch");
            }
            temp->var_type->base=$4.var_type->base;
            temp->value=$4.var;
            temp->width=1; 
            $$.var_tab=temp;
         }
         | ID ARRS EQUAL LIST{
             //定义数组并初始化，还未实现

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
    //初始化数组变量，还没实现


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
            $$.true_addr=make_list(Wait);
            $$.false_addr=make_list(Wait);
            debug(1," ***FUNCTIONCALL*** ");
            }
            |ID EQUAL EXPRESSION {
                struct var_symtab* temp_id=query_var_sym($1.var);
                if(temp_id==(struct var_symtab*)0)
                {
                    my_yyerror(2,"no such variable:",$1.var);
                    exit(1);
                }
                if(typecmp(temp_id->var_type,$3.var_type)!=0)
                {
                    my_yyerror(1,"can not assign such type ");
                }
                assign_addr($3.next_addr,emit_stm(3,temp_id->var,"=",$3.var));
                $$.addr=$3.addr;
                $$.next_addr=make_list(Wait);
                $$.var=$1.var;
                $$.var_type=$3.var_type;
                debug(2,"ID EQUAL EXPRESSION",get_value($$.addr));
                $$.true_addr=$3.true_addr;
                $$.false_addr=$3.false_addr;
            }
            |VALUE{
                debug(2,"EXPRESSION:VALUE:",$1.value);
                $$.var=$1.value;
                $$.next_addr=make_list(Wait);
                $$.addr=$$.next_addr;
                $$.var_type=creat_variable_type();
                $$.var_type->base=$1.value_type;
                $$.true_addr=make_list(Wait);
                $$.false_addr=make_list(Wait);

            }
            |EXPRESSION OPERATOR1 EXPRESSION {
                $$.var=creat_temp_name();
                backPatch($1.next_addr,$3.addr);
                $$.addr=$1.addr;
                assign_addr($3.next_addr,emit_stm(5,$$.var,"=",$1.var,$2.name,$3.var));
                $$.next_addr=make_list(Wait);
                $$.var_type=handle_type($1.var_type,$3.var_type);
                $$.true_addr=$1.true_addr;
                $$.false_addr=$1.false_addr;
                if($3.true_addr)
                    free($3.true_addr);
                if($3.false_addr)
                    free($3.false_addr);                
                debug(2,"EXPRESSION OPERATOR1 EXPRESSION:",get_value($$.addr));
            }
            |EXPRESSION OPERATOR2 EXPRESSION {
                // 为了体现优先级，将"* /"和"+ -"分开
                debug(1,"EXPRESSION OPERATOR2 EXPRESSION\n");
                $$.var=creat_temp_name();
                $$.addr=$1.addr;
                backPatch($1.next_addr,$3.addr);
                assign_addr($3.next_addr,emit_stm(5,$$.var,"=",$1.var,$2.name,$3.var));
                $$.next_addr=make_list(Wait);
                $$.var_type=handle_type($1.var_type,$3.var_type);
                $$.true_addr=$1.true_addr;
                $$.false_addr=$1.false_addr;
                if($3.true_addr)
                    free($3.true_addr);
                if($3.false_addr)
                    free($3.false_addr); 
                debug(2,"EXPRESSION OPERATOR1 EXPRESSION:",get_value($$.addr));
            }
            |OPERATOR2 EXPRESSION{
                $$.var=creat_temp_name();
                $$.addr=make_list(emit_stm(4,$$.var,"=",$1.name,$2.var));
                backPatch($2.next_addr,$$.addr);
                $$.next_addr=make_list(Wait);
                $$.var_type=$2.var_type;
                $$.true_addr=$2.true_addr;
                $$.false_addr=$2.false_addr;
            }
            |T_BOOL_OPERATOR EXPRESSION{
                //支持单个变量的!运算
                $$.var=creat_temp_name();
                $$.addr=make_list(emit_stm(4,$$.var,"=",$1.name,$2.var)); 
                backPatch($2.next_addr,$$.addr);
                $$.next_addr=make_list(Wait);
                $$.var_type=creat_variable_type();
                $$.var_type->base="bool";
                if(strcmp($1.name,"!")==0){
                    $$.true_addr=$2.false_addr;
                    $$.false_addr=$2.true_addr;
                }            
            }
            |L {
                $$.var_type=$1.var_type;
                $$.var=creat_temp_name();
                $$.addr=make_list(emit_stm(6,$$.var,"=",$1.base,"[",$1.var,"]"));
                $$.next_addr=make_list(Wait);
                $$.true_addr=make_list(Wait);
                $$.false_addr=make_list(Wait);               
            }
            |ID T_INCRDECR {
                $$.var_type=creat_variable_type();
                $$.var_type->base="int";
                $$.next_addr=make_list(Wait);
                $$.var=creat_temp_name();
                $$.addr=make_list(emit_stm(3,$$.var,"=",$1.var));
                if(strcmp($2.name,"++")==0)
                    emit_stm(5,$1.var,"=",$1.var,"+","1");
                else 
                    emit_stm(5,$1.var,"=",$1.var,"-","1"); 
                $$.true_addr=make_list(Wait);
                $$.false_addr=make_list(Wait);
            }
            |T_INCRDECR ID {
                $$.var_type=creat_variable_type();
                $$.var_type->base="int";
                $$.next_addr=make_list(Wait);
                $$.var=creat_temp_name();
                if(strcmp($1.name,"++")==0)
                    $$.addr= make_list(emit_stm(5,$2.var,"=",$2.var,"+","1"));
                else
                    $$.addr= make_list(emit_stm(5,$2.var,"=",$2.var,"-","1"));
                emit_stm(3,$$.var,"=",$2.var);
                $$.true_addr=make_list(Wait);
                $$.false_addr=make_list(Wait); 
               
            }    
            |'(' EXPRESSION ')' {
                debug(1,"EXPRESSION");
                $$.var_type=$2.var_type;
                $$.var=creat_temp_name();
                $$.addr=make_list(emit_stm(3,$$.var,"=",$2.var));
                $$.next_addr=make_list(Wait);  
                $$.true_addr=$2.true_addr;
                $$.false_addr=$2.false_addr; 
            }
            | ID {
                debug(1,"ID");
                var_symtab_type* temp=query_var_sym($1.var);
                if(temp==(var_symtab_type*)0)
                {
                    my_yyerror(3,"no such variable",$1.var,"exit with erro code 1");
                    exit(1);
                }  
                $$.var=$1.var;
                $$.next_addr=make_list(Wait);
                $$.addr=$$.next_addr;
                $$.var_type=temp->var_type;
                debug(3,"ID end:",temp->var_type->base,temp->var);
                $$.true_addr=make_list(Wait);
                $$.false_addr=make_list(Wait);
            }
            |EXPRESSION T_BOOL_OPERATOR EXPRESSION    {    
                //表达式之间的逻辑运算             
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
                else
                {
                    //两个表达式能进行的逻辑运算只有$$和||
                    my_yyerror(4,"can not compute:",$1.var,$2.name,$3.var);
                    exit(1);
                }
                $$.var=creat_temp_name();
                $$.addr=$1.addr;
                assign_addr($3.next_addr,emit_stm(5,$$.var,"=",$1.var,$2.name,$3.var));
            }
            |EXPRESSION T_RELATION EXPRESSION {
                //表达式之间的关系运算
                $$.var=creat_temp_name();
                $$.addr=$1.addr;
                assign_addr($3.next_addr,emit_stm(5,$$.var,"=",$1.var,$2.name,$3.var));
                backPatch($1.next_addr,$3.addr);
                $$.true_addr=make_list(Wait);
                $$.false_addr=make_list(Wait);
            }
L :L '[' EXPRESSION ']' {
        backPatch($1.next_addr,$3.addr);
        $$.var=creat_temp_name();
        struct var_symtab* temp=query_var_sym($1.var); 
        $$.var_type=$1.var_type;
        $$.addr=make_list(emit_stm(5,$$.var,"=",$3.var,"*",itoa(temp->width)));
        emit_stm(5,$$.var,"=",$1.var,"+",$$.var);
        backPatch($3.next_addr,$$.addr);
        $$.next_addr=make_list(Wait);
        }
    | ID '[' EXPRESSION ']'{
        $$.base=$1.var;
        $$.var=creat_temp_name();
        $$.next_addr=make_list(Wait);
        if(strcmp($3.var_type->base,"int")!=0)
        {
            my_yyerror(2,"index erro type",$3.var_type->base);
        }
        struct var_symtab* temp=query_var_sym($1.var); 
        debug(3,"L:base:",temp->var_type->base,temp->var_type->exten);
        if(temp==(var_symtab_type*)0||strcmp(temp->var_type->exten,"arrary")!=0)
        {
            my_yyerror(2,"such id is not array",$1.var);
        }
        $$.var_type=temp->var_type;
        $$.addr=make_list(emit_stm(5,$$.var,"=",$3.var,"*",itoa(get_width_by_type(temp->elem_type))));
        backPatch($3.next_addr,$$.addr);
    }

          
VALUE : INT_VALUE      {
        //定义了值类型,包括整数，浮点数bool，字符串
        $$.value=$1.value;$$.value_type=strdup("int");}
        |FLOAT_VALUE   {$$.value=$1.value;$$.value_type=strdup("float");}
        |BOOL_VALUE    {$$.value=$1.value;$$.value_type=strdup("bool");}
        |STRING        {$$.value=$1.value;$$.value_type=strdup("string");}
        
FUNCTIONCALL: ID '(' ACT_PARAS ')' {
            //支持函数调用
                    if(func_env!=0)
                        debug(1,func_env->name);
                    func_symtab_type* temp_func=query_fuc_sym($1.var);
                    if(temp_func==(func_symtab_type*)0)
                    {
                        my_yyerror(2,"no such function:",$1.var);
                        exit(1);
                    }
                    else
                    {
                        $$.return_type=temp_func->return_type;
                        debug(1,"1");
                        int i;
                        if($3.para_cont>0)
                        {
                            if(typecmp(temp_func->paras_type[0],$3.paras_type[0])!=0)
                                my_yyerror(3,"para type dismatch",temp_func->paras_type[i]->base,$3.paras_type[i]->base);
                            else
                                $$.addr=make_list(emit_stm(2,"push",$3.paras_name[0])) ;
                            for(i=1;i<temp_func->para_cont;i++)
                            {
                                if(typecmp(temp_func->paras_type[i],$3.paras_type[i])!=0)
                                    my_yyerror(3,"para type dismatch1:",temp_func->paras_type[i]->base,$3.paras_type[i]->base);
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
    //函数调用时传递的实参
            if($1.para_cont==0)
                my_yyerror(1,"void follow no void");
            $$.paras_name=$1.paras_name;
            $$.paras_type=$1.paras_type;
            $$.paras_type[$1.para_cont]=$3.var_type;
            $$.paras_name[$1.para_cont]=$3.var;
            $$.para_cont=$1.para_cont+1;
            }
            | ACT_PARA   {
                debug(1,"ACT_PARAS ");
                $$.paras_type=(struct variable_type**)malloc(sizeof(struct variable_type*)*MAX_PARA_CONT);
                if($$.paras_type==(struct variable_type**)0)
                {
                    my_yyerror(1,"ACT_PARA malloc erro");
                    exit(1);
                }    
                $$.paras_name=(char**)malloc(sizeof(char*)*MAX_PARA_CONT);
                if($$.paras_name==(char**)0)
                {
                    my_yyerror(1,"ACT_PARA malloc erro");
                    exit(1);
                }    
                $$.para_cont=1;
                $$.paras_type[0]=$1.var_type;
                $$.paras_name[0]=$1.var;
            }
            |   {   
                    $$.para_cont=0;
                }
    
ACT_PARA :EXPRESSION {
                debug(1,"ACT_PARA :EXPRESSION");
                $$.var=$1.var;
                $$.var_type=$1.var_type;
           }
         
IF_BLOCK :  IF_PREFIX STATEMENT %prec LOWER_THAN_ELSE {
                $$.addr=$1.addr;
                if(strcmp(get_value($2.addr),Wait)==0)
                {
                    debug(1,"come yes");
                    merge($1.false_addr,$1.true_addr);
                    merge($2.next_addr,$1.false_addr);
                }
                else
                {
                    backPatch($1.true_addr,$2.addr);
                    merge($2.next_addr,$1.false_addr);
                }
                $$.next_addr=$2.next_addr;
                $$.var_type=$2.var_type;
                debug(1,"_____if acc_____");
                }
            | IF_PREFIX STATEMENT  ELSE STATEMENT     {
                $$.addr=$1.addr;
                if(strcmp(get_value($2.addr),Wait)==0&&strcmp(get_value($4.addr),Wait)==0)
                {
                    //两个STATEMENT均为空
                    merge($2.addr,$1.true_addr);
                    merge($4.next_addr,$1.false_addr);
                    merge($1.true_addr,$4.next_addr);
                    $$.next_addr=$1.true_addr; 
                }
                else if(strcmp(get_value($2.addr),Wait)==0)
                {
                    //第一个STATEMENT为空

                    merge($2.addr,$1.true_addr);
                    merge($4.next_addr,$2.next_addr);
                    backPatch($1.false_addr,$4.addr);
                    $$.next_addr=$4.next_addr;       
                }
                else if(strcmp(get_value($4.addr),Wait)==0)
                {
                    //第二个STATEMENT为空
                    backPatch($1.true_addr,$2.addr);
                    merge($4.next_addr,$1.false_addr);
                    merge($2.next_addr,$4.next_addr);
                    $$.next_addr=$2.addr;
                }
                else
                {
                    //均不为空，回填true_addr和false_addr
                    backPatch($1.true_addr,$2.addr);
                    backPatch($1.false_addr,$4.addr);
                    merge($2.next_addr,$4.next_addr);
                    $$.next_addr=$2.next_addr;
                }
                if($4.var_type!=(struct variable_type*)0)
                    $$.var_type=$4.var_type;
                else
                    $$.var_type=$2.var_type;
                debug(1,"_____if acc_____");
            }
IF_PREFIX: IF '(' EXPRESSION ')' {
        debug(1,"IF '(' EXPRESSION ')'");
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
                debug(1,"_______while acc________");
                $$.var_type=$2.var_type;
                }
WHILE_PREFIX : WHILE '(' EXPRESSION ')' {
        debug(1,"WHILE '(' EXPRESSION ')'\n");
        enter_while++;
        $$.addr=$3.addr;
        continue_addr=$3.addr;
        $$.true_addr=$3.true_addr;
        $$.false_addr=$3.false_addr;
        emit_stm(4,"if",$3.var,"goto ",emit_stm_ready($3.true_addr));
        emit_stm(2,"goto ",emit_stm_ready($3.false_addr)); 
        break_addr=$3.false_addr;
        debug(2,"*****WHILE_PREFIX****",get_value(break_addr));
}
FOR_BLOCK : FOR_PREFIX  FOR_ITERATES ')' STATEMENT {
                //减少循环的层数
                    enter_while--;
                    backPatch($1.true_addr,$4.addr);
                    backPatch($4.next_addr,$2.addr);
                    backPatch($2.next_addr,$1.addr);
                    $$.addr=$1.addr;
                    $$.next_addr=$1.false_addr;
                    debug(1,"____for acc_____");
                    emit_stm(2,"goto ",get_value($2.addr)); 
                    $$.var_type=$4.var_type;
}
FOR_PREFIX : FOR '(' FOR_INITIALS ';' EXPRESSION ';' {
        debug(1,"FOR '(' FOR_INITIALS ';' EXPRESSION\n");
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
            //for循环的初始条件,每一个循环都只执行一次
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
                debug(1,"FOR_INITIAL EXPRESSION\n");
                $$.addr=$1.addr;
                $$.next_addr=$1.next_addr;
            }
FOR_ITERATES: FOR_ITERATE {
            //for循环的循环执行判断,与FOR_INITIALS不同,循环执行多少次,这里的语句就会执行多少次
            $$.addr=$1.addr;
            $$.next_addr=$1.next_addr;
            emit_stm(2,"goto ",emit_stm_ready($1.next_addr));     
}
            | {
                $$.next_addr=make_list(Wait);
                $$.addr=make_list(emit_stm(2,"goto ",emit_stm_ready($$.next_addr)));
            }

FOR_ITERATE :FOR_ITERATE ','  EXPRESSION {
            $$.addr=$1.addr;
            backPatch($1.next_addr,$3.addr);
            $$.next_addr=$3.next_addr;  
}
            |EXPRESSION  {
                debug(1,"FOR_ITERATE EXPRESSION\n");

                $$.addr=$1.addr;
                $$.next_addr=$1.next_addr;
            }
%%


//插入变量符号表项到变量符号表中,如果已经存在同样的变量返回ALREAY_EXIST
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
//将结构体符号表项插入带函数符号表，如果结构体符号表中已经存在对应的符号表项，则返回错误标记ALREAY_EXIST
int var_sym_look(var_symtab_type* var_sym)
{
    var_symtab_type* var_tab=var_env; 
    while(var_tab!=(var_symtab_type*)0) {  
        if(strcmp(var_tab->var,var_sym->var)==0) 
            return ALREAY_EXIST;
        var_tab=var_tab->next;
        }
    var_sym->next=var_env;
    var_env=var_sym;
    return ERRO_NONE;
}
//将函数符号表项插入带函数符号表，如果函数符号表中已经存在对应的符号表项，则返回错误标记ALREAY_EXIST
int str_sym_look(char* sym_name,str_symtab_type* str_tab)
{
    str_symtab_type* str_tab_pointer=str_env; 
    while(str_tab_pointer!=(str_symtab_type*)0) {  
        if(str_tab_pointer->var==str_tab->var) 
            return ALREAY_EXIST;
        str_tab_pointer=str_tab_pointer->next;
        }
    str_tab->next=str_env;
    str_env=str_tab;
    return ERRO_NONE;
}
int func_sym_look(char* sym_name,func_symtab_type* func_tab_para)
{
    if(!func_tab_para)
    {
        debug(1,"func_tab_para is null ");
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
//查询符号表是否存在给定名字的函数
func_symtab_type* query_fuc_sym(char* sym_name)
{
    func_symtab_type* func_tab=func_env; 
    while(func_tab!=(func_symtab_type*)0) { 
         debug(2,"query_fuc_sym:",func_tab->name); 
        if(strcmp(func_tab->name,sym_name)==0) 
        {
            debug(2,"find func ",sym_name);
            return func_tab;
        }    
        func_tab=func_tab->next;
    }
    return (func_symtab_type*)0;
}
//查询符号表是否存在给定名字的变量
var_symtab_type* query_var_sym(char* sym_name)
{
    debug(2,"query_var_sym:",sym_name);
    var_symtab_type* var_tab=var_env;  
    while(var_tab!=(var_symtab_type*)0) {  
        if(strcmp(var_tab->var,sym_name)==0) 
        {
            debug(1,"find end\n");
            return var_tab;
        }
        var_tab=var_tab->next;
        }
    stack* temp_st=creatStack();
    var_symtab_type* temp_env=var_env;
    while(!stack_isEmpty(st))
    {
        temp_env=pop(st);
        push(temp_st,temp_env);
        var_tab=temp_env;
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
    debug(1,"not found end\n");
    return (struct var_symtab*)0;
}

//输出中间代码，如果某一行中间代码有地址需要回填或者当前中间代码的队列不为空，则将中间代码装入队列中
char* emit_stm(int num,...)
{
    debug(1,"emit_stm:");
    if(num>MAX_STMT_LENGTH)
    {
        debug(1,"too much stmt");
    }
    va_list args;
    int i;
    va_start(args,num);
    char has_wait=0;
    char** res=(char**)malloc(sizeof(char*)*MAX_STMT_LENGTH);
    for(i=0;i<MAX_STMT_LENGTH;i++)
        res[i]=NO_STMT;
    res[0]=strdup(itoa(temp_add_value));
    temp_add_value++; 
    for(i=1;i<=num;i++)
    {
        res[i]=va_arg(args,char*);
        debug(1,res[i]);
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
    debug(1,"end\n");
    return res[0];
}
//检查某个要输出的中间代码是否存在没有回填的地址
bool check_stmt_ready()
{
    if(queue_isEmpty(stmt_queue))
    {
        return false;
    }
    debug(1,"check_stmt_ready\n");    
    char** stmt_head=getHead(stmt_queue);

    int i;
    for(i=0;i<MAX_STMT_LENGTH&&stmt_head[i]!=NO_STMT;i++)
    {
        if(strcmp(stmt_head[i],waitpatch)==0)
            return false;
    }
     debug(1,"end\n");
    return true;
}
//将存在队列头部的中间代码输出到文件
void emit_stm_head()
{
    debug(1,"emit_stm_head\n");
    if(queue_isEmpty(stmt_queue))
        debug(1,"queue is Empty");
    char** stmt_head=dequeue(stmt_queue);
    int i;
    for(i=0;i<MAX_STMT_LENGTH&&stmt_head[i]!=NO_STMT;i++)
        fprintf(file,"%s ",stmt_head[i]);
    fputs("\n",file);
    debug(1,"end\n");
}
//将数字转为字符串,并链接到某个字符串后,创建临时变量会调用
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
//创建一个临时变量的名字tx;
char* creat_temp_name()
{
    char* temp=(char*)malloc(sizeof(char)*5);
    temp[0]='t';
    temp=strcat_int(temp,1,temp_lab_value);
    temp_lab_value++;
    return temp;
}
int main()
{
    //
    if((file=fopen(OUTPUT_PATH,"w"))==NULL)
    {
        my_yyerror(1,"can not open ouput file");
        exit(1);
    }    
    if((stmt_queue=creatQueue())==NULL)
    {
        debug(1,"can not creat queue");
    }
    str_env=(str_symtab_type*)0;
    func_env=(func_symtab_type*)0;
    var_env=(var_symtab_type*)0;
    st=creatStack();
    void_type=creat_variable_type();
    int errono=yyparse();
    if(errono==0)
    {
        my_info(1,"congratulations, build successfully!!!!!");
        my_info(2,"output file saved in",OUTPUT_PATH);
    }   
    else
        my_info(1,"build not successfully, please check the code");
    return errono;
}
//创建一个表示地址的列表
addr_type* make_list(char* content)
{
	addr_type* temp=(addr_type*)malloc(sizeof(addr_type));
    temp->is_top=1;
    temp->content=content;
    temp->upper=(addr_type*)0;
    return temp;    
}
//地址列表的操作，
addr_type* find_top(addr_type* list)
{
    if(!list)
    {
        debug(1,"list empty");
    }
    while(list->upper!=(addr_type*)0)
        list=list->upper;
    return list;
}
//用一个已知的地址来回填某个地址
void assign_addr(addr_type* list,char* instr)
{
    debug(1,"assign_addr");
    addr_type* list_temp=find_top(list);
    list_temp->content=instr;
    debug(1,"end");
}
//实现针对于地址列表的类似于并查集的merge操作
void merge(addr_type* list1,addr_type* list2)
{
    debug(3,"merge:",get_value(list1),get_value(list2));
    list1->upper=list2;
}
//返回某一地址列表的内容
char* get_value(addr_type* list)
{
	return find_top(list)->content;
}
//回填某一列地址
void backPatch(addr_type* list,addr_type* instr)
{
    debug(4,"backPatch:",list->content,get_value(list),get_value(instr));
    addr_type* list_temp=find_top(list);
    addr_type* instr_temp=find_top(instr);
    list_temp->upper=instr_temp;
    while(list!=(addr_type*)0)
    {
        if(strcmp(list->content,waitpatch)==0&&strcmp(get_value(instr),Wait)!=0)
            strcpy(list->content,get_value(instr));
        debug(2,"strcmp:",list->content);
        list=list->upper;
    }    
    while(check_stmt_ready())
        emit_stm_head();
    debug(1,"end\n");
}
//创建一个变量类型
struct variable_type* creat_variable_type()
{
    struct variable_type* temp_type=(struct variable_type*)malloc(sizeof(struct variable_type));
    temp_type->exten=Void;
    temp_type->base=Void;
    return temp_type;
}
//创建符号表的一项
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

//两个类型operate时返回的类型
struct variable_type* handle_type(struct variable_type* a,struct variable_type* b)
{
    return a;
}
//比较两个类型是否能够匹配
char typecmp(struct variable_type* one,struct variable_type* other)
{
    if(!one||!other)
        debug(1,"typecmp: one or other is Empty");
    if(get_width_by_type(one)<get_width_by_type(other))
        return 1;
    return 0;
}
//创建函数符号表的数据结构
func_symtab_type* creat_func_env()
{

    func_symtab_type* temp=(func_symtab_type* )malloc(sizeof(func_symtab_type));
    return temp;
}
var_symtab_type * creat_var_env()
{
    var_symtab_type* tab=(var_symtab_type *)malloc(sizeof( var_symtab_type));
    return tab;
}
str_symtab_type* creat_str_env()
{
    str_symtab_type* tab=(str_symtab_type *)malloc(sizeof( str_symtab_type));

}
//当创建一个需要被回填的地址时调用这个函数
char* emit_stm_ready(addr_type* addr)
{
    debug(1,"emit_stm_ready\n");
    if(!addr)
    {
        debug(1,"emit_stm_ready:addr is null \n exit with erro code 1");
        exit(1);
    }
    addr->content =(char*)malloc(sizeof(char)*10);
    strcpy(addr->content,"waitpatch");
    debug(1,"end\n");
    return  addr->content;
}
//输出调试信息
void debug(int num,...)
{
    #if DEBUG
    printf("debug:");
    va_list args;
    int i;
    va_start(args,num);
    for(i=0;i<num;i++)
    {
        printf("%s ",va_arg(args,const char*));
    }
    printf("\n");
    #endif
}
//输出错误信息,代码中显式调用
void my_yyerror(int num,...)
{
    printf("erro: line:%d ",line);
    va_list args;
    int i;
    va_start(args,num);
    for(i=0;i<num;i++)
    {
        printf("%s ",va_arg(args,const char*));
    }
    printf("\n");
}
//输出错误信息,由yyparse遇到语法错误时自动调用
void yyerror(const char* msg)
{
    printf("erro: line:%d %s\n",line,msg); 
}
//输出警告信息
void my_warrning(int num,...)
{
    printf("warrning: line:%d ",line);
    va_list args;
    int i;
    va_start(args,num);
    for(i=0;i<num;i++)
    {
        printf("%s ",va_arg(args,const char*));
    }
    printf("\n");    
}
//输出提示信息
void my_info(int num,...)
{
    printf("INFO:");
    va_list args;
    int i;
    va_start(args,num);
    for(i=0;i<num;i++)
    {
        printf("%s ",va_arg(args,const char*));
    }
    printf("\n");    
}