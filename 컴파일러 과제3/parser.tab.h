/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
#define YYTOKENTYPE
/* Put the tokens into the symbol table, so that GDB and other debuggers
   know about them.  */
enum yytokentype
{
   TEOF = 258,
   TERROR = 259,
   TCOMMENT = 260,
   TIDENT = 261,
   TNUMBER = 262,
   TFNUMBER = 263,
   TCONST = 264,
   TELSE = 265,
   TIF = 266,
   TINT = 267,
   TFLOAT = 268,
   TRETURN = 269,
   TVOID = 270,
   TWHILE = 271,
   TADD = 272,
   TSUB = 273,
   TMUL = 274,
   TDIV = 275,
   TMOD = 276,
   TASSIGN = 277,
   TADDASSIGN = 278,
   TSUBASSIGN = 279,
   TMULASSIGN = 280,
   TDIVASSIGN = 281,
   TMODASSIGN = 282,
   TNOT = 283,
   TAND = 284,
   TOR = 285,
   TEQUAL = 286,
   TNOTEQU = 287,
   TLESS = 288,
   TLESSE = 289,
   TGREAT = 290,
   TGREATE = 291,
   TINC = 292,
   TDEC = 293,
   TLPAREN = 294,
   TRPAREN = 295,
   TRBRACE = 296,
   TLBRACKET = 297,
   TRBRACKET = 298,
   TSEMI = 299,
   TCOMMA = 300,
   TLBRACE = 301,
   LOWER_THAN_ELSE = 302
};
#endif
/* Tokens.  */
#define TEOF 258
#define TERROR 259
#define TCOMMENT 260
#define TIDENT 261
#define TNUMBER 262
#define TFNUMBER 263
#define TCONST 264
#define TELSE 265
#define TIF 266
#define TINT 267
#define TFLOAT 268
#define TRETURN 269
#define TVOID 270
#define TWHILE 271
#define TADD 272
#define TSUB 273
#define TMUL 274
#define TDIV 275
#define TMOD 276
#define TASSIGN 277
#define TADDASSIGN 278
#define TSUBASSIGN 279
#define TMULASSIGN 280
#define TDIVASSIGN 281
#define TMODASSIGN 282
#define TNOT 283
#define TAND 284
#define TOR 285
#define TEQUAL 286
#define TNOTEQU 287
#define TLESS 288
#define TLESSE 289
#define TGREAT 290
#define TGREATE 291
#define TINC 292
#define TDEC 293
#define TLPAREN 294
#define TRPAREN 295
#define TRBRACE 296
#define TLBRACKET 297
#define TRBRACKET 298
#define TSEMI 299
#define TCOMMA 300
#define TLBRACE 301
#define LOWER_THAN_ELSE 302

#if !defined YYSTYPE && !defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
#define yystype YYSTYPE /* obsolescent; will be withdrawn */
#define YYSTYPE_IS_DECLARED 1
#define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;
