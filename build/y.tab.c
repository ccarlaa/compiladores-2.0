/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser/parser.y"

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conversor.h"
#include "ast.h"

void yyerror(const char *s);
int yylex(void);

ASTNode *ast_root = NULL;
int current_scope = 0;

// Funções auxiliares
ASTNode* create_declaration_node(char *type, char *name, ASTNode *init);
ASTNode* create_assignment_node(char *op, ASTNode *lhs, ASTNode *rhs);
ASTNode* create_binary_op(char *op, ASTNode *lhs, ASTNode *rhs);
ASTNode* create_unary_op(char *op, ASTNode *operand);

static ASTNode *func_node_temp = NULL;
static ASTNode *body_node_temp = NULL;
static ASTNode *if_node_temp = NULL;


#line 97 "build/y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "y.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_ID = 3,                       /* T_ID  */
  YYSYMBOL_T_STRING = 4,                   /* T_STRING  */
  YYSYMBOL_T_CHAR_LITERAL = 5,             /* T_CHAR_LITERAL  */
  YYSYMBOL_T_NUMBER_INT = 6,               /* T_NUMBER_INT  */
  YYSYMBOL_T_NUMBER_FLOAT = 7,             /* T_NUMBER_FLOAT  */
  YYSYMBOL_T_INT = 8,                      /* T_INT  */
  YYSYMBOL_T_FLOAT = 9,                    /* T_FLOAT  */
  YYSYMBOL_T_CHAR = 10,                    /* T_CHAR  */
  YYSYMBOL_T_VOID = 11,                    /* T_VOID  */
  YYSYMBOL_T_IF = 12,                      /* T_IF  */
  YYSYMBOL_T_ELSE = 13,                    /* T_ELSE  */
  YYSYMBOL_T_WHILE = 14,                   /* T_WHILE  */
  YYSYMBOL_T_FOR = 15,                     /* T_FOR  */
  YYSYMBOL_T_RETURN = 16,                  /* T_RETURN  */
  YYSYMBOL_T_PRINTF = 17,                  /* T_PRINTF  */
  YYSYMBOL_T_SCANF = 18,                   /* T_SCANF  */
  YYSYMBOL_T_SWITCH = 19,                  /* T_SWITCH  */
  YYSYMBOL_T_CASE = 20,                    /* T_CASE  */
  YYSYMBOL_T_DEFAULT = 21,                 /* T_DEFAULT  */
  YYSYMBOL_T_BREAK = 22,                   /* T_BREAK  */
  YYSYMBOL_T_CONTINUE = 23,                /* T_CONTINUE  */
  YYSYMBOL_T_DO = 24,                      /* T_DO  */
  YYSYMBOL_T_MOD = 25,                     /* T_MOD  */
  YYSYMBOL_T_INC = 26,                     /* T_INC  */
  YYSYMBOL_T_DEC = 27,                     /* T_DEC  */
  YYSYMBOL_T_PLUS_ASSIGN = 28,             /* T_PLUS_ASSIGN  */
  YYSYMBOL_T_MINUS_ASSIGN = 29,            /* T_MINUS_ASSIGN  */
  YYSYMBOL_T_ARROW = 30,                   /* T_ARROW  */
  YYSYMBOL_T_DOT = 31,                     /* T_DOT  */
  YYSYMBOL_T_AMPERSAND = 32,               /* T_AMPERSAND  */
  YYSYMBOL_T_BIT_OR = 33,                  /* T_BIT_OR  */
  YYSYMBOL_T_PLUS = 34,                    /* T_PLUS  */
  YYSYMBOL_T_MINUS = 35,                   /* T_MINUS  */
  YYSYMBOL_T_MULT = 36,                    /* T_MULT  */
  YYSYMBOL_T_DIV = 37,                     /* T_DIV  */
  YYSYMBOL_T_ASSIGN = 38,                  /* T_ASSIGN  */
  YYSYMBOL_T_EQ = 39,                      /* T_EQ  */
  YYSYMBOL_T_NEQ = 40,                     /* T_NEQ  */
  YYSYMBOL_T_LT = 41,                      /* T_LT  */
  YYSYMBOL_T_GT = 42,                      /* T_GT  */
  YYSYMBOL_T_LE = 43,                      /* T_LE  */
  YYSYMBOL_T_GE = 44,                      /* T_GE  */
  YYSYMBOL_T_AND = 45,                     /* T_AND  */
  YYSYMBOL_T_OR = 46,                      /* T_OR  */
  YYSYMBOL_T_NOT = 47,                     /* T_NOT  */
  YYSYMBOL_T_LPAREN = 48,                  /* T_LPAREN  */
  YYSYMBOL_T_RPAREN = 49,                  /* T_RPAREN  */
  YYSYMBOL_T_LBRACE = 50,                  /* T_LBRACE  */
  YYSYMBOL_T_RBRACE = 51,                  /* T_RBRACE  */
  YYSYMBOL_T_SEMICOLON = 52,               /* T_SEMICOLON  */
  YYSYMBOL_T_COMMA = 53,                   /* T_COMMA  */
  YYSYMBOL_T_COLON = 54,                   /* T_COLON  */
  YYSYMBOL_T_CONST = 55,                   /* T_CONST  */
  YYSYMBOL_T_UNSIGNED = 56,                /* T_UNSIGNED  */
  YYSYMBOL_57_ = 57,                       /* '*'  */
  YYSYMBOL_YYACCEPT = 58,                  /* $accept  */
  YYSYMBOL_program = 59,                   /* program  */
  YYSYMBOL_60_1 = 60,                      /* $@1  */
  YYSYMBOL_function_list = 61,             /* function_list  */
  YYSYMBOL_function_declaration = 62,      /* function_declaration  */
  YYSYMBOL_63_2 = 63,                      /* $@2  */
  YYSYMBOL_declarations = 64,              /* declarations  */
  YYSYMBOL_declaration = 65,               /* declaration  */
  YYSYMBOL_declarator = 66,                /* declarator  */
  YYSYMBOL_pointer = 67,                   /* pointer  */
  YYSYMBOL_direct_declarator = 68,         /* direct_declarator  */
  YYSYMBOL_type_specifier = 69,            /* type_specifier  */
  YYSYMBOL_statements = 70,                /* statements  */
  YYSYMBOL_statement = 71,                 /* statement  */
  YYSYMBOL_do_while_statement = 72,        /* do_while_statement  */
  YYSYMBOL_break_statement = 73,           /* break_statement  */
  YYSYMBOL_continue_statement = 74,        /* continue_statement  */
  YYSYMBOL_scanf_statement = 75,           /* scanf_statement  */
  YYSYMBOL_while_statement = 76,           /* while_statement  */
  YYSYMBOL_for_statement = 77,             /* for_statement  */
  YYSYMBOL_declaration_or_expression = 78, /* declaration_or_expression  */
  YYSYMBOL_assignment_statement = 79,      /* assignment_statement  */
  YYSYMBOL_increment_statement = 80,       /* increment_statement  */
  YYSYMBOL_decrement_statement = 81,       /* decrement_statement  */
  YYSYMBOL_return_statement = 82,          /* return_statement  */
  YYSYMBOL_if_statement = 83,              /* if_statement  */
  YYSYMBOL_84_3 = 84,                      /* $@3  */
  YYSYMBOL_elseif_chain = 85,              /* elseif_chain  */
  YYSYMBOL_switch_statement = 86,          /* switch_statement  */
  YYSYMBOL_case_list = 87,                 /* case_list  */
  YYSYMBOL_case_statement = 88,            /* case_statement  */
  YYSYMBOL_default_statement = 89,         /* default_statement  */
  YYSYMBOL_statement_list = 90,            /* statement_list  */
  YYSYMBOL_function_call_statement = 91,   /* function_call_statement  */
  YYSYMBOL_expression = 92,                /* expression  */
  YYSYMBOL_printf_statement = 93           /* printf_statement  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
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
#define YYLAST   604

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  214

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   311


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    57,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    85,    85,    85,    98,   102,   111,   110,   137,   141,
     151,   157,   166,   171,   178,   182,   190,   197,   198,   199,
     200,   201,   202,   206,   210,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   239,   249,   256,   263,   273,   283,   296,   297,   298,
     299,   303,   310,   317,   327,   334,   344,   351,   361,   371,
     370,   385,   386,   393,   401,   411,   412,   419,   423,   433,
     442,   443,   453,   462,   463,   468,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   499,   506,   511,   515
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "T_ID", "T_STRING",
  "T_CHAR_LITERAL", "T_NUMBER_INT", "T_NUMBER_FLOAT", "T_INT", "T_FLOAT",
  "T_CHAR", "T_VOID", "T_IF", "T_ELSE", "T_WHILE", "T_FOR", "T_RETURN",
  "T_PRINTF", "T_SCANF", "T_SWITCH", "T_CASE", "T_DEFAULT", "T_BREAK",
  "T_CONTINUE", "T_DO", "T_MOD", "T_INC", "T_DEC", "T_PLUS_ASSIGN",
  "T_MINUS_ASSIGN", "T_ARROW", "T_DOT", "T_AMPERSAND", "T_BIT_OR",
  "T_PLUS", "T_MINUS", "T_MULT", "T_DIV", "T_ASSIGN", "T_EQ", "T_NEQ",
  "T_LT", "T_GT", "T_LE", "T_GE", "T_AND", "T_OR", "T_NOT", "T_LPAREN",
  "T_RPAREN", "T_LBRACE", "T_RBRACE", "T_SEMICOLON", "T_COMMA", "T_COLON",
  "T_CONST", "T_UNSIGNED", "'*'", "$accept", "program", "$@1",
  "function_list", "function_declaration", "$@2", "declarations",
  "declaration", "declarator", "pointer", "direct_declarator",
  "type_specifier", "statements", "statement", "do_while_statement",
  "break_statement", "continue_statement", "scanf_statement",
  "while_statement", "for_statement", "declaration_or_expression",
  "assignment_statement", "increment_statement", "decrement_statement",
  "return_statement", "if_statement", "$@3", "elseif_chain",
  "switch_statement", "case_list", "case_statement", "default_statement",
  "statement_list", "function_call_statement", "expression",
  "printf_statement", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-155)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -155,    12,  -155,  -155,    22,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,    32,    -7,    -9,    20,  -155,    22,   133,    22,
      14,    46,    -2,     1,     4,    19,    21,    31,    33,    30,
      43,    47,    80,    95,  -155,  -155,    48,   133,  -155,  -155,
    -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,  -155,  -155,    64,    -4,   100,  -155,    52,    70,
      19,    19,    19,    74,    19,    19,    82,    76,  -155,  -155,
    -155,  -155,    19,    19,    19,    19,   183,    19,   121,    19,
    -155,  -155,   133,    79,    81,  -155,  -155,  -155,    19,  -155,
    -155,  -155,  -155,   206,   229,   252,    83,   321,   343,    -1,
    -155,    88,  -155,   497,    85,   -22,   -22,   365,  -155,    19,
     125,   129,    19,    19,    19,    19,    19,    19,    19,    19,
      19,    19,    19,    19,    19,  -155,   387,   101,   409,   102,
    -155,  -155,   275,  -155,  -155,  -155,  -155,   108,   112,    19,
    -155,  -155,   -22,  -155,  -155,   560,    71,    71,   -22,   -22,
      75,    75,   142,   142,   142,   142,   540,   519,   111,   132,
     115,   154,  -155,   133,   133,   298,  -155,   166,   -10,   122,
     120,   124,    19,   131,    19,   127,   136,   -10,  -155,    19,
    -155,  -155,   431,   130,   161,   133,  -155,  -155,   453,   170,
     134,  -155,   133,   133,  -155,   138,    -8,  -155,   133,  -155,
    -155,  -155,   145,   133,   148,    19,   158,  -155,   475,  -155,
     160,   133,   179,  -155
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     4,     1,     3,    17,    18,    19,    20,    21,
      22,     5,     0,     0,     0,     0,     6,     8,    23,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    40,    27,     0,    23,    30,    33,
      34,    26,    29,    31,    36,    37,    38,    35,    28,    32,
      39,    25,     9,    16,    14,     0,     0,    13,     0,     0,
       0,     0,     0,     0,     0,     0,    50,    73,    76,    77,
      74,    75,     0,     0,     0,     0,     0,     0,     0,     0,
      42,    43,    23,     0,     0,     7,    24,    15,     0,    10,
      12,    54,    56,     0,     0,     0,     0,     0,     0,    73,
      47,     0,    48,    49,     0,    92,    93,     0,    98,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    58,     0,     0,     0,     0,
      55,    57,     0,    52,    53,    51,    72,     0,     0,     0,
      97,    94,    82,    96,    95,    91,    78,    79,    80,    81,
      83,    84,    85,    86,    87,    88,    89,    90,     0,     0,
       0,     0,    11,    23,    23,     0,    99,     0,    65,     0,
       0,     0,     0,     0,     0,     0,     0,    65,    67,     0,
      59,    45,     0,     0,     0,    70,    64,    66,     0,    61,
       0,    44,    70,    70,    69,     0,     0,    60,    23,    68,
      71,    41,     0,    23,     0,     0,     0,    46,     0,    63,
       0,    23,     0,    62
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -155,  -155,  -155,  -155,  -155,  -155,   192,     2,  -155,   167,
     156,   228,   -37,  -149,  -155,  -155,  -155,  -155,  -155,  -155,
    -155,   168,  -155,  -155,  -155,  -155,  -155,  -155,  -155,    56,
    -155,  -155,  -154,  -155,   -59,  -155
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     4,    11,    17,    18,    35,    55,    56,
      57,    20,    36,    37,    38,    39,    40,    41,    42,    43,
     101,    44,    45,    46,    47,    48,   189,   197,    49,   176,
     177,   178,   194,    50,    76,    51
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      86,    93,    94,    95,   202,    97,    98,   103,   110,   111,
     174,   175,     3,   105,   106,   107,   108,    53,   126,    19,
     128,    19,    67,    68,    69,    70,    71,    60,    61,   132,
       5,     6,     7,     8,    88,    13,   193,    62,   199,   200,
      15,    14,   203,   193,   193,   129,    64,   104,    89,    65,
     142,    72,    66,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,    73,    74,   100,    77,
      16,    54,    58,    59,    60,    61,    75,     9,    10,    78,
     165,    79,    80,    83,    62,    99,    68,    69,    70,    71,
       5,     6,     7,     8,    63,    81,   109,    82,    84,    85,
     109,   110,   111,    53,    91,   110,   111,   115,   116,   113,
     114,   115,   116,   182,    72,   184,   119,   120,   121,   122,
     188,    54,    92,    96,   104,   127,   170,   171,   143,    73,
      74,   130,   144,   131,   140,   136,    21,     9,    10,    75,
     139,     5,     6,     7,     8,    22,   208,    23,    24,    25,
      26,    27,    28,   161,   159,    29,    30,    31,   163,    32,
      33,   204,   164,   166,   167,   168,   206,   109,   169,   173,
     179,   180,   110,   111,   212,   181,   113,   114,   115,   116,
     183,   185,   191,   196,   198,    34,   109,   186,     9,    10,
     201,   110,   111,   205,   112,   113,   114,   115,   116,   207,
     117,   118,   119,   120,   121,   122,   123,   124,   109,   209,
     211,    52,    90,   110,   111,   192,   112,   113,   114,   115,
     116,    87,   117,   118,   119,   120,   121,   122,   123,   124,
     213,   109,    12,   187,   102,   125,   110,   111,     0,   112,
     113,   114,   115,   116,     0,   117,   118,   119,   120,   121,
     122,   123,   124,     0,   109,     0,     0,     0,   133,   110,
     111,     0,   112,   113,   114,   115,   116,     0,   117,   118,
     119,   120,   121,   122,   123,   124,     0,   109,     0,     0,
       0,   134,   110,   111,     0,   112,   113,   114,   115,   116,
       0,   117,   118,   119,   120,   121,   122,   123,   124,     0,
     109,     0,     0,     0,   135,   110,   111,     0,   112,   113,
     114,   115,   116,     0,   117,   118,   119,   120,   121,   122,
     123,   124,     0,   109,     0,     0,     0,   162,   110,   111,
       0,   112,   113,   114,   115,   116,     0,   117,   118,   119,
     120,   121,   122,   123,   124,     0,   109,     0,     0,     0,
     172,   110,   111,     0,   112,   113,   114,   115,   116,     0,
     117,   118,   119,   120,   121,   122,   123,   124,   109,     0,
     137,     0,     0,   110,   111,     0,   112,   113,   114,   115,
     116,     0,   117,   118,   119,   120,   121,   122,   123,   124,
     109,     0,   138,     0,     0,   110,   111,     0,   112,   113,
     114,   115,   116,     0,   117,   118,   119,   120,   121,   122,
     123,   124,   109,     0,   141,     0,     0,   110,   111,     0,
     112,   113,   114,   115,   116,     0,   117,   118,   119,   120,
     121,   122,   123,   124,   109,     0,   158,     0,     0,   110,
     111,     0,   112,   113,   114,   115,   116,     0,   117,   118,
     119,   120,   121,   122,   123,   124,   109,     0,   160,     0,
       0,   110,   111,     0,   112,   113,   114,   115,   116,     0,
     117,   118,   119,   120,   121,   122,   123,   124,   109,     0,
     190,     0,     0,   110,   111,     0,   112,   113,   114,   115,
     116,     0,   117,   118,   119,   120,   121,   122,   123,   124,
     109,     0,   195,     0,     0,   110,   111,     0,   112,   113,
     114,   115,   116,     0,   117,   118,   119,   120,   121,   122,
     123,   124,   109,     0,   210,     0,     0,   110,   111,     0,
     112,   113,   114,   115,   116,     0,   117,   118,   119,   120,
     121,   122,   123,   124,   109,     0,     0,     0,     0,   110,
     111,     0,   112,   113,   114,   115,   116,     0,   117,   118,
     119,   120,   121,   122,   123,   109,     0,     0,     0,     0,
     110,   111,     0,   112,   113,   114,   115,   116,     0,   117,
     118,   119,   120,   121,   122,   109,     0,     0,     0,     0,
     110,   111,     0,     0,   113,   114,   115,   116,     0,   117,
     118,   119,   120,   121,   122
};

static const yytype_int16 yycheck[] =
{
      37,    60,    61,    62,    12,    64,    65,    66,    30,    31,
      20,    21,     0,    72,    73,    74,    75,     3,    77,    17,
      79,    19,     3,     4,     5,     6,     7,    28,    29,    88,
       8,     9,    10,    11,    38,     3,   185,    38,   192,   193,
      49,    48,    50,   192,   193,    82,    48,    48,    52,    48,
     109,    32,    48,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    47,    48,    66,    48,
      50,    57,    26,    27,    28,    29,    57,    55,    56,    48,
     139,    48,    52,     3,    38,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    48,    52,    25,    50,     3,    51,
      25,    30,    31,     3,    52,    30,    31,    36,    37,    34,
      35,    36,    37,   172,    32,   174,    41,    42,    43,    44,
     179,    57,    52,    49,    48,     4,   163,   164,     3,    47,
      48,    52,     3,    52,    49,    52,     3,    55,    56,    57,
      52,     8,     9,    10,    11,    12,   205,    14,    15,    16,
      17,    18,    19,    51,    53,    22,    23,    24,    50,    26,
      27,   198,    50,    52,    32,    50,   203,    25,    14,     3,
      48,    51,    30,    31,   211,    51,    34,    35,    36,    37,
      49,    54,    52,    13,    50,    52,    25,    51,    55,    56,
      52,    30,    31,    48,    33,    34,    35,    36,    37,    51,
      39,    40,    41,    42,    43,    44,    45,    46,    25,    51,
      50,    19,    56,    30,    31,    54,    33,    34,    35,    36,
      37,    54,    39,    40,    41,    42,    43,    44,    45,    46,
      51,    25,     4,   177,    66,    52,    30,    31,    -1,    33,
      34,    35,    36,    37,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    25,    -1,    -1,    -1,    52,    30,
      31,    -1,    33,    34,    35,    36,    37,    -1,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    25,    -1,    -1,
      -1,    52,    30,    31,    -1,    33,    34,    35,    36,    37,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      25,    -1,    -1,    -1,    52,    30,    31,    -1,    33,    34,
      35,    36,    37,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    25,    -1,    -1,    -1,    52,    30,    31,
      -1,    33,    34,    35,    36,    37,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    25,    -1,    -1,    -1,
      52,    30,    31,    -1,    33,    34,    35,    36,    37,    -1,
      39,    40,    41,    42,    43,    44,    45,    46,    25,    -1,
      49,    -1,    -1,    30,    31,    -1,    33,    34,    35,    36,
      37,    -1,    39,    40,    41,    42,    43,    44,    45,    46,
      25,    -1,    49,    -1,    -1,    30,    31,    -1,    33,    34,
      35,    36,    37,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    25,    -1,    49,    -1,    -1,    30,    31,    -1,
      33,    34,    35,    36,    37,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    25,    -1,    49,    -1,    -1,    30,
      31,    -1,    33,    34,    35,    36,    37,    -1,    39,    40,
      41,    42,    43,    44,    45,    46,    25,    -1,    49,    -1,
      -1,    30,    31,    -1,    33,    34,    35,    36,    37,    -1,
      39,    40,    41,    42,    43,    44,    45,    46,    25,    -1,
      49,    -1,    -1,    30,    31,    -1,    33,    34,    35,    36,
      37,    -1,    39,    40,    41,    42,    43,    44,    45,    46,
      25,    -1,    49,    -1,    -1,    30,    31,    -1,    33,    34,
      35,    36,    37,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    25,    -1,    49,    -1,    -1,    30,    31,    -1,
      33,    34,    35,    36,    37,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    25,    -1,    -1,    -1,    -1,    30,
      31,    -1,    33,    34,    35,    36,    37,    -1,    39,    40,
      41,    42,    43,    44,    45,    25,    -1,    -1,    -1,    -1,
      30,    31,    -1,    33,    34,    35,    36,    37,    -1,    39,
      40,    41,    42,    43,    44,    25,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    34,    35,    36,    37,    -1,    39,
      40,    41,    42,    43,    44
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    59,    60,     0,    61,     8,     9,    10,    11,    55,
      56,    62,    69,     3,    48,    49,    50,    63,    64,    65,
      69,     3,    12,    14,    15,    16,    17,    18,    19,    22,
      23,    24,    26,    27,    52,    65,    70,    71,    72,    73,
      74,    75,    76,    77,    79,    80,    81,    82,    83,    86,
      91,    93,    64,     3,    57,    66,    67,    68,    26,    27,
      28,    29,    38,    48,    48,    48,    48,     3,     4,     5,
       6,     7,    32,    47,    48,    57,    92,    48,    48,    48,
      52,    52,    50,     3,     3,    51,    70,    67,    38,    52,
      68,    52,    52,    92,    92,    92,    49,    92,    92,     3,
      65,    78,    79,    92,    48,    92,    92,    92,    92,    25,
      30,    31,    33,    34,    35,    36,    37,    39,    40,    41,
      42,    43,    44,    45,    46,    52,    92,     4,    92,    70,
      52,    52,    92,    52,    52,    52,    52,    49,    49,    52,
      49,    49,    92,     3,     3,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    49,    53,
      49,    51,    52,    50,    50,    92,    52,    32,    50,    14,
      70,    70,    52,     3,    20,    21,    87,    88,    89,    48,
      51,    51,    92,    49,    92,    54,    51,    87,    92,    84,
      49,    52,    54,    71,    90,    49,    13,    85,    50,    90,
      90,    52,    12,    50,    70,    48,    70,    51,    92,    51,
      49,    50,    70,    51
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    60,    59,    61,    61,    63,    62,    64,    64,
      65,    65,    66,    66,    67,    67,    68,    69,    69,    69,
      69,    69,    69,    70,    70,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    72,    73,    74,    75,    76,    77,    78,    78,    78,
      78,    79,    79,    79,    80,    80,    81,    81,    82,    84,
      83,    85,    85,    85,    86,    87,    87,    87,    88,    89,
      90,    90,    91,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    93
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     0,     9,     0,     2,
       3,     5,     2,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     9,     2,     2,     8,     7,    11,     1,     1,     1,
       0,     4,     4,     4,     3,     3,     3,     3,     3,     0,
       9,     0,     8,     4,     7,     0,     2,     1,     4,     3,
       0,     2,     4,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     3,     3,     3,     3,     2,     5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* $@1: %empty  */
#line 85 "parser/parser.y"
    {
        init_symbol_table();
        ast_root = create_node(NODE_PROGRAM, "programa");
    }
#line 1406 "build/y.tab.c"
    break;

  case 3: /* program: $@1 function_list  */
#line 90 "parser/parser.y"
    {
        generate_portugol(ast_root);  // Gera código Portugol
        free_ast(ast_root);
        free_symbol_table();
    }
#line 1416 "build/y.tab.c"
    break;

  case 4: /* function_list: %empty  */
#line 99 "parser/parser.y"
    {
        (yyval.ast) = create_node(NODE_EMPTY, NULL);
    }
#line 1424 "build/y.tab.c"
    break;

  case 5: /* function_list: function_list function_declaration  */
#line 103 "parser/parser.y"
    {
        add_child(ast_root, (yyvsp[0].ast));
        (yyval.ast) = (yyvsp[-1].ast);
    }
#line 1433 "build/y.tab.c"
    break;

  case 6: /* $@2: %empty  */
#line 111 "parser/parser.y"
    {
        insert_symbol((yyvsp[-3].sval), (yyvsp[-4].sval), 0);
        ASTNode *func_node = create_node(NODE_FUNCTION, (yyvsp[-3].sval));
        ASTNode *type_node = create_node(NODE_TYPE, (yyvsp[-4].sval));
        ASTNode *body_node = create_node(NODE_BLOCK, NULL);

        add_child(func_node, type_node);
        add_child(func_node, body_node);
        
        // Usar variáveis globais declaradas
        func_node_temp = func_node;
        body_node_temp = body_node;
    }
#line 1451 "build/y.tab.c"
    break;

  case 7: /* function_declaration: type_specifier T_ID T_LPAREN T_RPAREN T_LBRACE $@2 declarations statements T_RBRACE  */
#line 127 "parser/parser.y"
    {
        // Usa as variáveis temporárias
        add_child(body_node_temp, (yyvsp[-2].ast));
        add_child(body_node_temp, (yyvsp[-1].ast));
        (yyval.ast) = func_node_temp;
        free((yyvsp[-8].sval)); free((yyvsp[-7].sval));
    }
#line 1463 "build/y.tab.c"
    break;

  case 8: /* declarations: %empty  */
#line 138 "parser/parser.y"
    {
        (yyval.ast) = create_node(NODE_EMPTY, NULL);
    }
#line 1471 "build/y.tab.c"
    break;

  case 9: /* declarations: declaration declarations  */
#line 142 "parser/parser.y"
    {
        ASTNode *decls = create_node(NODE_DECLARATION_LIST, NULL);
        add_child(decls, (yyvsp[-1].ast));
        add_child(decls, (yyvsp[0].ast));
        (yyval.ast) = decls;
    }
#line 1482 "build/y.tab.c"
    break;

  case 10: /* declaration: type_specifier declarator T_SEMICOLON  */
#line 152 "parser/parser.y"
    {
        (yyval.ast) = create_declaration_node((yyvsp[-2].sval), (yyvsp[-1].sval), NULL);
        insert_symbol((yyvsp[-1].sval), (yyvsp[-2].sval), current_scope);
        free((yyvsp[-2].sval)); free((yyvsp[-1].sval));
    }
#line 1492 "build/y.tab.c"
    break;

  case 11: /* declaration: type_specifier declarator T_ASSIGN expression T_SEMICOLON  */
#line 158 "parser/parser.y"
    {
        (yyval.ast) = create_declaration_node((yyvsp[-4].sval), (yyvsp[-3].sval), (yyvsp[-1].ast));
        insert_symbol((yyvsp[-3].sval), (yyvsp[-4].sval), current_scope);
        free((yyvsp[-4].sval)); free((yyvsp[-3].sval));
    }
#line 1502 "build/y.tab.c"
    break;

  case 12: /* declarator: pointer direct_declarator  */
#line 167 "parser/parser.y"
    {
        asprintf(&(yyval.sval), "%s%s", (yyvsp[-1].sval), (yyvsp[0].sval));
        free((yyvsp[-1].sval)); free((yyvsp[0].sval));
    }
#line 1511 "build/y.tab.c"
    break;

  case 13: /* declarator: direct_declarator  */
#line 172 "parser/parser.y"
    {
        (yyval.sval) = (yyvsp[0].sval);
    }
#line 1519 "build/y.tab.c"
    break;

  case 14: /* pointer: '*'  */
#line 179 "parser/parser.y"
    {
        (yyval.sval) = strdup("*");
    }
#line 1527 "build/y.tab.c"
    break;

  case 15: /* pointer: '*' pointer  */
#line 183 "parser/parser.y"
    {
        asprintf(&(yyval.sval), "*%s", (yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 1536 "build/y.tab.c"
    break;

  case 16: /* direct_declarator: T_ID  */
#line 191 "parser/parser.y"
    {
        (yyval.sval) = (yyvsp[0].sval);
    }
#line 1544 "build/y.tab.c"
    break;

  case 17: /* type_specifier: T_INT  */
#line 197 "parser/parser.y"
               { (yyval.sval) = strdup("inteiro"); }
#line 1550 "build/y.tab.c"
    break;

  case 18: /* type_specifier: T_FLOAT  */
#line 198 "parser/parser.y"
                 { (yyval.sval) = strdup("real"); }
#line 1556 "build/y.tab.c"
    break;

  case 19: /* type_specifier: T_CHAR  */
#line 199 "parser/parser.y"
                 { (yyval.sval) = strdup("caractere"); }
#line 1562 "build/y.tab.c"
    break;

  case 20: /* type_specifier: T_VOID  */
#line 200 "parser/parser.y"
                 { (yyval.sval) = strdup("vazio"); }
#line 1568 "build/y.tab.c"
    break;

  case 21: /* type_specifier: T_CONST  */
#line 201 "parser/parser.y"
                 { (yyval.sval) = strdup("constante"); }
#line 1574 "build/y.tab.c"
    break;

  case 22: /* type_specifier: T_UNSIGNED  */
#line 202 "parser/parser.y"
                 { (yyval.sval) = strdup("inteiro"); }
#line 1580 "build/y.tab.c"
    break;

  case 23: /* statements: %empty  */
#line 207 "parser/parser.y"
    {
        (yyval.ast) = create_node(NODE_EMPTY, NULL);
    }
#line 1588 "build/y.tab.c"
    break;

  case 24: /* statements: statement statements  */
#line 211 "parser/parser.y"
    {
        ASTNode *stmts = create_node(NODE_STATEMENT_LIST, NULL);
        add_child(stmts, (yyvsp[-1].ast));
        add_child(stmts, (yyvsp[0].ast));
        (yyval.ast) = stmts;
    }
#line 1599 "build/y.tab.c"
    break;

  case 40: /* statement: T_SEMICOLON  */
#line 235 "parser/parser.y"
                  { (yyval.ast) = create_node(NODE_EMPTY, NULL); }
#line 1605 "build/y.tab.c"
    break;

  case 41: /* do_while_statement: T_DO T_LBRACE statements T_RBRACE T_WHILE T_LPAREN expression T_RPAREN T_SEMICOLON  */
#line 240 "parser/parser.y"
    {
        ASTNode *do_while = create_node(NODE_DO_WHILE, NULL);
        add_child(do_while, (yyvsp[-6].ast)); // Bloco de statements
        add_child(do_while, (yyvsp[-2].ast)); // Condição
        (yyval.ast) = do_while;
    }
#line 1616 "build/y.tab.c"
    break;

  case 42: /* break_statement: T_BREAK T_SEMICOLON  */
#line 250 "parser/parser.y"
    {
        (yyval.ast) = create_node(NODE_BREAK, NULL);
    }
#line 1624 "build/y.tab.c"
    break;

  case 43: /* continue_statement: T_CONTINUE T_SEMICOLON  */
#line 257 "parser/parser.y"
    {
        (yyval.ast) = create_node(NODE_CONTINUE, NULL);
    }
#line 1632 "build/y.tab.c"
    break;

  case 44: /* scanf_statement: T_SCANF T_LPAREN T_STRING T_COMMA T_AMPERSAND T_ID T_RPAREN T_SEMICOLON  */
#line 264 "parser/parser.y"
    {
        ASTNode *scanf_node = create_node(NODE_SCANF, (yyvsp[-5].sval));
        add_child(scanf_node, create_node(NODE_IDENTIFIER, (yyvsp[-2].sval)));
        (yyval.ast) = scanf_node;
        free((yyvsp[-5].sval)); free((yyvsp[-2].sval));
    }
#line 1643 "build/y.tab.c"
    break;

  case 45: /* while_statement: T_WHILE T_LPAREN expression T_RPAREN T_LBRACE statements T_RBRACE  */
#line 274 "parser/parser.y"
    {
        ASTNode *while_node = create_node(NODE_WHILE, NULL);
        add_child(while_node, (yyvsp[-4].ast)); // Condição
        add_child(while_node, (yyvsp[-1].ast)); // Corpo
        (yyval.ast) = while_node;
    }
#line 1654 "build/y.tab.c"
    break;

  case 46: /* for_statement: T_FOR T_LPAREN declaration_or_expression T_SEMICOLON expression T_SEMICOLON expression T_RPAREN T_LBRACE statements T_RBRACE  */
#line 285 "parser/parser.y"
    {
        ASTNode *for_node = create_node(NODE_FOR, NULL);
        add_child(for_node, (yyvsp[-8].ast)); // Inicialização
        add_child(for_node, (yyvsp[-6].ast)); // Condição
        add_child(for_node, (yyvsp[-4].ast)); // Incremento
        add_child(for_node, (yyvsp[-1].ast)); // Corpo
        (yyval.ast) = for_node;
    }
#line 1667 "build/y.tab.c"
    break;

  case 50: /* declaration_or_expression: %empty  */
#line 299 "parser/parser.y"
             { (yyval.ast) = create_node(NODE_EMPTY, NULL); }
#line 1673 "build/y.tab.c"
    break;

  case 51: /* assignment_statement: T_ID T_ASSIGN expression T_SEMICOLON  */
#line 304 "parser/parser.y"
    {
        (yyval.ast) = create_assignment_node("=", 
            create_node(NODE_IDENTIFIER, (yyvsp[-3].sval)), 
            (yyvsp[-1].ast));
        free((yyvsp[-3].sval));
    }
#line 1684 "build/y.tab.c"
    break;

  case 52: /* assignment_statement: T_ID T_PLUS_ASSIGN expression T_SEMICOLON  */
#line 311 "parser/parser.y"
    {
        ASTNode *lhs = create_node(NODE_IDENTIFIER, (yyvsp[-3].sval));
        ASTNode *rhs = create_binary_op("+", lhs, (yyvsp[-1].ast));
        (yyval.ast) = create_assignment_node("=", lhs, rhs);
        free((yyvsp[-3].sval));
    }
#line 1695 "build/y.tab.c"
    break;

  case 53: /* assignment_statement: T_ID T_MINUS_ASSIGN expression T_SEMICOLON  */
#line 318 "parser/parser.y"
    {
        ASTNode *lhs = create_node(NODE_IDENTIFIER, (yyvsp[-3].sval));
        ASTNode *rhs = create_binary_op("-", lhs, (yyvsp[-1].ast));
        (yyval.ast) = create_assignment_node("=", lhs, rhs);
        free((yyvsp[-3].sval));
    }
#line 1706 "build/y.tab.c"
    break;

  case 54: /* increment_statement: T_ID T_INC T_SEMICOLON  */
#line 328 "parser/parser.y"
    {
        ASTNode *inc = create_node(NODE_UNARY_OP, "++");
        add_child(inc, create_node(NODE_IDENTIFIER, (yyvsp[-2].sval)));
        (yyval.ast) = inc;
        free((yyvsp[-2].sval));
    }
#line 1717 "build/y.tab.c"
    break;

  case 55: /* increment_statement: T_INC T_ID T_SEMICOLON  */
#line 335 "parser/parser.y"
    {
        ASTNode *inc = create_node(NODE_UNARY_OP, "++");
        add_child(inc, create_node(NODE_IDENTIFIER, (yyvsp[-1].sval)));
        (yyval.ast) = inc;
        free((yyvsp[-1].sval));
    }
#line 1728 "build/y.tab.c"
    break;

  case 56: /* decrement_statement: T_ID T_DEC T_SEMICOLON  */
#line 345 "parser/parser.y"
    {
        ASTNode *dec = create_node(NODE_UNARY_OP, "--");
        add_child(dec, create_node(NODE_IDENTIFIER, (yyvsp[-2].sval)));
        (yyval.ast) = dec;
        free((yyvsp[-2].sval));
    }
#line 1739 "build/y.tab.c"
    break;

  case 57: /* decrement_statement: T_DEC T_ID T_SEMICOLON  */
#line 352 "parser/parser.y"
    {
        ASTNode *dec = create_node(NODE_UNARY_OP, "--");
        add_child(dec, create_node(NODE_IDENTIFIER, (yyvsp[-1].sval)));
        (yyval.ast) = dec;
        free((yyvsp[-1].sval));
    }
#line 1750 "build/y.tab.c"
    break;

  case 58: /* return_statement: T_RETURN expression T_SEMICOLON  */
#line 362 "parser/parser.y"
    {
        ASTNode *ret = create_node(NODE_RETURN, NULL);
        add_child(ret, (yyvsp[-1].ast));
        (yyval.ast) = ret;
    }
#line 1760 "build/y.tab.c"
    break;

  case 59: /* $@3: %empty  */
#line 371 "parser/parser.y"
    {
        ASTNode *if_node = create_node(NODE_IF, NULL);
        add_child(if_node, (yyvsp[-4].ast)); // Condição
        add_child(if_node, (yyvsp[-1].ast)); // Then
        if_node_temp = if_node;
    }
#line 1771 "build/y.tab.c"
    break;

  case 60: /* if_statement: T_IF T_LPAREN expression T_RPAREN T_LBRACE statements T_RBRACE $@3 elseif_chain  */
#line 378 "parser/parser.y"
    {
        add_child(if_node_temp, (yyvsp[0].ast)); // Else/ElseIf
        (yyval.ast) = if_node_temp;
    }
#line 1780 "build/y.tab.c"
    break;

  case 61: /* elseif_chain: %empty  */
#line 385 "parser/parser.y"
           { (yyval.ast) = create_node(NODE_EMPTY, NULL); }
#line 1786 "build/y.tab.c"
    break;

  case 62: /* elseif_chain: T_ELSE T_IF T_LPAREN expression T_RPAREN T_LBRACE statements T_RBRACE  */
#line 387 "parser/parser.y"
    {
        ASTNode *elseif = create_node(NODE_ELSE_IF, NULL);
        add_child(elseif, (yyvsp[-4].ast)); // Condição
        add_child(elseif, (yyvsp[-1].ast)); // Then
        (yyval.ast) = elseif;
    }
#line 1797 "build/y.tab.c"
    break;

  case 63: /* elseif_chain: T_ELSE T_LBRACE statements T_RBRACE  */
#line 394 "parser/parser.y"
    {
        (yyval.ast) = create_node(NODE_ELSE, NULL);
        add_child((yyval.ast), (yyvsp[-1].ast)); // Bloco else
    }
#line 1806 "build/y.tab.c"
    break;

  case 64: /* switch_statement: T_SWITCH T_LPAREN expression T_RPAREN T_LBRACE case_list T_RBRACE  */
#line 402 "parser/parser.y"
    {
        ASTNode *switch_node = create_node(NODE_SWITCH, NULL);
        add_child(switch_node, (yyvsp[-4].ast)); // Expressão
        add_child(switch_node, (yyvsp[-1].ast)); // Casos
        (yyval.ast) = switch_node;
    }
#line 1817 "build/y.tab.c"
    break;

  case 65: /* case_list: %empty  */
#line 411 "parser/parser.y"
           { (yyval.ast) = create_node(NODE_EMPTY, NULL); }
#line 1823 "build/y.tab.c"
    break;

  case 66: /* case_list: case_statement case_list  */
#line 413 "parser/parser.y"
    {
        ASTNode *cases = create_node(NODE_CASE_LIST, NULL);
        add_child(cases, (yyvsp[-1].ast));
        add_child(cases, (yyvsp[0].ast));
        (yyval.ast) = cases;
    }
#line 1834 "build/y.tab.c"
    break;

  case 68: /* case_statement: T_CASE expression T_COLON statement_list  */
#line 424 "parser/parser.y"
    {
        ASTNode *case_node = create_node(NODE_CASE, NULL);
        add_child(case_node, (yyvsp[-2].ast)); // Valor
        add_child(case_node, (yyvsp[0].ast)); // Statements
        (yyval.ast) = case_node;
    }
#line 1845 "build/y.tab.c"
    break;

  case 69: /* default_statement: T_DEFAULT T_COLON statement_list  */
#line 434 "parser/parser.y"
    {
        ASTNode *default_node = create_node(NODE_DEFAULT, NULL);
        add_child(default_node, (yyvsp[0].ast)); // Statements
        (yyval.ast) = default_node;
    }
#line 1855 "build/y.tab.c"
    break;

  case 70: /* statement_list: %empty  */
#line 442 "parser/parser.y"
           { (yyval.ast) = create_node(NODE_EMPTY, NULL); }
#line 1861 "build/y.tab.c"
    break;

  case 71: /* statement_list: statement statement_list  */
#line 444 "parser/parser.y"
    {
        ASTNode *stmts = create_node(NODE_STATEMENT_LIST, NULL);
        add_child(stmts, (yyvsp[-1].ast));
        add_child(stmts, (yyvsp[0].ast));
        (yyval.ast) = stmts;
    }
#line 1872 "build/y.tab.c"
    break;

  case 72: /* function_call_statement: T_ID T_LPAREN T_RPAREN T_SEMICOLON  */
#line 454 "parser/parser.y"
    {
        ASTNode *call = create_node(NODE_FUNCTION_CALL, (yyvsp[-3].sval));
        (yyval.ast) = call;
        free((yyvsp[-3].sval));
    }
#line 1882 "build/y.tab.c"
    break;

  case 73: /* expression: T_ID  */
#line 462 "parser/parser.y"
                             { (yyval.ast) = create_node(NODE_IDENTIFIER, (yyvsp[0].sval)); }
#line 1888 "build/y.tab.c"
    break;

  case 74: /* expression: T_NUMBER_INT  */
#line 463 "parser/parser.y"
                             { 
        char num[20]; 
        sprintf(num, "%d", (yyvsp[0].ival)); 
        (yyval.ast) = create_node(NODE_CONST_INT, num); 
    }
#line 1898 "build/y.tab.c"
    break;

  case 75: /* expression: T_NUMBER_FLOAT  */
#line 468 "parser/parser.y"
                             { 
        char num[20]; 
        sprintf(num, "%f", (yyvsp[0].fval)); 
        (yyval.ast) = create_node(NODE_CONST_FLOAT, num); 
    }
#line 1908 "build/y.tab.c"
    break;

  case 76: /* expression: T_STRING  */
#line 473 "parser/parser.y"
                             { (yyval.ast) = create_node(NODE_CONST_STRING, (yyvsp[0].sval)); }
#line 1914 "build/y.tab.c"
    break;

  case 77: /* expression: T_CHAR_LITERAL  */
#line 474 "parser/parser.y"
                             { (yyval.ast) = create_node(NODE_CONST_CHAR, (yyvsp[0].sval)); }
#line 1920 "build/y.tab.c"
    break;

  case 78: /* expression: expression T_PLUS expression  */
#line 475 "parser/parser.y"
                                      { (yyval.ast) = create_binary_op("+", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1926 "build/y.tab.c"
    break;

  case 79: /* expression: expression T_MINUS expression  */
#line 476 "parser/parser.y"
                                      { (yyval.ast) = create_binary_op("-", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1932 "build/y.tab.c"
    break;

  case 80: /* expression: expression T_MULT expression  */
#line 477 "parser/parser.y"
                                      { (yyval.ast) = create_binary_op("*", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1938 "build/y.tab.c"
    break;

  case 81: /* expression: expression T_DIV expression  */
#line 478 "parser/parser.y"
                                      { (yyval.ast) = create_binary_op("/", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1944 "build/y.tab.c"
    break;

  case 82: /* expression: expression T_MOD expression  */
#line 479 "parser/parser.y"
                                      { (yyval.ast) = create_binary_op("%", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1950 "build/y.tab.c"
    break;

  case 83: /* expression: expression T_EQ expression  */
#line 480 "parser/parser.y"
                                      { (yyval.ast) = create_binary_op("==", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1956 "build/y.tab.c"
    break;

  case 84: /* expression: expression T_NEQ expression  */
#line 481 "parser/parser.y"
                                      { (yyval.ast) = create_binary_op("!=", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1962 "build/y.tab.c"
    break;

  case 85: /* expression: expression T_LT expression  */
#line 482 "parser/parser.y"
                                      { (yyval.ast) = create_binary_op("<", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1968 "build/y.tab.c"
    break;

  case 86: /* expression: expression T_GT expression  */
#line 483 "parser/parser.y"
                                      { (yyval.ast) = create_binary_op(">", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1974 "build/y.tab.c"
    break;

  case 87: /* expression: expression T_LE expression  */
#line 484 "parser/parser.y"
                                      { (yyval.ast) = create_binary_op("<=", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1980 "build/y.tab.c"
    break;

  case 88: /* expression: expression T_GE expression  */
#line 485 "parser/parser.y"
                                      { (yyval.ast) = create_binary_op(">=", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1986 "build/y.tab.c"
    break;

  case 89: /* expression: expression T_AND expression  */
#line 486 "parser/parser.y"
                                      { (yyval.ast) = create_binary_op("e", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1992 "build/y.tab.c"
    break;

  case 90: /* expression: expression T_OR expression  */
#line 487 "parser/parser.y"
                                      { (yyval.ast) = create_binary_op("ou", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1998 "build/y.tab.c"
    break;

  case 91: /* expression: expression T_BIT_OR expression  */
#line 488 "parser/parser.y"
                                      { (yyval.ast) = create_binary_op("|", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2004 "build/y.tab.c"
    break;

  case 92: /* expression: T_AMPERSAND expression  */
#line 489 "parser/parser.y"
                                     { (yyval.ast) = create_unary_op("&", (yyvsp[0].ast)); }
#line 2010 "build/y.tab.c"
    break;

  case 93: /* expression: T_NOT expression  */
#line 490 "parser/parser.y"
                                     { (yyval.ast) = create_unary_op("nao", (yyvsp[0].ast)); }
#line 2016 "build/y.tab.c"
    break;

  case 94: /* expression: T_LPAREN expression T_RPAREN  */
#line 491 "parser/parser.y"
                                     { (yyval.ast) = (yyvsp[-1].ast); }
#line 2022 "build/y.tab.c"
    break;

  case 95: /* expression: expression T_DOT T_ID  */
#line 492 "parser/parser.y"
                                      { 
        ASTNode *dot = create_node(NODE_MEMBER_ACCESS, ".");
        add_child(dot, (yyvsp[-2].ast));
        add_child(dot, create_node(NODE_IDENTIFIER, (yyvsp[0].sval)));
        (yyval.ast) = dot;
        free((yyvsp[0].sval));
    }
#line 2034 "build/y.tab.c"
    break;

  case 96: /* expression: expression T_ARROW T_ID  */
#line 499 "parser/parser.y"
                                      { 
        ASTNode *arrow = create_node(NODE_POINTER_ACCESS, "->");
        add_child(arrow, (yyvsp[-2].ast));
        add_child(arrow, create_node(NODE_IDENTIFIER, (yyvsp[0].sval)));
        (yyval.ast) = arrow;
        free((yyvsp[0].sval));
    }
#line 2046 "build/y.tab.c"
    break;

  case 97: /* expression: T_ID T_LPAREN T_RPAREN  */
#line 506 "parser/parser.y"
                                      { 
        ASTNode *call = create_node(NODE_FUNCTION_CALL, (yyvsp[-2].sval)); 
        (yyval.ast) = call;
        free((yyvsp[-2].sval));
    }
#line 2056 "build/y.tab.c"
    break;

  case 98: /* expression: '*' expression  */
#line 511 "parser/parser.y"
                                      { (yyval.ast) = create_unary_op("*", (yyvsp[0].ast)); }
#line 2062 "build/y.tab.c"
    break;

  case 99: /* printf_statement: T_PRINTF T_LPAREN expression T_RPAREN T_SEMICOLON  */
#line 516 "parser/parser.y"
    {
        ASTNode *printf_node = create_node(NODE_PRINTF, NULL);
        add_child(printf_node, (yyvsp[-2].ast));
        (yyval.ast) = printf_node;
    }
#line 2072 "build/y.tab.c"
    break;


#line 2076 "build/y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 523 "parser/parser.y"


// Funções auxiliares
ASTNode* create_declaration_node(char *type, char *name, ASTNode *init) {
    ASTNode *decl = create_node(NODE_DECLARATION, name);
    add_child(decl, create_node(NODE_TYPE, type));
    if (init) {
        ASTNode *assign = create_node(NODE_ASSIGNMENT, "=");
        add_child(assign, create_node(NODE_IDENTIFIER, name));
        add_child(assign, init);
        add_child(decl, assign);
    }
    return decl;
}

ASTNode* create_assignment_node(char *op, ASTNode *lhs, ASTNode *rhs) {
    ASTNode *assign = create_node(NODE_ASSIGNMENT, op);
    add_child(assign, lhs);
    add_child(assign, rhs);
    return assign;
}

ASTNode* create_binary_op(char *op, ASTNode *lhs, ASTNode *rhs) {
    ASTNode *binop = create_node(NODE_BINARY_OP, op);
    add_child(binop, lhs);
    add_child(binop, rhs);
    return binop;
}

ASTNode* create_unary_op(char *op, ASTNode *operand) {
    ASTNode *unop = create_node(NODE_UNARY_OP, op);
    add_child(unop, operand);
    return unop;
}

void yyerror(const char *s) {
    fprintf(stderr, "Erro de sintaxe: %s\n", s);
    exit(1);
}
