/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
#include "include.h"
/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    LOWER_THAN_ELSE = 258,
    ELSE = 259,
    ID = 260,
    EQUAL = 261,
    T_BOOL_OPERATOR = 262,
    T_RELATION = 263,
    OPERATOR2 = 264,
    OPERATOR1 = 265,
    T_BIT_OPERATOR = 266,
    TYPE_BASE = 267,
    INT_VALUE = 268,
    STRING = 269,
    FLOAT_VALUE = 270,
    BOOL_VALUE = 271,
    T_INCRDECR = 272,
    IF = 273,
    STRUCT = 274,
    WHILE = 275,
    BREAK = 276,
    FOR = 277,
    RETURN = 278,
    T_SEPERATOR = 279,
    CONTINUE = 280
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 28 "./src/parser.y" /* yacc.c:1909  */

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

#line 179 "parser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
