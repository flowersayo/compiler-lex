%{
#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
#include "glob.h"
extern reporterror(enum tnumber tn);
extern int linenum;
%}

%% 

"const" return(TCONST);
"else" return(TELSE);
"if" return(TIF);
"int" return(TINT);
"return" return(TRETURN);
"void" return(TVOID);
"while" return(TWHILE);
"=="  return(TEQUAL);
"!=" return(TNOTEQU);
"<=" return(TLESSE);
">=" return(TGREATE);
"&&" return(TAND);
"||" return(TOR);
"++" return(TINC);
"--" return(TDEC);
"+=" return(TADDASSIGN);
"-=" return(TSUBASSIGN);
"*=" return(TMULASSIGN);
"/=" return(TDIVASSIGN);
"%=" return(TMODASSIGN);

"!" 		return(TEXCLAM);
"%" 		return(TMOD);
"(" 		return(TLPAREN);
")" 		return(TRPAREN);
"*" 		return(TSTAR);
"+" 		return(TPLUS);
"," 		return(TCOMMA);
"-" 		return(TMINUS);
"/" 		return(TDIV);
";" 		return(TSEMICOLON);
"<" 		return(TLESS);
"=" 		return(TEQUALS);
">" 		return(TGREATER);
"[" 		return(TLBRACKET);
"]" 		return(TRBRACKET);
"{" 		return(TLBRACE);
"}" 		return(TRBRACE);
":=" 		return(TASSIGN);

[+-]?[1-9][0-9]*|0([0-7]+|(x|X)[0-9A-Fa-f]*)? 					return(TINTEGER);
[+-]?(([0–9]*\.?[0–9]+)|([0–9]+\.?[0–9]*))([Ee][+-]?[0–9]+)?	return(TFLOAT);
[a-zA-Z_][a-zA-Z0-9_]*		{
						if (yyleng > MAXIDENTLEN)
							reporterror(TLONGIDENT);
						else {
							symtable();
						}				
					}
"/*"([^*]|\*+[^*/])*\**"*/" ;
"//".*						;
[ \t]						;
[\n]						linenum++;
.							reporterror(TILLIDENT);

%%

int yywrap()
{

return 1;
}

