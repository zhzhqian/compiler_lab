/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

	#include <bits/stdc++.h>
	#include "symboltable.h"
	#include "lex.yy.c"

	using namespace std;

	int yyerror(char *msg);

	#define SYMBOL_TABLE symbol_table_list[current_scope].symbol_table

  	extern entry_t** constant_table;

	int current_dtype; /*当前识别到的数据类型*/

	table_t symbol_table_list[NUM_TABLES]; /*在symboltable.h中声明的外部变量的定义*/

	int is_declaration = 0;
	int is_loop = 0;
	int is_func = 0;
	int func_type;

	int param_list[10];  /*参数列表*/
	int p_idx = 0;  /*param_list中当前实际用到的参数个数*/
	int p=0;   /*用于标记是否进入了一个新的作用域，需要开启新的符号表*/
  	int rhs = 0; /*右值*/

	/*函数声明*/
	void type_check(int,int,int);  /*类型检查*/
	vector<int> merge(vector<int>& v1, vector<int>& v2);  /*合并两个链（回填时用到）*/
	void backpatch(vector<int>&, int);  /*回填*/
	void gencode(string); /*根据传进来的字符串生成中间代码*/
	void gencode_math(content_t* & lhs, content_t* arg1, content_t* arg2, const string& op);
	void gencode_rel(content_t* & lhs, content_t* arg1, content_t* arg2, const string& op);

	int nextinstr = 0;  /*中间代码中，下一条指令的指令号*/
	int temp_var_number = 0;   /*临时变量的数量，即三地址代码中的t0、t1...*/

	vector<string> ICG;  /*记录生成的中间代码*/


#line 108 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    DEC_CONSTANT = 259,
    HEX_CONSTANT = 260,
    CHAR_CONSTANT = 261,
    FLOAT_CONSTANT = 262,
    STRING = 263,
    LOGICAL_AND = 264,
    LOGICAL_OR = 265,
    LS_EQ = 266,
    GR_EQ = 267,
    EQ = 268,
    NOT_EQ = 269,
    MUL_ASSIGN = 270,
    DIV_ASSIGN = 271,
    MOD_ASSIGN = 272,
    ADD_ASSIGN = 273,
    SUB_ASSIGN = 274,
    INCREMENT = 275,
    DECREMENT = 276,
    SHORT = 277,
    INT = 278,
    LONG = 279,
    LONG_LONG = 280,
    SIGNED = 281,
    UNSIGNED = 282,
    CONST = 283,
    VOID = 284,
    CHAR = 285,
    FLOAT = 286,
    CHAR_STAR = 287,
    IF = 288,
    FOR = 289,
    WHILE = 290,
    CONTINUE = 291,
    BREAK = 292,
    RETURN = 293,
    UMINUS = 294,
    LOWER_THAN_ELSE = 295,
    ELSE = 296
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define DEC_CONSTANT 259
#define HEX_CONSTANT 260
#define CHAR_CONSTANT 261
#define FLOAT_CONSTANT 262
#define STRING 263
#define LOGICAL_AND 264
#define LOGICAL_OR 265
#define LS_EQ 266
#define GR_EQ 267
#define EQ 268
#define NOT_EQ 269
#define MUL_ASSIGN 270
#define DIV_ASSIGN 271
#define MOD_ASSIGN 272
#define ADD_ASSIGN 273
#define SUB_ASSIGN 274
#define INCREMENT 275
#define DECREMENT 276
#define SHORT 277
#define INT 278
#define LONG 279
#define LONG_LONG 280
#define SIGNED 281
#define UNSIGNED 282
#define CONST 283
#define VOID 284
#define CHAR 285
#define FLOAT 286
#define CHAR_STAR 287
#define IF 288
#define FOR 289
#define WHILE 290
#define CONTINUE 291
#define BREAK 292
#define RETURN 293
#define UMINUS 294
#define LOWER_THAN_ELSE 295
#define ELSE 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 44 "parser.y" /* yacc.c:355  */

	int data_type;
	entry_t* entry;
	content_t* content;
	string* op;  /*操作符*/
	vector<int>* nextlist;
	int instr;   /*指令号*/

#line 239 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 256 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  34
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   421

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  120
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  196

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,     2,     2,    47,     2,     2,
      52,    53,    45,    43,    39,    44,     2,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    56,
      41,    40,    42,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,    55,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   120,   120,   121,   124,   125,   130,   138,   129,   151,
     152,   155,   156,   159,   160,   163,   164,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   182,   183,
     186,   187,   191,   198,   199,   206,   204,   223,   231,   235,
     241,   247,   252,   253,   254,   263,   271,   278,   289,   289,
     289,   302,   312,   325,   325,   325,   337,   338,   339,   342,
     343,   346,   347,   348,   352,   359,   362,   368,   378,   384,
     391,   398,   405,   412,   419,   429,   439,   447,   453,   458,
     467,   477,   487,   494,   507,   515,   523,   531,   539,   540,
     543,   562,   563,   564,   565,   566,   567,   571,   579,   587,
     595,   603,   611,   619,   630,   637,   645,   646,   647,   648,
     651,   678,   679,   682,   690,   700,   701,   704,   709,   716,
     719
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "DEC_CONSTANT",
  "HEX_CONSTANT", "CHAR_CONSTANT", "FLOAT_CONSTANT", "STRING",
  "LOGICAL_AND", "LOGICAL_OR", "LS_EQ", "GR_EQ", "EQ", "NOT_EQ",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "INCREMENT", "DECREMENT", "SHORT", "INT", "LONG", "LONG_LONG", "SIGNED",
  "UNSIGNED", "CONST", "VOID", "CHAR", "FLOAT", "CHAR_STAR", "IF", "FOR",
  "WHILE", "CONTINUE", "BREAK", "RETURN", "','", "'='", "'<'", "'>'",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "UMINUS", "LOWER_THAN_ELSE",
  "ELSE", "'('", "')'", "'{'", "'}'", "';'", "'['", "']'", "$accept",
  "starter", "builder", "function", "$@1", "$@2", "type", "pointer",
  "data_type", "sign_specifier", "type_specifier", "argument_list",
  "arguments", "arg", "stmt", "compound_stmt", "$@3", "statements",
  "single_stmt", "for_block", "$@4", "$@5", "if_block", "while_block",
  "$@6", "$@7", "declaration", "declaration_list", "sub_decl",
  "expression_stmt", "expression", "sub_expr", "assignment_expr",
  "unary_expr", "lhs", "identifier", "assign", "arithmetic_expr",
  "constant", "array_access", "array_index", "function_call",
  "parameter_list", "parameter", "M", "N", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,    44,
      61,    60,    62,    43,    45,    42,    47,    37,    33,   294,
     295,   296,    40,    41,   123,   125,    59,    91,    93
};
# endif

#define YYPACT_NINF -136

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-136)))

#define YYTABLE_NINF -89

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     343,  -136,    13,    13,    -4,  -136,     4,     8,  -136,  -136,
    -136,  -136,  -136,  -136,   327,  -136,  -136,    13,    20,   373,
    -136,  -136,    -9,  -136,  -136,   -24,   361,   234,    49,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,   113,   109,    20,  -136,
    -136,    13,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
       2,  -136,  -136,   408,  -136,    44,  -136,  -136,    74,  -136,
    -136,  -136,  -136,   256,   256,  -136,    -8,   374,  -136,  -136,
    -136,  -136,  -136,    14,   359,  -136,  -136,   363,   120,   256,
     256,   256,   256,   256,  -136,    13,    16,    38,  -136,  -136,
    -136,   237,  -136,   303,  -136,  -136,   286,   374,  -136,   -10,
    -136,   145,   145,  -136,  -136,  -136,  -136,  -136,   359,  -136,
    -136,  -136,   237,   237,   237,   237,   237,   237,   231,  -136,
      47,  -136,   237,   237,  -136,  -136,    75,    75,  -136,  -136,
    -136,  -136,  -136,   320,    25,  -136,    52,  -136,   195,    57,
      60,  -136,    48,    63,    54,    13,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,   123,    64,   237,   130,    90,  -136,  -136,
    -136,   255,  -136,    17,   303,  -136,  -136,   114,   237,  -136,
     237,  -136,   130,  -136,    23,   303,   195,  -136,  -136,   103,
     237,  -136,  -136,    58,   195,  -136,  -136,  -136,   195,  -136,
    -136,  -136,  -136,   195,  -136,  -136
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    90,     0,     0,    19,    17,    20,    22,    15,    16,
      26,    24,    25,    27,     0,     3,     4,     0,    10,     0,
      14,     5,     0,    60,    61,     0,     0,    88,    89,    87,
      86,    18,    21,    23,     1,     2,     0,    88,    12,     9,
      13,     0,    57,    58,    94,    95,    96,    92,    93,    91,
       0,    84,    85,     0,    56,     0,    11,    59,    88,   106,
     107,   108,   109,     0,     0,    83,   104,    80,   105,    81,
      82,   112,   111,     0,    29,   104,   103,     0,     0,     0,
       0,     0,     0,     0,   110,     0,     0,    28,    31,   102,
     118,     0,   114,   117,    78,    79,   104,    77,    89,     0,
     116,    97,    98,    99,   100,   101,    32,     7,     0,    76,
     119,   119,     0,     0,     0,     0,     0,     0,     0,   113,
       0,    30,     0,     0,    73,    72,    70,    71,    69,    68,
     115,    35,     8,    74,    75,    38,   119,    36,     0,     0,
       0,   119,     0,     0,     0,     0,    37,    33,    34,    40,
      39,    41,    42,    88,     0,     0,     0,     0,    45,    46,
      44,     0,    43,     0,    67,    65,   119,     0,     0,    47,
       0,   119,     0,    64,     0,    66,     0,   119,   119,    51,
       0,    53,   120,     0,     0,   119,    48,    54,     0,   120,
      55,    52,   119,     0,    49,    50
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,   141,  -136,  -136,  -136,    10,   119,  -136,  -136,
     139,  -136,  -136,    55,    94,    40,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,    26,   -13,   126,    -1,
    -135,   -23,    11,    21,  -136,     0,  -136,   259,   128,     1,
    -136,   133,  -136,    78,   -63,    12
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    14,    15,    16,    55,   120,   145,    39,    18,    19,
      20,    86,    87,    88,   146,   147,   135,   136,   148,   149,
     189,   195,   150,   151,   184,   190,   152,    22,    23,   166,
     167,   164,    94,    95,    26,    96,    50,    97,    68,    98,
      73,   154,    99,   100,   122,   185
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,    28,    29,    30,    36,     1,    59,    60,    61,    62,
      17,    24,    51,    52,    27,    28,     1,    37,    28,    31,
     163,    25,     2,     3,    17,    24,    21,    32,    24,   118,
      41,    33,    43,   174,   110,    25,   112,   113,   114,   115,
      21,    58,    28,   119,    78,   183,    63,    42,   123,    53,
      66,    69,    24,    71,    64,    93,   170,     1,    59,    60,
      61,    62,   170,    75,    75,    38,   116,   117,   109,   107,
     171,    65,    84,   138,     2,     3,   178,   108,   157,    75,
      75,    75,    75,    75,    85,   106,   112,   113,   -63,   124,
     125,   126,   127,   128,   129,    93,    74,   170,    63,   133,
     134,   131,    91,   172,   158,   -63,    64,   137,   176,   155,
     160,   186,   156,   -62,   180,   181,   116,   117,    85,   159,
     162,   161,   188,     1,    59,    60,    61,    62,    90,   193,
     -62,    53,    36,     1,    59,    60,    61,    62,   153,    28,
       2,     3,   168,    51,    52,    58,    28,   175,   -62,    24,
       2,     3,    41,   170,   182,    35,    24,    56,    40,    25,
     132,    -6,   -62,   121,    63,   -62,    53,    57,    91,    54,
     173,   177,    64,    92,    63,    78,   153,    28,    91,   -62,
      53,    72,    64,    70,   153,    28,   165,    24,   153,    28,
      81,    82,    83,   153,    28,    24,   130,    25,     1,    24,
       0,   192,     0,     0,    24,    25,     0,     0,     0,    25,
       0,     0,     0,     0,    25,     2,     3,     4,     5,     6,
       7,     8,     9,     0,    10,    11,    12,    13,   139,   140,
     141,   142,   143,   144,     1,    59,    60,    61,    62,    90,
       1,    59,    60,    61,    62,     0,     0,     0,     0,   131,
       0,     2,     3,     0,    51,    52,     0,     2,     3,     1,
      59,    60,    61,    62,   110,   111,   112,   113,   114,   115,
     179,     0,     0,   -62,     0,    63,     0,     0,   187,    91,
       0,    63,   191,    64,     0,    91,     0,   194,     0,    64,
     -62,    53,     0,     0,     0,     0,   116,   117,     0,     0,
      63,   -88,   -88,   -88,   -88,   -88,    51,    52,    64,    67,
       0,   169,   110,   111,   112,   113,   114,   115,     0,     0,
       0,     0,    76,    77,     0,     0,   -88,    34,     0,     0,
       1,   112,   113,   114,   115,     0,     0,     0,   101,   102,
     103,   104,   105,    53,   116,   117,     1,     2,     3,     4,
       5,     6,     7,     8,     9,     0,    10,    11,    12,    13,
       0,   116,   117,     2,     3,     4,     5,     6,     7,     8,
       9,     0,    10,    11,    12,    13,    44,    45,    46,    47,
      48,     4,     5,     6,     7,     8,     9,     0,    10,    11,
      12,    13,     0,     0,     0,     4,     5,     6,     7,     0,
       0,    49,    10,    11,    12,    13,    79,    80,    81,    82,
      83,     1,    59,    60,    61,    62,    89,    79,    80,    81,
      82,    83
};

static const yytype_int16 yycheck[] =
{
       0,     0,     2,     3,    17,     3,     4,     5,     6,     7,
       0,     0,    20,    21,    14,    14,     3,    17,    17,    23,
     155,     0,    20,    21,    14,    14,     0,    23,    17,    39,
      39,    23,    56,   168,     9,    14,    11,    12,    13,    14,
      14,    41,    41,    53,    52,   180,    44,    56,   111,    57,
      50,    50,    41,    53,    52,    78,    39,     3,     4,     5,
       6,     7,    39,    63,    64,    45,    41,    42,    91,    53,
      53,    50,    58,   136,    20,    21,    53,    39,   141,    79,
      80,    81,    82,    83,    74,    85,    11,    12,    39,   112,
     113,   114,   115,   116,   117,   118,    52,    39,    44,   122,
     123,    54,    48,   166,    56,    56,    52,    55,   171,    52,
      56,    53,    52,    39,   177,   178,    41,    42,   108,    56,
      56,   144,   185,     3,     4,     5,     6,     7,     8,   192,
      56,    57,   145,     3,     4,     5,     6,     7,   138,   138,
      20,    21,    52,    20,    21,   145,   145,   170,    39,   138,
      20,    21,    39,    39,    51,    14,   145,    38,    19,   138,
     120,    52,    39,   108,    44,    56,    57,    41,    48,    56,
      56,   172,    52,    53,    44,    52,   176,   176,    48,    56,
      57,    53,    52,    50,   184,   184,    56,   176,   188,   188,
      45,    46,    47,   193,   193,   184,   118,   176,     3,   188,
      -1,   189,    -1,    -1,   193,   184,    -1,    -1,    -1,   188,
      -1,    -1,    -1,    -1,   193,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,     3,     4,     5,     6,     7,     8,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    54,
      -1,    20,    21,    -1,    20,    21,    -1,    20,    21,     3,
       4,     5,     6,     7,     9,    10,    11,    12,    13,    14,
     176,    -1,    -1,    39,    -1,    44,    -1,    -1,   184,    48,
      -1,    44,   188,    52,    -1,    48,    -1,   193,    -1,    52,
      56,    57,    -1,    -1,    -1,    -1,    41,    42,    -1,    -1,
      44,    15,    16,    17,    18,    19,    20,    21,    52,    50,
      -1,    56,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    40,     0,    -1,    -1,
       3,    11,    12,    13,    14,    -1,    -1,    -1,    79,    80,
      81,    82,    83,    57,    41,    42,     3,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    29,    30,    31,    32,
      -1,    41,    42,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    30,    31,    32,    15,    16,    17,    18,
      19,    22,    23,    24,    25,    26,    27,    -1,    29,    30,
      31,    32,    -1,    -1,    -1,    22,    23,    24,    25,    -1,
      -1,    40,    29,    30,    31,    32,    43,    44,    45,    46,
      47,     3,     4,     5,     6,     7,    53,    43,    44,    45,
      46,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    20,    21,    22,    23,    24,    25,    26,    27,
      29,    30,    31,    32,    60,    61,    62,    65,    67,    68,
      69,    85,    86,    87,    91,    92,    93,    94,    98,    94,
      94,    23,    23,    23,     0,    61,    86,    94,    45,    66,
      69,    39,    56,    56,    15,    16,    17,    18,    19,    40,
      95,    20,    21,    57,    56,    63,    66,    87,    94,     4,
       5,     6,     7,    44,    52,    92,    94,    96,    97,    98,
     100,    94,    97,    99,    52,    94,    96,    96,    52,    43,
      44,    45,    46,    47,    58,    65,    70,    71,    72,    53,
       8,    48,    53,    90,    91,    92,    94,    96,    98,   101,
     102,    96,    96,    96,    96,    96,    94,    53,    39,    90,
       9,    10,    11,    12,    13,    14,    41,    42,    39,    53,
      64,    72,   103,   103,    90,    90,    90,    90,    90,    90,
     102,    54,    74,    90,    90,    75,    76,    55,   103,    33,
      34,    35,    36,    37,    38,    65,    73,    74,    77,    78,
      81,    82,    85,    94,   100,    52,    52,   103,    56,    56,
      56,    90,    56,    89,    90,    56,    88,    89,    52,    56,
      39,    53,   103,    56,    89,    90,   103,    88,    53,    73,
     103,   103,    51,    89,    83,   104,    53,    73,   103,    79,
      84,    73,   104,   103,    73,    80
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    60,    61,    61,    63,    64,    62,    65,
      65,    66,    66,    67,    67,    68,    68,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    70,    70,
      71,    71,    72,    73,    73,    75,    74,    76,    76,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    79,    80,
      78,    81,    81,    83,    84,    82,    85,    85,    85,    86,
      86,    87,    87,    87,    88,    88,    89,    89,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      91,    91,    91,    91,    92,    92,    92,    92,    93,    93,
      94,    95,    95,    95,    95,    95,    95,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    97,    97,    97,    97,
      98,    99,    99,   100,   100,   101,   101,   102,   102,   103,
     104
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     0,     0,     8,     2,
       1,     2,     1,     2,     1,     1,     1,     1,     2,     1,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     0,
       3,     1,     2,     1,     1,     0,     4,     3,     0,     1,
       1,     1,     1,     2,     2,     2,     2,     3,     0,     0,
      13,     6,    10,     0,     0,     9,     3,     2,     2,     3,
       1,     1,     1,     1,     2,     1,     3,     1,     3,     3,
       3,     3,     3,     3,     4,     4,     2,     1,     1,     1,
       3,     3,     3,     3,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       4,     1,     1,     4,     3,     3,     1,     1,     1,     0,
       0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 6:
#line 130 "parser.y" /* yacc.c:1646  */
    {
				func_type = current_dtype;
				is_declaration = 0;  /*只有前面有type的identifier才是声明*/
				current_scope = create_new_scope();  /*函数进入了新的作用域，要创建新的符号表*/
				gencode((yyvsp[0].entry)->lexeme + string(":"));
			}
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 138 "parser.y" /* yacc.c:1646  */
    {
				is_declaration = 0;
				fill_parameter_list((yyvsp[-4].entry),param_list,p_idx);
				p_idx = 0;  /*记录param_list中参数数量的变量置0*/
				is_func = 1;
				p=1;   /*标记进入了新的作用域*/
			}
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 146 "parser.y" /* yacc.c:1646  */
    {   is_func = 0;  }
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 151 "parser.y" /* yacc.c:1646  */
    {is_declaration = 1; }
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 152 "parser.y" /* yacc.c:1646  */
    {is_declaration = 1; }
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 167 "parser.y" /* yacc.c:1646  */
    {current_dtype = INT;}
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 168 "parser.y" /* yacc.c:1646  */
    {current_dtype = SHORT;}
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 169 "parser.y" /* yacc.c:1646  */
    {current_dtype = SHORT;}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 170 "parser.y" /* yacc.c:1646  */
    {current_dtype = LONG;}
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 171 "parser.y" /* yacc.c:1646  */
    {current_dtype = LONG;}
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 172 "parser.y" /* yacc.c:1646  */
    {current_dtype = LONG_LONG;}
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 173 "parser.y" /* yacc.c:1646  */
    {current_dtype = LONG_LONG;}
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 174 "parser.y" /* yacc.c:1646  */
    {current_dtype = CHAR;}
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 175 "parser.y" /* yacc.c:1646  */
    {current_dtype = FLOAT;}
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 176 "parser.y" /* yacc.c:1646  */
    {current_dtype = VOID;}
#line 1626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 177 "parser.y" /* yacc.c:1646  */
    {current_dtype = STRING;}
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 191 "parser.y" /* yacc.c:1646  */
    {
							param_list[p_idx++] = (yyvsp[0].entry)->data_type;
							gencode(string("arg ") + (yyvsp[0].entry)->lexeme);
						}
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 198 "parser.y" /* yacc.c:1646  */
    {(yyval.content) = new content_t(); (yyval.content)=(yyvsp[0].content);}
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 199 "parser.y" /* yacc.c:1646  */
    {(yyval.content) = new content_t(); (yyval.content)=(yyvsp[0].content);}
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 206 "parser.y" /* yacc.c:1646  */
    {
				/*如果前面已经创建了新符号表，就不再创建*/
					if(!p)current_scope = create_new_scope(); 
					else p = 0;
				}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 216 "parser.y" /* yacc.c:1646  */
    {
					current_scope = exit_scope();  /*离开作用域，退回到父符号表*/
					(yyval.content) = new content_t();
					(yyval.content) = (yyvsp[-1].content);
				}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 223 "parser.y" /* yacc.c:1646  */
    {
									backpatch((yyvsp[-2].content)->nextlist,(yyvsp[-1].instr));
									(yyval.content) = new content_t();
									(yyval.content)->nextlist = (yyvsp[0].content)->nextlist;
									(yyval.content)->breaklist = merge((yyvsp[-2].content)->breaklist,(yyvsp[0].content)->breaklist);
									(yyval.content)->continuelist = merge((yyvsp[-2].content)->continuelist,(yyvsp[0].content)->continuelist);
								}
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 231 "parser.y" /* yacc.c:1646  */
    {	(yyval.content) = new content_t();	}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 235 "parser.y" /* yacc.c:1646  */
    {
							(yyval.content) = new content_t();
							(yyval.content) = (yyvsp[0].content);
							backpatch((yyval.content)->nextlist, nextinstr);
						}
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 241 "parser.y" /* yacc.c:1646  */
    {
							(yyval.content) = new content_t();
							(yyval.content) = (yyvsp[0].content);
							backpatch((yyval.content)->nextlist, nextinstr);
						}
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 247 "parser.y" /* yacc.c:1646  */
    {
							(yyval.content) = new content_t();
							(yyval.content) = (yyvsp[0].content);
							backpatch((yyval.content)->nextlist, nextinstr);
						 }
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 252 "parser.y" /* yacc.c:1646  */
    {(yyval.content) = new content_t();}
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 253 "parser.y" /* yacc.c:1646  */
    {(yyval.content) = new content_t();}
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 254 "parser.y" /* yacc.c:1646  */
    {
								if(is_func)
								{
									if(func_type != VOID)
										yyerror("return type (VOID) does not match function type");
								}
							  	else yyerror("return statement not inside function definition");
							}
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 263 "parser.y" /* yacc.c:1646  */
    {
								if(!is_loop)
									yyerror("Illegal use of continue");
								(yyval.content) = new content_t();
								(yyval.content)->continuelist = {nextinstr};
								gencode("goto _");
							}
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 271 "parser.y" /* yacc.c:1646  */
    {
								if(!is_loop) {yyerror("Illegal use of break");}
								(yyval.content) = new content_t();
								(yyval.content)->breaklist = {nextinstr};
								gencode("goto _");
						    }
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 279 "parser.y" /* yacc.c:1646  */
    {
								if(is_func)
								{
									if(func_type != (yyvsp[-1].content)->data_type)
										yyerror("return type does not match function type");
								}
								else yyerror("return statement not in function definition");
							}
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 289 "parser.y" /* yacc.c:1646  */
    {is_loop = 1;}
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 289 "parser.y" /* yacc.c:1646  */
    {is_loop = 0;}
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 290 "parser.y" /* yacc.c:1646  */
    {
				backpatch((yyvsp[-8].content)->truelist,(yyvsp[-2].instr));
				backpatch((yyvsp[-1].content)->nextlist,(yyvsp[-7].instr));
				backpatch((yyvsp[-1].content)->continuelist, (yyvsp[-7].instr));
				backpatch((yyvsp[-3].content)->nextlist, (yyvsp[-9].instr));
				(yyval.content) = new content_t();
				(yyval.content)->nextlist = merge((yyvsp[-8].content)->falselist,(yyvsp[-1].content)->breaklist);
				gencode(string("goto ") + to_string((yyvsp[-7].instr)));
			 }
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 303 "parser.y" /* yacc.c:1646  */
    {
			 /*本条规则具有与LOWER_THAN_ELSE相同的优先级，单if语句比else优先级低，保证了if-if-else结构中else和内层if配对*/
				backpatch((yyvsp[-3].content)->truelist,(yyvsp[-1].instr));
				(yyval.content) = new content_t();
				(yyval.content)->nextlist = merge((yyvsp[-3].content)->falselist,(yyvsp[0].content)->nextlist);
				(yyval.content)->breaklist = (yyvsp[0].content)->breaklist;
				(yyval.content)->continuelist = (yyvsp[0].content)->continuelist;
			}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 313 "parser.y" /* yacc.c:1646  */
    {
				backpatch((yyvsp[-7].content)->truelist,(yyvsp[-5].instr));
				backpatch((yyvsp[-7].content)->falselist,(yyvsp[-1].instr));

				(yyval.content) = new content_t();
				vector<int> temp = merge((yyvsp[-4].content)->nextlist,(yyvsp[-2].content)->nextlist);
				(yyval.content)->nextlist = merge(temp,(yyvsp[0].content)->nextlist);
				(yyval.content)->breaklist = merge((yyvsp[0].content)->breaklist,(yyvsp[-4].content)->breaklist);
				(yyval.content)->continuelist = merge((yyvsp[0].content)->continuelist,(yyvsp[-4].content)->continuelist);
			}
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 325 "parser.y" /* yacc.c:1646  */
    {is_loop = 1;}
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 325 "parser.y" /* yacc.c:1646  */
    {is_loop = 0;}
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 326 "parser.y" /* yacc.c:1646  */
    {
				backpatch((yyvsp[-1].content)->nextlist,(yyvsp[-7].instr));
				backpatch((yyvsp[-5].content)->truelist,(yyvsp[-3].instr));
				backpatch((yyvsp[-1].content)->continuelist, (yyvsp[-7].instr));
				(yyval.content) = new content_t();
				(yyval.content)->nextlist = merge((yyvsp[-5].content)->falselist,(yyvsp[-1].content)->breaklist);
				gencode(string("goto ") + to_string((yyvsp[-7].instr)));
			}
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 337 "parser.y" /* yacc.c:1646  */
    {is_declaration = 0;  /*声明结束之后置这个标记为0*/}
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 353 "parser.y" /* yacc.c:1646  */
    {
						(yyval.content) = new content_t(); 
						(yyval.content)->truelist = (yyvsp[-1].content)->truelist; 
						(yyval.content)->falselist = (yyvsp[-1].content)->falselist;
					}
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 359 "parser.y" /* yacc.c:1646  */
    {	(yyval.content) = new content_t();	}
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 363 "parser.y" /* yacc.c:1646  */
    {
					(yyval.content) = new content_t();
					(yyval.content)->truelist = (yyvsp[0].content)->truelist; 
					(yyval.content)->falselist = (yyvsp[0].content)->falselist;
				}
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 369 "parser.y" /* yacc.c:1646  */
    {
					(yyval.content) = new content_t(); 
					(yyval.content)->truelist = (yyvsp[0].content)->truelist; 
					(yyval.content)->falselist = (yyvsp[0].content)->falselist;
				}
#line 1903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 379 "parser.y" /* yacc.c:1646  */
    {
				type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,2);
				(yyval.content) = new content_t();
				gencode_rel((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" > "));  
			}
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 385 "parser.y" /* yacc.c:1646  */
    {
				type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,2);
				(yyval.content) = new content_t();
				gencode_rel((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" < "));
			}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 392 "parser.y" /* yacc.c:1646  */
    {
				type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,2);
				(yyval.content) = new content_t();
				gencode_rel((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" == "));
			}
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 399 "parser.y" /* yacc.c:1646  */
    {
				type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,2);
				(yyval.content) = new content_t();
				gencode_rel((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" != "));
			}
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 406 "parser.y" /* yacc.c:1646  */
    {
				type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,2);
				(yyval.content) = new content_t();
				gencode_rel((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" >= "));
			}
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 413 "parser.y" /* yacc.c:1646  */
    {
				type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,2);
				(yyval.content) = new content_t();
				gencode_rel((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" <= "));
			}
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 420 "parser.y" /* yacc.c:1646  */
    {
				type_check((yyvsp[-3].content)->data_type,(yyvsp[0].content)->data_type,2);
				(yyval.content) = new content_t();
				(yyval.content)->data_type = (yyvsp[-3].content)->data_type;
				backpatch((yyvsp[-3].content)->truelist,(yyvsp[-1].instr));
				(yyval.content)->truelist = (yyvsp[0].content)->truelist;
				(yyval.content)->falselist = merge((yyvsp[-3].content)->falselist,(yyvsp[0].content)->falselist);
			}
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 430 "parser.y" /* yacc.c:1646  */
    {
				type_check((yyvsp[-3].content)->data_type,(yyvsp[0].content)->data_type,2);
				(yyval.content) = new content_t();
				(yyval.content)->data_type = (yyvsp[-3].content)->data_type;
				backpatch((yyvsp[-3].content)->falselist,(yyvsp[-1].instr));
				(yyval.content)->truelist = merge((yyvsp[-3].content)->truelist,(yyvsp[0].content)->truelist);
				(yyval.content)->falselist = (yyvsp[0].content)->falselist;
			}
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 440 "parser.y" /* yacc.c:1646  */
    {
				(yyval.content) = new content_t();
				(yyval.content)->data_type = (yyvsp[0].content)->data_type;
				(yyval.content)->truelist = (yyvsp[0].content)->falselist;
				(yyval.content)->falselist = (yyvsp[0].content)->truelist;
			}
#line 2000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 448 "parser.y" /* yacc.c:1646  */
    {
				(yyval.content) = new content_t(); 
				(yyval.content)->data_type = (yyvsp[0].content)->data_type; 
				(yyval.content)->addr = (yyvsp[0].content)->addr;
			}
#line 2010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 454 "parser.y" /* yacc.c:1646  */
    {
				(yyval.content) = new content_t(); 
				(yyval.content)->data_type = (yyvsp[0].content)->data_type;
			}
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 459 "parser.y" /* yacc.c:1646  */
    {
				(yyval.content) = new content_t(); 
				(yyval.content)->data_type = (yyvsp[0].content)->data_type;
			}
#line 2028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 468 "parser.y" /* yacc.c:1646  */
    {
				type_check((yyvsp[-2].content)->entry->data_type,(yyvsp[0].content)->data_type,1);
		 		(yyval.content) = new content_t();
				(yyval.content)->data_type = (yyvsp[0].content)->data_type;
		 		(yyval.content)->code = (yyvsp[-2].content)->entry->lexeme + *(yyvsp[-1].op) + (yyvsp[0].content)->addr;
				gencode((yyval.content)->code);
		 		rhs = 0;
			}
#line 2041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 478 "parser.y" /* yacc.c:1646  */
    {
				type_check((yyvsp[-2].content)->entry->data_type,(yyvsp[0].content)->data_type,1);
	 			(yyval.content) = new content_t();
				(yyval.content)->data_type = (yyvsp[0].content)->data_type;
	 			(yyval.content)->code = (yyvsp[-2].content)->entry->lexeme + *(yyvsp[-1].op) + (yyvsp[0].content)->code;
				gencode((yyval.content)->code);
	 			rhs = 0;
			}
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 488 "parser.y" /* yacc.c:1646  */
    {
				type_check((yyvsp[-2].content)->entry->data_type,(yyvsp[0].data_type),1); 
				(yyval.content) = new content_t(); 
				(yyval.content)->data_type = (yyvsp[0].data_type);
			}
#line 2064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 495 "parser.y" /* yacc.c:1646  */
    {
				type_check((yyvsp[-2].content)->entry->data_type,(yyvsp[0].content)->data_type,1);
			 	(yyval.content) = new content_t();
				(yyval.content)->data_type = (yyvsp[0].content)->data_type;
			 	(yyval.content)->code = (yyvsp[-2].content)->entry->lexeme + *(yyvsp[-1].op) + (yyvsp[0].content)->code;
				gencode((yyval.content)->code);
			 	rhs = 0;
			}
#line 2077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 508 "parser.y" /* yacc.c:1646  */
    {
				(yyval.content) = new content_t();
				(yyval.content)->data_type = (yyvsp[-1].entry)->data_type;
				(yyval.content)->code = string((yyvsp[-1].entry)->lexeme) + string("++");
				gencode((yyval.content)->code);
			}
#line 2088 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 516 "parser.y" /* yacc.c:1646  */
    {
				(yyval.content) = new content_t();
				(yyval.content)->data_type = (yyvsp[-1].entry)->data_type;
				(yyval.content)->code = string((yyvsp[-1].entry)->lexeme) + string("--");
				gencode((yyval.content)->code);
			}
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 524 "parser.y" /* yacc.c:1646  */
    {
				(yyval.content) = new content_t();
				(yyval.content)->data_type = (yyvsp[0].entry)->data_type;
				(yyval.content)->code = string("--") + string((yyvsp[0].entry)->lexeme);
				gencode((yyval.content)->code);
			}
#line 2110 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 532 "parser.y" /* yacc.c:1646  */
    {
				(yyval.content) = new content_t();
				(yyval.content)->data_type = (yyvsp[0].entry)->data_type;
				(yyval.content)->code = string("++") + string((yyvsp[0].entry)->lexeme);
				gencode((yyval.content)->code);
			}
#line 2121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 539 "parser.y" /* yacc.c:1646  */
    {(yyval.content) = new content_t(); (yyval.content)->entry = (yyvsp[0].entry);}
#line 2127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 540 "parser.y" /* yacc.c:1646  */
    {(yyval.content) = new content_t(); (yyval.content)->code = (yyvsp[0].content)->code;}
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 544 "parser.y" /* yacc.c:1646  */
    {
                    if(is_declaration && !rhs)
                    {
                      (yyvsp[0].entry) = insert(SYMBOL_TABLE,yytext,INT_MAX,current_dtype);
                      if((yyvsp[0].entry) == NULL) 
					  	yyerror("Redeclaration of variable");
                    }
                    else
                    {
                      (yyvsp[0].entry) = search_recursive(yytext);
                      if((yyvsp[0].entry) == NULL) 
					  	yyerror("Variable not declared");
                    }
                    
					(yyval.entry) = (yyvsp[0].entry);
                }
#line 2154 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 562 "parser.y" /* yacc.c:1646  */
    {rhs=1; (yyval.op) = new string(" = ");}
#line 2160 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 563 "parser.y" /* yacc.c:1646  */
    {rhs=1; (yyval.op) = new string(" += ");}
#line 2166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 564 "parser.y" /* yacc.c:1646  */
    {rhs=1; (yyval.op) = new string(" -= ");}
#line 2172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 565 "parser.y" /* yacc.c:1646  */
    {rhs=1; (yyval.op) = new string(" *= ");}
#line 2178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 566 "parser.y" /* yacc.c:1646  */
    {rhs=1;	(yyval.op) = new string(" /= ");}
#line 2184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 567 "parser.y" /* yacc.c:1646  */
    {rhs=1; (yyval.op) = new string(" %= ");}
#line 2190 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 572 "parser.y" /* yacc.c:1646  */
    {
						type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,0);
						(yyval.content) = new content_t();
						(yyval.content)->data_type = (yyvsp[-2].content)->data_type;
						gencode_math((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" + "));
					 }
#line 2201 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 580 "parser.y" /* yacc.c:1646  */
    {
						type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,0);
						(yyval.content) = new content_t();
						(yyval.content)->data_type = (yyvsp[-2].content)->data_type;
						gencode_math((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" - "));
					 }
#line 2212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 588 "parser.y" /* yacc.c:1646  */
    {
						type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,0);
						(yyval.content) = new content_t();
		 				(yyval.content)->data_type = (yyvsp[-2].content)->data_type;
						gencode_math((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" * "));
					 }
#line 2223 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 596 "parser.y" /* yacc.c:1646  */
    {
						type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,0);
						(yyval.content) = new content_t();
						(yyval.content)->data_type = (yyvsp[-2].content)->data_type;
						gencode_math((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" / "));
					 }
#line 2234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 604 "parser.y" /* yacc.c:1646  */
    {
						type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,0);
						(yyval.content) = new content_t();
						(yyval.content)->data_type = (yyvsp[-2].content)->data_type;
						gencode_math((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" % "));
				 	 }
#line 2245 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 612 "parser.y" /* yacc.c:1646  */
    {
						(yyval.content) = new content_t();
						(yyval.content)->data_type = (yyvsp[-1].content)->data_type;
						(yyval.content)->addr = (yyvsp[-1].content)->addr;
						(yyval.content)->code = (yyvsp[-1].content)->code;
					 }
#line 2256 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 620 "parser.y" /* yacc.c:1646  */
    {
						(yyval.content) = new content_t();
						(yyval.content)->data_type = (yyvsp[0].content)->data_type;
						(yyval.content)->addr = "t" + to_string(temp_var_number);
						std::string expr = (yyval.content)->addr + " = " + "minus " + (yyvsp[0].content)->addr;
						(yyval.content)->code = (yyvsp[0].content)->code + expr;
						gencode(expr);
						temp_var_number++;
				 	 }
#line 2270 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 631 "parser.y" /* yacc.c:1646  */
    {
						(yyval.content) = new content_t();
						(yyval.content)->data_type = (yyvsp[0].entry)->data_type;
	 					(yyval.content)->addr = (yyvsp[0].entry)->lexeme;
			   		 }
#line 2280 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 638 "parser.y" /* yacc.c:1646  */
    {
						(yyval.content) = new content_t();
						(yyval.content)->data_type = (yyvsp[0].entry)->data_type;
						(yyval.content)->addr = to_string((yyvsp[0].entry)->value);
					 }
#line 2290 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 645 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].entry)->is_constant=1; (yyval.entry) = (yyvsp[0].entry);}
#line 2296 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 646 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].entry)->is_constant=1; (yyval.entry) = (yyvsp[0].entry);}
#line 2302 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 647 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].entry)->is_constant=1; (yyval.entry) = (yyvsp[0].entry);}
#line 2308 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 648 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].entry)->is_constant=1; (yyval.entry) = (yyvsp[0].entry);}
#line 2314 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 652 "parser.y" /* yacc.c:1646  */
    {
					if(is_declaration)
					{
						if((yyvsp[-1].entry)->value <= 0)
							yyerror("size of array is not positive");
						else if((yyvsp[-1].entry)->is_constant)
							(yyvsp[-3].entry)->array_dimension = (yyvsp[-1].entry)->value;
					}
					else if((yyvsp[-1].entry)->is_constant)
					{
						if((yyvsp[-1].entry)->value > (yyvsp[-3].entry)->array_dimension)
							yyerror("Array index out of bound");
						if((yyvsp[-1].entry)->value < 0)
							yyerror("Array index cannot be negative");
					}
					
					(yyval.content) = new content_t();
					(yyval.content)->data_type = (yyvsp[-3].entry)->data_type;
					
					if((yyvsp[-1].entry)->is_constant)
						(yyval.content)->code = string((yyvsp[-3].entry)->lexeme) + string("[") + to_string((yyvsp[-1].entry)->value) + string("]");
					else
						(yyval.content)->code = string((yyvsp[-3].entry)->lexeme) + string("[") + string((yyvsp[-1].entry)->lexeme) + string("]");
					(yyval.content)->entry = (yyvsp[-3].entry);
				}
#line 2344 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 678 "parser.y" /* yacc.c:1646  */
    {(yyval.entry) = (yyvsp[0].entry);}
#line 2350 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 679 "parser.y" /* yacc.c:1646  */
    {(yyval.entry) = (yyvsp[0].entry);}
#line 2356 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 683 "parser.y" /* yacc.c:1646  */
    {
					(yyval.data_type) = (yyvsp[-3].entry)->data_type;
					check_parameter_list((yyvsp[-3].entry),param_list,p_idx);
					p_idx = 0;
					gencode(string("call ") + (yyvsp[-3].entry)->lexeme);
				}
#line 2367 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 691 "parser.y" /* yacc.c:1646  */
    {
					(yyval.data_type) = (yyvsp[-2].entry)->data_type;
				 	check_parameter_list((yyvsp[-2].entry),param_list,p_idx);
				 	p_idx = 0;
	 				gencode(string("call ") + (yyvsp[-2].entry)->lexeme);
				}
#line 2378 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 705 "parser.y" /* yacc.c:1646  */
    {
					param_list[p_idx++] = (yyvsp[0].content)->data_type;
					gencode(string("param ") + (yyvsp[0].content)->addr);
				}
#line 2387 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 710 "parser.y" /* yacc.c:1646  */
    {
					param_list[p_idx++] = STRING;
					gencode(string("param ") + (yyvsp[0].entry)->lexeme);
				}
#line 2396 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 716 "parser.y" /* yacc.c:1646  */
    {(yyval.instr) = nextinstr;}
#line 2402 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 719 "parser.y" /* yacc.c:1646  */
    {
				(yyval.content) = new content_t;
				(yyval.content)->nextlist = {nextinstr};
				gencode("goto _");
			}
#line 2412 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2416 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 726 "parser.y" /* yacc.c:1906  */



//生成中间代码
void gencode(string x)
{
	std::string instruction;

	instruction = to_string(nextinstr) + string(": ") + x;
	ICG.push_back(instruction);
	nextinstr++;
}

//生成一个包含关系运算符的中间代码，这里会处理回填技术的truelist和falselist
void gencode_rel(content_t* & lhs, content_t* arg1, content_t* arg2, const string& op)
{
	lhs->data_type = arg1->data_type;

	lhs->truelist = {nextinstr};
	lhs->falselist = {nextinstr + 1};

	std::string code;

	code = string("if ") + arg1->addr + op + arg2->addr + string(" goto _");
	gencode(code);

	code = string("goto _");
	gencode(code);
}

//生成一个类似t0=a+b的中间代码
void gencode_math(content_t* & lhs, content_t* arg1, content_t* arg2, const string& op)
{
	lhs->addr = "t" + to_string(temp_var_number);
	std::string expr = lhs->addr + string(" = ") + arg1->addr + op + arg2->addr;
	lhs->code = arg1->code + arg2->code + expr;

	temp_var_number++;

	gencode(expr);
}

//回填
void backpatch(vector<int>& v1, int number)
{
	for(int i = 0; i<v1.size(); i++)
	{
		string instruction = ICG[v1[i]];

		if(instruction.find("_") < instruction.size())
		{
			instruction.replace(instruction.find("_"),1,to_string(number));
			ICG[v1[i]] = instruction;
		}
	}
}

//合并两个链
vector<int> merge(vector<int>& v1, vector<int>& v2)
{
	vector<int> concat;
	concat.reserve(v1.size() + v2.size());
	concat.insert(concat.end(), v1.begin(), v1.end());
	concat.insert(concat.end(), v2.begin(), v2.end());

	return concat;
}

//类型检查
void type_check(int left, int right, int flag)
{
	if(left != right)
	{
		switch(flag)
		{
			case 0: yyerror("Type mismatch in arithmetic expression"); break;
			case 1: yyerror("Type mismatch in assignment expression"); break;
			case 2: yyerror("Type mismatch in logical expression"); break;
		}
	}
}

//输出符号表到指定的文件中
void displayICG()
{
	ofstream outfile("ICG.code");

	for(int i=0; i<ICG.size();i++)
	outfile << ICG[i] <<endl;

	outfile << nextinstr << ": exit";

	outfile.close();
}

int main(int argc, char *argv[])
{
	 int i;
	 for(i=0; i<NUM_TABLES;i++) //创建符号表数组，每个符号表的父表置-1
	 {
	  symbol_table_list[i].symbol_table = NULL;
	  symbol_table_list[i].parent = -1;
	 }

	constant_table = create_table();  //创建常量表
  symbol_table_list[0].symbol_table = create_table(); //创建符号表数组的第0项为默认当前文件的第一个符号表
	yyin = fopen(argv[1], "r");

	if(!yyparse())
	{
		printf("\nPARSING COMPLETE\n\n\n");
	}
	else
	{
			printf("\nPARSING FAILED!\n\n\n");
	}

	displayICG(); //输出中间代码
/*
	printf("SYMBOL TABLES\n\n");
	display_all();

	printf("CONSTANT TABLE");
	display_constant_table(constant_table);*/

}

int yyerror(const char *msg)
{
	printf("Line no: %d Error message: %s Token: %s\n", yylineno, msg, yytext);
	exit(0);
}
