/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Tokens.  */
#ifndef YYTOKENTYPE
#define YYTOKENTYPE
/* Put the tokens into the symbol table, so that GDB and other debuggers
   know about them.  */

/*tn.h 에 있던 토큰 내용으로 수정 -> 충돌방지*/
enum yytokentype
{
  TEOF,
  TERROR,
  TCOMMENT,
  TNUMBER,
  TFNUMBER,
  TIDENT,
  TCONST,
  TELSE,
  TIF,
  TINT,
  TFLOAT,
  TRETURN,
  TVOID,
  TWHILE,
  TADD,
  TSUB,
  TMUL,
  TDIV,
  TMOD,
  TASSIGN,
  TADDASSIGN,
  TSUBASSIGN,
  TMULASSIGN,
  TDIVASSIGN,
  TMODASSIGN,
  TNOT,
  TAND,
  TOR,
  TEQUAL,
  TNOTEQU,
  TLESS,
  TLESSE,
  TGREAT,
  TGREATE,
  TINC,
  TDEC,
  TLPAREN,
  TRPAREN,
  TCOMMA,
  TLBRACE,
  TRBRACE,
  TLBRACKET,
  TRBRACKET,
  TSEMI
};
#endif
/* Tokens.  */

/* Copy the first part of user declarations.  */
#line 1 "parser.y"

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "lex.yy.c" /* #include "lex.yy.c" */

/*yacc source for Mini C */
void semantic(int);
void yyerror(char *);

/* Enabling traces.  */
#ifndef YYDEBUG
#define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
#undef YYERROR_VERBOSE
#define YYERROR_VERBOSE 1
#else
#define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
#define YYTOKEN_TABLE 0
#endif

#if !defined YYSTYPE && !defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
#define yystype YYSTYPE /* obsolescent; will be withdrawn */
#define YYSTYPE_IS_DECLARED 1
#define YYSTYPE_IS_TRIVIAL 1
#endif

/* Copy the second part of user declarations.  */

/* Line 216 of yacc.c.  */
#line 212 "parser.tab.c"

#ifdef short
#undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
#ifdef __SIZE_TYPE__
#define YYSIZE_T __SIZE_TYPE__
#elif defined size_t
#define YYSIZE_T size_t
#elif !defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ || defined __cplusplus || defined _MSC_VER)
#include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#define YYSIZE_T size_t
#else
#define YYSIZE_T unsigned int
#endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) - 1)

#ifndef YY_
#if defined YYENABLE_NLS && YYENABLE_NLS
#if ENABLE_NLS
#include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#define YY_(msgid) dgettext("bison-runtime", msgid)
#endif
#endif
#ifndef YY_
#define YY_(msgid) msgid
#endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if !defined lint || defined __GNUC__
#define YYUSE(e) ((void)(e))
#else
#define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
#define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ || defined __cplusplus || defined _MSC_VER)
static int
YYID(int i)
#else
static int
YYID(i)
int i;
#endif
{
  return i;
}
#endif

#if !defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

#ifdef YYSTACK_USE_ALLOCA
#if YYSTACK_USE_ALLOCA
#ifdef __GNUC__
#define YYSTACK_ALLOC __builtin_alloca
#elif defined __BUILTIN_VA_ARG_INCR
#include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#elif defined _AIX
#define YYSTACK_ALLOC __alloca
#elif defined _MSC_VER
#include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#define alloca _alloca
#else
#define YYSTACK_ALLOC alloca
#if !defined _ALLOCA_H && !defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ || defined __cplusplus || defined _MSC_VER)
#include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#ifndef _STDLIB_H
#define _STDLIB_H 1
#endif
#endif
#endif
#endif
#endif

#ifdef YYSTACK_ALLOC
/* Pacify GCC's `empty if-body' warning.  */
#define YYSTACK_FREE(Ptr) \
  do                      \
  { /* empty */           \
    ;                     \
  } while (YYID(0))
#ifndef YYSTACK_ALLOC_MAXIMUM
/* The OS might guarantee only one guard page at the bottom of the stack,
   and a page size can be as small as 4096 bytes.  So we cannot safely
   invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
   to allow for a few compiler-allocated temporary stack slots.  */
#define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#endif
#else
#define YYSTACK_ALLOC YYMALLOC
#define YYSTACK_FREE YYFREE
#ifndef YYSTACK_ALLOC_MAXIMUM
#define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#endif
#if (defined __cplusplus && !defined _STDLIB_H && !((defined YYMALLOC || defined malloc) && (defined YYFREE || defined free)))
#include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#ifndef _STDLIB_H
#define _STDLIB_H 1
#endif
#endif
#ifndef YYMALLOC
#define YYMALLOC malloc
#if !defined malloc && !defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ || defined __cplusplus || defined _MSC_VER)
void *malloc(YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#endif
#endif
#ifndef YYFREE
#define YYFREE free
#if !defined free && !defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ || defined __cplusplus || defined _MSC_VER)
void free(void *); /* INFRINGES ON USER NAME SPACE */
#endif
#endif
#endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */

#if (!defined yyoverflow && (!defined __cplusplus || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
};

/* The size of the maximum gap between one aligned stack and the next.  */
#define YYSTACK_GAP_MAXIMUM (sizeof(union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
#define YYSTACK_BYTES(N) \
  ((N) * (sizeof(yytype_int16) + sizeof(YYSTYPE)) + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
#ifndef YYCOPY
#if defined __GNUC__ && 1 < __GNUC__
#define YYCOPY(To, From, Count) \
  __builtin_memcpy(To, From, (Count) * sizeof(*(From)))
#else
#define YYCOPY(To, From, Count)         \
  do                                    \
  {                                     \
    YYSIZE_T yyi;                       \
    for (yyi = 0; yyi < (Count); yyi++) \
      (To)[yyi] = (From)[yyi];          \
  } while (YYID(0))
#endif
#endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
#define YYSTACK_RELOCATE(Stack)                                      \
  do                                                                 \
  {                                                                  \
    YYSIZE_T yynewbytes;                                             \
    YYCOPY(&yyptr->Stack, Stack, yysize);                            \
    Stack = &yyptr->Stack;                                           \
    yynewbytes = yystacksize * sizeof(*Stack) + YYSTACK_GAP_MAXIMUM; \
    yyptr += yynewbytes / sizeof(*yyptr);                            \
  } while (YYID(0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL 15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST 141

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS 65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS 46
/* YYNRULES -- Number of rules.  */
#define YYNRULES 98
/* YYNRULES -- Number of states.  */
#define YYNSTATES 153

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK 2
#define YYMAXUTOK 302

#define YYTRANSLATE(YYX) \
  ((unsigned int)(YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
    {
        0, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 64, 2, 2, 2, 63, 2, 2,
        48, 49, 61, 59, 50, 60, 2, 62, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 53,
        58, 54, 57, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 55, 2, 56, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 51, 2, 52, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 1, 2, 3, 4,
        5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
        15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
        25, 26, 27, 28, 29, 30, 31, 32, 33, 34,
        35, 36, 37, 38, 39, 40, 41, 42, 43, 44,
        45, 46, 47};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
    {
        0, 0, 3, 5, 7, 10, 12, 14, 17, 21,
        23, 25, 28, 30, 32, 34, 36, 38, 40, 44,
        46, 47, 49, 53, 56, 61, 63, 64, 66, 69,
        73, 75, 79, 81, 85, 87, 92, 94, 95, 97,
        98, 100, 103, 105, 107, 109, 111, 113, 116, 118,
        119, 125, 133, 139, 143, 145, 147, 151, 155, 159,
        163, 167, 171, 173, 177, 179, 183, 185, 189, 193,
        195, 199, 203, 207, 211, 213, 217, 221, 223, 227,
        231, 235, 237, 240, 243, 246, 249, 251, 256, 261,
        264, 267, 269, 270, 272, 274, 278, 280, 282};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
    {
        66, 0, -1, 67, -1, 68, -1, 67, 68, -1,
        69, -1, 84, -1, 70, 81, -1, 71, 76, 77,
        -1, 72, -1, 73, -1, 72, 73, -1, 74, -1,
        75, -1, 9, -1, 12, -1, 15, -1, 6, -1,
        48, 78, 49, -1, 79, -1, -1, 80, -1, 79,
        50, 80, -1, 71, 87, -1, 51, 82, 89, 52,
        -1, 83, -1, -1, 84, -1, 83, 84, -1, 71,
        85, 53, -1, 86, -1, 85, 50, 86, -1, 87,
        -1, 87, 54, 7, -1, 6, -1, 6, 55, 88,
        56, -1, 7, -1, -1, 90, -1, -1, 91, -1,
        90, 91, -1, 81, -1, 92, -1, 94, -1, 95,
        -1, 96, -1, 93, 53, -1, 97, -1, -1, 11,
        48, 97, 49, 91, -1, 11, 48, 97, 49, 91,
        10, 91, -1, 16, 48, 97, 49, 91, -1, 14,
        93, 53, -1, 98, -1, 99, -1, 105, 54, 98,
        -1, 105, 23, 98, -1, 105, 24, 98, -1, 105,
        25, 98, -1, 105, 26, 98, -1, 105, 27, 98,
        -1, 100, -1, 99, 30, 100, -1, 101, -1, 100,
        29, 101, -1, 102, -1, 101, 31, 102, -1, 101,
        32, 102, -1, 103, -1, 102, 57, 103, -1, 102,
        58, 103, -1, 102, 36, 103, -1, 102, 34, 103,
        -1, 104, -1, 103, 59, 104, -1, 103, 60, 104,
        -1, 105, -1, 104, 61, 105, -1, 104, 62, 105,
        -1, 104, 63, 105, -1, 106, -1, 60, 105, -1,
        64, 105, -1, 37, 105, -1, 38, 105, -1, 110,
        -1, 106, 55, 97, 56, -1, 106, 48, 107, 49,
        -1, 106, 37, -1, 106, 38, -1, 108, -1, -1,
        109, -1, 98, -1, 109, 50, 98, -1, 6, -1,
        7, -1, 48, 97, 49, -1};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
    {
        0, 23, 23, 24, 25, 26, 27, 28, 29, 30,
        31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
        41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
        51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
        61, 62, 63, 64, 65, 66, 67, 69, 70, 71,
        72, 73, 74, 75, 76, 77, 78, 79, 80, 81,
        82, 83, 85, 86, 87, 88, 89, 90, 91, 92,
        93, 94, 95, 96, 97, 98, 99, 100, 101, 102,
        103, 104, 105, 106, 107, 108, 109, 110, 111, 112,
        113, 114, 115, 116, 117, 118, 119, 120, 121};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
    {
        "$end", "error", "$undefined", "TEOF", "TERROR", "TCOMMENT", "TIDENT",
        "TNUMBER", "TFNUMBER", "TCONST", "TELSE", "TIF", "TINT", "TFLOAT",
        "TRETURN", "TVOID", "TWHILE", "TADD", "TSUB", "TMUL", "TDIV", "TMOD",
        "TASSIGN", "TADDASSIGN", "TSUBASSIGN", "TMULASSIGN", "TDIVASSIGN",
        "TMODASSIGN", "TNOT", "TAND", "TOR", "TEQUAL", "TNOTEQU", "TLESS",
        "TLESSE", "TGREAT", "TGREATE", "TINC", "TDEC", "TLPAREN", "TRPAREN",
        "TRBRACE", "TLBRACKET", "TRBRACKET", "TSEMI", "TCOMMA", "TLBRACE",
        "LOWER_THAN_ELSE", "'('", "')'", "','", "'{'", "'}'", "';'", "'='",
        "'['", "']'", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'",
        "$accept", "mini_c", "translation_unit", "external_dcl", "function_def",
        "function_header", "dcl_spec", "dcl_specifiers", "dcl_specifier",
        "type_qualifier", "type_specifier", "function_name", "formal_param",
        "opt_formal_param", "formal_param_list", "param_dcl", "compound_st",
        "opt_dcl_list", "declaration_list", "declaration", "init_dcl_list",
        "init_declarator", "declarator", "opt_number", "opt_stat_list",
        "statement_list", "statement", "expression_st", "opt_expression",
        "if_st", "while_st", "return_st", "expression", "assignment_exp",
        "logical_or_exp", "logical_and_exp", "equality_exp", "relational_exp",
        "additive_exp", "multiplicative_exp", "unary_exp", "postfix_exp",
        "opt_actual_param", "actual_param", "actual_param_list", "primary_exp", 0};
#endif

#ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
    {
        0, 256, 257, 258, 259, 260, 261, 262, 263, 264,
        265, 266, 267, 268, 269, 270, 271, 272, 273, 274,
        275, 276, 277, 278, 279, 280, 281, 282, 283, 284,
        285, 286, 287, 288, 289, 290, 291, 292, 293, 294,
        295, 296, 297, 298, 299, 300, 301, 302, 40, 41,
        44, 123, 125, 59, 61, 91, 93, 62, 60, 43,
        45, 42, 47, 37, 33};
#endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
    {
        0, 65, 66, 67, 67, 68, 68, 69, 70, 71,
        72, 72, 73, 73, 74, 75, 75, 76, 77, 78,
        78, 79, 79, 80, 81, 82, 82, 83, 83, 84,
        85, 85, 86, 86, 87, 87, 88, 88, 89, 89,
        90, 90, 91, 91, 91, 91, 91, 92, 93, 93,
        94, 94, 95, 96, 97, 98, 98, 98, 98, 98,
        98, 98, 99, 99, 100, 100, 101, 101, 101, 102,
        102, 102, 102, 102, 103, 103, 103, 104, 104, 104,
        104, 105, 105, 105, 105, 105, 106, 106, 106, 106,
        106, 107, 107, 108, 109, 109, 110, 110, 110};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
    {
        0, 2, 1, 1, 2, 1, 1, 2, 3, 1,
        1, 2, 1, 1, 1, 1, 1, 1, 3, 1,
        0, 1, 3, 2, 4, 1, 0, 1, 2, 3,
        1, 3, 1, 3, 1, 4, 1, 0, 1, 0,
        1, 2, 1, 1, 1, 1, 1, 2, 1, 0,
        5, 7, 5, 3, 1, 1, 3, 3, 3, 3,
        3, 3, 1, 3, 1, 3, 1, 3, 3, 1,
        3, 3, 3, 3, 1, 3, 3, 1, 3, 3,
        3, 1, 2, 2, 2, 2, 1, 4, 4, 2,
        2, 1, 0, 1, 1, 3, 1, 1, 3};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
    {
        0, 14, 15, 16, 0, 2, 3, 5, 0, 0,
        9, 10, 12, 13, 6, 1, 4, 26, 7, 34,
        0, 0, 30, 32, 11, 0, 39, 25, 27, 37,
        20, 8, 0, 29, 0, 34, 96, 97, 0, 49,
        0, 0, 0, 0, 0, 0, 42, 0, 38, 40,
        43, 0, 44, 45, 46, 48, 54, 55, 62, 64,
        66, 69, 74, 77, 81, 86, 28, 36, 0, 0,
        0, 19, 21, 31, 33, 0, 0, 0, 84, 85,
        0, 82, 83, 24, 41, 47, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 89, 90, 92, 0, 35,
        23, 18, 0, 0, 53, 0, 98, 63, 77, 65,
        67, 68, 73, 72, 70, 71, 75, 76, 78, 79,
        80, 57, 58, 59, 60, 61, 56, 94, 0, 91,
        93, 0, 22, 49, 49, 88, 0, 87, 50, 52,
        95, 49, 51};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
    {
        -1, 4, 5, 6, 7, 8, 9, 10, 11, 12,
        13, 20, 31, 70, 71, 72, 46, 26, 27, 14,
        21, 22, 23, 68, 47, 48, 49, 50, 51, 52,
        53, 54, 55, 56, 57, 58, 59, 60, 61, 62,
        63, 64, 138, 139, 140, 65};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -61
static const yytype_int8 yypact[] =
    {
        76, -61, -61, -61, 4, 76, -61, -61, -26, 3,
        76, -61, -61, -61, -61, -61, -61, 76, -61, -38,
        -16, -45, -61, -4, -61, 46, 0, 76, -61, 55,
        76, -61, 46, -61, 60, 21, -61, -61, 39, 17,
        50, 17, 17, 17, 17, 17, -61, 42, 0, -61,
        -61, 51, -61, -61, -61, -61, -61, 75, 77, 43,
        25, 19, -33, -5, 8, -61, -61, -61, 52, 46,
        58, 59, -61, -61, -61, 17, 57, 17, -61, -61,
        62, -61, -61, -61, -61, -61, 17, 17, 17, 17,
        17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
        17, 17, 17, 17, 17, -61, -61, 17, 17, -61,
        -61, -61, 76, 63, -61, 64, -61, 77, -61, 43,
        25, 25, 19, 19, 19, 19, -33, -33, -61, -61,
        -61, -61, -61, -61, -61, -61, -61, -61, 78, -61,
        79, 72, -61, 20, 20, -61, 17, -61, 120, -61,
        -61, 20, -61};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
    {
        -61, -61, -61, 126, -61, -61, -15, -61, 122, -61,
        -61, -61, -61, -61, -61, 22, 125, -61, -61, -14,
        -61, 103, 67, -61, -61, -61, -48, -61, 98, -61,
        -61, -61, -42, -60, -61, 53, 54, 1, 9, -2,
        28, -61, -61, -61, -61, -61};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -50
static const yytype_int16 yytable[] =
    {
        84, 80, 25, 28, 15, 32, 36, 37, 33, 19,
        -17, 38, 25, 66, 39, 69, 40, 29, 99, 100,
        101, 102, 103, 36, 37, 17, 36, 37, 96, 97,
        98, 38, 30, 113, 39, 115, 40, 41, 42, 131,
        132, 133, 134, 135, 136, 105, 106, 137, 43, 104,
        34, 17, 35, -49, 41, 42, 107, 41, 42, 90,
        44, 91, 67, 108, 45, 43, 141, 74, 43, 78,
        79, 17, 81, 82, 88, 89, 29, 44, 94, 95,
        44, 45, 92, 93, 45, 1, 150, 75, 2, 120,
        121, 3, 126, 127, 83, 148, 149, 69, 77, 122,
        123, 124, 125, 152, 85, 86, 87, 111, 109, 112,
        114, 116, 143, 144, 118, 118, 118, 118, 118, 118,
        118, 118, 118, 118, 128, 129, 130, 145, 147, 146,
        151, 16, 24, 18, 142, 73, 110, 76, 0, 117,
        0, 119};

static const yytype_int16 yycheck[] =
    {
        48, 43, 17, 17, 0, 50, 6, 7, 53, 6,
        48, 11, 27, 27, 14, 30, 16, 55, 23, 24,
        25, 26, 27, 6, 7, 51, 6, 7, 61, 62,
        63, 11, 48, 75, 14, 77, 16, 37, 38, 99,
        100, 101, 102, 103, 104, 37, 38, 107, 48, 54,
        54, 51, 6, 53, 37, 38, 48, 37, 38, 34,
        60, 36, 7, 55, 64, 48, 108, 7, 48, 41,
        42, 51, 44, 45, 31, 32, 55, 60, 59, 60,
        60, 64, 57, 58, 64, 9, 146, 48, 12, 88,
        89, 15, 94, 95, 52, 143, 144, 112, 48, 90,
        91, 92, 93, 151, 53, 30, 29, 49, 56, 50,
        53, 49, 49, 49, 86, 87, 88, 89, 90, 91,
        92, 93, 94, 95, 96, 97, 98, 49, 56, 50,
        10, 5, 10, 8, 112, 32, 69, 39, -1, 86,
        -1, 87};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
    {
        0, 9, 12, 15, 66, 67, 68, 69, 70, 71,
        72, 73, 74, 75, 84, 0, 68, 51, 81, 6,
        76, 85, 86, 87, 73, 71, 82, 83, 84, 55,
        48, 77, 50, 53, 54, 6, 6, 7, 11, 14,
        16, 37, 38, 48, 60, 64, 81, 89, 90, 91,
        92, 93, 94, 95, 96, 97, 98, 99, 100, 101,
        102, 103, 104, 105, 106, 110, 84, 7, 88, 71,
        78, 79, 80, 86, 7, 48, 93, 48, 105, 105,
        97, 105, 105, 52, 91, 53, 30, 29, 31, 32,
        34, 36, 57, 58, 59, 60, 61, 62, 63, 23,
        24, 25, 26, 27, 54, 37, 38, 48, 55, 56,
        87, 49, 50, 97, 53, 97, 49, 100, 105, 101,
        102, 102, 103, 103, 103, 103, 104, 104, 105, 105,
        105, 98, 98, 98, 98, 98, 98, 98, 107, 108,
        109, 97, 80, 49, 49, 49, 50, 56, 91, 91,
        98, 10, 91};

#define yyerrok (yyerrstatus = 0)
#define yyclearin (yychar = YYEMPTY)
#define YYEMPTY (-2)
#define YYEOF 0

#define YYACCEPT goto yyacceptlab
#define YYABORT goto yyabortlab
#define YYERROR goto yyerrorlab

/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL goto yyerrlab

#define YYRECOVERING() (!!yyerrstatus)

#define YYBACKUP(Token, Value)                      \
  do                                                \
    if (yychar == YYEMPTY && yylen == 1)            \
    {                                               \
      yychar = (Token);                             \
      yylval = (Value);                             \
      yytoken = YYTRANSLATE(yychar);                \
      YYPOPSTACK(1);                                \
      goto yybackup;                                \
    }                                               \
    else                                            \
    {                                               \
      yyerror(YY_("syntax error: cannot back up")); \
      YYERROR;                                      \
    }                                               \
  while (YYID(0))

#define YYTERROR 1
#define YYERRCODE 256

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
#define YYLLOC_DEFAULT(Current, Rhs, N)                       \
  do                                                          \
    if (YYID(N))                                              \
    {                                                         \
      (Current).first_line = YYRHSLOC(Rhs, 1).first_line;     \
      (Current).first_column = YYRHSLOC(Rhs, 1).first_column; \
      (Current).last_line = YYRHSLOC(Rhs, N).last_line;       \
      (Current).last_column = YYRHSLOC(Rhs, N).last_column;   \
    }                                                         \
    else                                                      \
    {                                                         \
      (Current).first_line = (Current).last_line =            \
          YYRHSLOC(Rhs, 0).last_line;                         \
      (Current).first_column = (Current).last_column =        \
          YYRHSLOC(Rhs, 0).last_column;                       \
    }                                                         \
  while (YYID(0))
#endif

/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#define YY_LOCATION_PRINT(File, Loc)            \
  fprintf(File, "%d.%d-%d.%d",                  \
          (Loc).first_line, (Loc).first_column, \
          (Loc).last_line, (Loc).last_column)
#else
#define YY_LOCATION_PRINT(File, Loc) ((void)0)
#endif
#endif

/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
#define YYLEX yylex(YYLEX_PARAM)
#else
#define YYLEX yylex()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

#ifndef YYFPRINTF
#include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#define YYFPRINTF fprintf
#endif

#define YYDPRINTF(Args) \
  do                    \
  {                     \
    if (yydebug)        \
      YYFPRINTF Args;   \
  } while (YYID(0))

#define YY_SYMBOL_PRINT(Title, Type, Value, Location) \
  do                                                  \
  {                                                   \
    if (yydebug)                                      \
    {                                                 \
      YYFPRINTF(stderr, "%s ", Title);                \
      yy_symbol_print(stderr,                         \
                      Type, Value);                   \
      YYFPRINTF(stderr, "\n");                        \
    }                                                 \
  } while (YYID(0))

/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print(FILE *yyoutput, int yytype, YYSTYPE const *const yyvaluep)
#else
static void
    yy_symbol_value_print(yyoutput, yytype, yyvaluep)
        FILE *yyoutput;
int yytype;
YYSTYPE const *const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
#ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT(yyoutput, yytoknum[yytype], *yyvaluep);
#else
  YYUSE(yyoutput);
#endif
  switch (yytype)
  {
  default:
    break;
  }
}

/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print(FILE *yyoutput, int yytype, YYSTYPE const *const yyvaluep)
#else
static void
    yy_symbol_print(yyoutput, yytype, yyvaluep)
        FILE *yyoutput;
int yytype;
YYSTYPE const *const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF(yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF(yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print(yyoutput, yytype, yyvaluep);
  YYFPRINTF(yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print(yytype_int16 *bottom, yytype_int16 *top)
#else
static void
    yy_stack_print(bottom, top)
        yytype_int16 *bottom;
yytype_int16 *top;
#endif
{
  YYFPRINTF(stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF(stderr, " %d", *bottom);
  YYFPRINTF(stderr, "\n");
}

#define YY_STACK_PRINT(Bottom, Top)    \
  do                                   \
  {                                    \
    if (yydebug)                       \
      yy_stack_print((Bottom), (Top)); \
  } while (YYID(0))

/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print(YYSTYPE *yyvsp, int yyrule)
#else
static void
    yy_reduce_print(yyvsp, yyrule)
        YYSTYPE *yyvsp;
int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF(stderr, "Reducing stack by rule %d (line %lu):\n",
            yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
  {
    fprintf(stderr, "   $%d = ", yyi + 1);
    yy_symbol_print(stderr, yyrhs[yyprhs[yyrule] + yyi],
                    &(yyvsp[(yyi + 1) - (yynrhs)]));
    fprintf(stderr, "\n");
  }
}

#define YY_REDUCE_PRINT(Rule)       \
  do                                \
  {                                 \
    if (yydebug)                    \
      yy_reduce_print(yyvsp, Rule); \
  } while (YYID(0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
#define YYDPRINTF(Args)
#define YY_SYMBOL_PRINT(Title, Type, Value, Location)
#define YY_STACK_PRINT(Bottom, Top)
#define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
#define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

#if YYERROR_VERBOSE

#ifndef yystrlen
#if defined __GLIBC__ && defined _STRING_H
#define yystrlen strlen
#else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen(const char *yystr)
#else
static YYSIZE_T
    yystrlen(yystr)
        const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#endif
#endif

#ifndef yystpcpy
#if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#define yystpcpy stpcpy
#else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy(char *yydest, const char *yysrc)
#else
static char *
yystpcpy(yydest, yysrc)
char *yydest;
const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr(char *yyres, const char *yystr)
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
  do_not_strip_quotes:;
  }

  if (!yyres)
    return yystrlen(yystr);

  return yystpcpy(yyres, yystr) - yyres;
}
#endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error(char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (!(YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
  {
    int yytype = YYTRANSLATE(yychar);
    YYSIZE_T yysize0 = yytnamerr(0, yytname[yytype]);
    YYSIZE_T yysize = yysize0;
    YYSIZE_T yysize1;
    int yysize_overflow = 0;
    enum
    {
      YYERROR_VERBOSE_ARGS_MAXIMUM = 5
    };
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
    int yyx;

#if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
#endif
    char *yyfmt;
    char const *yyf;
    static char const yyunexpected[] = "syntax error, unexpected %s";
    static char const yyexpecting[] = ", expecting %s";
    static char const yyor[] = " or %s";
    char yyformat[sizeof yyunexpected + sizeof yyexpecting - 1 + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2) * (sizeof yyor - 1))];
    char const *yyprefix = yyexpecting;

    /* Start YYX at -YYN if negative to avoid negative indexes in
 YYCHECK.  */
    int yyxbegin = yyn < 0 ? -yyn : 0;

    /* Stay within bounds of both yycheck and yytname.  */
    int yychecklim = YYLAST - yyn + 1;
    int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
    int yycount = 1;

    yyarg[0] = yytname[yytype];
    yyfmt = yystpcpy(yyformat, yyunexpected);

    for (yyx = yyxbegin; yyx < yyxend; ++yyx)
      if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
      {
        if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
        {
          yycount = 1;
          yysize = yysize0;
          yyformat[sizeof yyunexpected - 1] = '\0';
          break;
        }
        yyarg[yycount++] = yytname[yyx];
        yysize1 = yysize + yytnamerr(0, yytname[yyx]);
        yysize_overflow |= (yysize1 < yysize);
        yysize = yysize1;
        yyfmt = yystpcpy(yyfmt, yyprefix);
        yyprefix = yyor;
      }

    yyf = YY_(yyformat);
    yysize1 = yysize + yystrlen(yyf);
    yysize_overflow |= (yysize1 < yysize);
    yysize = yysize1;

    if (yysize_overflow)
      return YYSIZE_MAXIMUM;

    if (yyresult)
    {
      /* Avoid sprintf, as that infringes on the user's name space.
         Don't have undefined behavior even if the translation
         produced a string with the wrong number of "%s"s.  */
      char *yyp = yyresult;
      int yyi = 0;
      while ((*yyp = *yyf) != '\0')
      {
        if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr(yyp, yyarg[yyi++]);
          yyf += 2;
        }
        else
        {
          yyp++;
          yyf++;
        }
      }
    }
    return yysize;
  }
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ || defined __cplusplus || defined _MSC_VER)
static void
yydestruct(const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
    yydestruct(yymsg, yytype, yyvaluep)
        const char *yymsg;
int yytype;
YYSTYPE *yyvaluep;
#endif
{
  YYUSE(yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT(yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
  {

  default:
    break;
  }
}

/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse(void *YYPARSE_PARAM);
#else
int yyparse();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse(void);
#else
int yyparse();
#endif
#endif /* ! YYPARSE_PARAM */

/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;

/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ || defined __cplusplus || defined _MSC_VER)
int yyparse(void *YYPARSE_PARAM)
#else
int
    yyparse(YYPARSE_PARAM) void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ || defined __cplusplus || defined _MSC_VER)
int yyparse(void)
#else
int yyparse()

#endif
#endif
{

  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

#define YYPOPSTACK(N) (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
      yyoverflow(YY_("memory exhausted"),
                 &yyss1, yysize * sizeof(*yyssp),
                 &yyvs1, yysize * sizeof(*yyvsp),

                 &yystacksize);

      yyss = yyss1;
      yyvs = yyvs1;
    }
#else /* no yyoverflow */
#ifndef YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    /* Extend the stack our own way.  */
    if (YYMAXDEPTH <= yystacksize)
      goto yyexhaustedlab;
    yystacksize *= 2;
    if (YYMAXDEPTH < yystacksize)
      yystacksize = YYMAXDEPTH;

    {
      yytype_int16 *yyss1 = yyss;
      union yyalloc *yyptr =
          (union yyalloc *)YYSTACK_ALLOC(YYSTACK_BYTES(yystacksize));
      if (!yyptr)
        goto yyexhaustedlab;
      YYSTACK_RELOCATE(yyss);
      YYSTACK_RELOCATE(yyvs);

#undef YYSTACK_RELOCATE
      if (yyss1 != yyssa)
        YYSTACK_FREE(yyss1);
    }
#endif
#endif /* no yyoverflow */

    yyssp = yyss + yysize - 1;
    yyvsp = yyvs + yysize - 1;

    YYDPRINTF((stderr, "Stack size increased to %lu\n",
               (unsigned long int)yystacksize));

    if (yyss + yystacksize - 1 <= yyssp)
      YYABORT;
  }

  YYDPRINTF((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
  {
    YYDPRINTF((stderr, "Reading a token: "));
    yychar = YYLEX;
  }

  if (yychar <= YYEOF)
  {
    yychar = yytoken = YYEOF;
    YYDPRINTF((stderr, "Now at end of input.\n"));
  }
  else
  {
    yytoken = YYTRANSLATE(yychar);
    YY_SYMBOL_PRINT("Next token is", yytoken, &yylval, &yylloc);
  }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
  {
    if (yyn == 0 || yyn == YYTABLE_NINF)
      goto yyerrlab;
    yyn = -yyn;
    goto yyreduce;
  }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1 - yylen];

  YY_REDUCE_PRINT(yyn);
  switch (yyn)
  {
  case 2:
#line 23 "parser.y"
  {
    semantic(1);
    ;
  }
  break;

  case 3:
#line 24 "parser.y"
  {
    semantic(2);
    ;
  }
  break;

  case 4:
#line 25 "parser.y"
  {
    semantic(3);
    ;
  }
  break;

  case 5:
#line 26 "parser.y"
  {
    semantic(4);
    ;
  }
  break;

  case 6:
#line 27 "parser.y"
  {
    semantic(5);
    ;
  }
  break;

  case 7:
#line 28 "parser.y"
  {
    semantic(6);
    ;
  }
  break;

  case 8:
#line 29 "parser.y"
  {
    semantic(7);
    ;
  }
  break;

  case 9:
#line 30 "parser.y"
  {
    semantic(8);
    ;
  }
  break;

  case 10:
#line 31 "parser.y"
  {
    semantic(9);
    ;
  }
  break;

  case 11:
#line 32 "parser.y"
  {
    semantic(10);
    ;
  }
  break;

  case 12:
#line 33 "parser.y"
  {
    semantic(11);
    ;
  }
  break;

  case 13:
#line 34 "parser.y"
  {
    semantic(12);
    ;
  }
  break;

  case 14:
#line 35 "parser.y"
  {
    semantic(13);
    ;
  }
  break;

  case 15:
#line 36 "parser.y"
  {
    semantic(14);
    ;
  }
  break;

  case 16:
#line 37 "parser.y"
  {
    semantic(15);
    ;
  }
  break;

  case 17:
#line 38 "parser.y"
  {
    semantic(16);
    ;
  }
  break;

  case 18:
#line 39 "parser.y"
  {
    semantic(17);
    ;
  }
  break;

  case 19:
#line 40 "parser.y"
  {
    semantic(18);
    ;
  }
  break;

  case 20:
#line 41 "parser.y"
  {
    semantic(19);
    ;
  }
  break;

  case 21:
#line 42 "parser.y"
  {
    semantic(20);
    ;
  }
  break;

  case 22:
#line 43 "parser.y"
  {
    semantic(21);
    ;
  }
  break;

  case 23:
#line 44 "parser.y"
  {
    semantic(22);
    ;
  }
  break;

  case 24:
#line 45 "parser.y"
  {
    semantic(23);
    ;
  }
  break;

  case 25:
#line 46 "parser.y"
  {
    semantic(24);
    ;
  }
  break;

  case 26:
#line 47 "parser.y"
  {
    semantic(25);
    ;
  }
  break;

  case 27:
#line 48 "parser.y"
  {
    semantic(26);
    ;
  }
  break;

  case 28:
#line 49 "parser.y"
  {
    semantic(27);
    ;
  }
  break;

  case 29:
#line 50 "parser.y"
  {
    semantic(28);
    ;
  }
  break;

  case 30:
#line 51 "parser.y"
  {
    semantic(29);
    ;
  }
  break;

  case 31:
#line 52 "parser.y"
  {
    semantic(30);
    ;
  }
  break;

  case 32:
#line 53 "parser.y"
  {
    semantic(31);
    ;
  }
  break;

  case 33:
#line 54 "parser.y"
  {
    semantic(32);
    ;
  }
  break;

  case 34:
#line 55 "parser.y"
  {
    semantic(33);
    ;
  }
  break;

  case 35:
#line 56 "parser.y"
  {
    semantic(34);
    ;
  }
  break;

  case 36:
#line 57 "parser.y"
  {
    semantic(35);
    ;
  }
  break;

  case 37:
#line 58 "parser.y"
  {
    semantic(36);
    ;
  }
  break;

  case 38:
#line 59 "parser.y"
  {
    semantic(37);
    ;
  }
  break;

  case 39:
#line 60 "parser.y"
  {
    semantic(38);
    ;
  }
  break;

  case 40:
#line 61 "parser.y"
  {
    semantic(39);
    ;
  }
  break;

  case 41:
#line 62 "parser.y"
  {
    semantic(40);
    ;
  }
  break;

  case 42:
#line 63 "parser.y"
  {
    semantic(41);
    ;
  }
  break;

  case 43:
#line 64 "parser.y"
  {
    semantic(42);
    ;
  }
  break;

  case 44:
#line 65 "parser.y"
  {
    semantic(43);
    ;
  }
  break;

  case 45:
#line 66 "parser.y"
  {
    semantic(44);
    ;
  }
  break;

  case 46:
#line 67 "parser.y"
  {
    semantic(45);
    ;
  }
  break;

  case 47:
#line 69 "parser.y"
  {
    semantic(46);
    ;
  }
  break;

  case 48:
#line 70 "parser.y"
  {
    semantic(47);
    ;
  }
  break;

  case 49:
#line 71 "parser.y"
  {
    semantic(48);
    ;
  }
  break;

  case 50:
#line 72 "parser.y"
  {
    semantic(49);
    ;
  }
  break;

  case 51:
#line 73 "parser.y"
  {
    semantic(50);
    ;
  }
  break;

  case 52:
#line 74 "parser.y"
  {
    semantic(51);
    ;
  }
  break;

  case 53:
#line 75 "parser.y"
  {
    semantic(52);
    ;
  }
  break;

  case 54:
#line 76 "parser.y"
  {
    semantic(53);
    ;
  }
  break;

  case 55:
#line 77 "parser.y"
  {
    semantic(54);
    ;
  }
  break;

  case 56:
#line 78 "parser.y"
  {
    semantic(55);
    ;
  }
  break;

  case 57:
#line 79 "parser.y"
  {
    semantic(56);
    ;
  }
  break;

  case 58:
#line 80 "parser.y"
  {
    semantic(57);
    ;
  }
  break;

  case 59:
#line 81 "parser.y"
  {
    semantic(58);
    ;
  }
  break;

  case 60:
#line 82 "parser.y"
  {
    semantic(59);
    ;
  }
  break;

  case 61:
#line 83 "parser.y"
  {
    semantic(60);
    ;
  }
  break;

  case 62:
#line 85 "parser.y"
  {
    semantic(61);
    ;
  }
  break;

  case 63:
#line 86 "parser.y"
  {
    semantic(62);
    ;
  }
  break;

  case 64:
#line 87 "parser.y"
  {
    semantic(63);
    ;
  }
  break;

  case 65:
#line 88 "parser.y"
  {
    semantic(64);
    ;
  }
  break;

  case 66:
#line 89 "parser.y"
  {
    semantic(65);
    ;
  }
  break;

  case 67:
#line 90 "parser.y"
  {
    semantic(66);
    ;
  }
  break;

  case 68:
#line 91 "parser.y"
  {
    semantic(67);
    ;
  }
  break;

  case 69:
#line 92 "parser.y"
  {
    semantic(68);
    ;
  }
  break;

  case 70:
#line 93 "parser.y"
  {
    semantic(69);
    ;
  }
  break;

  case 71:
#line 94 "parser.y"
  {
    semantic(70);
    ;
  }
  break;

  case 72:
#line 95 "parser.y"
  {
    semantic(71);
    ;
  }
  break;

  case 73:
#line 96 "parser.y"
  {
    semantic(72);
    ;
  }
  break;

  case 74:
#line 97 "parser.y"
  {
    semantic(73);
    ;
  }
  break;

  case 75:
#line 98 "parser.y"
  {
    semantic(74);
    ;
  }
  break;

  case 76:
#line 99 "parser.y"
  {
    semantic(75);
    ;
  }
  break;

  case 77:
#line 100 "parser.y"
  {
    semantic(76);
    ;
  }
  break;

  case 78:
#line 101 "parser.y"
  {
    semantic(77);
    ;
  }
  break;

  case 79:
#line 102 "parser.y"
  {
    semantic(78);
    ;
  }
  break;

  case 80:
#line 103 "parser.y"
  {
    semantic(79);
    ;
  }
  break;

  case 81:
#line 104 "parser.y"
  {
    semantic(80);
    ;
  }
  break;

  case 82:
#line 105 "parser.y"
  {
    semantic(81);
    ;
  }
  break;

  case 83:
#line 106 "parser.y"
  {
    semantic(82);
    ;
  }
  break;

  case 84:
#line 107 "parser.y"
  {
    semantic(83);
    ;
  }
  break;

  case 85:
#line 108 "parser.y"
  {
    semantic(84);
    ;
  }
  break;

  case 86:
#line 109 "parser.y"
  {
    semantic(85);
    ;
  }
  break;

  case 87:
#line 110 "parser.y"
  {
    semantic(86);
    ;
  }
  break;

  case 88:
#line 111 "parser.y"
  {
    semantic(87);
    ;
  }
  break;

  case 89:
#line 112 "parser.y"
  {
    semantic(88);
    ;
  }
  break;

  case 90:
#line 113 "parser.y"
  {
    semantic(89);
    ;
  }
  break;

  case 91:
#line 114 "parser.y"
  {
    semantic(90);
    ;
  }
  break;

  case 92:
#line 115 "parser.y"
  {
    semantic(91);
    ;
  }
  break;

  case 93:
#line 116 "parser.y"
  {
    semantic(92);
    ;
  }
  break;

  case 94:
#line 117 "parser.y"
  {
    semantic(93);
    ;
  }
  break;

  case 95:
#line 118 "parser.y"
  {
    semantic(94);
    ;
  }
  break;

  case 96:
#line 119 "parser.y"
  {
    semantic(95);
    ;
  }
  break;

  case 97:
#line 120 "parser.y"
  {
    semantic(96);
    ;
  }
  break;

  case 98:
#line 121 "parser.y"
  {
    semantic(97);
    ;
  }
  break;

/* Line 1267 of yacc.c.  */
#line 2050 "parser.tab.c"
  default:
    break;
  }
  YY_SYMBOL_PRINT("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK(yylen);
  yylen = 0;
  YY_STACK_PRINT(yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;

/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
  {
    ++yynerrs;
#if !YYERROR_VERBOSE
    yyerror(YY_("syntax error"));
#else
    {
      YYSIZE_T yysize = yysyntax_error(0, yystate, yychar);
      if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
      {
        YYSIZE_T yyalloc = 2 * yysize;
        if (!(yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
          yyalloc = YYSTACK_ALLOC_MAXIMUM;
        if (yymsg != yymsgbuf)
          YYSTACK_FREE(yymsg);
        yymsg = (char *)YYSTACK_ALLOC(yyalloc);
        if (yymsg)
          yymsg_alloc = yyalloc;
        else
        {
          yymsg = yymsgbuf;
          yymsg_alloc = sizeof yymsgbuf;
        }
      }

      if (0 < yysize && yysize <= yymsg_alloc)
      {
        (void)yysyntax_error(yymsg, yystate, yychar);
        yyerror(yymsg);
      }
      else
      {
        yyerror(YY_("syntax error"));
        if (yysize != 0)
          goto yyexhaustedlab;
      }
    }
#endif
  }

  if (yyerrstatus == 3)
  {
    /* If just tried and failed to reuse look-ahead token after an
 error, discard it.  */

    if (yychar <= YYEOF)
    {
      /* Return failure if at end of input.  */
      if (yychar == YYEOF)
        YYABORT;
    }
    else
    {
      yydestruct("Error: discarding",
                 yytoken, &yylval);
      yychar = YYEMPTY;
    }
  }

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK(yylen);
  yylen = 0;
  YY_STACK_PRINT(yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;

/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3; /* Each real token shifted decrements this.  */

  for (;;)
  {
    yyn = yypact[yystate];
    if (yyn != YYPACT_NINF)
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

    yydestruct("Error: popping",
               yystos[yystate], yyvsp);
    YYPOPSTACK(1);
    yystate = *yyssp;
    YY_STACK_PRINT(yyss, yyssp);
  }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT("Shifting", yystos[yyn], yyvsp, yylsp);

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror(YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
    yydestruct("Cleanup: discarding lookahead",
               yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK(yylen);
  YY_STACK_PRINT(yyss, yyssp);
  while (yyssp != yyss)
  {
    yydestruct("Cleanup: popping",
               yystos[*yyssp], yyvsp);
    YYPOPSTACK(1);
  }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE(yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE(yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID(yyresult);
}

#line 122 "parser.y"

void yyerror(char *s)
{
  printf("%s\n", s);
}
void semantic(int n)
{
  printf("reduced rule number = %d\n", n);
}
