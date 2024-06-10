
/*  A Bison parser, made from parser.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	TEOF	258
#define	TERROR	259
#define	TCOMMENT	260
#define	TCONST	261
#define	TELSE	262
#define	TIF	263
#define	TINT	264
#define	TFLOAT	265
#define	TRETURN	266
#define	TVOID	267
#define	TWHILE	268
#define	TADD	269
#define	TSUB	270
#define	TMUL	271
#define	TDIV	272
#define	TMOD	273
#define	TASSIGN	274
#define	TADDASSIGN	275
#define	TSUBASSIGN	276
#define	TMULASSIGN	277
#define	TDIVASSIGN	278
#define	TMODASSIGN	279
#define	TNOT	280
#define	TAND	281
#define	TOR	282
#define	TEQUAL	283
#define	TNOTEQU	284
#define	TLESS	285
#define	TLESSE	286
#define	TGREAT	287
#define	TGREATE	288
#define	TINC	289
#define	TDEC	290
#define	TLPAREN	291
#define	TRPAREN	292
#define	TRBRACE	293
#define	TLBRACKET	294
#define	TRBRACKET	295
#define	TSEMI	296
#define	TCOMMA	297
#define	TLBRACE	298
#define	LOWER_THAN_ELSE	299
#define	TIDENT	300
#define	TNUMBER	301
#define	TFNUMBER	302

#line 1 "parser.y"

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "lex.yy.c"			/* #include "lex.yy.c" */
#include "sym_table_lab.h"

/*yacc source for Mini C */
void semantic(int);
void reportError(char *); 
void yyerror(char *); // bison 자체에서 error 를 만나면 호출

char * current_func ; // 현재 실행 중인 함수 이름
int total_err_cnt = 0 ;
Type current_type = NONE_TYPE; // 현재 활성화된 선언 타입





#line 29 "parser.y"

#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		186
#define	YYFLAG		-32768
#define	YYNTBASE	50

#define YYTRANSLATE(x) ((unsigned)(x) <= 302 ? yytranslate[x] : 99)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    49,
     2,    48,     2,     2,     2,     2,     2,     2,     2,     2,
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
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     7,     9,    11,    14,    18,    20,    22,
    25,    27,    29,    31,    33,    35,    37,    39,    43,    47,
    49,    50,    52,    56,    59,    64,    69,    74,    76,    77,
    79,    82,    86,    90,    92,    94,    96,   101,   106,   108,
   112,   114,   118,   120,   124,   128,   130,   135,   137,   138,
   140,   141,   143,   146,   148,   150,   152,   154,   156,   159,
   162,   164,   165,   171,   179,   185,   191,   197,   201,   205,
   207,   209,   213,   217,   221,   225,   229,   233,   238,   240,
   244,   246,   250,   252,   256,   260,   262,   266,   270,   274,
   278,   280,   284,   288,   290,   294,   298,   302,   304,   307,
   310,   313,   316,   318,   323,   328,   331,   334,   336,   337,
   339,   341,   345,   347,   349,   351
};

static const short yyrhs[] = {    51,
     0,    52,     0,    51,    52,     0,    53,     0,    69,     0,
    54,    66,     0,    55,    60,    62,     0,    56,     0,    57,
     0,    56,    57,     0,    58,     0,    59,     0,     6,     0,
     9,     0,    10,     0,    12,     0,    45,     0,    36,    72,
    37,     0,    36,    63,    37,     0,    64,     0,     0,    65,
     0,    64,    42,    65,     0,    55,    75,     0,    43,    67,
    77,    38,     0,     1,    67,    77,    38,     0,    43,    67,
    77,     1,     0,    68,     0,     0,    69,     0,    68,    69,
     0,    55,    73,    41,     0,    55,    73,     1,     0,    71,
     0,    61,     0,    62,     0,    55,    60,    70,    41,     0,
    55,    60,    70,     1,     0,    55,     0,    72,    42,    55,
     0,    74,     0,    73,    42,    74,     0,    75,     0,    75,
    19,    46,     0,    75,    19,    47,     0,    45,     0,    45,
    39,    76,    40,     0,    46,     0,     0,    78,     0,     0,
    79,     0,    78,    79,     0,    66,     0,    80,     0,    82,
     0,    83,     0,    84,     0,    81,    41,     0,    81,     1,
     0,    85,     0,     0,     8,    36,    85,    37,    79,     0,
     8,    36,    85,    37,    79,     7,    79,     0,    13,    36,
    85,    37,    79,     0,    13,    36,    85,     1,    79,     0,
    13,     1,    85,    37,    79,     0,    11,    81,    41,     0,
    11,    81,     1,     0,    86,     0,    87,     0,    93,    19,
    86,     0,    93,    20,    86,     0,    93,    21,    86,     0,
    93,    22,    86,     0,    93,    23,    86,     0,    93,    24,
    86,     0,    92,    19,    86,    41,     0,    88,     0,    87,
    27,    88,     0,    89,     0,    88,    26,    89,     0,    90,
     0,    89,    28,    90,     0,    89,    29,    90,     0,    91,
     0,    90,    48,    91,     0,    90,    49,    91,     0,    90,
    33,    91,     0,    90,    31,    91,     0,    92,     0,    91,
    14,    92,     0,    91,    15,    92,     0,    93,     0,    92,
    16,    93,     0,    92,    17,    93,     0,    92,    18,    93,
     0,    94,     0,    15,    93,     0,    25,    93,     0,    34,
    93,     0,    35,    93,     0,    98,     0,    94,    39,    85,
    40,     0,    94,    36,    95,    37,     0,    94,    34,     0,
    94,    35,     0,    96,     0,     0,    97,     0,    86,     0,
    97,    42,    86,     0,    45,     0,    46,     0,    47,     0,
    36,    85,    37,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
    90,    91,    92,    93,    94,    95,    96,    98,    99,   101,
   102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
   112,   114,   115,   116,   117,   117,   118,   119,   120,   121,
   122,   123,   124,   125,   127,   130,   133,   144,   145,   151,
   152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
   163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
   173,   174,   175,   176,   177,   178,   179,   180,   182,   183,
   184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
   194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
   204,   205,   206,   207,   208,   213,   214,   215,   216,   217,
   218,   220,   221,   230,   231,   232
};

static const char * const yytname[] = {   "$","error","$undefined.","TEOF","TERROR",
"TCOMMENT","TCONST","TELSE","TIF","TINT","TFLOAT","TRETURN","TVOID","TWHILE",
"TADD","TSUB","TMUL","TDIV","TMOD","TASSIGN","TADDASSIGN","TSUBASSIGN","TMULASSIGN",
"TDIVASSIGN","TMODASSIGN","TNOT","TAND","TOR","TEQUAL","TNOTEQU","TLESS","TLESSE",
"TGREAT","TGREATE","TINC","TDEC","TLPAREN","TRPAREN","TRBRACE","TLBRACKET","TRBRACKET",
"TSEMI","TCOMMA","TLBRACE","LOWER_THAN_ELSE","TIDENT","TNUMBER","TFNUMBER","'>'",
"'<'","mini_c","translation_unit","external_dcl","function_def","function_header",
"dcl_spec","dcl_specifiers","dcl_specifier","type_qualifier","type_specifier",
"function_name","abbreviated_param","formal_param","opt_formal_param","formal_param_list",
"param_dcl","compound_st","opt_dcl_list","declaration_list","declaration","declaration_param",
"function_declaration","dcl_spec_list","init_dcl_list","init_declarator","declarator",
"opt_number","opt_stat_list","statement_list","statement","expression_st","opt_expression",
"if_st","while_st","return_st","expression","assignment_exp","logical_or_exp",
"logical_and_exp","equality_exp","relational_exp","additive_exp","multiplicative_exp",
"unary_exp","postfix_exp","opt_actual_param","actual_param","actual_param_list",
"primary_exp",""
};
#endif

static const short yyr1[] = {     0,
    50,    51,    51,    52,    52,    53,    54,    55,    56,    56,
    57,    57,    58,    59,    59,    59,    60,    61,    62,    63,
    63,    64,    64,    65,    66,    66,    66,    67,    67,    68,
    68,    69,    69,    69,    70,    70,    71,    71,    72,    72,
    73,    73,    74,    74,    74,    75,    75,    76,    76,    77,
    77,    78,    78,    79,    79,    79,    79,    79,    80,    80,
    81,    81,    82,    82,    83,    83,    83,    84,    84,    85,
    86,    86,    86,    86,    86,    86,    86,    86,    87,    87,
    88,    88,    89,    89,    89,    90,    90,    90,    90,    90,
    91,    91,    91,    92,    92,    92,    92,    93,    93,    93,
    93,    93,    94,    94,    94,    94,    94,    95,    95,    96,
    97,    97,    98,    98,    98,    98
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     1,     2,     3,     1,     1,     2,
     1,     1,     1,     1,     1,     1,     1,     3,     3,     1,
     0,     1,     3,     2,     4,     4,     4,     1,     0,     1,
     2,     3,     3,     1,     1,     1,     4,     4,     1,     3,
     1,     3,     1,     3,     3,     1,     4,     1,     0,     1,
     0,     1,     2,     1,     1,     1,     1,     1,     2,     2,
     1,     0,     5,     7,     5,     5,     5,     3,     3,     1,
     1,     3,     3,     3,     3,     3,     3,     4,     1,     3,
     1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
     1,     3,     3,     1,     3,     3,     3,     1,     2,     2,
     2,     2,     1,     4,     4,     2,     2,     1,     0,     1,
     1,     3,     1,     1,     1,     3
};

static const short yydefact[] = {     0,
    13,    14,    15,    16,     1,     2,     4,     0,     0,     8,
     9,    11,    12,     5,    34,     3,    29,    29,     6,    46,
     0,     0,    41,    43,    10,     0,     0,    28,    30,     0,
    49,    21,    35,     7,     0,    33,    32,     0,     0,     0,
     0,    62,     0,     0,     0,     0,     0,     0,   113,   114,
   115,    54,     0,     0,    52,    55,     0,    56,    57,    58,
    61,    70,    71,    79,    81,    83,    86,    91,    94,    98,
   103,    31,     0,    48,     0,    39,     0,    20,    22,     0,
    38,    37,    46,    42,    44,    45,    36,     0,     0,     0,
     0,    99,   100,   101,   102,     0,    26,    53,    60,    59,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   106,   107,   109,     0,    27,    25,    47,    24,    19,     0,
    18,     0,     0,    69,    68,     0,     0,   116,    80,    91,
    94,    82,    84,    85,    90,    89,    87,    88,    92,    93,
    95,    96,    97,     0,    72,    73,    74,    75,    76,    77,
   111,     0,   108,   110,     0,     0,    23,    40,     0,     0,
     0,     0,    78,   105,     0,   104,    63,    67,    66,    65,
   112,     0,    64,     0,     0,     0
};

static const short yydefgoto[] = {   184,
     5,     6,     7,     8,    26,    10,    11,    12,    13,    21,
    33,    34,    77,    78,    79,    52,    27,    28,    14,    35,
    15,    80,    22,    23,    24,    75,    53,    54,    55,    56,
    57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
    67,    68,    69,    70,   162,   163,   164,    71
};

static const short yypact[] = {    25,
-32768,-32768,-32768,-32768,    25,-32768,-32768,     9,   -18,    25,
-32768,-32768,-32768,-32768,-32768,-32768,    25,    25,-32768,    63,
    61,    12,-32768,    20,-32768,   -18,    90,    25,-32768,    90,
    -5,    25,-32768,    16,     3,-32768,-32768,    59,    31,    61,
    72,    75,    22,    75,    75,    75,    75,    75,-32768,-32768,
-32768,-32768,    76,   133,-32768,-32768,    10,-32768,-32768,-32768,
-32768,-32768,    96,   101,    78,     7,    98,    77,   131,    -6,
-32768,-32768,    11,-32768,   100,    59,   105,     6,-32768,     5,
-32768,-32768,   104,-32768,-32768,-32768,-32768,    75,    21,    75,
    75,-32768,-32768,-32768,-32768,   108,-32768,-32768,-32768,-32768,
    75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
    75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
-32768,-32768,    75,    75,-32768,-32768,-32768,-32768,-32768,    25,
-32768,    25,   110,-32768,-32768,   120,    13,-32768,   101,    43,
-32768,    78,     7,     7,    98,    98,    98,    98,    43,    43,
-32768,-32768,-32768,   119,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,   125,-32768,   122,   126,    59,-32768,-32768,   148,   148,
   148,   148,-32768,-32768,    75,-32768,   158,-32768,-32768,-32768,
-32768,   148,-32768,   170,   172,-32768
};

static const short yypgoto[] = {-32768,
-32768,   176,-32768,-32768,     0,-32768,   165,-32768,-32768,   151,
-32768,   150,-32768,-32768,    62,   188,   179,-32768,     8,-32768,
-32768,-32768,-32768,   160,   -74,-32768,   169,-32768,   -53,-32768,
   159,-32768,-32768,-32768,   -45,   -99,-32768,    99,   102,    35,
    80,   -21,   -38,-32768,-32768,-32768,-32768,-32768
};


#define	YYLAST		204


static const short yytable[] = {     9,
    98,   128,    96,    81,     9,    92,    93,    94,    95,    17,
    99,   125,    36,   171,   154,   155,   156,   157,   158,   159,
   160,   134,    90,   161,    29,    29,    20,   121,   122,   123,
     1,    76,   124,     2,     3,    72,     4,   105,    39,   106,
    74,   131,   133,    82,   136,   137,   132,   130,   126,   172,
   100,    18,    37,    38,   107,   108,   -36,    91,   111,   112,
   113,   135,   141,   141,   141,   141,   141,   141,   141,   141,
   141,   141,   151,   152,   153,   181,    85,    86,   165,   140,
   140,   140,   140,   140,   140,   140,   140,   149,   150,    44,
    17,   128,   111,   112,   113,   114,    32,    41,   -17,    45,
    42,    31,    43,    83,    44,   103,   104,    88,    46,    47,
    48,   109,   110,    97,    45,   177,   178,   179,   180,    49,
    50,    51,   101,    46,    47,    48,   102,   -51,   183,   166,
   -62,   168,    18,    17,    49,    50,    51,   143,   144,   127,
    41,   129,    31,    42,   138,    43,   169,    44,    17,   115,
   116,   117,   118,   119,   120,    41,   170,    45,    42,   173,
    43,   174,    44,   175,   182,   176,    46,    47,    48,   185,
   -50,   186,    45,   -62,    25,    18,    40,    49,    50,    51,
    16,    46,    47,    48,   145,   146,   147,   148,   -62,    87,
    18,   167,    49,    50,    51,    19,    30,    84,    73,   139,
    89,     0,     0,   142
};

static const short yycheck[] = {     0,
    54,    76,    48,     1,     5,    44,    45,    46,    47,     1,
     1,     1,     1,     1,   114,   115,   116,   117,   118,   119,
   120,     1,     1,   123,    17,    18,    45,    34,    35,    36,
     6,    32,    39,     9,    10,    28,    12,    31,    19,    33,
    46,    37,    88,    41,    90,    91,    42,    42,    38,    37,
    41,    43,    41,    42,    48,    49,    41,    36,    16,    17,
    18,    41,   101,   102,   103,   104,   105,   106,   107,   108,
   109,   110,   111,   112,   113,   175,    46,    47,   124,   101,
   102,   103,   104,   105,   106,   107,   108,   109,   110,    15,
     1,   166,    16,    17,    18,    19,    36,     8,    36,    25,
    11,    39,    13,    45,    15,    28,    29,    36,    34,    35,
    36,    14,    15,    38,    25,   169,   170,   171,   172,    45,
    46,    47,    27,    34,    35,    36,    26,    38,   182,   130,
    41,   132,    43,     1,    45,    46,    47,   103,   104,    40,
     8,    37,    39,    11,    37,    13,    37,    15,     1,    19,
    20,    21,    22,    23,    24,     8,    37,    25,    11,    41,
    13,    37,    15,    42,     7,    40,    34,    35,    36,     0,
    38,     0,    25,    41,    10,    43,    26,    45,    46,    47,
     5,    34,    35,    36,   105,   106,   107,   108,    41,    40,
    43,   130,    45,    46,    47,     8,    18,    38,    30,   101,
    42,    -1,    -1,   102
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

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
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 80 "parser.y"
{;
    break;}
case 2:
#line 81 "parser.y"
{;
    break;}
case 3:
#line 82 "parser.y"
{;
    break;}
case 4:
#line 83 "parser.y"
{;
    break;}
case 5:
#line 84 "parser.y"
{;
    break;}
case 6:
#line 85 "parser.y"
{;
    break;}
case 7:
#line 86 "parser.y"
{ current_func = NULL; ;
    break;}
case 8:
#line 87 "parser.y"
{;
    break;}
case 9:
#line 88 "parser.y"
{;
    break;}
case 10:
#line 89 "parser.y"
{;
    break;}
case 11:
#line 90 "parser.y"
{;
    break;}
case 12:
#line 91 "parser.y"
{;
    break;}
case 13:
#line 92 "parser.y"
{;
    break;}
case 14:
#line 93 "parser.y"
{ current_type = INT_TYPE; ;
    break;}
case 15:
#line 94 "parser.y"
{ current_type = FLOAT_TYPE; ;
    break;}
case 16:
#line 95 "parser.y"
{ current_type = VOID_TYPE; ;
    break;}
case 17:
#line 96 "parser.y"
{ current_func = yyvsp[0].sval; update_symbol_kind(yyvsp[0].sval, FUNC); update_symbol_type(yyvsp[0].sval,current_type); ;
    break;}
case 18:
#line 98 "parser.y"
{ printf("abbreviated_param\n"); ;
    break;}
case 19:
#line 99 "parser.y"
{;
    break;}
case 20:
#line 101 "parser.y"
{;
    break;}
case 21:
#line 102 "parser.y"
{;
    break;}
case 22:
#line 103 "parser.y"
{;
    break;}
case 23:
#line 104 "parser.y"
{;
    break;}
case 24:
#line 105 "parser.y"
{ update_symbol_type(yyvsp[0].sval,current_type); update_function_param(current_func,current_type); update_symbol_kind(yyvsp[0].sval,PARAM); ;
    break;}
case 25:
#line 106 "parser.y"
{ ;
    break;}
case 26:
#line 107 "parser.y"
{ yyerrok; reportError("Missing left brace"); ;
    break;}
case 27:
#line 108 "parser.y"
{ yyerrok; reportError("Missing right brace ");;
    break;}
case 28:
#line 109 "parser.y"
{;
    break;}
case 29:
#line 110 "parser.y"
{;
    break;}
case 30:
#line 111 "parser.y"
{;
    break;}
case 31:
#line 112 "parser.y"
{;
    break;}
case 32:
#line 114 "parser.y"
{ current_type = NONE_TYPE; ;
    break;}
case 33:
#line 115 "parser.y"
{  yyerrok; reportError("Missing semicolon");  current_type = NONE_TYPE; ;
    break;}
case 34:
#line 116 "parser.y"
{;
    break;}
case 36:
#line 117 "parser.y"
{;
    break;}
case 37:
#line 118 "parser.y"
{  ;
    break;}
case 38:
#line 119 "parser.y"
{ yyerrok;  reportError("Missing semicolon");  ;
    break;}
case 39:
#line 120 "parser.y"
{ update_function_param(current_func,current_type); ;
    break;}
case 40:
#line 121 "parser.y"
{ update_function_param(current_func,current_type); ;
    break;}
case 41:
#line 122 "parser.y"
{;
    break;}
case 42:
#line 123 "parser.y"
{;
    break;}
case 43:
#line 124 "parser.y"
{ update_symbol_type(yyvsp[0].sval, current_type); ;
    break;}
case 44:
#line 125 "parser.y"
{ if(current_type != INT_TYPE){ reportError("Type Mismatched. Expected int but float."); }
																			else{ update_symbol_type(yyvsp[-2].sval, current_type); } ;
    break;}
case 45:
#line 127 "parser.y"
{ if(current_type != FLOAT_TYPE){ reportError("Type Mismatched. Expected float but int."); } 
																			else{ update_symbol_type(yyvsp[-2].sval, current_type); } ;
    break;}
case 46:
#line 130 "parser.y"
{ yyval.sval = yyvsp[0].sval; if(is_declared(yyvsp[0].sval)){ char error_message[256]; 
																				sprintf(error_message, "Aleardy declared identifier %s", yyvsp[0].sval);
																				reportError(error_message); } else { update_symbol_kind(yyvsp[0].sval,SCALAR); } ;
    break;}
case 47:
#line 133 "parser.y"
{
																			if (yyvsp[-1].ival < 0) {
																				reportError("Error: Array size cannot be negative.");
																			} else {
																				yyval.sval = yyvsp[-3].sval;
																				update_symbol_kind(yyvsp[-3].sval, ARRAY);
																			
																			}
																		;
    break;}
case 48:
#line 144 "parser.y"
{ if (yyvsp[0].ival < 0) { reportError("Error: Array size cannot be negative."); yyval.ival = 0; } else { yyval.ival = yyvsp[0].ival; };
    break;}
case 49:
#line 145 "parser.y"
{ 
									yyval.ival = 0; // 배열 크기 정해지지 않았을 경우 디폴트 크기 0으로 설정
								
								;
    break;}
case 50:
#line 151 "parser.y"
{;
    break;}
case 51:
#line 152 "parser.y"
{;
    break;}
case 52:
#line 153 "parser.y"
{;
    break;}
case 53:
#line 154 "parser.y"
{;
    break;}
case 54:
#line 155 "parser.y"
{;
    break;}
case 55:
#line 156 "parser.y"
{;
    break;}
case 56:
#line 157 "parser.y"
{;
    break;}
case 57:
#line 158 "parser.y"
{;
    break;}
case 58:
#line 159 "parser.y"
{;
    break;}
case 59:
#line 160 "parser.y"
{;
    break;}
case 60:
#line 161 "parser.y"
{  yyerrok; reportError("Missing semicolon");  ;
    break;}
case 61:
#line 163 "parser.y"
{;
    break;}
case 62:
#line 164 "parser.y"
{;
    break;}
case 63:
#line 165 "parser.y"
{;
    break;}
case 64:
#line 166 "parser.y"
{;
    break;}
case 65:
#line 167 "parser.y"
{;
    break;}
case 66:
#line 168 "parser.y"
{ yyerrok; reportError("Missing right paren"); ;
    break;}
case 67:
#line 169 "parser.y"
{ yyerrok; reportError("Missing left paren"); ;
    break;}
case 68:
#line 170 "parser.y"
{;
    break;}
case 69:
#line 171 "parser.y"
{  yyerrok; reportError("Missing semicolon");  ;
    break;}
case 70:
#line 172 "parser.y"
{;
    break;}
case 71:
#line 173 "parser.y"
{ yyval.type = yyvsp[0].type; ;
    break;}
case 72:
#line 174 "parser.y"
{;
    break;}
case 73:
#line 175 "parser.y"
{;
    break;}
case 74:
#line 176 "parser.y"
{;
    break;}
case 75:
#line 177 "parser.y"
{;
    break;}
case 76:
#line 178 "parser.y"
{;
    break;}
case 77:
#line 179 "parser.y"
{;
    break;}
case 78:
#line 180 "parser.y"
{ reportError("Invalid assignment expression"); ;
    break;}
case 79:
#line 182 "parser.y"
{ yyval.type = yyvsp[0].type; ;
    break;}
case 80:
#line 183 "parser.y"
{;
    break;}
case 81:
#line 184 "parser.y"
{ yyval.type = yyvsp[0].type; ;
    break;}
case 82:
#line 185 "parser.y"
{;
    break;}
case 83:
#line 186 "parser.y"
{ yyval.type = yyvsp[0].type; ;
    break;}
case 84:
#line 187 "parser.y"
{;
    break;}
case 85:
#line 188 "parser.y"
{;
    break;}
case 86:
#line 189 "parser.y"
{ yyval.type = yyvsp[0].type; ;
    break;}
case 87:
#line 190 "parser.y"
{;
    break;}
case 88:
#line 191 "parser.y"
{;
    break;}
case 89:
#line 192 "parser.y"
{;
    break;}
case 90:
#line 193 "parser.y"
{;
    break;}
case 91:
#line 194 "parser.y"
{ yyval.type = yyvsp[0].type; ;
    break;}
case 92:
#line 195 "parser.y"
{;
    break;}
case 93:
#line 196 "parser.y"
{;
    break;}
case 94:
#line 197 "parser.y"
{ yyval.type = yyvsp[0].type; ;
    break;}
case 95:
#line 198 "parser.y"
{;
    break;}
case 96:
#line 199 "parser.y"
{;
    break;}
case 97:
#line 200 "parser.y"
{;
    break;}
case 98:
#line 201 "parser.y"
{ yyval.type = yyvsp[0].type; ;
    break;}
case 99:
#line 202 "parser.y"
{;
    break;}
case 100:
#line 203 "parser.y"
{;
    break;}
case 101:
#line 204 "parser.y"
{;
    break;}
case 102:
#line 205 "parser.y"
{;
    break;}
case 103:
#line 206 "parser.y"
{ yyval.type = yyvsp[0].type; ;
    break;}
case 104:
#line 207 "parser.y"
{;
    break;}
case 105:
#line 208 "parser.y"
{ if(!is_func(current_func)){ reportError("Attempt to call a non-function"); } 
																								else if(!check_param_match(current_func,yyvsp[-1].params))
																								{
																									reportError("Parameter not match");
																								} ;
    break;}
case 106:
#line 213 "parser.y"
{;
    break;}
case 107:
#line 214 "parser.y"
{;
    break;}
case 108:
#line 215 "parser.y"
{ yyval.params = yyvsp[0].params; ;
    break;}
case 109:
#line 216 "parser.y"
{ yyval.params = NULL; ;
    break;}
case 110:
#line 217 "parser.y"
{ yyval.params = yyvsp[0].params; ;
    break;}
case 111:
#line 218 "parser.y"
{ Params* new_params = malloc(sizeof(Params));
																			new_params->types[0] = yyvsp[0].type; new_params->param_cnt++; yyval.params = new_params; ;
    break;}
case 112:
#line 220 "parser.y"
{ yyvsp[-2].params->types[yyvsp[-2].params->param_cnt++] = yyvsp[0].type; yyval.params = yyvsp[-2].params; ;
    break;}
case 113:
#line 221 "parser.y"
{ yyval.type = get_symbol_type(yyvsp[0].sval); if(!is_declared(yyvsp[0].sval)){
																				char error_message[256]; 
																				sprintf(error_message, "Undeclared identifier %s", yyvsp[0].sval);
																				reportError(error_message);
																							} 

																				if(is_func(yyvsp[0].sval)){
																					current_func = yyvsp[0].sval; 
																				};
    break;}
case 114:
#line 230 "parser.y"
{ yyval.type = INT_TYPE; ;
    break;}
case 115:
#line 231 "parser.y"
{ yyval.type = FLOAT_TYPE; ;
    break;}
case 116:
#line 232 "parser.y"
{;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 233 "parser.y"


void reportError(char *s)
{
   printf("Error at line %d: %s\n", lineNumber, s);
    total_err_cnt++; 
}

void yyerror(char *s)
{
   printf("Error at line %d: %s\n", lineNumber, s);
   // total_err_cnt++; 
}

void semantic(int n)
{
	printf("reduced rule number = %d\n", n);
}


