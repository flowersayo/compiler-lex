typedef union{
 	int ival;
    float fval;
    char *sval;
    int type;
} YYSTYPE;
#define	TEOF	258
#define	TERROR	259
#define	TCOMMENT	260
#define	TIDENT	261
#define	TNUMBER	262
#define	TFNUMBER	263
#define	TCONST	264
#define	TELSE	265
#define	TIF	266
#define	TINT	267
#define	TFLOAT	268
#define	TRETURN	269
#define	TVOID	270
#define	TWHILE	271
#define	TADD	272
#define	TSUB	273
#define	TMUL	274
#define	TDIV	275
#define	TMOD	276
#define	TASSIGN	277
#define	TADDASSIGN	278
#define	TSUBASSIGN	279
#define	TMULASSIGN	280
#define	TDIVASSIGN	281
#define	TMODASSIGN	282
#define	TNOT	283
#define	TAND	284
#define	TOR	285
#define	TEQUAL	286
#define	TNOTEQU	287
#define	TLESS	288
#define	TLESSE	289
#define	TGREAT	290
#define	TGREATE	291
#define	TINC	292
#define	TDEC	293
#define	TLPAREN	294
#define	TRPAREN	295
#define	TRBRACE	296
#define	TLBRACKET	297
#define	TRBRACKET	298
#define	TSEMI	299
#define	TCOMMA	300
#define	TLBRACE	301
#define	LOWER_THAN_ELSE	302


extern YYSTYPE yylval;
