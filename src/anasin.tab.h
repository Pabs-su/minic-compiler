/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_ANASIN_TAB_H_INCLUDED
# define YY_YY_ANASIN_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 40 "anasin.y"

    #include "listaCodigo.h"

#line 53 "anasin.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    STRING = 258,                  /* STRING  */
    ID = 259,                      /* ID  */
    INTLITERAL = 260,              /* INTLITERAL  */
    VOID = 261,                    /* VOID  */
    VAR = 262,                     /* VAR  */
    CONST = 263,                   /* CONST  */
    IF = 264,                      /* IF  */
    ELSE = 265,                    /* ELSE  */
    WHILE = 266,                   /* WHILE  */
    PRINT = 267,                   /* PRINT  */
    READ = 268,                    /* READ  */
    LPAREN = 269,                  /* LPAREN  */
    RPAREN = 270,                  /* RPAREN  */
    SEMICOLON = 271,               /* SEMICOLON  */
    PLUSOP = 272,                  /* PLUSOP  */
    MINUSOP = 273,                 /* MINUSOP  */
    COMMA = 274,                   /* COMMA  */
    ASSIGNOP = 275,                /* ASSIGNOP  */
    BARRA = 276,                   /* BARRA  */
    LCORCH = 277,                  /* LCORCH  */
    RCORCH = 278,                  /* RCORCH  */
    POR = 279,                     /* POR  */
    DIV = 280,                     /* DIV  */
    INT = 281,                     /* INT  */
    DO = 282,                      /* DO  */
    BREAK = 283,                   /* BREAK  */
    MENOR = 284,                   /* MENOR  */
    MAYOR = 285,                   /* MAYOR  */
    MEQ = 286,                     /* MEQ  */
    MAQ = 287,                     /* MAQ  */
    EQQ = 288,                     /* EQQ  */
    NEQ = 289,                     /* NEQ  */
    UMINUS = 290,                  /* UMINUS  */
    ABAJO_DEL_ELSE = 291           /* ABAJO_DEL_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 43 "anasin.y"

    char *lexema;
    ListaC codigo;

#line 111 "anasin.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_ANASIN_TAB_H_INCLUDED  */
