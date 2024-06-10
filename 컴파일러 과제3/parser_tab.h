#include "sym_table_lab.h"
typedef union
{
    int ival;
    float fval;
    char *sval;
    int type;
    Params *params;
} YYSTYPE;
#define TEOF 258
#define TERROR 259
#define TCOMMENT 260
#define TCONST 261
#define TELSE 262
#define TIF 263
#define TINT 264
#define TFLOAT 265
#define TRETURN 266
#define TVOID 267
#define TWHILE 268
#define TADD 269
#define TSUB 270
#define TMUL 271
#define TDIV 272
#define TMOD 273
#define TASSIGN 274
#define TADDASSIGN 275
#define TSUBASSIGN 276
#define TMULASSIGN 277
#define TDIVASSIGN 278
#define TMODASSIGN 279
#define TNOT 280
#define TAND 281
#define TOR 282
#define TEQUAL 283
#define TNOTEQU 284
#define TLESS 285
#define TLESSE 286
#define TGREAT 287
#define TGREATE 288
#define TINC 289
#define TDEC 290
#define TLPAREN 291
#define TRPAREN 292
#define TRBRACE 293
#define TLBRACKET 294
#define TRBRACKET 295
#define TSEMI 296
#define TCOMMA 297
#define TLBRACE 298
#define LOWER_THAN_ELSE 299
#define TIDENT 300
#define TNUMBER 301
#define TFNUMBER 302

extern YYSTYPE yylval;
