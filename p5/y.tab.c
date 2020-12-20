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
#line 1 "alfa.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alfa.h"

#define MAX 64

extern FILE* yyout;
extern int yylex(void);
void yyerror(const char * s);

extern int is_morpho;
extern int n_lines;
extern int n_cols;

extern symbol_table aux_symbol_table;
symbol *aux_symb;

int curr_type;
int curr_class;
int curr_len;

int local_var_pos;
int pos_params;

int num_params = 0;
int local_var_num = 1;
int func_ret = 0;
int func_flag_dec = 0;
int num_params_call = 0;
int func_call = 0;
int label = 0;




#line 104 "y.tab.c" /* yacc.c:339  */

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
    TOK_MAIN = 258,
    TOK_INT = 259,
    TOK_BOOLEAN = 260,
    TOK_ARRAY = 261,
    TOK_FUNCTION = 262,
    TOK_IF = 263,
    TOK_ELSE = 264,
    TOK_WHILE = 265,
    TOK_SCANF = 266,
    TOK_PRINTF = 267,
    TOK_RETURN = 268,
    TOK_PUNTOYCOMA = 269,
    TOK_COMA = 270,
    TOK_PARENTESISIZQUIERDO = 271,
    TOK_PARENTESISDERECHO = 272,
    TOK_CORCHETEIZQUIERDO = 273,
    TOK_CORCHETEDERECHO = 274,
    TOK_LLAVEIZQUIERDA = 275,
    TOK_LLAVEDERECHA = 276,
    TOK_ASIGNACION = 277,
    TOK_MAS = 278,
    TOK_MENOS = 279,
    TOK_DIVISION = 280,
    TOK_ASTERISCO = 281,
    TOK_AND = 282,
    TOK_OR = 283,
    TOK_NOT = 284,
    TOK_IGUAL = 285,
    TOK_DISTINTO = 286,
    TOK_MENORIGUAL = 287,
    TOK_MAYORIGUAL = 288,
    TOK_MENOR = 289,
    TOK_MAYOR = 290,
    TOK_TRUE = 291,
    TOK_FALSE = 292,
    TOK_CONSTANTE_ENTERA = 293,
    TOK_IDENTIFICADOR = 294
  };
#endif
/* Tokens.  */
#define TOK_MAIN 258
#define TOK_INT 259
#define TOK_BOOLEAN 260
#define TOK_ARRAY 261
#define TOK_FUNCTION 262
#define TOK_IF 263
#define TOK_ELSE 264
#define TOK_WHILE 265
#define TOK_SCANF 266
#define TOK_PRINTF 267
#define TOK_RETURN 268
#define TOK_PUNTOYCOMA 269
#define TOK_COMA 270
#define TOK_PARENTESISIZQUIERDO 271
#define TOK_PARENTESISDERECHO 272
#define TOK_CORCHETEIZQUIERDO 273
#define TOK_CORCHETEDERECHO 274
#define TOK_LLAVEIZQUIERDA 275
#define TOK_LLAVEDERECHA 276
#define TOK_ASIGNACION 277
#define TOK_MAS 278
#define TOK_MENOS 279
#define TOK_DIVISION 280
#define TOK_ASTERISCO 281
#define TOK_AND 282
#define TOK_OR 283
#define TOK_NOT 284
#define TOK_IGUAL 285
#define TOK_DISTINTO 286
#define TOK_MENORIGUAL 287
#define TOK_MAYORIGUAL 288
#define TOK_MENOR 289
#define TOK_MAYOR 290
#define TOK_TRUE 291
#define TOK_FALSE 292
#define TOK_CONSTANTE_ENTERA 293
#define TOK_IDENTIFICADOR 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 40 "alfa.y" /* yacc.c:355  */

    attribute_type attributes;

#line 226 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 243 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   159

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  151

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

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
      35,    36,    37,    38,    39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   117,   117,   123,   129,   134,   139,   142,   147,   152,
     156,   162,   167,   172,   179,   190,   193,   198,   201,   206,
     228,   246,   273,   276,   281,   284,   289,   296,   299,   304,
     307,   312,   315,   320,   323,   326,   329,   334,   337,   342,
     374,   407,   443,   447,   453,   465,   471,   477,   483,   494,
     512,   518,   531,   548,   565,   583,   600,   617,   634,   651,
     669,   701,   709,   714,   719,   742,   772,   776,   781,   785,
     790,   807,   825,   843,   861,   879,   899,   904,   911,   918,
     927,   940,   966
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_MAIN", "TOK_INT", "TOK_BOOLEAN",
  "TOK_ARRAY", "TOK_FUNCTION", "TOK_IF", "TOK_ELSE", "TOK_WHILE",
  "TOK_SCANF", "TOK_PRINTF", "TOK_RETURN", "TOK_PUNTOYCOMA", "TOK_COMA",
  "TOK_PARENTESISIZQUIERDO", "TOK_PARENTESISDERECHO",
  "TOK_CORCHETEIZQUIERDO", "TOK_CORCHETEDERECHO", "TOK_LLAVEIZQUIERDA",
  "TOK_LLAVEDERECHA", "TOK_ASIGNACION", "TOK_MAS", "TOK_MENOS",
  "TOK_DIVISION", "TOK_ASTERISCO", "TOK_AND", "TOK_OR", "TOK_NOT",
  "TOK_IGUAL", "TOK_DISTINTO", "TOK_MENORIGUAL", "TOK_MAYORIGUAL",
  "TOK_MENOR", "TOK_MAYOR", "TOK_TRUE", "TOK_FALSE",
  "TOK_CONSTANTE_ENTERA", "TOK_IDENTIFICADOR", "$accept", "programa",
  "escritura_cabecera", "escritura_codigo", "escritura_main",
  "declaraciones", "declaracion", "clase", "clase_escalar", "tipo",
  "clase_vector", "identificadores", "funciones", "funcion",
  "funcion_declaracion", "nombre_funcion", "parametros_funcion",
  "resto_parametros_funcion", "parametro_funcion", "declaraciones_funcion",
  "sentencias", "sentencia", "sentencia_simple", "bloque", "asignacion",
  "elemento_vector", "condicional", "if_exp", "if_exp_sentencias", "bucle",
  "while", "while_exp", "lectura", "escritura", "retorno_funcion", "exp",
  "lista_expresiones", "resto_lista_expresiones", "comparacion",
  "constante", "constante_logica", "constante_entera", "identificador",
  "idpf", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

#define YYPACT_NINF -35

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-35)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -35,     2,     4,   -35,    -1,    34,   -35,   -35,    10,   -35,
      34,   -18,   -35,   -35,   -35,    -8,    21,   -35,   -35,    11,
      36,    14,    10,   -35,    21,    37,    55,   -35,   -18,   -35,
      54,    35,    37,   -35,    59,    61,    39,    73,    73,   -13,
      58,    37,    74,   -35,   -35,    65,   -35,    37,    75,   -35,
      73,    37,   -35,   -35,   -35,    10,   -35,   -35,   -35,    77,
      73,   -35,   -35,    73,    73,    73,   -35,   -35,    -5,   -35,
      31,   -35,   -35,   -35,    31,    73,    73,   -35,   -35,   -35,
      73,   -35,    91,   119,    78,    64,    87,   104,   -35,   131,
     100,    88,    18,   -35,    73,    73,    73,    73,    73,    73,
      73,    67,    31,    31,    99,   101,   -35,   -35,   -35,   109,
      10,   -35,   117,   -35,    73,    73,    73,    73,    73,    73,
     -35,     9,   103,    18,    18,   -35,   -35,    44,    90,   -35,
      37,   -35,    34,   104,   -35,    31,    31,    31,    31,    31,
      31,    73,   -35,   -35,   118,   -35,   -35,   -35,     9,   -35,
     -35
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,     0,     0,    12,    13,     0,     4,
       6,     0,     9,    11,    10,     0,    18,     7,    81,     0,
      15,     0,     0,     5,    18,     0,     0,     8,     0,    80,
       0,     0,     0,    17,     0,     0,     0,     0,     0,     0,
       0,    29,     0,    32,    33,     0,    37,     0,     0,    38,
       0,     0,    34,    35,    36,    23,    16,    14,    21,     0,
       0,    47,    49,     0,     0,     0,    78,    79,    60,    64,
      50,    61,    77,    76,    51,     0,     0,    19,    30,    31,
       0,    45,    42,     0,     0,     0,     0,    25,     2,     0,
       0,     0,    56,    59,    67,     0,     0,     0,     0,     0,
       0,     0,    39,    40,     0,     0,    46,    82,    26,     0,
       0,    22,     0,    62,     0,     0,     0,     0,     0,     0,
      63,    69,     0,    52,    53,    54,    55,    57,    58,    41,
       0,    48,    28,    25,    44,    70,    71,    72,    73,    74,
      75,     0,    66,    65,     0,    27,    20,    24,    69,    43,
      68
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -35,   -35,   -35,   -35,   -35,   -10,   -35,   -35,   -35,    -2,
     -35,   110,   116,   -35,   -35,   -35,   -35,     8,    40,   -35,
     -29,   -35,   -35,   -35,   -35,   -24,   -35,   -35,   -35,   -35,
     -35,   -35,   -35,   -35,   -35,   -34,   -35,     1,   -35,   -35,
     -35,   130,   -35,   -35
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    16,    32,     9,    10,    11,    12,    13,
      14,    19,    23,    24,    25,    26,    86,   111,    87,   146,
      40,    41,    42,    43,    44,    69,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    70,   122,   142,    91,    71,
      72,    73,    20,   108
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      17,    45,     3,    59,    74,    75,    15,     4,    45,    76,
      21,    94,    78,    75,     6,     7,    83,    45,    81,     5,
      31,    18,    84,    45,   141,    27,    89,    45,    22,    90,
      92,    93,    95,    96,    97,    98,    99,   100,     6,     7,
       8,   101,   102,    97,    98,    34,   103,    35,    36,    37,
      38,    28,    29,    85,    95,    96,    97,    98,    99,   100,
     121,   123,   124,   125,   126,   127,   128,    95,    96,    97,
      98,    55,   100,    57,    58,    60,    39,    61,    62,    77,
     135,   136,   137,   138,   139,   140,   129,    80,    79,    63,
      95,    96,    97,    98,    99,   100,    82,    64,    88,   106,
     104,   144,    65,   107,   109,   120,    45,   148,    85,    66,
      67,    29,    68,    95,    96,    97,    98,   113,   110,   130,
     143,   131,   145,    95,    96,    97,    98,    99,   100,   132,
     114,   115,   116,   117,   118,   119,   105,   134,    56,   149,
      33,   147,    95,    96,    97,    98,    99,   100,   112,   150,
     133,    30,     0,     0,    95,    96,    97,    98,    99,   100
};

static const yytype_int16 yycheck[] =
{
      10,    25,     0,    32,    38,    18,     8,     3,    32,    22,
      18,    16,    41,    18,     4,     5,    50,    41,    47,    20,
      22,    39,    51,    47,    15,    14,    60,    51,     7,    63,
      64,    65,    23,    24,    25,    26,    27,    28,     4,     5,
       6,    75,    76,    25,    26,     8,    80,    10,    11,    12,
      13,    15,    38,    55,    23,    24,    25,    26,    27,    28,
      94,    95,    96,    97,    98,    99,   100,    23,    24,    25,
      26,    16,    28,    19,    39,    16,    39,    16,    39,    21,
     114,   115,   116,   117,   118,   119,    19,    22,    14,    16,
      23,    24,    25,    26,    27,    28,    21,    24,    21,    21,
       9,   130,    29,    39,    17,    17,   130,   141,   110,    36,
      37,    38,    39,    23,    24,    25,    26,    17,    14,    20,
      17,    20,   132,    23,    24,    25,    26,    27,    28,    20,
      30,    31,    32,    33,    34,    35,    17,    20,    28,    21,
      24,   133,    23,    24,    25,    26,    27,    28,    17,   148,
     110,    21,    -1,    -1,    23,    24,    25,    26,    27,    28
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,    42,     0,     3,    20,     4,     5,     6,    45,
      46,    47,    48,    49,    50,    49,    43,    45,    39,    51,
      82,    18,     7,    52,    53,    54,    55,    14,    15,    38,
      81,    49,    44,    52,     8,    10,    11,    12,    13,    39,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    16,    51,    19,    39,    60,
      16,    16,    39,    16,    24,    29,    36,    37,    39,    65,
      75,    79,    80,    81,    75,    18,    22,    21,    60,    14,
      22,    60,    21,    75,    60,    49,    56,    58,    21,    75,
      75,    78,    75,    75,    16,    23,    24,    25,    26,    27,
      28,    75,    75,    75,     9,    17,    21,    39,    83,    17,
      14,    57,    17,    17,    30,    31,    32,    33,    34,    35,
      17,    75,    76,    75,    75,    75,    75,    75,    75,    19,
      20,    20,    20,    58,    20,    75,    75,    75,    75,    75,
      75,    15,    77,    17,    60,    45,    59,    57,    75,    21,
      77
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    43,    44,    45,    45,    46,    47,
      47,    48,    49,    49,    50,    51,    51,    52,    52,    53,
      54,    55,    56,    56,    57,    57,    58,    59,    59,    60,
      60,    61,    61,    62,    62,    62,    62,    63,    63,    64,
      64,    65,    66,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    76,    76,    77,    77,
      78,    78,    78,    78,    78,    78,    79,    79,    80,    80,
      81,    82,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     9,     0,     0,     0,     1,     2,     3,     1,
       1,     1,     1,     1,     5,     1,     3,     2,     0,     3,
       6,     3,     2,     0,     3,     0,     2,     1,     0,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     4,     2,     6,     5,     2,     3,     2,     4,     2,
       2,     2,     3,     3,     3,     3,     2,     3,     3,     2,
       1,     1,     3,     3,     1,     4,     2,     0,     3,     0,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1
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
        case 2:
#line 117 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n");
        escribir_fin(yyout);
    }
#line 1444 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 123 "alfa.y" /* yacc.c:1646  */
    {
        escribir_subseccion_data(yyout);
        escribir_cabecera_bss(yyout);
    }
#line 1453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 129 "alfa.y" /* yacc.c:1646  */
    {
        escribir_segmento_codigo(yyout);
    }
#line 1461 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 134 "alfa.y" /* yacc.c:1646  */
    {
        escribir_inicio_main(yyout);
    }
#line 1469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 139 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R2:\t<declaraciones> ::= <declaracion>\n");
    }
#line 1477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 142 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");
    }
#line 1485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 147 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");
    }
#line 1493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 152 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R5:\t<clase> ::= <clase_escalar>\n");
        curr_class = SCALAR;
    }
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 156 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R7:\t<clase> ::= <clase_vector>\n");
        curr_class = VECTOR;
    }
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 162 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R9:\t<clase_escalar> ::= <tipo>\n");
    }
#line 1519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 167 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R10:\t<tipo> ::= int\n");
        curr_type = INT;
        curr_len = 1;
    }
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 172 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R11:\t<tipo> ::= boolean\n");
        curr_type = BOOL;
        curr_len = 1;
    }
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 179 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R15:\t<clase_vector> ::= array <tipo> [ <constante_entera> ]\n");
        if((yyvsp[-1].attributes).value > MAX || (yyvsp[-1].attributes).value <= 0){
            printf("****Error semantico en lin %d: El tamanyo del vector %s excede los limites permitidos (1,64).\n", n_lines, (yyvsp[-1].attributes).lexeme);
            return -1;
        }
        (yyval.attributes).value = (yyvsp[-1].attributes).value;
        curr_len = (yyvsp[-1].attributes).value;
    }
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 190 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R18:\t<identificadores> ::= <identificador>\n");
    }
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 193 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");
    }
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 198 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R20:\t<funciones> ::= <funcion> <funciones>\n");
    }
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 201 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R21:\t<funciones> ::=\n");
    }
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 206 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R22:\t<funcion> ::= function <tipo> <identificador> ( <parametros_funcion> ) { <declaraciones_funcion> <sentencias> }\n");
        if(func_ret==0){
            printf("****Error semantico en lin %d: Funcion <nombre_funcion> sin sentencia de retorno\n", n_lines);
			return -1;
        }
        if(close_scope(&aux_symbol_table) == -1) return -1;

        aux_symb = search_table(&aux_symbol_table, (yyvsp[-2].attributes).lexeme);
        if(!aux_symb) return -1;

        aux_symb = symbol_create((yyvsp[-2].attributes).lexeme, FUNCTION, aux_symb->type, -1, -1, -1, num_params, -1, local_var_num);

        insert_table(&aux_symbol_table, (yyvsp[-2].attributes).lexeme, aux_symb);

        if(close_scope(&aux_symbol_table) == -1) return -1;

        func_flag_dec = 0;
        // symbol_delete(aux_symb);
    }
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 228 "alfa.y" /* yacc.c:1646  */
    {

        strcpy((yyval.attributes).lexeme, (yyvsp[-5].attributes).lexeme);
        (yyval.attributes).type = (yyvsp[-5].attributes).type;

        declararFuncion(yyout, (yyvsp[-5].attributes).lexeme, local_var_num);

        aux_symb = search_table(&aux_symbol_table, (yyvsp[-5].attributes).lexeme);

        if(!aux_symb) return -1;

        aux_symb = symbol_create((yyvsp[-5].attributes).lexeme, FUNCTION, aux_symb->type, -1, -1, -1, num_params, -1, local_var_num);

        insert_table(&aux_symbol_table, (yyvsp[-5].attributes).lexeme, aux_symb);

        // symbol_delete(aux_symb);
    }
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 246 "alfa.y" /* yacc.c:1646  */
    {

        aux_symb = search_table(&aux_symbol_table, (yyvsp[0].attributes).lexeme);

        if(!aux_symb){
            printf("****Error semantico en lin %d: Declaracion duplicada.\n", n_lines);
			return -1;
        }

        aux_symb = symbol_create((yyvsp[0].attributes).lexeme, FUNCTION, curr_type, -1, -1, -1, -1, -1, -1);

        insert_table(&aux_symbol_table, (yyvsp[0].attributes).lexeme, aux_symb);

        num_params = 0;
        pos_params = 0;
        local_var_num = 1;
        local_var_pos = 1;
        func_flag_dec = 1;
        func_ret = 0;

        strcpy((yyval.attributes).lexeme, (yyvsp[0].attributes).lexeme);
        (yyval.attributes).type = curr_type;

        // symbol_delete(aux_symb);
    }
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 273 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");
    }
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 276 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R24:\t<parametros_funcion> ::=\n");
    }
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 281 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R25:\t<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>\n");
    }
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 284 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R26:\t<resto_parametros_funcion> ::=\n");
    }
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 289 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n");
        num_params++;
        pos_params++;
    }
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 296 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R28:\t<declaraciones_funcion> ::= <declaraciones>\n");
    }
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 299 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R29:\t<declaraciones_funcion> ::=\n");
    }
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 304 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R30:\t<sentencias> ::= <sentencia>\n");
    }
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 307 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R31:\t<sentencias> ::= <sentencia> <sentencias>\n");
    }
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 312 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R32:\t<sentencia> ::= <sentencia_simple> ;\n");
    }
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 315 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R33:\t<sentencia> ::= <bloque>\n");
    }
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 320 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R34:\t<sentencia_simple> ::= <asignacion>\n");
    }
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 323 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R35:\t<sentencia_simple> ::= <lectura>\n");
    }
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 326 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R36:\t<sentencia_simple> ::= <escritura>\n");
    }
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 329 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");
    }
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 334 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R40:\t<bloque> ::= <condicional>\n");
    }
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 337 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R41:\t<bloque> ::= <bucle>\n");
    }
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 342 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R43:\t<asignacion> ::= <identificador> = <exp>\n");

        aux_symb = search_table(&aux_symbol_table, (yyvsp[-2].attributes).lexeme);
        if(!aux_symb || aux_symb->symb_cat == FUNCTION || aux_symb->cat == VECTOR){
            printf("****Error semántico en lin %d: Asignacion incompatible.\n",n_lines);
            return -1;
        }

        if(aux_symb->type != (yyvsp[0].attributes).type){
            printf("****Error semántico en lin %d: Asignacion incompatible.\n",n_lines);
            return -1;
        }

        if(func_flag_dec == 1){

            if(aux_symb->symb_cat == PARAMETER){
			    escribirParametro(yyout, aux_symb->position, num_params);
            }
            else
            {
                escribirVariableLocal(yyout, aux_symb->position);
            }

		    asignarDestinoEnPila(yyout, (yyvsp[0].attributes).is_address);
        }
        else
        {
		    asignar(yyout, (yyvsp[-2].attributes).lexeme, (yyvsp[0].attributes).is_address);
        }

    }
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 374 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");

        if((yyvsp[-2].attributes).type != (yyvsp[0].attributes).type){
            printf("****Error semantico en linea %d: Asignacion incompatible\n", n_lines);
            return -1;
        }

        aux_symb = search_table(&aux_symbol_table, (yyvsp[-2].attributes).lexeme);
        if(!aux_symb){
            printf("****Error semantico en linea %d: Acceso a variable no delcarada (%s)\n", n_lines, (yyvsp[-2].attributes).lexeme);
            return -1;
        }

        if(aux_symb->symb_cat == FUNCTION || aux_symb->cat != VECTOR){
            printf("****Error semántico en lin %d: Asignacion incompatible.\n",n_lines);
            return -1;
        }

        if((yyvsp[-2].attributes).index_address == 0) {
            char buffer[MAX];
            sprintf(buffer, "%d", (yyvsp[-2].attributes).value);
            escribir_operando(yyout, buffer, 0);
        }
        if((yyvsp[-2].attributes).index_address == 1) escribir_operando(yyout, (yyvsp[-2].attributes).index, 1);

        escribir_elemento_vector(yyout, (yyvsp[-2].attributes).lexeme, aux_symb->size, (yyvsp[0].attributes).is_address);
        asignarDestinoEnPila(yyout, (yyvsp[0].attributes).is_address);
        // symbol_delete(aux_symb);

    }
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 407 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R48:\t<elemento_vector> ::= <identificador> [ <exp> ]\n");

        if((yyvsp[-1].attributes).type != INT){
            printf("****Error semantico en lin %d: El indice en una operacion de indexacion tiene que ser de tipo entero.\n", n_lines);
            return -1;
        }

        aux_symb = search_table(&aux_symbol_table, (yyvsp[-3].attributes).lexeme);

        if(!aux_symb){
            printf("****Error semantico en lin %d: Acceso a variable no declarada (%s).\n", n_lines, (yyvsp[-3].attributes).lexeme);
            return -1;
        }

        if(aux_symb->symb_cat == FUNCTION || aux_symb->cat != VECTOR){
            printf("****Error semántico en lin %d: Intento de indexacion de una variable que no es de tipo vector.\n",n_lines);
            return -1;
        }

        if((yyvsp[-1].attributes).is_address == 0){
            (yyval.attributes).index_address = 0;
            (yyval.attributes).value = (yyvsp[-1].attributes).value;
        }
        else if((yyvsp[-1].attributes).is_address == 1){
            (yyval.attributes).index_address = 1;
            strcpy((yyval.attributes).index, (yyvsp[-1].attributes).lexeme);
        }

        (yyval.attributes).type = aux_symb->type;
        (yyval.attributes).is_address = 1;
        strcpy((yyval.attributes).lexeme, (yyvsp[-3].attributes).lexeme);
        // symbol_delete(aux_symb);
    }
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 443 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R50:\t<condicional> ::= if ( <exp> ) { <sentencias> }\n");
        ifthen_fin(yyout, (yyvsp[-1].attributes).label);
    }
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 447 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R51:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");
        ifthenelse_fin(yyout, (yyvsp[-5].attributes).label);
    }
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 453 "alfa.y" /* yacc.c:1646  */
    {

        if((yyvsp[-2].attributes).type != BOOL){
            printf("****Error semantico en linea %d: Condicional con condicion de tipo int.\n", n_lines);
            return -1;
        }

        (yyval.attributes).label = label++;
        ifthen_inicio(yyout, (yyvsp[-2].attributes).is_address, (yyval.attributes).label);
    }
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 465 "alfa.y" /* yacc.c:1646  */
    {
        (yyval.attributes).label = (yyvsp[-1].attributes).label;
        ifthenelse_fin_then(yyout, (yyval.attributes).label);
    }
#line 1954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 471 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R52:\t<bucle> ::= while ( <exp> ) { <sentencias> }\n");
        while_fin(yyout, (yyvsp[-2].attributes).label);
    }
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 477 "alfa.y" /* yacc.c:1646  */
    {
        (yyval.attributes).label = label++;
        while_inicio(yyout, (yyval.attributes).label);
    }
#line 1972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 483 "alfa.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].attributes).type != BOOL){
            printf("****Error semantico en linea %d: Condicional con condicion de tipo int.\n", n_lines);
            return -1;
        }

        (yyval.attributes).label = (yyvsp[-3].attributes).label;
        while_exp_pila(yyout, (yyvsp[-2].attributes).is_address, (yyval.attributes).label);
    }
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 494 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R54:\t<lectura> ::= scanf <identificador>\n");
        aux_symb = search_table(&aux_symbol_table, (yyvsp[0].attributes).lexeme);
        if(!aux_symb){
            printf("****Error semantico en lin %d: Acceso a variable no declarada (%s).\n", n_lines, (yyvsp[0].attributes).lexeme);
            return -1;
        }

        if(aux_symb->symb_cat == FUNCTION || aux_symb->cat != SCALAR){
            printf("****Error semántico en lin %d: Asignacion incompatible.\n", n_lines);
            return -1;
        }

        leer(yyout, (yyvsp[0].attributes).lexeme, aux_symb->type);
        // symbol_delete(aux_symb);
    }
#line 2007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 512 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R56:\t<escritura> ::= printf <exp>\n");
        escribir(yyout, (yyvsp[0].attributes).is_address, (yyvsp[0].attributes).type);
    }
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 518 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R61:\t<retorno_funcion> ::= return <exp>\n");

        if(func_flag_dec == 0){
            printf("****Error semantico en lin %d: Sentencia de retorno fuera del cuerpo de una funcion.\n", n_lines);
		    return -1;
        }
        func_ret = 1;
        retornarFuncion(yyout, (yyvsp[0].attributes).is_address);

    }
#line 2032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 531 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R72:\t<exp> ::= <exp> + <exp>\n");

        if((yyvsp[-2].attributes).type == BOOL || (yyvsp[0].attributes).type == BOOL){
            printf("****Error semantico en lin %d: Operacion aritmetica con operandos boolean.\n", n_lines);
            return -1;
        }

        if((yyvsp[-2].attributes).type == INT && (yyvsp[0].attributes).type == INT){
            sumar(yyout,(yyvsp[-2].attributes).is_address, (yyvsp[0].attributes).is_address);

            (yyval.attributes).type = INT;
            (yyval.attributes).is_address = 0;
            (yyval.attributes).value = (yyvsp[-2].attributes).value + (yyvsp[0].attributes).value;
        }

    }
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 548 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R73:\t<exp> ::= <exp> - <exp>\n");

        if((yyvsp[-2].attributes).type == BOOL || (yyvsp[0].attributes).type == BOOL){
            printf("****Error semantico en lin %d: Operacion aritmetica con operandos boolean.\n", n_lines);
            return -1;
        }

        if((yyvsp[-2].attributes).type == INT && (yyvsp[0].attributes).type == INT){
            restar(yyout,(yyvsp[-2].attributes).is_address, (yyvsp[0].attributes).is_address);

            (yyval.attributes).type = INT;
            (yyval.attributes).is_address = 0;
            (yyval.attributes).value = (yyvsp[-2].attributes).value - (yyvsp[0].attributes).value;
        }

    }
#line 2076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 565 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R74:\t<exp> ::= <exp> / <exp>\n");

        if((yyvsp[-2].attributes).type == BOOL || (yyvsp[0].attributes).type == BOOL){
            printf("****Error semantico en lin %d: Operacion aritmetica con operandos boolean.\n", n_lines);
            return -1;
        }

        if((yyvsp[-2].attributes).type == INT && (yyvsp[0].attributes).type == INT){
            dividir(yyout,(yyvsp[-2].attributes).is_address, (yyvsp[0].attributes).is_address);

            (yyval.attributes).type = INT;
            (yyval.attributes).is_address = 0;
            if (!(yyvsp[0].attributes).value) (yyval.attributes).value = -1;
            else (yyval.attributes).value = (yyvsp[-2].attributes).value / (yyvsp[0].attributes).value;
        }

    }
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 583 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R75:\t<exp> ::= <exp> * <exp>\n");

        if((yyvsp[-2].attributes).type == BOOL || (yyvsp[0].attributes).type == BOOL){
            printf("****Error semantico en lin %d: Operacion aritmetica con operandos boolean.\n", n_lines);
            return -1;
        }

        if((yyvsp[-2].attributes).type == INT && (yyvsp[0].attributes).type == INT){
            multiplicar(yyout,(yyvsp[-2].attributes).is_address, (yyvsp[0].attributes).is_address);

            (yyval.attributes).type = INT;
            (yyval.attributes).is_address = 0;
            (yyval.attributes).value = (yyvsp[-2].attributes).value * (yyvsp[0].attributes).value;
        }

    }
#line 2121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 600 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R76:\t<exp> ::= - <exp>\n");

        if((yyvsp[0].attributes).type == BOOL){
            printf("****Error semantico en lin %d: Operacion aritmetica con operandos boolean.\n", n_lines);
            return -1;
        }

        if((yyvsp[0].attributes).type == INT){
            cambiar_signo(yyout,(yyvsp[0].attributes).is_address);

            (yyval.attributes).type = INT;
            (yyval.attributes).is_address = 0;
            (yyval.attributes).value = -(yyvsp[0].attributes).value;
        }

    }
#line 2143 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 617 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R77:\t<exp> ::= <exp> && <exp>\n");

        if((yyvsp[-2].attributes).type == INT || (yyvsp[0].attributes).type == INT){
            printf("****Error semantico en lin %d: Operacion logica con operandos int.\n", n_lines);
            return -1;
        }

        if((yyvsp[-2].attributes).type == BOOL && (yyvsp[0].attributes).type == BOOL){
            y(yyout,(yyvsp[-2].attributes).is_address, (yyvsp[0].attributes).is_address);

            (yyval.attributes).type = BOOL;
            (yyval.attributes).is_address = 0;
            (yyval.attributes).value = (yyvsp[-2].attributes).value && (yyvsp[0].attributes).value;
        }

    }
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 634 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R78:\t<exp> ::= <exp> || <exp>\n");

        if((yyvsp[-2].attributes).type == INT || (yyvsp[0].attributes).type == INT){
            printf("****Error semantico en lin %d: Operacion logica con operandos int.\n", n_lines);
            return -1;
        }

        if((yyvsp[-2].attributes).type == BOOL && (yyvsp[0].attributes).type == BOOL){
            o(yyout,(yyvsp[-2].attributes).is_address, (yyvsp[0].attributes).is_address);

            (yyval.attributes).type = BOOL;
            (yyval.attributes).is_address = 0;
            (yyval.attributes).value = (yyvsp[-2].attributes).value || (yyvsp[0].attributes).value;
        }

    }
#line 2187 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 651 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R79:\t<exp> ::= ! <exp>\n");

        if((yyvsp[0].attributes).type == INT){
            printf("****Error semantico en lin %d: Operacion logica con operandos int.\n", n_lines);
            return -1;
        }

        if((yyvsp[0].attributes).type == BOOL){
            no(yyout, (yyvsp[0].attributes).is_address, 1);

            (yyval.attributes).type = BOOL;
            (yyval.attributes).is_address = 0;
            (yyval.attributes).value = !(yyvsp[0].attributes).value;
        }


    }
#line 2210 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 669 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R80:\t<exp> ::= <identificador>\n");

        aux_symb = search_table(&aux_symbol_table, (yyvsp[0].attributes).lexeme);

        if(!aux_symb){
            printf("****Error semantico en linea %d: Acceso a variable no delcarada (%s)\n", n_lines, (yyvsp[0].attributes).lexeme);
            return -1;
        }

        if(aux_symb->cat == VECTOR || aux_symb->symb_cat == FUNCTION){
            printf("****Error semantico en linea %d: Asignacion incompatible\n", n_lines);
            return -1;
        }

        (yyval.attributes).type = aux_symb->type;
        (yyval.attributes).is_address = 1;

        if(func_flag_dec != 1) escribir_operando(yyout, (yyvsp[0].attributes).lexeme, 1);
        else
        {
            if(aux_symb->symb_cat == PARAMETER) escribirParametro(yyout, aux_symb->position, num_params);
            else escribirVariableLocal(yyout, aux_symb->position);
        }

        if(func_call == 1){
            operandoEnPilaAArgumento(yyout, 1);
            (yyval.attributes).is_address = 0;
        }
        // symbol_delete(aux_symb);

    }
#line 2247 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 701 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R81:\t<exp> ::= <constante>\n");

        (yyval.attributes).type = (yyvsp[0].attributes).type;
        (yyval.attributes).is_address = (yyvsp[0].attributes).is_address;
        if(func_call == 1) operandoEnPilaAArgumento(yyout, 0);

    }
#line 2260 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 709 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R82:\t<exp> ::= ( <exp> )\n");
        (yyval.attributes).type = (yyvsp[-1].attributes).type;
        (yyval.attributes).is_address = (yyvsp[-1].attributes).is_address;
    }
#line 2270 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 714 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R83:\t<exp> ::= ( <comparacion> )\n");
        (yyval.attributes).type = (yyvsp[-1].attributes).type;
        (yyval.attributes).is_address = (yyvsp[-1].attributes).is_address;
    }
#line 2280 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 719 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R85:\t<exp> ::= <elemento_vector>\n");

        (yyval.attributes).type = (yyvsp[0].attributes).type;
        (yyval.attributes).is_address = 1;
        (yyval.attributes).value = (yyvsp[0].attributes).value;
        strcpy((yyval.attributes).lexeme, (yyvsp[0].attributes).lexeme);

        aux_symb = search_table(&aux_symbol_table, (yyvsp[0].attributes).lexeme);

        if(!aux_symb || aux_symb->cat != VECTOR || aux_symb->symb_cat == FUNCTION){
            printf("****Error semantico en linea %d: Asignacion incompatible\n", n_lines);
            return -1;
        }

        escribir_elemento_vector(yyout, (yyvsp[0].attributes).lexeme, aux_symb->size, (yyvsp[0].attributes).index_address);

        if(func_call == 1){
            operandoEnPilaAArgumento(yyout, 1);
            (yyval.attributes).is_address = 0;
        }

    }
#line 2308 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 742 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R88:\t<exp> ::= <identificador> ( <lista_expresiones> )\n");

        if(func_call == 1){
            printf("****Error semantico en lin %d: No esta permitido el uso de llamadas a funciones como parametros de otras funciones.\n", n_lines);
            return -1;
        }

        func_call = 1;

        aux_symb = search_table(&aux_symbol_table, (yyvsp[-3].attributes).lexeme);
        if(!aux_symb){
            printf("****Error semantico en lin %d. Asignacion incompatible.\n", n_lines);
		    return -1;
        }
        if(num_params_call != aux_symb->num_param){
            printf("****Error semantico en lin %d: Numero incorrecto de parametros en llamada a funcion.\n", n_lines);
            return -1;
        }

        llamarFuncion(yyout, (yyvsp[-3].attributes).lexeme, num_params_call);
        limpiarPila(yyout, num_params_call);
        num_params_call = 0;
        func_call = 0;
        (yyval.attributes).is_address = 0;
        (yyval.attributes).type = aux_symb->type;
        // symbol_delete(aux_symb);
    }
#line 2341 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 772 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");
        num_params_call++;
    }
#line 2350 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 776 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R90:\t<lista_expresiones> ::=\n");
    }
#line 2358 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 781 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n");
        num_params_call++;
    }
#line 2367 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 785 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R92:\t<resto_lista_expresiones> ::=\n");
    }
#line 2375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 790 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R93:\t<comparacion> ::= <exp> == <exp>\n");

        if((yyvsp[-2].attributes).type == BOOL || (yyvsp[0].attributes).type == BOOL){
            printf("****Error semantico en lin %d: Comparacion con operandos boolean.\n", n_lines);
            return -1;
        }

        if((yyvsp[-2].attributes).type == INT && (yyvsp[0].attributes).type == INT){
            igual(yyout,(yyvsp[-2].attributes).is_address, (yyvsp[0].attributes).is_address, label);

            label++;
            (yyval.attributes).type =  BOOL;
            (yyval.attributes).is_address = 0;
            (yyval.attributes).value = (yyvsp[-2].attributes).value == (yyvsp[0].attributes).value;
        }
    }
#line 2397 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 807 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R94:\t<comparacion> ::= <exp> != <exp>\n");

        if((yyvsp[-2].attributes).type == BOOL || (yyvsp[0].attributes).type == BOOL){
            printf("****Error semantico en lin %d: Comparacion con operandos boolean.\n", n_lines);
            return -1;
        }

        if((yyvsp[-2].attributes).type == INT && (yyvsp[0].attributes).type == INT){
            distinto(yyout,(yyvsp[-2].attributes).is_address, (yyvsp[0].attributes).is_address, label);

            label++;
            (yyval.attributes).type =  BOOL;
            (yyval.attributes).is_address = 0;
            (yyval.attributes).value = (yyvsp[-2].attributes).value != (yyvsp[0].attributes).value;
        }

    }
#line 2420 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 825 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R95:\t<comparacion> ::= <exp> <= <exp>\n");

        if((yyvsp[-2].attributes).type == BOOL || (yyvsp[0].attributes).type == BOOL){
            printf("****Error semantico en lin %d: Comparacion con operandos boolean.\n", n_lines);
            return -1;
        }

        if((yyvsp[-2].attributes).type == INT && (yyvsp[0].attributes).type == INT){
            menor_igual(yyout,(yyvsp[-2].attributes).is_address, (yyvsp[0].attributes).is_address, label);

            label++;
            (yyval.attributes).type =  BOOL;
            (yyval.attributes).is_address = 0;
            (yyval.attributes).value = (yyvsp[-2].attributes).value <= (yyvsp[0].attributes).value;
        }

    }
#line 2443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 843 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R96:\t<comparacion> ::= <exp> >= <exp>\n");

        if((yyvsp[-2].attributes).type == BOOL || (yyvsp[0].attributes).type == BOOL){
            printf("****Error semantico en lin %d: Comparacion con operandos boolean.\n", n_lines);
            return -1;
        }

        if((yyvsp[-2].attributes).type == INT && (yyvsp[0].attributes).type == INT){
            mayor_igual(yyout,(yyvsp[-2].attributes).is_address, (yyvsp[0].attributes).is_address, label);

            label++;
            (yyval.attributes).type =  BOOL;
            (yyval.attributes).is_address = 0;
            (yyval.attributes).value = (yyvsp[-2].attributes).value >= (yyvsp[0].attributes).value;
        }

    }
#line 2466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 861 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R97:\t<comparacion> ::= <exp> < <exp>\n");

        if((yyvsp[-2].attributes).type == BOOL || (yyvsp[0].attributes).type == BOOL){
            printf("****Error semantico en lin %d: Comparacion con operandos boolean.\n", n_lines);
            return -1;
        }

        if((yyvsp[-2].attributes).type == INT && (yyvsp[0].attributes).type == INT){
            menor(yyout,(yyvsp[-2].attributes).is_address, (yyvsp[0].attributes).is_address, label);

            label++;
            (yyval.attributes).type =  BOOL;
            (yyval.attributes).is_address = 0;
            (yyval.attributes).value = (yyvsp[-2].attributes).value < (yyvsp[0].attributes).value;
        }

    }
#line 2489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 879 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R98:\t<comparacion> ::= <exp> > <exp>\n");

        if((yyvsp[-2].attributes).type == BOOL || (yyvsp[0].attributes).type == BOOL){
            printf("****Error semantico en lin %d: Comparacion con operandos boolean.\n", n_lines);
            return -1;
        }

        if((yyvsp[-2].attributes).type == INT && (yyvsp[0].attributes).type == INT){
            mayor(yyout,(yyvsp[-2].attributes).is_address, (yyvsp[0].attributes).is_address, label);

            label++;
            (yyval.attributes).type =  BOOL;
            (yyval.attributes).is_address = 0;
            (yyval.attributes).value = (yyvsp[-2].attributes).value > (yyvsp[0].attributes).value;
        }

    }
#line 2512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 899 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R100:\t<constante> ::= <constante_entera>\n");
        (yyval.attributes).type = (yyvsp[0].attributes).type;
        (yyval.attributes).is_address = (yyvsp[0].attributes).is_address;
    }
#line 2522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 904 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R101:\t<constante> ::= <constante_logica>\n");
        (yyval.attributes).type = (yyvsp[0].attributes).type;
        (yyval.attributes).is_address = (yyvsp[0].attributes).is_address;
    }
#line 2532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 911 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R102:\t<constante_logica> ::= true\n");

        (yyval.attributes).type = BOOL;
        (yyval.attributes).is_address = 0;
        escribir_operando(yyout, "1", 0);
    }
#line 2544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 918 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R103:\t<constante_logica> ::= false\n");

        (yyval.attributes).type = BOOL;
        (yyval.attributes).is_address = 0;
        escribir_operando(yyout, "0", 0);
    }
#line 2556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 927 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R104:\t<constante_entera> ::= TOK_CONSTANTE_ENTERA\n");

        (yyval.attributes).type = INT;
        (yyval.attributes).is_address = 0;
        (yyval.attributes).value = (yyvsp[0].attributes).value;

        char buffer[MAX];
        sprintf(buffer, "%d", (yyval.attributes).value);
        escribir_operando(yyout, buffer, 0);
    }
#line 2572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 940 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");
        if(search_table(&aux_symbol_table, (yyvsp[0].attributes).lexeme)){
            printf( "****Error semantico en linea %d: Declaracion duplicada.\n", n_lines);
            return -1;
        }
        if(func_flag_dec == 1){
            if(curr_class != SCALAR){
                printf("****Error semantico en lin %d: Variable local de tipo no escalar.\n", n_lines);
                return -1;
            }

            aux_symb = symbol_create((yyvsp[0].attributes).lexeme, VARIABLE, curr_type, SCALAR, -1, 1, -1, local_var_num, -1);
            insert_table(&aux_symbol_table, (yyvsp[0].attributes).lexeme, aux_symb);
            local_var_num++;
        }
        else
        {
            aux_symb = symbol_create((yyvsp[0].attributes).lexeme, VARIABLE, curr_type, curr_class, -1, curr_len, -1, -1, -1);
            insert_table(&aux_symbol_table, (yyvsp[0].attributes).lexeme, aux_symb);
            declarar_variable(yyout, (yyvsp[0].attributes).lexeme, curr_type, curr_len);
        }
        // symbol_delete(aux_symb);
    }
#line 2601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 966 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");

        if(search_table(&aux_symbol_table, (yyvsp[0].attributes).lexeme)){
            printf( "****Error semantico en linea %d: Declaracion duplicada.", n_lines);
            return -1;
        }

        aux_symb = symbol_create((yyvsp[0].attributes).lexeme, PARAMETER, curr_type, SCALAR, -1, 1, -1, pos_params, -1);

        insert_table(&aux_symbol_table, (yyvsp[0].attributes).lexeme, aux_symb);
        // symbol_delete(aux_symb);
    }
#line 2619 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2623 "y.tab.c" /* yacc.c:1646  */
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
#line 980 "alfa.y" /* yacc.c:1906  */


void yyerror(const char *error){
    extern int yyleng;
    extern int is_morpho;
    extern int n_cols;
    extern int n_lines;
    if(!is_morpho){
        printf("****Error sintactico en [lin %d, col %d]\n", n_lines, n_cols-yyleng);
    }
}
