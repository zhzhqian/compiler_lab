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

#line 92 "parser.tab.c" /* yacc.c:339  */

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
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
#line 26 "parser.y" /* yacc.c:355  */

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

#line 243 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 260 "parser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   262

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  159

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   280

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      26,    27,    32,     2,    31,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    28,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    33,     2,    34,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,    29,     2,     2,     2,     2,
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
      25
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   139,   139,   140,   141,   142,   143,   144,   145,   161,
     178,   207,   218,   224,   232,   239,   246,   250,   254,   259,
     264,   268,   272,   278,   282,   287,   291,   298,   304,   310,
     315,   319,   326,   331,   336,   350,   355,   359,   389,   399,
     404,   410,   422,   433,   436,   439,   446,   453,   458,   461,
     467,   474,   491,   498,   507,   517,   524,   532,   538,   546,
     554,   560,   575,   585,   604,   623,   630,   638,   656,   657,
     658,   659,   661,   695,   704,   711,   715,   721,   737,   771,
     778,   787,   798,   808,   819,   823,   827,   832,   836,   840,
     845,   850
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LOWER_THAN_ELSE", "ELSE", "ID", "EQUAL",
  "T_BOOL_OPERATOR", "T_RELATION", "OPERATOR2", "OPERATOR1",
  "T_BIT_OPERATOR", "TYPE_BASE", "INT_VALUE", "STRING", "FLOAT_VALUE",
  "BOOL_VALUE", "T_INCRDECR", "IF", "STRUCT", "WHILE", "BREAK", "FOR",
  "RETURN", "T_SEPERATOR", "CONTINUE", "'('", "')'", "';'", "'}'", "'{'",
  "','", "'*'", "'['", "']'", "$accept", "Program", "PARTITION",
  "FUNCTIONDEC", "FUNCTIONDEF", "FUNC_DEF_PREFIX", "PARAMETERS", "PARAS",
  "PARA", "TYPE", "STATEMENTS", "STATEMENT", "STAT_BODY", "TEMP_M",
  "RETURN_STAT", "DECLARATION", "DEFINITIONS", "DEFINITION", "VARIABLES",
  "VARIABLE", "LIST", "ARRS", "EXPRESSION", "L", "BOOL_EXPRESSION",
  "VALUE", "FUNCTIONCALL", "ACT_PARAS", "ACT_PARA", "IF_BLOCK",
  "IF_PREFIX", "WHILE_BLOCK", "WHILE_PREFIX", "FOR_BLOCK", "FOR_PREFIX",
  "FOR_INITIALS", "FOR_INITIAL", "FOR_ITERATES", "FOR_ITERATE", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,    40,    41,    59,   125,
     123,    44,    42,    91,    93
};
# endif

#define YYPACT_NINF -51

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-51)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -51,    50,   -51,   -22,    30,   -51,   -51,   -51,   166,     0,
     -51,     9,   -51,   -51,    12,     1,   222,   222,   -51,   -51,
     -51,   -51,    40,    27,    35,    36,    42,    52,   222,   -51,
      15,   118,   -51,   -51,   -51,    57,    54,   -51,   -51,   -51,
     166,   -51,   166,   -51,   222,    -3,    93,   -12,   -51,   -51,
     -51,   222,   -51,   236,   222,    81,    89,   -51,   236,   236,
     -51,   222,   -51,    67,   166,    16,   206,   -51,    71,   222,
     222,   -51,   222,    97,   -51,    81,    76,    73,   222,     9,
      92,    19,   100,   -51,    15,     9,    81,   236,    87,   102,
      29,   -51,    31,     4,    21,    81,    83,    82,   -51,   140,
     -51,    61,   -51,    89,   -51,    49,   166,   166,   222,    81,
      85,    86,   -51,   111,    84,    90,   106,   188,   -51,    63,
      87,   -51,   222,   236,   -51,   236,   -51,   -51,   -51,   236,
     222,   -51,   -51,   -51,   -51,   -51,    81,    -4,     9,   -51,
     -51,   236,   -51,    94,   -51,    81,   -51,    81,   -51,   -51,
       5,    81,   -51,   -51,   -51,    55,   -51,   -51,   -51
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,    17,     0,     2,     6,     5,    20,     0,
       7,     4,    36,    16,     0,    61,     0,     0,    68,    71,
      69,    70,     0,     0,     0,     0,     0,     0,     0,    30,
       0,    33,    19,    25,    21,     0,    57,    52,    50,    23,
       0,    24,     0,    28,    89,    40,     0,     0,    39,    35,
      30,     0,    58,    75,     0,    56,    55,    59,     0,     0,
      26,    85,    27,     0,    20,    40,     0,    18,     0,     0,
       0,    22,     0,    77,    80,    91,     0,    88,     0,    12,
       0,    45,    46,    37,     0,     0,    51,     0,    65,    76,
       0,    74,     0,     0,     0,    87,     0,    84,    60,     0,
      32,     0,     9,    54,    53,     0,     0,     0,     0,    41,
       0,    11,    14,     0,     0,     0,     0,     0,    38,     0,
      56,    67,     0,     0,    72,     0,    63,    79,    81,     0,
       0,    29,    31,    62,    78,    82,    90,     0,     0,    15,
      49,    75,    43,     0,    44,    42,    34,    66,    64,    73,
       0,    86,     8,    10,    13,     0,    48,    83,    47
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -17,    -1,
      60,   -25,   -51,    79,   -51,   -51,    65,     3,   -51,    58,
      34,   -51,   -15,   -51,   -50,   -51,   -51,    18,    38,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     5,     6,     7,     8,   110,   111,   112,    30,
      31,    32,    33,    64,    68,    10,    11,    34,    47,    48,
     142,    81,    35,    36,    89,    37,    38,    90,    91,    39,
      40,    41,    42,    43,    44,    96,    97,    76,    77
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       9,    55,    56,    78,    12,    45,    67,    51,    93,    94,
      13,   123,   123,    63,    49,    73,    83,    74,    52,    84,
      65,     3,    78,    79,   152,   115,   153,    53,   123,    75,
      80,   127,    46,   157,    54,    14,    86,   121,    88,    92,
      69,    70,    50,    88,    88,    57,    95,    46,   128,    80,
       2,   101,   116,    58,   103,   104,   124,   105,    69,    70,
     125,    59,     3,   109,    60,   126,    69,    70,    61,     4,
      69,    70,   120,   148,    67,     3,    69,    70,   113,   150,
      62,   134,   135,   133,   158,    71,   125,    72,    12,   132,
      69,    70,   146,   136,    98,   122,    69,    70,    82,    70,
     102,   106,   145,   107,   108,   114,   117,   147,    88,   123,
      88,   129,   137,   130,    88,   151,   139,   138,   140,   143,
     141,   154,    49,    15,    99,    16,    88,    17,   156,    85,
       3,    18,    19,    20,    21,    22,    23,   113,    24,    25,
      26,    66,   118,    27,    28,    15,     0,    16,    29,    17,
     119,   144,     3,    18,    19,    20,    21,    22,    23,   155,
      24,    25,    26,   149,     0,    27,    28,     0,     0,   131,
      29,    15,     0,    16,     0,    17,     0,     0,     3,    18,
      19,    20,    21,    22,    23,     0,    24,    25,    26,     0,
       0,    27,    28,    15,     0,    16,    29,    17,     0,     0,
       0,    18,    19,    20,    21,    22,     0,     0,     0,     0,
       0,    15,     0,    16,    28,    17,     0,     0,   141,    18,
      19,    20,    21,    22,     0,     0,     0,    15,     0,    16,
       0,    17,    28,     0,   100,    18,    19,    20,    21,    22,
       0,    15,     0,    87,     0,    17,     0,     0,    28,    18,
      19,    20,    21,    22,     0,     0,     0,     0,     0,     0,
       0,     0,    28
};

static const yytype_int16 yycheck[] =
{
       1,    16,    17,     6,     1,     5,    31,     6,    58,    59,
      32,     7,     7,    28,    11,    40,    28,    42,    17,    31,
       5,    12,     6,    26,    28,     6,    30,    26,     7,    44,
      33,    27,    32,    28,    33,     5,    51,    87,    53,    54,
       9,    10,    30,    58,    59,     5,    61,    32,    27,    33,
       0,    66,    33,    26,    69,    70,    27,    72,     9,    10,
      31,    26,    12,    78,    28,    34,     9,    10,    26,    19,
       9,    10,    87,   123,    99,    12,     9,    10,    79,   129,
      28,   106,   107,    34,    29,    28,    31,    33,    85,    28,
       9,    10,    29,   108,    27,     8,     9,    10,     5,    10,
      29,     4,   117,    27,    31,    13,     6,   122,   123,     7,
     125,    28,    27,    31,   129,   130,     5,    31,    34,    13,
      30,   138,   119,     5,    64,     7,   141,     9,    34,    50,
      12,    13,    14,    15,    16,    17,    18,   138,    20,    21,
      22,    23,    84,    25,    26,     5,    -1,     7,    30,     9,
      85,   117,    12,    13,    14,    15,    16,    17,    18,   141,
      20,    21,    22,   125,    -1,    25,    26,    -1,    -1,    29,
      30,     5,    -1,     7,    -1,     9,    -1,    -1,    12,    13,
      14,    15,    16,    17,    18,    -1,    20,    21,    22,    -1,
      -1,    25,    26,     5,    -1,     7,    30,     9,    -1,    -1,
      -1,    13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,
      -1,     5,    -1,     7,    26,     9,    -1,    -1,    30,    13,
      14,    15,    16,    17,    -1,    -1,    -1,     5,    -1,     7,
      -1,     9,    26,    -1,    28,    13,    14,    15,    16,    17,
      -1,     5,    -1,     7,    -1,     9,    -1,    -1,    26,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    36,     0,    12,    19,    37,    38,    39,    40,    44,
      50,    51,    52,    32,     5,     5,     7,     9,    13,    14,
      15,    16,    17,    18,    20,    21,    22,    25,    26,    30,
      44,    45,    46,    47,    52,    57,    58,    60,    61,    64,
      65,    66,    67,    68,    69,     5,    32,    53,    54,    52,
      30,     6,    17,    26,    33,    57,    57,     5,    26,    26,
      28,    26,    28,    57,    48,     5,    23,    46,    49,     9,
      10,    28,    33,    46,    46,    57,    72,    73,     6,    26,
      33,    56,     5,    28,    31,    48,    57,     7,    57,    59,
      62,    63,    57,    59,    59,    57,    70,    71,    27,    45,
      28,    57,    29,    57,    57,    57,     4,    27,    31,    57,
      41,    42,    43,    44,    13,     6,    33,     6,    54,    51,
      57,    59,     8,     7,    27,    31,    34,    27,    27,    28,
      31,    29,    28,    34,    46,    46,    57,    27,    31,     5,
      34,    30,    55,    13,    55,    57,    29,    57,    59,    63,
      59,    57,    28,    30,    43,    62,    34,    28,    29
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    36,    36,    37,    37,    37,    37,    38,    39,
      40,    41,    41,    42,    42,    43,    44,    44,    45,    45,
      45,    46,    46,    46,    46,    46,    46,    46,    46,    47,
      48,    49,    49,    49,    50,    51,    51,    52,    53,    53,
      54,    54,    54,    54,    54,    54,    54,    55,    56,    56,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    58,    58,    59,    59,    59,    59,    60,    60,
      60,    60,    61,    62,    62,    62,    63,    64,    64,    65,
      66,    67,    68,    69,    70,    70,    71,    71,    72,    72,
      73,    73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     1,     6,     4,
       6,     1,     0,     3,     1,     2,     2,     1,     2,     1,
       0,     1,     2,     1,     1,     1,     2,     2,     1,     4,
       0,     3,     2,     0,     6,     2,     1,     3,     3,     1,
       1,     3,     4,     4,     4,     2,     2,     3,     4,     3,
       1,     3,     1,     3,     3,     2,     2,     1,     2,     2,
       3,     1,     4,     4,     3,     1,     3,     2,     1,     1,
       1,     1,     4,     3,     1,     0,     1,     2,     4,     4,
       2,     4,     4,     6,     1,     0,     3,     1,     1,     0,
       3,     1
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
        case 8:
#line 145 "parser.y" /* yacc.c:1646  */
    {
    func_symtab_type* temp=creat_func_env();
    temp->name=(yyvsp[-4].id).var;
    temp->para_cont=(yyvsp[-2].form_paras).para_cont;
    temp->paras_type=(yyvsp[-2].form_paras).paras_type;
    temp->paras_name=(yyvsp[-2].form_paras).paras_name;
    temp->return_type=creat_variable_type();
    temp->return_type->base=(yyvsp[-5].type).base;
    temp->return_type->exten=(yyvsp[-5].type).exten;
    temp->addr=Wait;
    if(func_sym_look((yyvsp[-4].id).var,temp)==ALREAY_EXIST)
    {
        yyerror("function redeclaration");
        return 1;
    }
}
#line 1487 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 161 "parser.y" /* yacc.c:1646  */
    {
                    printf("\n*********recognize a function**********\n\n");
                    backPatch((yyvsp[-2].stmt_value).next_addr,(yyvsp[-1].exp_value).addr);
                    if(typecmp((yyvsp[-1].exp_value).var_type,(yyvsp[-3].func_prefix).return_type)!=0)
                    {
                        yyerror("return Type mismatch ");
                        return 1;
                    }
                    if(func_sym_look((yyvsp[-3].func_prefix).func_tab->name,(yyvsp[-3].func_prefix).func_tab)==ALREAY_EXIST)
                    {
                        yyerror("function redefinition");
                        return 1;
                    }
                    current_env=creat_envirement();
                    while(!queue_isEmpty(stmt_queue) )
                        emit_stm_head();
                }
#line 1509 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 178 "parser.y" /* yacc.c:1646  */
    {
    (yyval.func_prefix).return_type=creat_variable_type();
    (yyval.func_prefix).return_type->base=(yyvsp[-5].type).base;
    (yyval.func_prefix).return_type->exten=(yyvsp[-5].type).exten;
    int i=0,once=1;
    func_symtab_type* temp=creat_func_env();
    temp->paras_name=(yyvsp[-2].form_paras).paras_name;
    temp->paras_type=(yyvsp[-2].form_paras).paras_type;
    temp->name=(yyvsp[-4].id).var;
    temp->para_cont=(yyvsp[-2].form_paras).para_cont;
    temp->env=current_env;
    for(i=0;i<(yyvsp[-2].form_paras).para_cont;i++)
    {
        if(var_sym_look(creat_symtab((yyvsp[-2].form_paras).paras_name[i],(yyvsp[-2].form_paras).paras_type[i]))!=ERRO_NONE)
        {
            yyerror("parameter error");

        }
        if(once)
        {
            temp->addr=emit_stm(3,(yyvsp[-2].form_paras).paras_name[i],"=","pop()"); 
            once=0;
        }    
        else
           emit_stm(3,(yyvsp[-2].form_paras).paras_name[i],"=","pop()");  
    }
    (yyval.func_prefix).func_tab=temp;
}
#line 1542 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 207 "parser.y" /* yacc.c:1646  */
    {
                int i=0;
                if((yyvsp[0].form_paras).para_cont>MAX_PARA_CONT)
                {
                    yyerror("para num over flow");
                }
  
                    (yyval.form_paras).paras_type=(yyvsp[0].form_paras).paras_type;
                    (yyval.form_paras).paras_name=(yyvsp[0].form_paras).paras_name;
                (yyval.form_paras).para_cont=(yyvsp[0].form_paras).para_cont;          
            }
#line 1558 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 218 "parser.y" /* yacc.c:1646  */
    {
            (yyval.form_paras).paras_type=(struct variable_type**)malloc(sizeof(struct variable_type*)*MAX_PARA_CONT);
            (yyval.form_paras).paras_name=(char**)malloc(sizeof(char*)*MAX_PARA_CONT);
           (yyval.form_paras).paras_type[0]=void_type;
           (yyval.form_paras).para_cont=0;
        }
#line 1569 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 224 "parser.y" /* yacc.c:1646  */
    {
                
                (yyval.form_paras).paras_name=(yyvsp[-2].form_paras).paras_name;
                (yyval.form_paras).paras_type=(yyvsp[-2].form_paras).paras_type;
                (yyval.form_paras).paras_type[(yyval.form_paras).para_cont]=(yyvsp[0].form_para).var_type;
                (yyval.form_paras).paras_name[(yyval.form_paras).para_cont]=(yyvsp[0].form_para).name;
                (yyval.form_paras).para_cont=(yyvsp[-2].form_paras).para_cont+1;
                }
#line 1582 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 232 "parser.y" /* yacc.c:1646  */
    {
                (yyval.form_paras).para_cont=1;
                (yyval.form_paras).paras_type=(struct variable_type**)malloc(sizeof(struct variable_type*)*MAX_PARA_CONT);
                (yyval.form_paras).paras_name=(char**)malloc(sizeof(char*)*MAX_PARA_CONT);
                (yyval.form_paras).paras_type[0]=(yyvsp[0].form_para).var_type;
                (yyval.form_paras).paras_name[0]=(yyvsp[0].form_para).name;
        }
#line 1594 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 239 "parser.y" /* yacc.c:1646  */
    {
            (yyval.form_para).var_type=creat_variable_type();
            (yyval.form_para).var_type->base=(yyvsp[-1].type).base;
            (yyval.form_para).var_type->exten=(yyvsp[-1].type).exten;
            (yyval.form_para).name=(yyvsp[0].id).var;
        }
#line 1605 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 246 "parser.y" /* yacc.c:1646  */
    {
    (yyval.type).base=(yyvsp[-1].base_type).value_type;
    (yyval.type).exten=strdup("pointer");
}
#line 1614 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 250 "parser.y" /* yacc.c:1646  */
    {
        (yyval.type).base=(yyvsp[0].base_type).value_type;
        (yyval.type).exten=strdup("void");
    }
#line 1623 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 254 "parser.y" /* yacc.c:1646  */
    {
            (yyval.stmt_value).addr=(yyvsp[-1].stmt_value).addr;
            (yyval.stmt_value).next_addr=(yyvsp[0].stmt_value).next_addr;
            backPatch((yyvsp[-1].stmt_value).next_addr,(yyvsp[0].stmt_value).addr);
}
#line 1633 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 259 "parser.y" /* yacc.c:1646  */
    {
                (yyval.stmt_value).addr=(yyvsp[0].stmt_value).addr;
                (yyval.stmt_value).next_addr=(yyvsp[0].stmt_value).next_addr;
                //merge($1.next_addr,&$$.next_addr);
            }
#line 1643 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 264 "parser.y" /* yacc.c:1646  */
    {
                (yyval.stmt_value).next_addr=make_list(Wait);
                (yyval.stmt_value).addr=(yyval.stmt_value).next_addr;
            }
#line 1652 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 268 "parser.y" /* yacc.c:1646  */
    {
            (yyval.stmt_value).addr=(yyvsp[0].stmt_value).addr;
            (yyval.stmt_value).next_addr=(yyvsp[0].stmt_value).next_addr;
            }
#line 1661 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 272 "parser.y" /* yacc.c:1646  */
    {
            (yyval.stmt_value).addr=(yyvsp[-1].exp_value).addr;              
            (yyval.stmt_value).next_addr=(yyvsp[-1].exp_value).next_addr;
            printf("EXPRESSION:%s\n",get_value((yyval.stmt_value).addr));
            
            }
#line 1672 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 278 "parser.y" /* yacc.c:1646  */
    {
            (yyval.stmt_value).addr=(yyvsp[0].exp_value).addr;               
            (yyval.stmt_value).next_addr=(yyvsp[0].exp_value).next_addr;
            }
#line 1681 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 282 "parser.y" /* yacc.c:1646  */
    {
             (yyval.stmt_value).addr=(yyvsp[0].exp_value).addr;
            // merge($1.next_addr,$$.next_addr);               
             (yyval.stmt_value).next_addr=(yyvsp[0].exp_value).next_addr;
            }
#line 1691 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 287 "parser.y" /* yacc.c:1646  */
    {
                (yyval.stmt_value).addr=(yyvsp[0].stmt_value).addr;
                 (yyval.stmt_value).next_addr=(yyvsp[0].stmt_value).next_addr;              
            }
#line 1700 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 291 "parser.y" /* yacc.c:1646  */
    {
                if(!enter_while) 
                    yyerror("break should in while or switch");

                (yyval.stmt_value).next_addr=make_list(Wait);
                (yyval.stmt_value).addr=make_list(emit_stm(2,"goto",get_value(break_addr))) ;
            }
#line 1712 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 298 "parser.y" /* yacc.c:1646  */
    {
                if(!enter_while) 
                    yyerror("CONTINUE should in while or switch");
                (yyval.stmt_value).next_addr=make_list(Wait);
                (yyval.stmt_value).addr=make_list(emit_stm(2,"goto",get_value(continue_addr))) ;
            }
#line 1723 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 304 "parser.y" /* yacc.c:1646  */
    {
                (yyval.stmt_value).addr=(yyvsp[0].stmt_value).addr;
                //merge($1.next_addr,$$.next_addr) ;     
                (yyval.stmt_value).next_addr=(yyvsp[0].stmt_value).next_addr;
                printf(" FOR_block acc ");
                }
#line 1734 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 310 "parser.y" /* yacc.c:1646  */
    {
                (yyval.stmt_value).addr=(yyvsp[-1].stmt_value).addr;
                (yyval.stmt_value).next_addr=(yyvsp[-1].stmt_value).next_addr;
                current_env=pop(st);
            }
#line 1744 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 315 "parser.y" /* yacc.c:1646  */
    {
    push(st,current_env);
    current_env=creat_envirement();
}
#line 1753 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 319 "parser.y" /* yacc.c:1646  */
    {
                (yyval.exp_value).addr=(yyvsp[-1].exp_value).addr;
                assign_addr((yyvsp[-1].exp_value).next_addr,emit_stm(2,"ret",(yyvsp[-1].exp_value).var));
                //merge($2.next_addr,$$.next_addr);
                (yyval.exp_value).next_addr=make_list(Wait);
                (yyval.exp_value).var_type=(yyvsp[-1].exp_value).var_type;
            }
#line 1765 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 326 "parser.y" /* yacc.c:1646  */
    {
                (yyval.exp_value).addr=make_list(emit_stm(1,"ret"));
                (yyval.exp_value).next_addr=make_list(Wait);
                (yyval.exp_value).var_type=void_type;
            }
#line 1775 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 331 "parser.y" /* yacc.c:1646  */
    {
                (yyval.exp_value).addr=make_list(emit_stm(1,"ret"));
                (yyval.exp_value).next_addr=make_list(Wait);
                (yyval.exp_value).var_type=void_type;
                printf("return_empty ACC\n");}
#line 1785 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 336 "parser.y" /* yacc.c:1646  */
    {
                    // $$.addr=$5.addr;
                    // $$.next_addr=$5.next_addr;
                    str_symtab_type* temp=(str_symtab_type*)malloc(sizeof(str_symtab_type));
                    temp->var=(yyvsp[-4].id).var;
                    temp->width=0;
                    temp->env=current_env;
                    current_env=pop(st);
                    if(str_sym_look((yyvsp[-4].id).var,temp)==ALREAY_EXIST)
                    {
                        yyerror("variable redefinition");
                        return 1;
                    }
            }
#line 1804 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 350 "parser.y" /* yacc.c:1646  */
    {
            (yyval.stmt_value).addr=(yyvsp[-1].stmt_value).addr;
            backPatch((yyvsp[-1].stmt_value).next_addr,(yyvsp[0].stmt_value).addr);
            (yyval.stmt_value).next_addr=(yyvsp[0].stmt_value).next_addr;
}
#line 1814 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 355 "parser.y" /* yacc.c:1646  */
    {
                (yyval.stmt_value).addr=(yyvsp[0].stmt_value).addr;
                (yyval.stmt_value).next_addr=(yyvsp[0].stmt_value).next_addr;
            }
#line 1823 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 359 "parser.y" /* yacc.c:1646  */
    {
            int i;
            for(i=0;i<(yyvsp[-1].variables).cont;i++)
            {
                if(strcmp((yyvsp[-1].variables).var_tabs[i]->var_type->exten,"arrary")==0)
                {
                    (yyvsp[-1].variables).var_tabs[i]->elem_type=creat_variable_type();
                    (yyvsp[-1].variables).var_tabs[i]->elem_type->base=(yyvsp[-2].type).base;
                    (yyvsp[-1].variables).var_tabs[i]->elem_type->exten=(yyvsp[-2].type).exten;
                }
                else if(strcmp((yyvsp[-1].variables).var_tabs[i]->var_type->base,Void)==0)
                {
                    (yyvsp[-1].variables).var_tabs[i]->var_type->base=(yyvsp[-2].type).base;
                }    
                else
                {
                    if(typecmp((yyvsp[-1].variables).var_tabs[i]->var_type,&(yyvsp[-2].type))!=0)
                        yyerror("type definition  dismatch");
                }
                if(var_sym_look((yyvsp[-1].variables).var_tabs[i])==ALREAY_EXIST)
                {
                    yyerror("variable redefinition");
                }
                (yyvsp[-1].variables).var_tabs[i]->width*=get_width_by_type(&(yyvsp[-2].type));
            }
            (yyval.stmt_value).addr=make_list(emit_stm(3,(yyvsp[-1].variables).var_tabs[0]->var_type->base,(yyvsp[-1].variables).var_tabs[0]->var_type->exten,(yyvsp[-1].variables).var_tabs[0]->var));
            for(i=1;i<(yyvsp[-1].variables).cont;i++)
                emit_stm(3,(yyvsp[-1].variables).var_tabs[i]->var_type->base,(yyvsp[-1].variables).var_tabs[i]->var_type->exten,(yyvsp[-1].variables).var_tabs[i]->var);
            (yyval.stmt_value).next_addr=make_list(Wait);
            }
#line 1858 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 389 "parser.y" /* yacc.c:1646  */
    {
            int i;
            (yyval.variables).var_tabs=(yyvsp[-2].variables).var_tabs;
            if((yyvsp[-2].variables).cont>=MAX_PARA_CONT)
            {
                yyerror("define variable too much");
            }
            (yyval.variables).var_tabs[(yyvsp[-2].variables).cont]=(yyvsp[0].variable).var_tab;
            (yyval.variables).cont=(yyvsp[-2].variables).cont+1;
}
#line 1873 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 399 "parser.y" /* yacc.c:1646  */
    {
                (yyval.variables).var_tabs=(var_symtab_type**)malloc(sizeof(var_symtab_type*)*MAX_PARA_CONT);
                (yyval.variables).var_tabs[0]=(yyvsp[0].variable).var_tab;
                (yyval.variables).cont=1;
            }
#line 1883 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 404 "parser.y" /* yacc.c:1646  */
    {
            struct variable_type* temp_type=creat_variable_type(); 
            var_symtab_type* temp=creat_symtab((yyvsp[0].id).var,temp_type);
            temp->width=1;
            (yyval.variable).var_tab=temp;
        }
#line 1894 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 410 "parser.y" /* yacc.c:1646  */
    {
            var_symtab_type* temp=creat_symtab((yyvsp[-2].id).var,(yyvsp[0].exp_value).var_type);
            if(strcmp(temp->var_type->exten,(yyvsp[0].exp_value).var_type->exten)!=0)
            {
                yyerror("EXPRESSION retrun type dismatch");
            }
            temp->var_type->base=(yyvsp[0].exp_value).var_type->base;
            temp->value=(yyvsp[0].exp_value).var;
            temp->width=1;
            (yyval.variable).var_tab=temp;
            
         }
#line 1911 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 422 "parser.y" /* yacc.c:1646  */
    {
            var_symtab_type* temp=creat_symtab((yyvsp[-2].id).var,(yyvsp[0].exp_value).var_type);
            if(strcmp(temp->var_type->exten,(yyvsp[0].exp_value).var_type->exten)!=0)
            {
                yyerror("EXPRESSION retrun type dismatch");
            }
            temp->var_type->base=(yyvsp[0].exp_value).var_type->base;
            temp->value=(yyvsp[0].exp_value).var;
            temp->width=1; 
            (yyval.variable).var_tab=temp;
         }
#line 1927 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 433 "parser.y" /* yacc.c:1646  */
    {

         }
#line 1935 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 436 "parser.y" /* yacc.c:1646  */
    {

         }
#line 1943 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 439 "parser.y" /* yacc.c:1646  */
    {
            struct variable_type* temp_type=creat_variable_type(); 
            temp_type->exten=strdup("arrary");
            var_symtab_type* temp=creat_symtab((yyvsp[-1].id).var,temp_type);
            temp->width=(yyvsp[0].arr).cont;
            (yyval.variable).var_tab=temp;
         }
#line 1955 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 446 "parser.y" /* yacc.c:1646  */
    {   
            struct variable_type* temp_type=creat_variable_type(); 
            temp_type->exten=strdup("pointer");
            var_symtab_type* temp=creat_symtab((yyvsp[0].id).var,temp_type);
            temp->width=MACHINE_BIT/8;
            (yyval.variable).var_tab=temp;
         }
#line 1967 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 453 "parser.y" /* yacc.c:1646  */
    { 


}
#line 1976 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 458 "parser.y" /* yacc.c:1646  */
    {
            (yyval.arr).cont=(yyvsp[-3].arr).cont*atoi((yyvsp[-1].values).value);
            }
#line 1984 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 461 "parser.y" /* yacc.c:1646  */
    {
            (yyval.arr).cont=atoi((yyvsp[-1].values).value);
        }
#line 1992 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 467 "parser.y" /* yacc.c:1646  */
    {
            (yyval.exp_value).addr=(yyvsp[0].function_call).addr;
            (yyval.exp_value).next_addr=(yyvsp[0].function_call).next_addr;
            (yyval.exp_value).var=(yyvsp[0].function_call).name;
            (yyval.exp_value).var_type=(yyvsp[0].function_call).return_type;
            printf(" ***FUNCTIONCALL*** ");
            }
#line 2004 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 474 "parser.y" /* yacc.c:1646  */
    {
                struct var_symtab* temp_id=query_var_sym((yyvsp[-2].id).var);
                if(!temp_id)
                {
                    yyerror("not such variable");
                }
                if(typecmp(temp_id->var_type,(yyvsp[0].exp_value).var_type)!=0)
                {
                    yyerror("can not assign such type ");
                }
                assign_addr((yyvsp[0].exp_value).next_addr,emit_stm(3,temp_id->var,"=",(yyvsp[0].exp_value).var));
                (yyval.exp_value).addr=(yyvsp[0].exp_value).addr;
                (yyval.exp_value).next_addr=make_list(Wait);
                (yyval.exp_value).var=(yyvsp[-2].id).var;
                (yyval.exp_value).var_type=(yyvsp[0].exp_value).var_type;
                printf("ID EQUAL EXPRESSION:%s\n",get_value((yyval.exp_value).addr));
            }
#line 2026 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 491 "parser.y" /* yacc.c:1646  */
    {
                (yyval.exp_value).var=(yyvsp[0].value).value;
                (yyval.exp_value).next_addr=make_list(Wait);
                (yyval.exp_value).addr=(yyval.exp_value).next_addr;
                (yyval.exp_value).var_type=creat_variable_type();
                (yyval.exp_value).var_type->base=(yyvsp[0].value).value_type;
            }
#line 2038 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 498 "parser.y" /* yacc.c:1646  */
    {
                (yyval.exp_value).var=creat_temp_add();
                backPatch((yyvsp[-2].exp_value).next_addr,(yyvsp[0].exp_value).addr);
                (yyval.exp_value).addr=(yyvsp[-2].exp_value).addr;
                assign_addr((yyvsp[0].exp_value).next_addr,emit_stm(5,(yyval.exp_value).var,"=",(yyvsp[-2].exp_value).var,(yyvsp[-1].operator).name,(yyvsp[0].exp_value).var));
                (yyval.exp_value).next_addr=make_list(Wait);
                (yyval.exp_value).var_type=handle_type((yyvsp[-2].exp_value).var_type,(yyvsp[0].exp_value).var_type);
                printf("EXPRESSION OPERATOR1 EXPRESSION:%s\n",get_value((yyval.exp_value).addr));
            }
#line 2052 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 507 "parser.y" /* yacc.c:1646  */
    {
                printf("EXPRESSION OPERATOR2 EXPRESSION\n");
                (yyval.exp_value).var=creat_temp_add();
                (yyval.exp_value).addr=(yyvsp[-2].exp_value).addr;
                backPatch((yyvsp[-2].exp_value).next_addr,(yyvsp[0].exp_value).addr);
                assign_addr((yyvsp[0].exp_value).next_addr,emit_stm(5,(yyval.exp_value).var,"=",(yyvsp[-2].exp_value).var,(yyvsp[-1].operator).name,(yyvsp[0].exp_value).var));
                (yyval.exp_value).next_addr=make_list(Wait);
                (yyval.exp_value).var_type=handle_type((yyvsp[-2].exp_value).var_type,(yyvsp[0].exp_value).var_type);
                printf("EXPRESSION OPERATOR1 EXPRESSION:%s\n",get_value((yyval.exp_value).addr));
            }
#line 2067 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 517 "parser.y" /* yacc.c:1646  */
    {
                (yyval.exp_value).var=creat_temp_add();
                (yyval.exp_value).addr=make_list(emit_stm(4,(yyval.exp_value).var,"=",(yyvsp[-1].operator).name,(yyvsp[0].exp_value).var));
                backPatch((yyvsp[0].exp_value).next_addr,(yyval.exp_value).addr);
                (yyval.exp_value).next_addr=make_list(Wait);
                (yyval.exp_value).var_type=(yyvsp[0].exp_value).var_type;
            }
#line 2079 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 524 "parser.y" /* yacc.c:1646  */
    {
                (yyval.exp_value).var=creat_temp_add();
                (yyval.exp_value).addr=make_list(emit_stm(4,(yyval.exp_value).var,"=",(yyvsp[-1].operator).name,(yyvsp[0].exp_value).var)); 
                backPatch((yyvsp[0].exp_value).next_addr,(yyval.exp_value).addr);
                (yyval.exp_value).next_addr=make_list(Wait);
                (yyval.exp_value).var_type=creat_variable_type();
                (yyval.exp_value).var_type->base="bool";
            }
#line 2092 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 532 "parser.y" /* yacc.c:1646  */
    {
                (yyval.exp_value).var_type=(yyvsp[0].arrary).var_type;
                (yyval.exp_value).var=creat_temp_add();
                (yyval.exp_value).addr=make_list(emit_stm(6,(yyval.exp_value).var,"=",(yyvsp[0].arrary).base,"[",(yyvsp[0].arrary).var,"]"));
                (yyval.exp_value).next_addr=make_list(Wait);
            }
#line 2103 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 538 "parser.y" /* yacc.c:1646  */
    {
                (yyval.exp_value).var_type=creat_variable_type();
                (yyval.exp_value).var_type->base="int";
                (yyval.exp_value).next_addr=make_list(Wait);
                (yyval.exp_value).var=creat_temp_add();
                (yyval.exp_value).addr=make_list(emit_stm(3,(yyval.exp_value).var,"=",(yyvsp[-1].id).var));
                emit_stm(5,(yyvsp[-1].id).var,"=",(yyvsp[-1].id).var,"-","1"); 
            }
#line 2116 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 546 "parser.y" /* yacc.c:1646  */
    {
                (yyval.exp_value).var_type=creat_variable_type();
                (yyval.exp_value).var_type->base="int";
                (yyval.exp_value).next_addr=make_list(Wait);
                (yyval.exp_value).var=creat_temp_add();
                (yyval.exp_value).addr= make_list(emit_stm(5,(yyval.exp_value).var,"=",(yyvsp[0].id).var,"-","1")); 
               
            }
#line 2129 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 554 "parser.y" /* yacc.c:1646  */
    {
                (yyval.exp_value).var_type=(yyvsp[-1].exp_value).var_type;
                (yyval.exp_value).var=creat_temp_add();
                (yyval.exp_value).addr=make_list(emit_stm(3,(yyval.exp_value).var,"=",(yyvsp[-1].exp_value).var));
                (yyval.exp_value).next_addr=make_list(Wait);    
            }
#line 2140 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 560 "parser.y" /* yacc.c:1646  */
    {
                printf("ID\n");
                var_symtab_type* temp=query_var_sym((yyvsp[0].id).var);
                printf("ID\n");
                if(temp==(var_symtab_type*)0)
                {
                    yyerror("no such id:");
                    printf("%s\n",(yyvsp[0].id).var);
                }    
                (yyval.exp_value).var=(yyvsp[0].id).var;
                (yyval.exp_value).next_addr=make_list(Wait);
                (yyval.exp_value).addr=(yyval.exp_value).next_addr;
                (yyval.exp_value).var_type=temp->var_type;
                
            }
#line 2160 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 575 "parser.y" /* yacc.c:1646  */
    {
        backPatch((yyvsp[-3].arrary).next_addr,(yyvsp[-1].exp_value).addr);
        (yyval.arrary).var=creat_temp_add();
        struct var_symtab* temp=query_var_sym((yyvsp[-3].arrary).var); 
        (yyval.arrary).var_type=(yyvsp[-3].arrary).var_type;
        (yyval.arrary).addr=make_list(emit_stm(5,(yyval.arrary).var,"=",(yyvsp[-1].exp_value).var,"*",itoa(temp->width)));
        emit_stm(5,(yyval.arrary).var,"=",(yyvsp[-3].arrary).var,"+",(yyval.arrary).var);
        backPatch((yyvsp[-1].exp_value).next_addr,(yyval.arrary).addr);
        (yyval.arrary).next_addr=make_list(Wait);
        }
#line 2175 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 585 "parser.y" /* yacc.c:1646  */
    {
        (yyval.arrary).base=(yyvsp[-3].id).var;
        (yyval.arrary).var=creat_temp_add();
        (yyval.arrary).next_addr=make_list(Wait);
        if(strcmp((yyvsp[-1].exp_value).var_type->base,"int")!=0)
        {
            yyerror("index erro type");
        }
        struct var_symtab* temp=query_var_sym((yyvsp[-3].id).var); 
        printf("L:base:%s %s\n",temp->var_type->base,temp->var_type->exten);
        if(temp==(var_symtab_type*)0||strcmp(temp->var_type->exten,"arrary")!=0)
        {
            yyerror("such id is not array");
        }
        (yyval.arrary).var_type=temp->var_type;
        (yyval.arrary).addr=make_list(emit_stm(5,(yyval.arrary).var,"=",(yyvsp[-1].exp_value).var,"*",itoa(get_width_by_type(temp->elem_type))));
        backPatch((yyvsp[-1].exp_value).next_addr,(yyval.arrary).addr);
    }
#line 2198 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 604 "parser.y" /* yacc.c:1646  */
    {                 
                if(strcmp((yyvsp[-1].operator).name,"&&")==0)
                { 
                    (yyval.bool_exp_value).false_addr=(yyvsp[-2].bool_exp_value).false_addr;
                    backPatch((yyvsp[-2].bool_exp_value).true_addr,(yyvsp[0].bool_exp_value).addr);
                    merge((yyvsp[0].bool_exp_value).false_addr,(yyvsp[-2].bool_exp_value).false_addr);
                    (yyval.bool_exp_value).true_addr=(yyvsp[0].bool_exp_value).true_addr;
                }
                else if(strcmp((yyvsp[-1].operator).name,"||")==0)
                {
                    backPatch((yyvsp[-2].bool_exp_value).false_addr,(yyvsp[0].bool_exp_value).addr);
                    merge((yyvsp[-2].bool_exp_value).true_addr,(yyvsp[0].bool_exp_value).true_addr);
                    (yyval.bool_exp_value).true_addr=(yyvsp[0].bool_exp_value).true_addr;
                    (yyval.bool_exp_value).false_addr=(yyvsp[0].bool_exp_value).false_addr;
                }
                (yyval.bool_exp_value).var=creat_temp_add();
                (yyval.bool_exp_value).addr=(yyvsp[-2].bool_exp_value).addr;
                assign_addr((yyvsp[0].bool_exp_value).next_addr,emit_stm(5,(yyval.bool_exp_value).var,"=",(yyvsp[-2].bool_exp_value).var,(yyvsp[-1].operator).name,(yyvsp[0].bool_exp_value).var));
            }
#line 2222 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 623 "parser.y" /* yacc.c:1646  */
    {
                (yyval.bool_exp_value).addr=(yyvsp[0].exp_value).addr;
                (yyval.bool_exp_value).var=creat_temp_add();
                assign_addr((yyvsp[0].exp_value).next_addr,emit_stm(3,(yyval.bool_exp_value).var,"=",(yyvsp[0].exp_value).var));
                (yyval.bool_exp_value).true_addr=make_list(Wait);
                (yyval.bool_exp_value).false_addr=make_list(Wait);
            }
#line 2234 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 630 "parser.y" /* yacc.c:1646  */
    {
                (yyval.bool_exp_value).var=creat_temp_add();
                (yyval.bool_exp_value).addr=(yyvsp[-2].exp_value).addr;
                assign_addr((yyvsp[0].exp_value).next_addr,emit_stm(5,(yyval.bool_exp_value).var,"=",(yyvsp[-2].exp_value).var,(yyvsp[-1].operator).name,(yyvsp[0].exp_value).var));
                backPatch((yyvsp[-2].exp_value).next_addr,(yyvsp[0].exp_value).addr);
                (yyval.bool_exp_value).true_addr=make_list(Wait);
                (yyval.bool_exp_value).false_addr=make_list(Wait);
            }
#line 2247 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 638 "parser.y" /* yacc.c:1646  */
    {
                (yyval.bool_exp_value).var=creat_temp_add();
                (yyval.bool_exp_value).addr=(yyvsp[0].bool_exp_value).addr;
                emit_stm(4,(yyval.bool_exp_value).var,"=",(yyvsp[-1].operator).name,(yyvsp[0].bool_exp_value).var);
                (yyval.bool_exp_value).true_addr=make_list(Wait);
                (yyval.bool_exp_value).false_addr=make_list(Wait);
                //$$.next_addr=make_list(Wait);

                if(strcmp((yyvsp[-1].operator).name,"!")==0){
                    (yyval.bool_exp_value).true_addr=(yyvsp[0].bool_exp_value).false_addr;
                    (yyval.bool_exp_value).false_addr=(yyvsp[0].bool_exp_value).true_addr;
                }
                else{
                    yyerror("wrong bool operator");
                }
            }
#line 2268 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 656 "parser.y" /* yacc.c:1646  */
    {(yyval.value).value=(yyvsp[0].values).value;(yyval.value).value_type="int";}
#line 2274 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 657 "parser.y" /* yacc.c:1646  */
    {(yyval.value).value=(yyvsp[0].values).value;(yyval.value).value_type="float";}
#line 2280 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 658 "parser.y" /* yacc.c:1646  */
    {(yyval.value).value=(yyvsp[0].values).value;(yyval.value).value_type="bool";}
#line 2286 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 659 "parser.y" /* yacc.c:1646  */
    {(yyval.value).value=(yyvsp[0].values).value;(yyval.value).value_type="string";}
#line 2292 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 661 "parser.y" /* yacc.c:1646  */
    {
                    printf("1");
                    printf(":%s\n",func_env->name);
                    func_symtab_type* temp_func=query_fuc_sym((yyvsp[-3].id).var);
                    if(temp_func==(func_symtab_type*)0)
                    {
                        yyerror("no such function");
                    }
                    else
                    {
                        (yyval.function_call).return_type=temp_func->return_type;
                        printf("1");
                        int i;
                        if((yyvsp[-1].actual_paras).para_cont>0)
                        {
                            if(typecmp(temp_func->paras_type[0],(yyvsp[-1].actual_paras).paras_type[0])!=0)
                                yyerror("para type dismatch");
                            else
                                (yyval.function_call).addr=make_list(emit_stm(2,"push",(yyvsp[-1].actual_paras).paras_name[0])) ;
                            for(i=1;i<temp_func->para_cont;i++)
                            {
                                if(typecmp(temp_func->paras_type[i],(yyvsp[-1].actual_paras).paras_type[i])!=0)
                                    yyerror("para type dismatch");
                                emit_stm(2,"push",(yyvsp[-1].actual_paras).paras_name[i]);
                            }
                            emit_stm(2,"goto",temp_func->addr);
                        }
                        else
                            (yyval.function_call).addr=make_list(emit_stm(2,"goto",temp_func->addr));
                        (yyval.function_call).name=strdup("eax");
                        (yyval.function_call).next_addr=make_list(Wait);
                    }
                }
#line 2330 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 695 "parser.y" /* yacc.c:1646  */
    {
            if((yyvsp[-2].actual_paras).para_cont==0)
                yyerror("void follow no void");
            (yyval.actual_paras).paras_name=(yyvsp[-2].actual_paras).paras_name;
            (yyval.actual_paras).paras_type=(yyvsp[-2].actual_paras).paras_type;
            (yyval.actual_paras).paras_type[(yyvsp[-2].actual_paras).para_cont]=(yyvsp[0].actual_para).var_type;
            (yyval.actual_paras).paras_name[(yyvsp[-2].actual_paras).para_cont]=(yyvsp[0].actual_para).var;
            (yyval.actual_paras).para_cont=(yyvsp[-2].actual_paras).para_cont+1;
            }
#line 2344 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 704 "parser.y" /* yacc.c:1646  */
    {
                (yyval.actual_paras).paras_type=(struct variable_type**)malloc(sizeof(struct variable_type*)*MAX_PARA_CONT);
                (yyval.actual_paras).paras_name=(char**)malloc(sizeof(char*)*MAX_PARA_CONT);
                (yyval.actual_paras).para_cont=1;
                (yyval.actual_paras).paras_type[0]=(yyvsp[0].actual_para).var_type;
                (yyval.actual_paras).paras_name[0]=(yyvsp[0].actual_para).var;
            }
#line 2356 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 711 "parser.y" /* yacc.c:1646  */
    {   
                    (yyval.actual_paras).para_cont=0;
                }
#line 2364 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 715 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.actual_para).var=(yyvsp[0].bool_exp_value).var;
                    (yyval.actual_para).var_type=creat_variable_type();
                    (yyval.actual_para).var_type->base="bool";
           }
#line 2374 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 721 "parser.y" /* yacc.c:1646  */
    {
                (yyval.exp_value).addr=(yyvsp[-1].bool_exp_value).addr;
                if(strcmp(get_value((yyvsp[0].stmt_value).addr),Wait)==0)
                {
                    printf("come yes");
                    merge((yyvsp[-1].bool_exp_value).false_addr,(yyvsp[-1].bool_exp_value).true_addr);
                    merge((yyvsp[0].stmt_value).next_addr,(yyvsp[-1].bool_exp_value).false_addr);
                }
                else
                {
                    backPatch((yyvsp[-1].bool_exp_value).true_addr,(yyvsp[0].stmt_value).addr);
                    merge((yyvsp[0].stmt_value).next_addr,(yyvsp[-1].bool_exp_value).false_addr);
                }
                (yyval.exp_value).next_addr=(yyvsp[0].stmt_value).next_addr;
                printf("_____if acc_____");
                }
#line 2395 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 737 "parser.y" /* yacc.c:1646  */
    {
                (yyval.exp_value).addr=(yyvsp[-3].bool_exp_value).addr;
                if(strcmp(get_value((yyvsp[-2].stmt_value).addr),Wait)==0&&strcmp(get_value((yyvsp[0].stmt_value).addr),Wait)==0)
                {
                    merge((yyvsp[-2].stmt_value).addr,(yyvsp[-3].bool_exp_value).true_addr);
                    merge((yyvsp[0].stmt_value).next_addr,(yyvsp[-3].bool_exp_value).false_addr);
                    merge((yyvsp[-3].bool_exp_value).true_addr,(yyvsp[0].stmt_value).next_addr);
                    (yyval.exp_value).next_addr=(yyvsp[-3].bool_exp_value).true_addr; 
                }
                else if(strcmp(get_value((yyvsp[-2].stmt_value).addr),Wait)==0)
                {

                    merge((yyvsp[-2].stmt_value).addr,(yyvsp[-3].bool_exp_value).true_addr);
                    merge((yyvsp[0].stmt_value).next_addr,(yyvsp[-2].stmt_value).next_addr);
                    backPatch((yyvsp[-3].bool_exp_value).false_addr,(yyvsp[0].stmt_value).addr);
                    (yyval.exp_value).next_addr=(yyvsp[0].stmt_value).next_addr;       
                }
                else if(strcmp(get_value((yyvsp[0].stmt_value).addr),Wait)==0)
                {
                    backPatch((yyvsp[-3].bool_exp_value).true_addr,(yyvsp[-2].stmt_value).addr);
                    merge((yyvsp[0].stmt_value).next_addr,(yyvsp[-3].bool_exp_value).false_addr);
                    merge((yyvsp[-2].stmt_value).next_addr,(yyvsp[0].stmt_value).next_addr);
                    (yyval.exp_value).next_addr=(yyvsp[-2].stmt_value).addr;
                }
                else
                {
                    backPatch((yyvsp[-3].bool_exp_value).true_addr,(yyvsp[-2].stmt_value).addr);
                    backPatch((yyvsp[-3].bool_exp_value).false_addr,(yyvsp[0].stmt_value).addr);
                    merge((yyvsp[-2].stmt_value).next_addr,(yyvsp[0].stmt_value).next_addr);
                    (yyval.exp_value).next_addr=(yyvsp[-2].stmt_value).next_addr;
                }

                printf("_____if acc_____");
            }
#line 2434 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 771 "parser.y" /* yacc.c:1646  */
    {
                (yyval.bool_exp_value).addr=(yyvsp[-1].bool_exp_value).addr;
                (yyval.bool_exp_value).true_addr=(yyvsp[-1].bool_exp_value).true_addr;
                (yyval.bool_exp_value).false_addr=(yyvsp[-1].bool_exp_value).false_addr;
                emit_stm(4,"if",(yyvsp[-1].bool_exp_value).var,"goto ",emit_stm_ready((yyvsp[-1].bool_exp_value).true_addr));
                emit_stm(2,"goto ",emit_stm_ready((yyvsp[-1].bool_exp_value).false_addr));     
        }
#line 2446 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 778 "parser.y" /* yacc.c:1646  */
    {
                enter_while--;
                backPatch((yyvsp[-1].bool_exp_value).true_addr,(yyvsp[0].stmt_value).addr);
                backPatch((yyvsp[0].stmt_value).next_addr,(yyvsp[-1].bool_exp_value).addr);
                (yyval.exp_value).next_addr=(yyvsp[-1].bool_exp_value).false_addr;
                (yyval.exp_value).addr=(yyvsp[-1].bool_exp_value).addr;
                emit_stm(2,"goto ",get_value((yyvsp[-1].bool_exp_value).addr));
                printf("_______while acc________");
                }
#line 2460 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 787 "parser.y" /* yacc.c:1646  */
    {
        enter_while++;
        (yyval.bool_exp_value).addr=(yyvsp[-1].bool_exp_value).addr;
        continue_addr=(yyvsp[-1].bool_exp_value).addr;
        (yyval.bool_exp_value).true_addr=(yyvsp[-1].bool_exp_value).true_addr;
        (yyval.bool_exp_value).false_addr=(yyvsp[-1].bool_exp_value).false_addr;
        emit_stm(4,"if",(yyvsp[-1].bool_exp_value).var,"goto ",emit_stm_ready((yyvsp[-1].bool_exp_value).true_addr));
        emit_stm(2,"goto ",emit_stm_ready((yyvsp[-1].bool_exp_value).false_addr)); 
        break_addr=(yyvsp[-1].bool_exp_value).false_addr;
        printf("*****WHILE_PREFIX:%s****\n",get_value(break_addr));
}
#line 2476 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 798 "parser.y" /* yacc.c:1646  */
    {
                    enter_while--;
                    backPatch((yyvsp[-3].bool_exp_value).true_addr,(yyvsp[-2].exp_value).addr);
                    backPatch((yyvsp[0].stmt_value).next_addr,(yyvsp[-3].bool_exp_value).addr);
                    backPatch((yyvsp[-2].exp_value).next_addr,(yyvsp[0].stmt_value).addr);
                    (yyval.stmt_value).addr=(yyvsp[-3].bool_exp_value).addr;
                    (yyval.stmt_value).next_addr=(yyvsp[-3].bool_exp_value).false_addr;
                    printf("____for acc_____");
                    emit_stm(2,"goto ",get_value((yyvsp[-3].bool_exp_value).next_addr)); 
}
#line 2491 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 808 "parser.y" /* yacc.c:1646  */
    {
            (yyval.bool_exp_value).addr=(yyvsp[-3].exp_value).addr;
            backPatch((yyvsp[-3].exp_value).next_addr,(yyvsp[-1].bool_exp_value).addr);
            (yyval.bool_exp_value).next_addr=(yyvsp[-1].bool_exp_value).addr;
            continue_addr=(yyvsp[-1].bool_exp_value).addr;
            (yyval.bool_exp_value).true_addr=(yyvsp[-1].bool_exp_value).true_addr;
            (yyval.bool_exp_value).false_addr=(yyvsp[-1].bool_exp_value).false_addr;
            emit_stm(4,"if",(yyvsp[-1].bool_exp_value).var,"goto ",emit_stm_ready((yyvsp[-1].bool_exp_value).true_addr));
            emit_stm(2,"goto ",emit_stm_ready((yyvsp[-1].bool_exp_value).false_addr)); 
            break_addr=(yyvsp[-1].bool_exp_value).false_addr;
}
#line 2507 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 819 "parser.y" /* yacc.c:1646  */
    {
            (yyval.exp_value).addr=(yyvsp[0].exp_value).addr;
            (yyval.exp_value).next_addr=(yyvsp[0].exp_value).next_addr;
}
#line 2516 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 823 "parser.y" /* yacc.c:1646  */
    {
                (yyval.exp_value).next_addr=make_list(Wait);
                (yyval.exp_value).addr=(yyval.exp_value).next_addr;
            }
#line 2525 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 827 "parser.y" /* yacc.c:1646  */
    {
            (yyval.exp_value).addr=(yyvsp[-2].exp_value).addr;
            backPatch((yyvsp[-2].exp_value).next_addr,(yyvsp[0].exp_value).addr);
            (yyval.exp_value).next_addr=(yyvsp[0].exp_value).next_addr;
            }
#line 2535 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 832 "parser.y" /* yacc.c:1646  */
    {
                (yyval.exp_value).addr=(yyvsp[0].exp_value).addr;
                (yyval.exp_value).next_addr=(yyvsp[0].exp_value).next_addr;
            }
#line 2544 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 836 "parser.y" /* yacc.c:1646  */
    {
            (yyval.exp_value).addr=(yyvsp[0].exp_value).addr;
            (yyval.exp_value).next_addr=(yyvsp[0].exp_value).next_addr;     
}
#line 2553 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 840 "parser.y" /* yacc.c:1646  */
    {
                (yyval.exp_value).next_addr=make_list(Wait);
                (yyval.exp_value).addr=(yyval.exp_value).next_addr;
            }
#line 2562 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 845 "parser.y" /* yacc.c:1646  */
    {
            (yyval.exp_value).addr=(yyvsp[-2].exp_value).addr;
            backPatch((yyvsp[-2].exp_value).next_addr,(yyvsp[0].exp_value).addr);
            (yyval.exp_value).next_addr=(yyvsp[0].exp_value).next_addr;  
}
#line 2572 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 850 "parser.y" /* yacc.c:1646  */
    {
                (yyval.exp_value).addr=(yyvsp[0].exp_value).addr;
                (yyval.exp_value).next_addr=(yyvsp[0].exp_value).next_addr;
            }
#line 2581 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2585 "parser.tab.c" /* yacc.c:1646  */
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
#line 854 "parser.y" /* yacc.c:1906  */

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
