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
#line 1 "anasin.y"

    #include <stdio.h>
    //Modificacion convocatoria de julio, necesitamos esta libreria para el nuevo main
    #include <stdlib.h>
    #include "listaSimbolos.h"
    #include "listaCodigo.h"
    #include <string.h>
    #include <stdbool.h> 
    //Modificacion convocatoria de julio
    // char main(); ya no hace falta declararlo en los %
    void comprMain(char *id);
    bool perteneceTablaS(char *id);
    void insertaTablaS(char *id, Tipo t, int contador);
    bool esConstante(Tipo t);
    void yyerror(const char *s);
    char *obtenerRegistro();
    void liberarRegistro(char *nombre);
    void ocuparRegistro(int indice);
    char *crearEtiqueta();
    void imprimirCodigo(ListaC codigoFinal);
    ListaC crearRelacional(ListaC izq, ListaC der, char *opRelacion);
    void push(char *etiqueta); 
    void pop();
    char *top();
    extern int yylineno;
    extern int yylex();
    extern FILE *yyin; //Modificacion de la convocatoria de julio, para el nuevo main
    Lista tablaSimb;
    int contCadenas = 0;
    Tipo t;
    int registros[10] = {0,0,0,0,0,0,0,0,0,0}; 
    int contEtiquetas = 0;
    //Vale para la mejora del break lo que se nos ha ocurrido es hacer una pila para almacenar las etiquetas de los bucles para que asi al hacer el break dentro de un bucle siempre salte entonces al bucle mas interno
    char *pilaSalidas[100];
    int tope = -1; //Inicializamos el tope de la pila
    bool error = false; //variable booleana para saber si hemos tenido un error y asi no generar el codigo ensamblador
    //hemos de decir que a nosotros nos ha parecido util implementarla sobre todo para que en los casos de prueba no nos genere este codigo que estaria mal. Aunque creemos que no es requerida por el documento pero a nosotros no nos ha parecido mal implementarlo
    FILE *fich;//Modificacion de la convocatoria de julio ,para el nuemo main

#line 111 "anasin.tab.c"

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

#include "anasin.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_STRING = 3,                     /* STRING  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_INTLITERAL = 5,                 /* INTLITERAL  */
  YYSYMBOL_VOID = 6,                       /* VOID  */
  YYSYMBOL_VAR = 7,                        /* VAR  */
  YYSYMBOL_CONST = 8,                      /* CONST  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_ELSE = 10,                      /* ELSE  */
  YYSYMBOL_WHILE = 11,                     /* WHILE  */
  YYSYMBOL_PRINT = 12,                     /* PRINT  */
  YYSYMBOL_READ = 13,                      /* READ  */
  YYSYMBOL_LPAREN = 14,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 15,                    /* RPAREN  */
  YYSYMBOL_SEMICOLON = 16,                 /* SEMICOLON  */
  YYSYMBOL_PLUSOP = 17,                    /* PLUSOP  */
  YYSYMBOL_MINUSOP = 18,                   /* MINUSOP  */
  YYSYMBOL_COMMA = 19,                     /* COMMA  */
  YYSYMBOL_ASSIGNOP = 20,                  /* ASSIGNOP  */
  YYSYMBOL_BARRA = 21,                     /* BARRA  */
  YYSYMBOL_LCORCH = 22,                    /* LCORCH  */
  YYSYMBOL_RCORCH = 23,                    /* RCORCH  */
  YYSYMBOL_POR = 24,                       /* POR  */
  YYSYMBOL_DIV = 25,                       /* DIV  */
  YYSYMBOL_INT = 26,                       /* INT  */
  YYSYMBOL_DO = 27,                        /* DO  */
  YYSYMBOL_BREAK = 28,                     /* BREAK  */
  YYSYMBOL_MENOR = 29,                     /* MENOR  */
  YYSYMBOL_MAYOR = 30,                     /* MAYOR  */
  YYSYMBOL_MEQ = 31,                       /* MEQ  */
  YYSYMBOL_MAQ = 32,                       /* MAQ  */
  YYSYMBOL_EQQ = 33,                       /* EQQ  */
  YYSYMBOL_NEQ = 34,                       /* NEQ  */
  YYSYMBOL_UMINUS = 35,                    /* UMINUS  */
  YYSYMBOL_ABAJO_DEL_ELSE = 36,            /* ABAJO_DEL_ELSE  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_program = 38,                   /* program  */
  YYSYMBOL_body = 39,                      /* body  */
  YYSYMBOL_declaration = 40,               /* declaration  */
  YYSYMBOL_41_1 = 41,                      /* $@1  */
  YYSYMBOL_42_2 = 42,                      /* $@2  */
  YYSYMBOL_tipo = 43,                      /* tipo  */
  YYSYMBOL_id_list = 44,                   /* id_list  */
  YYSYMBOL_id_decl = 45,                   /* id_decl  */
  YYSYMBOL_statement = 46,                 /* statement  */
  YYSYMBOL_47_3 = 47,                      /* $@3  */
  YYSYMBOL_48_4 = 48,                      /* $@4  */
  YYSYMBOL_statement_list = 49,            /* statement_list  */
  YYSYMBOL_print_list = 50,                /* print_list  */
  YYSYMBOL_print_item = 51,                /* print_item  */
  YYSYMBOL_read_list = 52,                 /* read_list  */
  YYSYMBOL_expresion = 53                  /* expresion  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   196

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  47
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  105

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


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
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    59,    59,    67,    73,    79,    83,    83,    87,    87,
      92,    93,    97,   104,   115,   139,   167,   170,   207,   229,
     229,   273,   273,   306,   321,   324,   328,   333,   337,   340,
     346,   369,   401,   439,   478,   483,   487,   491,   495,   499,
     502,   519,   536,   553,   570,   584,   587,   601
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
  "\"end of file\"", "error", "\"invalid token\"", "STRING", "ID",
  "INTLITERAL", "VOID", "VAR", "CONST", "IF", "ELSE", "WHILE", "PRINT",
  "READ", "LPAREN", "RPAREN", "SEMICOLON", "PLUSOP", "MINUSOP", "COMMA",
  "ASSIGNOP", "BARRA", "LCORCH", "RCORCH", "POR", "DIV", "INT", "DO",
  "BREAK", "MENOR", "MAYOR", "MEQ", "MAQ", "EQQ", "NEQ", "UMINUS",
  "ABAJO_DEL_ELSE", "$accept", "program", "body", "declaration", "$@1",
  "$@2", "tipo", "id_list", "id_decl", "statement", "$@3", "$@4",
  "statement_list", "print_list", "print_item", "read_list", "expresion", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-25)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -5,     4,    19,    29,   -25,    40,    35,   -25,    38,    49,
     -25,   -25,    64,    70,    71,    74,   -25,   -25,   -25,    57,
     -25,   -25,    10,    53,    53,    10,    10,    13,    87,    -2,
      59,   -25,   -25,   -25,    10,    10,   144,   -25,    88,    88,
      65,    85,   -25,    33,   -25,   162,   -25,    39,   -25,   -25,
      82,   105,   -25,   -25,    10,    10,    10,    10,    10,    10,
      10,    10,    10,    10,    81,    37,   -25,    43,    59,   -25,
      89,    13,    90,   100,    93,   -25,    52,    52,   -25,   -25,
       5,     5,     5,     5,     5,     5,    10,   -25,    88,   -25,
      98,    59,   -25,   -25,   -25,   -25,    10,   162,   -25,    59,
     -25,   125,   -25,    95,   -25
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     5,     0,     0,
       6,     8,     0,     0,     0,     0,    27,     2,    21,     0,
       3,     4,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    23,    46,    47,     0,     0,     0,    10,     0,     0,
       0,     0,    31,     0,    28,    30,    32,     0,    16,    26,
       0,     0,    44,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    13,     0,    11,     0,     0,    19,
       0,     0,     0,     0,     0,    45,    40,    41,    42,    43,
      34,    35,    36,    37,    38,    39,     0,     7,     0,     9,
      18,     0,    24,    29,    25,    33,     0,    14,    12,     0,
      20,     0,    17,     0,    22
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -25,   -25,   -25,   -25,   -25,   -25,    97,    73,    25,   -24,
     -25,   -25,   -25,   -25,    54,   -25,   -22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     8,    20,    23,    24,    38,    65,    66,    21,
      91,    30,    29,    43,    44,    47,    45
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      36,     1,     9,    40,    41,    49,    50,    12,     3,    13,
      14,    15,    51,    52,    32,    33,    42,    32,    33,     4,
      16,    48,    54,    55,    34,    18,    19,    34,    35,    56,
      57,    35,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,     9,     5,    90,    10,    11,    12,    70,    13,
      14,    15,    71,    87,    72,     6,    88,     7,    73,    89,
      16,    17,    88,     9,    97,    18,    19,   100,    12,    22,
      13,    14,    15,    31,   101,   102,    56,    57,    25,    37,
      68,    16,    54,    55,    26,    27,    18,    19,    28,    56,
      57,    46,    64,    74,    58,    59,    60,    61,    62,    63,
      69,    86,    54,    55,    95,    92,    94,    96,    99,    56,
      57,   104,    67,    98,    58,    59,    60,    61,    62,    63,
      75,    39,    54,    55,     0,    93,     0,     0,     0,    56,
      57,     0,     0,     0,    58,    59,    60,    61,    62,    63,
     103,     0,    54,    55,     0,     0,     0,     0,     0,    56,
      57,     0,     0,     0,    58,    59,    60,    61,    62,    63,
      53,    54,    55,     0,     0,     0,     0,     0,    56,    57,
       0,     0,     0,    58,    59,    60,    61,    62,    63,    54,
      55,     0,     0,     0,     0,     0,    56,    57,     0,     0,
       0,    58,    59,    60,    61,    62,    63
};

static const yytype_int8 yycheck[] =
{
      22,     6,     4,    25,    26,    29,    30,     9,     4,    11,
      12,    13,    34,    35,     4,     5,     3,     4,     5,     0,
      22,    23,    17,    18,    14,    27,    28,    14,    18,    24,
      25,    18,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,     4,    14,    68,     7,     8,     9,    15,    11,
      12,    13,    19,    16,    15,    15,    19,    22,    19,    16,
      22,    23,    19,     4,    86,    27,    28,    91,     9,    20,
      11,    12,    13,    16,    96,    99,    24,    25,    14,    26,
      15,    22,    17,    18,    14,    14,    27,    28,    14,    24,
      25,     4,     4,    11,    29,    30,    31,    32,    33,    34,
      15,    20,    17,    18,     4,    16,    16,    14,    10,    24,
      25,    16,    39,    88,    29,    30,    31,    32,    33,    34,
      15,    24,    17,    18,    -1,    71,    -1,    -1,    -1,    24,
      25,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
      15,    -1,    17,    18,    -1,    -1,    -1,    -1,    -1,    24,
      25,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
      16,    17,    18,    -1,    -1,    -1,    -1,    -1,    24,    25,
      -1,    -1,    -1,    29,    30,    31,    32,    33,    34,    17,
      18,    -1,    -1,    -1,    -1,    -1,    24,    25,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    38,     4,     0,    14,    15,    22,    39,     4,
       7,     8,     9,    11,    12,    13,    22,    23,    27,    28,
      40,    46,    20,    41,    42,    14,    14,    14,    14,    49,
      48,    16,     4,     5,    14,    18,    53,    26,    43,    43,
      53,    53,     3,    50,    51,    53,     4,    52,    23,    46,
      46,    53,    53,    16,    17,    18,    24,    25,    29,    30,
      31,    32,    33,    34,     4,    44,    45,    44,    15,    15,
      15,    19,    15,    19,    11,    15,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    20,    16,    19,    16,
      46,    47,    16,    51,    16,     4,    14,    53,    45,    10,
      46,    53,    46,    15,    16
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    39,    41,    40,    42,    40,
      43,    44,    44,    45,    45,    46,    46,    46,    46,    47,
      46,    48,    46,    46,    46,    46,    49,    49,    50,    50,
      51,    51,    52,    52,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     7,     2,     2,     0,     0,     5,     0,     5,
       1,     1,     3,     1,     3,     4,     3,     7,     5,     0,
       6,     0,     8,     2,     5,     5,     2,     0,     1,     3,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     1,     1
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
  case 2: /* program: VOID ID LPAREN RPAREN LCORCH body RCORCH  */
#line 59 "anasin.y"
                                                   {//Aqui vamos a llamar a la funcion que nos comprueba que sea main 
    comprMain((yyvsp[-5].lexema));
    ListaC codigoFinal = (yyvsp[-1].codigo);
    if(!error){
        imprimirCodigo(codigoFinal);
    }
}
#line 1235 "anasin.tab.c"
    break;

  case 3: /* body: body declaration  */
#line 67 "anasin.y"
                       {
    //MODIFICACIONES CONVOCATORIA DE JULIO CONCATENA Y LIBERA
    concatenaLC((yyvsp[-1].codigo),(yyvsp[0].codigo));
    (yyval.codigo) = (yyvsp[-1].codigo);
    liberaLC((yyvsp[0].codigo));
}
#line 1246 "anasin.tab.c"
    break;

  case 4: /* body: body statement  */
#line 73 "anasin.y"
                    {
        //Aqui culminamos todo ya que si no concatenamos los codigos que nos han llegado subiendo esta mal el compilador 
        concatenaLC((yyvsp[-1].codigo),(yyvsp[0].codigo));
        (yyval.codigo) = (yyvsp[-1].codigo);
        liberaLC((yyvsp[0].codigo));
    }
#line 1257 "anasin.tab.c"
    break;

  case 5: /* body: %empty  */
#line 79 "anasin.y"
     {
        (yyval.codigo) = creaLC(); //Igual que en el otro caso de lambda
    }
#line 1265 "anasin.tab.c"
    break;

  case 6: /* $@1: %empty  */
#line 83 "anasin.y"
                 {t = VARIABLE;}
#line 1271 "anasin.tab.c"
    break;

  case 7: /* declaration: VAR $@1 tipo id_list SEMICOLON  */
#line 83 "anasin.y"
                                                       {
    //MODIFICACION CONVOCATORIA DE JULIO
    (yyval.codigo) = (yyvsp[-1].codigo);
}
#line 1280 "anasin.tab.c"
    break;

  case 8: /* $@2: %empty  */
#line 87 "anasin.y"
            {t = CONSTANTE;}
#line 1286 "anasin.tab.c"
    break;

  case 9: /* declaration: CONST $@2 tipo id_list SEMICOLON  */
#line 87 "anasin.y"
                                                   {
        //MODIFICACION CONVOCATORIA DE JULIO
        (yyval.codigo) = (yyvsp[-1].codigo);
    }
#line 1295 "anasin.tab.c"
    break;

  case 11: /* id_list: id_decl  */
#line 93 "anasin.y"
                {
    //MODIFICACION CONVOCATORIA DE JULIO
    (yyval.codigo) = (yyvsp[0].codigo);
}
#line 1304 "anasin.tab.c"
    break;

  case 12: /* id_list: id_list COMMA id_decl  */
#line 97 "anasin.y"
                           {
        //MODIFICACION CONVOCATORIA DE JULIO
        concatenaLC((yyvsp[-2].codigo),(yyvsp[0].codigo));// Junto los codigos de las variables
        (yyval.codigo) = (yyvsp[-2].codigo);
        liberaLC((yyvsp[0].codigo));
    }
#line 1315 "anasin.tab.c"
    break;

  case 13: /* id_decl: ID  */
#line 104 "anasin.y"
           {
    if(perteneceTablaS((yyvsp[0].lexema))){
        printf("Error semantico en la linea %d: La variable '%s' ya ha sido declarada anteriormente\n",yylineno,(yyvsp[0].lexema));
        //Cambio convocatoria de julio, en caso de error ponemos error a true
        error = true;
    }else{
        insertaTablaS((yyvsp[0].lexema),t,0); //Recordamos que t es el tipo de la variable y que ya esta declarado anteriormente 
    }
    //MODIFICACIONES CONVOCATORIA DE JULIO
    (yyval.codigo) = creaLC(); //Subimos el codigo 
    /*Hay que dar de alta este tipo de variables y si aparece en la tabla de simbolos no damos error y si no aparece damos error */}
#line 1331 "anasin.tab.c"
    break;

  case 14: /* id_decl: ID ASSIGNOP expresion  */
#line 115 "anasin.y"
                           { 
    if(perteneceTablaS((yyvsp[-2].lexema))){
        printf("Error semantico en la linea %d: La variable '%s' ya ha sido declarada anteriormente\n",yylineno,(yyvsp[-2].lexema));
        //MODIFICACION CONVOCATORIA DE JULIO
        error = true;
        (yyval.codigo) = (yyvsp[0].codigo);
    }else{
        insertaTablaS((yyvsp[-2].lexema),t,0); //Recordamos que t es el tipo de la variable y que ya esta declarado anteriormente 
        //MOFICIACIONES CONVOCATORIA DE JULIO
        //Literalmente nos falta solo la implementacion 
        (yyval.codigo) = (yyvsp[0].codigo);
        char *res = recuperaResLC((yyvsp[0].codigo));
        Operacion op;
        op.op = "sw";
        op.res = res;
        op.arg1 = (yyvsp[-2].lexema);
        op.arg2 = NULL;
        insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
        guardaResLC((yyval.codigo),res);
        liberarRegistro(res);
        //Resumen de lo que hemos hecho, en definitiva implementar que se pueda declarar una variable y se le pueda dar valor en una misma linea
    }
    /*Hay que dar de alta este tipo de variables y si aparece en la tabla de simbolos no damos error y si no aparece damos error */}
#line 1359 "anasin.tab.c"
    break;

  case 15: /* statement: ID ASSIGNOP expresion SEMICOLON  */
#line 139 "anasin.y"
                                          { 
    PosicionLista p = buscaLS(tablaSimb,(yyvsp[-3].lexema)); //Aqui buscamos si id esta en la tabla de simbolos 
    if(p == finalLS(tablaSimb)){
        printf("Error semantico en la linea %d: La variable '%s' no ha sido declarada en la tabla\n",yylineno,(yyvsp[-3].lexema));
        //Aqui aunque de error vamos a crear una lista vacia para que no nos de un segmentation error 
        error = true; //Marcamos que hubo un error para que no genere el codigo
        (yyval.codigo) = (yyvsp[-1].codigo);
    }else{
        Simbolo s = recuperaLS(tablaSimb,p); //Recuperamos el simbolo buscandolo en la lista
        if(esConstante(s.tipo)){ //En el caso de que sea una constante no se debe de poder modificar
            printf("Error semantico en la linea %d: La variable '%s' es una constante y no se puede modificar\n",yylineno,(yyvsp[-3].lexema));
            //Aqui vamos a hacer lo mismo que arriba
            error = true;
            (yyval.codigo) = (yyvsp[-1].codigo);
        }else{
            (yyval.codigo) = (yyvsp[-1].codigo);
            char *res = recuperaResLC((yyvsp[-1].codigo));
            Operacion op;
            op.op = "sw"; 
            op.res = res;
            op.arg1 = (yyvsp[-3].lexema); //Aqui esta el nombre la variable
            op.arg2 = NULL;
            insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
            guardaResLC((yyval.codigo),res);
            liberarRegistro(res);
    }
    }
}
#line 1392 "anasin.tab.c"
    break;

  case 16: /* statement: LCORCH statement_list RCORCH  */
#line 167 "anasin.y"
                                  {
        (yyval.codigo) = (yyvsp[-1].codigo);
    }
#line 1400 "anasin.tab.c"
    break;

  case 17: /* statement: IF LPAREN expresion RPAREN statement ELSE statement  */
#line 170 "anasin.y"
                                                          {/*Aqui tenemos conflicto por que si ponemos dos if juntos bison nos estara agrupando el else con el primer if y queremos que ese else sea del segundo if por tanto vamos a darle prioridad*/
        (yyval.codigo) = (yyvsp[-4].codigo);
        char *res = recuperaResLC((yyvsp[-4].codigo));
        char *label = crearEtiqueta();
        Operacion op;
        op.op = "beqz";
        op.res = res;
        op.arg1 = label;
        op.arg2 = NULL;
        insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
        guardaResLC((yyval.codigo),res);
        liberarRegistro(res);
        concatenaLC((yyval.codigo),(yyvsp[-2].codigo));
        liberaLC((yyvsp[-2].codigo));
        Operacion op1;
        char *label2 = crearEtiqueta();
        op1.op = "b";
        op1.res = label2; //Esto es para que al imprimir salga con el : al fin y al cabo estoy aprovechando estos campos simplemente para mostrar en el fichero o por pantalla la generacion del codigo
        op1.arg1 = NULL;
        op1.arg2 = NULL;
        insertaLC((yyval.codigo),finalLC((yyval.codigo)),op1);
        Operacion op2;
        op2.op = label;
        op2.res = ":";
        op2.arg1 = NULL;
        op2.arg2 = NULL;
        insertaLC((yyval.codigo),finalLC((yyval.codigo)),op2);
        concatenaLC((yyval.codigo),(yyvsp[0].codigo));
        liberaLC((yyvsp[0].codigo));
        Operacion op3;
        op3.op = label2;
        op3.res = ":";
        op3.arg1 = NULL;
        op3.arg2 = NULL;
        insertaLC((yyval.codigo),finalLC((yyval.codigo)),op3);

    }
#line 1442 "anasin.tab.c"
    break;

  case 18: /* statement: IF LPAREN expresion RPAREN statement  */
#line 207 "anasin.y"
                                                                {/*A esta regla que es la que no tiene todavia el else le ponemos una prioridad mas baja que la del else para que asi vaya primero el else y luego reconozca junto a ese else el if mas cercano al else*/
    
    (yyval.codigo) = (yyvsp[-2].codigo);
    char *res = recuperaResLC((yyvsp[-2].codigo));
    char *label = crearEtiqueta();
    Operacion op;
    op.op = "beqz";
    op.res = res;
    op.arg1 = label;
    op.arg2 = NULL;
    insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
    guardaResLC((yyval.codigo),res);
    liberarRegistro(res);
    concatenaLC((yyval.codigo),(yyvsp[0].codigo));
    liberaLC((yyvsp[0].codigo));
    Operacion op1;
    op1.op = label;
    op1.res = ":"; //Esto es para que al imprimir salga con el : al fin y al cabo estoy aprovechando estos campos simplemente para mostrar en el fichero o por pantalla la generacion del codigo
    op1.arg1 = NULL;
    op1.arg2 = NULL;
    insertaLC((yyval.codigo),finalLC((yyval.codigo)),op1);
    }
#line 1469 "anasin.tab.c"
    break;

  case 19: /* $@3: %empty  */
#line 229 "anasin.y"
                                   {char *labelFin = crearEtiqueta(); 
                                    push(labelFin);
    }
#line 1477 "anasin.tab.c"
    break;

  case 20: /* statement: WHILE LPAREN expresion RPAREN $@3 statement  */
#line 231 "anasin.y"
                {
        char *label = crearEtiqueta();
        char *labelFin = top();
        Operacion op;
        op.op = label;
        op.res = ":";
        op.arg1 = NULL;
        op.arg2 = NULL;
        ListaC listaAux = creaLC();
        insertaLC(listaAux,finalLC(listaAux),op);
        concatenaLC(listaAux,(yyvsp[-3].codigo));
        //Primero hacemos la etiqueta y como esta debe de ir al principo la concatenamos la expresion con la lista auxiliar estando antes la auxiliar para que este primera
        Operacion op1;
        (yyval.codigo) = listaAux;
        op1.op = "beqz";
        char *res = recuperaResLC((yyvsp[-3].codigo));
        op1.res = res;
        //CAMBIO CONVOCATORIA DE JULIO
        op1.arg1 = labelFin; //Nos hemos dado cuenta de que a la hora de hacer el while pusimos mal la etiqueta y los bucles se quedaban colgados
        op1.arg2 = NULL;
        insertaLC((yyval.codigo),finalLC((yyval.codigo)),op1);
        guardaResLC((yyval.codigo),res);
        liberarRegistro(res);
        concatenaLC((yyval.codigo),(yyvsp[0].codigo));
        Operacion op2;
        op2.op = "b";
        op2.res = label;
        op2.arg1 = NULL;
        op2.arg2 = NULL;
        insertaLC((yyval.codigo),finalLC((yyval.codigo)),op2);
        Operacion op3;
        op3.op = labelFin;
        op3.res = ":";
        //CAMBIO CONVOCATORIA DE JULIO
        op3.arg1 = NULL;
        op3.arg2 = NULL;
        //Se nos olvido poner el 3,puede ser que no explotara pero es mejor poner esto
        insertaLC((yyval.codigo),finalLC((yyval.codigo)),op3);
        liberaLC((yyvsp[-3].codigo));
        liberaLC((yyvsp[0].codigo));
        pop(); //Al terminar el bucle si no se ha producido el break pues eliminamos la etiqueta de la pila 
    }
#line 1524 "anasin.tab.c"
    break;

  case 21: /* $@4: %empty  */
#line 273 "anasin.y"
        {
        char *labelFin = crearEtiqueta();
        push(labelFin);
    }
#line 1533 "anasin.tab.c"
    break;

  case 22: /* statement: DO $@4 statement WHILE LPAREN expresion RPAREN SEMICOLON  */
#line 276 "anasin.y"
                                                       {
        char *etiquetaRet = crearEtiqueta();
        char *labelFin = top();
        (yyval.codigo) = creaLC();
        Operacion op1;
        op1.op = etiquetaRet;
        op1.res = ":";
        op1.arg1 = NULL;
        op1.arg2 = NULL;
        insertaLC((yyval.codigo),finalLC((yyval.codigo)),op1);
        concatenaLC((yyval.codigo),(yyvsp[-5].codigo)); //Lo ponemos al principio del codigo del statement para que se ejecute al menos una vez
        concatenaLC((yyval.codigo),(yyvsp[-2].codigo)); //Concatenamos ahora con lo que viene de la evaluacion de la condicion
        char *res = recuperaResLC((yyvsp[-2].codigo));
        Operacion op2;
        op2.op = "bnez"; //En este caso es negada a como funciona por ejemplo el while puesto que en ensamblador la forma de ejecutar el while es asi
        op2.res = res;
        op2.arg1 = etiquetaRet;
        op2.arg2 = NULL;
        insertaLC((yyval.codigo),finalLC((yyval.codigo)),op2); //Insertamos entonces la instruccion que nos dice si debemos de volver al principio del do while o salirnos de el, la implementacion ha sido sencilla ya que es muy parecido a un while solo que invertido por asi decirlo
        Operacion op3;
        op3.op = labelFin;
        op3.res = ":";
        op3.arg1 = NULL;
        op3.arg2 = NULL;
        insertaLC((yyval.codigo),finalLC((yyval.codigo)),op3);
        liberarRegistro(res);
        liberaLC((yyvsp[-5].codigo));
        liberaLC((yyvsp[-2].codigo));
        pop();
    }
#line 1568 "anasin.tab.c"
    break;

  case 23: /* statement: BREAK SEMICOLON  */
#line 306 "anasin.y"
                     {
        if(tope < 0){
            printf("Error semantico en la linea %d: break fuera de un bucle\n",yylineno);
            error = true;
            (yyval.codigo) = creaLC();
        }else{
            (yyval.codigo) = creaLC();
            Operacion op1;
            op1.op = "b";
            op1.res = top();
            op1.arg1 = NULL;
            op1.arg2 = NULL;
            insertaLC((yyval.codigo),finalLC((yyval.codigo)),op1);
        }
    }
#line 1588 "anasin.tab.c"
    break;

  case 24: /* statement: PRINT LPAREN print_list RPAREN SEMICOLON  */
#line 321 "anasin.y"
                                               {
        (yyval.codigo) = (yyvsp[-2].codigo); //Simplemente lo heredamos
    }
#line 1596 "anasin.tab.c"
    break;

  case 25: /* statement: READ LPAREN read_list RPAREN SEMICOLON  */
#line 324 "anasin.y"
                                            {
        (yyval.codigo) = (yyvsp[-2].codigo);
    }
#line 1604 "anasin.tab.c"
    break;

  case 26: /* statement_list: statement_list statement  */
#line 328 "anasin.y"
                                        {
    concatenaLC((yyvsp[-1].codigo),(yyvsp[0].codigo)); //Concatenamos los codigos
    (yyval.codigo) = (yyvsp[-1].codigo);
    liberaLC((yyvsp[0].codigo));
}
#line 1614 "anasin.tab.c"
    break;

  case 27: /* statement_list: %empty  */
#line 333 "anasin.y"
      {
        (yyval.codigo) = creaLC(); //Creamos lista vacia por recomendacion de la profesora para que no se produzca una violacion de segmento
    }
#line 1622 "anasin.tab.c"
    break;

  case 28: /* print_list: print_item  */
#line 337 "anasin.y"
                      {
    (yyval.codigo) = (yyvsp[0].codigo);
}
#line 1630 "anasin.tab.c"
    break;

  case 29: /* print_list: print_list COMMA print_item  */
#line 340 "anasin.y"
                                 {
        concatenaLC((yyvsp[-2].codigo),(yyvsp[0].codigo)); //Unimos los dos codigos
        (yyval.codigo) = (yyvsp[-2].codigo);
        liberaLC((yyvsp[0].codigo));
    }
#line 1640 "anasin.tab.c"
    break;

  case 30: /* print_item: expresion  */
#line 346 "anasin.y"
                     {
        (yyval.codigo) = (yyvsp[0].codigo);
        char *regdes = recuperaResLC((yyval.codigo));
        Operacion op1;
        op1.op = "move";
        op1.res = "$a0";
        op1.arg1 = regdes;
        op1.arg2 = NULL;
        insertaLC((yyval.codigo),finalLC((yyval.codigo)),op1);
        Operacion op2;
        op2.op = "li";
        op2.res = "$v0";
        op2.arg1 = "1"; //Para imprimir entero
        op2.arg2 = NULL;
        insertaLC((yyval.codigo),finalLC((yyval.codigo)),op2);
        Operacion op3;
        op3.op = "syscall";
        op3.res = NULL;
        op3.arg1 = NULL;
        op3.arg2 = NULL;
        insertaLC((yyval.codigo),finalLC((yyval.codigo)),op3);
        liberarRegistro(regdes);
}
#line 1668 "anasin.tab.c"
    break;

  case 31: /* print_item: STRING  */
#line 369 "anasin.y"
            {
        contCadenas++; //Incrementamos el contador de cadenas por que hemos encontrado un STRING
        (yyval.codigo) = creaLC();
        char * etiquetaStr;
        insertaTablaS((yyvsp[0].lexema), CADENA, contCadenas);  //Insertamos el string en la tabla de simbolos para luego imprimirlo
        asprintf(&etiquetaStr,"$str%d",contCadenas); //Esto es para ponerle a la etiqueta el numero de String por el que vamos para que no todas las etiquetas de str sean iguales

        Operacion op1;
        op1.op = "la";
        op1.res = "$a0";
        op1.arg1 = etiquetaStr;
        op1.arg2 = NULL;
        insertaLC((yyval.codigo),finalLC((yyval.codigo)),op1);
        Operacion op2;
        op2.op = "li";
        op2.res = "$v0";
        op2.arg1 = "4";
        op2.arg2 = NULL;
        insertaLC((yyval.codigo),finalLC((yyval.codigo)),op2);
        Operacion op3;
        op3.op = "syscall";
        op3.res = NULL;
        op3.arg1 = NULL;
        op3.arg2 = NULL;
        insertaLC((yyval.codigo),finalLC((yyval.codigo)),op3);
        /*Basicamentes estamos haciendo
        la $a0,str
        li $v0,4
        syscall
        */
    }
#line 1704 "anasin.tab.c"
    break;

  case 32: /* read_list: ID  */
#line 401 "anasin.y"
              { 
   PosicionLista p = buscaLS(tablaSimb,(yyvsp[0].lexema));
   if(p == finalLS(tablaSimb)){
    printf("Error semantico en la linea %d: La variable '%s' no ha sido declarada en la tabla\n",yylineno,(yyvsp[0].lexema));
    error = true;
    //Modificacion convocatoria de julio, nos faltaba crear una lista vacia de codigo en cambio de error 
    (yyval.codigo) = creaLC();
   }else{
    Simbolo s = recuperaLS(tablaSimb,p);
    if(esConstante(s.tipo)){
        printf("Error semantico en la linea %d: La variable '%s' es una constante y no se puede modificar\n",yylineno,(yyvsp[0].lexema));
        error = true;
        //Modificacion convocatoria de julio, igual que antes
        (yyval.codigo) = creaLC();
    }
    else{
        (yyval.codigo) = creaLC();
        Operacion op1;
        op1.op = "li";
        op1.res = "$v0";
        op1.arg1 = "5";
        op1.arg2 = NULL;
        insertaLC((yyval.codigo),finalLC((yyval.codigo)),op1);
        Operacion op2;
        op2.op = "syscall";
        op2.res = NULL;
        op2.arg1 = NULL;
        op2.arg2 = NULL;
        insertaLC((yyval.codigo),finalLC((yyval.codigo)),op2);
        Operacion op3;
        op3.op = "sw";
        op3.res = "$v0";
        op3.arg1 = (yyvsp[0].lexema);
        op3.arg2 = NULL;
        insertaLC((yyval.codigo),finalLC((yyval.codigo)),op3);
    }
   }
}
#line 1747 "anasin.tab.c"
    break;

  case 33: /* read_list: read_list COMMA ID  */
#line 439 "anasin.y"
                         {
        PosicionLista p = buscaLS(tablaSimb,(yyvsp[0].lexema));
        if(p == finalLS(tablaSimb)){
            printf("Error semantico en la linea %d: La variable '%s' no ha sido declarada en la tabla\n",yylineno,(yyvsp[0].lexema));
            error = true;
            //Cambio convocatoria de julio, esto no es realmente necesario pero si recomendable, en vez de crear una lista de codigo vacia lo que estamos haciendo es heredar el codigo hacia arriba aunque nunca se va a imprimir pues ponemos error = true, pero es una practica mejor de programacion
            (yyval.codigo) = (yyvsp[-2].codigo);
        }else{
            Simbolo s = recuperaLS(tablaSimb,p);
            if(esConstante(s.tipo)){
                printf("Error semantico en la linea %d: La variable '%s' es una constante y no se puede modificar\n",yylineno,(yyvsp[0].lexema));
                error = true;
                (yyval.codigo) = (yyvsp[-2].codigo);
            }
            else{
                (yyval.codigo) = (yyvsp[-2].codigo);
                Operacion op1;
                op1.op = "li";
                op1.res = "$v0";
                op1.arg1 = "5";
                op1.arg2 = NULL;
                insertaLC((yyval.codigo),finalLC((yyval.codigo)),op1);
                Operacion op2;
                op2.op = "syscall";
                op2.res = NULL;
                op2.arg1 = NULL;
                op2.arg2 = NULL;
                insertaLC((yyval.codigo),finalLC((yyval.codigo)),op2);
                Operacion op3;
                op3.op = "sw";
                op3.res = "$v0";
                op3.arg1 = (yyvsp[0].lexema);
                op3.arg2 = NULL;
                insertaLC((yyval.codigo),finalLC((yyval.codigo)),op3);
            }
        }
        /*aqui tambien debemos de comprobnar con la tabla de simbolos*/}
#line 1789 "anasin.tab.c"
    break;

  case 34: /* expresion: expresion MENOR expresion  */
#line 478 "anasin.y"
                             {
        //Para hacer las operaciones relacionales vamos a crear una funcion auxiliar que lo haga ya que el codigo es bastante repetitivo
        (yyval.codigo) = crearRelacional((yyvsp[-2].codigo),(yyvsp[0].codigo),"slt");
    }
#line 1798 "anasin.tab.c"
    break;

  case 35: /* expresion: expresion MAYOR expresion  */
#line 483 "anasin.y"
                             {
        (yyval.codigo) = crearRelacional((yyvsp[-2].codigo),(yyvsp[0].codigo),"sgt");
    }
#line 1806 "anasin.tab.c"
    break;

  case 36: /* expresion: expresion MEQ expresion  */
#line 487 "anasin.y"
                           {
        (yyval.codigo) = crearRelacional((yyvsp[-2].codigo),(yyvsp[0].codigo),"sle");
    }
#line 1814 "anasin.tab.c"
    break;

  case 37: /* expresion: expresion MAQ expresion  */
#line 491 "anasin.y"
                           {
        (yyval.codigo) = crearRelacional((yyvsp[-2].codigo),(yyvsp[0].codigo),"sge");
    }
#line 1822 "anasin.tab.c"
    break;

  case 38: /* expresion: expresion EQQ expresion  */
#line 495 "anasin.y"
                           {
        (yyval.codigo) = crearRelacional((yyvsp[-2].codigo),(yyvsp[0].codigo),"seq");
    }
#line 1830 "anasin.tab.c"
    break;

  case 39: /* expresion: expresion NEQ expresion  */
#line 499 "anasin.y"
                           {
        (yyval.codigo) = crearRelacional((yyvsp[-2].codigo),(yyvsp[0].codigo),"sne");
    }
#line 1838 "anasin.tab.c"
    break;

  case 40: /* expresion: expresion PLUSOP expresion  */
#line 502 "anasin.y"
                               {
        concatenaLC((yyvsp[-2].codigo),(yyvsp[0].codigo));
        (yyval.codigo) = (yyvsp[-2].codigo);
        char *res = obtenerRegistro();
        char *arg1 = recuperaResLC((yyvsp[-2].codigo));
        char *arg2 = recuperaResLC((yyvsp[0].codigo));
        liberaLC((yyvsp[0].codigo));
        Operacion op;
        op.op = "add";
        op.res = res;
        op.arg1 = arg1;
        op.arg2 = arg2;
        insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
        guardaResLC((yyval.codigo),res);
        liberarRegistro(arg1);
        liberarRegistro(arg2);
}
#line 1860 "anasin.tab.c"
    break;

  case 41: /* expresion: expresion MINUSOP expresion  */
#line 519 "anasin.y"
                                 {
        concatenaLC((yyvsp[-2].codigo),(yyvsp[0].codigo));
        (yyval.codigo) = (yyvsp[-2].codigo);
        char *res = obtenerRegistro();
        char *arg1 = recuperaResLC((yyvsp[-2].codigo));
        char *arg2 = recuperaResLC((yyvsp[0].codigo));
        liberaLC((yyvsp[0].codigo));
        Operacion op;
        op.op = "sub";
        op.res = res;
        op.arg1 = arg1;
        op.arg2 = arg2;
        insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
        guardaResLC((yyval.codigo),res);
        liberarRegistro(arg1);
        liberarRegistro(arg2);
    }
#line 1882 "anasin.tab.c"
    break;

  case 42: /* expresion: expresion POR expresion  */
#line 536 "anasin.y"
                             {
        concatenaLC((yyvsp[-2].codigo),(yyvsp[0].codigo));
        (yyval.codigo) = (yyvsp[-2].codigo);
        char *res = obtenerRegistro();
        char *arg1 = recuperaResLC((yyvsp[-2].codigo));
        char *arg2 = recuperaResLC((yyvsp[0].codigo));
        liberaLC((yyvsp[0].codigo));
        Operacion op;
        op.op = "mul";
        op.res = res;
        op.arg1 = arg1;
        op.arg2 = arg2;
        insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
        guardaResLC((yyval.codigo),res);
        liberarRegistro(arg1);
        liberarRegistro(arg2);
    }
#line 1904 "anasin.tab.c"
    break;

  case 43: /* expresion: expresion DIV expresion  */
#line 553 "anasin.y"
                             {
        concatenaLC((yyvsp[-2].codigo),(yyvsp[0].codigo));
        (yyval.codigo) = (yyvsp[-2].codigo);
        char *res = obtenerRegistro();
        char *arg1 = recuperaResLC((yyvsp[-2].codigo));
        char *arg2 = recuperaResLC((yyvsp[0].codigo));
        liberaLC((yyvsp[0].codigo));
        Operacion op;
        op.op = "div";
        op.res = res;
        op.arg1 = arg1;
        op.arg2 = arg2;
        insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
        guardaResLC((yyval.codigo),res);
        liberarRegistro(arg1);
        liberarRegistro(arg2);
    }
#line 1926 "anasin.tab.c"
    break;

  case 44: /* expresion: MINUSOP expresion  */
#line 570 "anasin.y"
                                     {/*Con esto aplicamos antes el simbolo de negativo antes que la resta ya que le hemos dado una altisima prioridad*/ 
        (yyval.codigo) = (yyvsp[0].codigo);
        char *res = obtenerRegistro(); //Obtenemos el registro destino
        char *regArg = recuperaResLC((yyvsp[0].codigo)); //recuperamos el registro destino de la operacion original
        Operacion op; //Ahora tenemos que completar los campos de operacion
        op.op = "neg";
        op.res = res;
        op.arg1 =regArg;
        op.arg2 = NULL;
        insertaLC((yyval.codigo),finalLC((yyval.codigo)),op); //Insertamos en nuestro codigo
        guardaResLC((yyval.codigo),res); //Guardamos el registro destino
        liberarRegistro(regArg); //Liberamos el registro que hemos usado de argumento
    
    }
#line 1945 "anasin.tab.c"
    break;

  case 45: /* expresion: LPAREN expresion RPAREN  */
#line 584 "anasin.y"
                             { 
        (yyval.codigo) = (yyvsp[-1].codigo); //esto es por que la expresion resultado debe de ser la que tenemos en el medio
    }
#line 1953 "anasin.tab.c"
    break;

  case 46: /* expresion: ID  */
#line 587 "anasin.y"
        {
        if(!perteneceTablaS((yyvsp[0].lexema))){
             printf("Error semantico en la linea %d: La variable '%s' no ha sido declarada en la tabla\n",yylineno,(yyvsp[0].lexema));
             error = true;
             (yyval.codigo) = creaLC();
        }else{
            (yyval.codigo) = creaLC(); //Creamos la lista de codigo en caso de que no haya
            char *reg = obtenerRegistro();
            Operacion op = {"lw",reg,(yyvsp[0].lexema),NULL}; //Ahora lo que hacemos es crear el campo operacion 
            insertaLC((yyval.codigo), finalLC((yyval.codigo)),op);
            guardaResLC((yyval.codigo),reg); //Guardamos en nuestra lista de codigo en que registro guardamos el resultado 
        }
        
    }
#line 1972 "anasin.tab.c"
    break;

  case 47: /* expresion: INTLITERAL  */
#line 601 "anasin.y"
                {
        (yyval.codigo) = creaLC();
        char *reg = obtenerRegistro();
        Operacion op = {"li",reg,(yyvsp[0].lexema),NULL}; 
        insertaLC((yyval.codigo),finalLC((yyval.codigo)),op);
        guardaResLC((yyval.codigo),reg);
    }
#line 1984 "anasin.tab.c"
    break;


#line 1988 "anasin.tab.c"

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

#line 609 "anasin.y"

//MODIFICACION CONVOCATORIA DE JULIO
int main(int argc, char *argv[]) {
	
    if (argc != 2) {
		printf("Uso correcto: %s fichero\n",argv[0]);
		exit(1);
	}
	FILE *fich = fopen(argv[1],"r");
	if (fich == 0) {
		printf("No se puede abrir %s\n",argv[1]);
		exit(1);
	}
	yyin = fich;
    tablaSimb = creaLS();
	yyparse();
	fclose(fich);
}

void yyerror (char const *s)
     {
        extern int yylineno; //Esta variable viene de flex y es para saber en que linea hemos obtenido el error 
       fprintf(stderr, "Error sintáctico en la línea %d: %s\n", yylineno, s);
       
     }

void comprMain(char *id){
    if((strcmp(id,"main")) == 0){
        return;
    }
    printf("Ha ocurrido un error el id no corresponde con la palabra main\n");
    //Modificacion convocatoria de julio
    error = true;
}
bool perteneceTablaS(char *id){
  PosicionLista p = buscaLS(tablaSimb,id);
  if (p != finalLS(tablaSimb)) {
    Simbolo aux = recuperaLS(tablaSimb,p);
    return true;
  }
  else {
    return false;
  }
}
void insertaTablaS(char *id,Tipo t,int contador){
    Simbolo s;
    s.nombre = strdup(id);  //aqui reservamos memoria para el nombre del simbolo, esto es para literalmente no copiar el puntero y que sea una copia independiente
    s.tipo = t;
    s.valor = contador; 
  insertaLS(tablaSimb,finalLS(tablaSimb),s); //Ahora simplemente insertamos en nuestra tabla de simbolos

}
bool esConstante(Tipo t){
    return t == CONSTANTE;
}

void ocuparRegistro(int indice){
    registros[indice] = 1; //Ocupamos el registro que nos indiquen
}
char *obtenerRegistro(){
    for(int i=0;i<10;i++){
        if(registros[i] == 0){
            registros[i] = 1;
            char *nombre = malloc(5); //Vamos a hacerlo de esta forma por que el registro que queremos es "$t" + "i" siendo i el que este libre para eso hacemos uso de lo siguiente
            sprintf(nombre,"$t%d",i);//Hacemos uso de esta funcion para que quede grabado en nombre lo que queremos
            return nombre;
        }
    }
    //Cambio convocatoria de julio, debemos de devolver error si al recorrer el bucle nos hemos quedado sin registros para no generar el codigo.
    printf("Se ha producicdo un error, nos hemos quedado sin registros\n");
    error = true;
    char *nombre_falso = malloc(5);
    sprintf(nombre_falso, "$t0");
    return nombre_falso; //esto es por que nos da igual cual devolvemos puesto que NO VAMOS A GENERAR CODIGO EN CASO DE QUE SE PRODUZCA ERROR POR FALTA DE REGISTROS
}
void liberarRegistro(char *nombre){
    if(nombre!=NULL && nombre[0] == '$' && nombre[1] == 't' ){
        int indice = nombre[2] - '0'; //Para convertir el caracter en numero
        if(indice>=0&&indice<10){
            registros[indice] = 0; //Finalmente liberamos el registro
        }
    }
}
char * crearEtiqueta(){
    char *etiqueta;
    asprintf(&etiqueta,"l%d",contEtiquetas++); //El asprintf es como el sprintf pero me esta reservando memoria
    return etiqueta;
}


void imprimirCodigo(ListaC codigoFinal){
    //Primero imprimimos la cabecera tal cual como se debe de mostrar en ensamblador
    printf(".data\n");
    PosicionLista p = inicioLS(tablaSimb);
    while(p != finalLS(tablaSimb)){
        Simbolo s = recuperaLS(tablaSimb,p);
        if(s.tipo == CADENA){
            printf("$str%d: .asciiz %s\n", s.valor, s.nombre); //Si es una cadena imprimimos primeramente la etiqueta str y luego el .asciiz seguido del valor del String
        }
        else if(s.tipo == VARIABLE || s.tipo == CONSTANTE){
            printf("_%s: .word 0\n",s.nombre); //Ponemos este valor para constantes
        }
        p = siguienteLS(tablaSimb,p);
    }
    printf(".text\n");
    printf(".globl main\n");
    printf("main:\n");

   PosicionListaC pc = inicioLC(codigoFinal);
    while (pc != finalLC(codigoFinal)) {
        Operacion op = recuperaLC(codigoFinal, pc);

    
        if (op.res != NULL && strcmp(op.res, ":") == 0) { //SI es una etiqueta lo imprimimos asi
            printf("%s:\n", op.op);
        }
        // Caso en el que los argumentos son: add, sub, mul, div 
        else if (op.arg2 != NULL) {
            printf("\t%s %s, %s, %s\n", op.op, op.res, op.arg1, op.arg2);
        }
        // Caso en el que los argumentos son: li, lw, sw, move, la, beqz 
        else if (op.arg1 != NULL) {
            if ((strcmp(op.op, "lw") == 0 || strcmp(op.op, "sw") == 0) && op.arg1[0] != '$') {
                printf("\t%s %s, _%s\n", op.op, op.res, op.arg1);
            } else {
                printf("\t%s %s, %s\n", op.op, op.res, op.arg1);
            }
        }
        // Caso en el que tengamos que hacer un syscall
        else {
            if (op.res != NULL) printf("\t%s %s\n", op.op, op.res);
            else printf("\t%s\n", op.op);
        }
        pc = siguienteLC(codigoFinal, pc);
    }

    //Este codigo es obligatorio imprimirlo al final de nuestro programa
    printf("\tli $v0, 10\n\tsyscall\n");
}

ListaC crearRelacional(ListaC izq,ListaC der, char* OpRelacional){
    
    concatenaLC(izq,der);
    char *res = obtenerRegistro(); //Aqui vamos a guardar la solucion de lo que obtengamos de la operacion relacional
    char *arg1 = recuperaResLC(izq);
    char *arg2 = recuperaResLC(der);
    Operacion op1;
    op1.op = OpRelacional;
    op1.res = res;
    op1.arg1 = arg1;
    op1.arg2 = arg2;
    insertaLC(izq,finalLC(izq),op1);
    guardaResLC(izq,res);
    liberarRegistro(arg1);
    liberarRegistro(arg2);
    liberaLC(der);
    return izq;
}

void push(char *etiqueta){
    pilaSalidas[++tope] = etiqueta; //Almacenamos la etiqueta en el tope de la pila
    //Vale asi como idea generar ahora en los bucles tendremos la etiqueta de siempre del bucle y la etiqueta de salida que es para identificar por asi decirlo el bucle mas cercano en el que estamos
}
void pop(){
    if(tope>=0){
        tope--; //Reducimos el tope de la pila 
    }
}
char *top(){
    if(tope>=0){
        return pilaSalidas[tope]; //Devolvemos la ultima etiqueta introducida en la pila
    }
    return NULL; //En caso de que no se cumpla el if pues devolvemos nulo
}
