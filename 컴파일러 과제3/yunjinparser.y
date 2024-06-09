%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "lex.yy.c"			/* #include "lex.yy.c" */
#include "sym_table_lab.h"

/*yacc source for Mini C */
void semantic(int);
void yyerror(char *);

char * current_func ; // 현재 실행 중인 함수 이름
int total_err_cnt = 0 ;
Type current_type = NONE_TYPE; // 현재 활성화된 선언 타입
int left_brace_cnt = 0; //왼쪽 중괄호 개수
int right_brace_cnt = 0; //오른쪽 중괄호 개수
%}

%token TEOF TERROR TCOMMENT
%token TIDENT TNUMBER TFNUMBER TCONST TELSE TIF TINT TFLOAT TRETURN TVOID TWHILE
%token TADD TSUB TMUL TDIV TMOD TASSIGN 
%token TADDASSIGN TSUBASSIGN TMULASSIGN TDIVASSIGN TMODASSIGN
%token TNOT TAND TOR TEQUAL TNOTEQU TLESS TLESSE TGREAT TGREATE TINC TDEC 
%token TLPAREN TRPAREN TRBRACE TLBRACKET TRBRACKET TSEMI TCOMMA TLBRACE TSEMICOLON
%token TUNMATCHEDLPAREN
%token TUNMATCHEDRPAREN
%union{
 	int ival;
    float fval;
    char *sval;
    int type;
}


%nonassoc LOWER_THAN_ELSE
%nonassoc TELSE


%token <sval> TIDENT

%type <type> type_specifier
%type <type> dcl_specifiers
%type <type> dcl_specifier
%type <type> dcl_spec



%type <sval> function_name
%type <sval> declarator
%type <sval> init_dcl_list
%type <sval> init_declarator


%%
mini_c: translation_unit {
    semantic(1);
};

translation_unit	    	: external_dcl								{ semantic(2); }
							| translation_unit external_dcl			    { semantic(3); };
external_dcl				: function_def								{ semantic(4); }
							| declaration								{ semantic(5); };
function_def				: function_header compound_st 	     		{ semantic(6); };
					 | function_header TLPAREN error compound_st { yyerror("Missing closing parenthesis in function definition"); yyerrok; }
    				         | function_header error TRPAREN compound_st { yyerror("Missing opening parenthesis in function definition"); yyerrok; }
;
function_header	        	: dcl_spec function_name formal_param		{ current_func = NULL; semantic(7); };
dcl_spec					: dcl_specifiers							{ semantic(8); };
dcl_specifiers			    : dcl_specifier								{ semantic(9); }
							| dcl_specifiers dcl_specifier				{ semantic(10); };
dcl_specifier			    : type_qualifier							{ semantic(11); }
							| type_specifier							{ semantic(12); };					
type_qualifier		    	: TCONST									{ semantic(13); };
type_specifier			    : TINT										{ current_type = INT_TYPE; semantic(14); }
							| TFLOAT									{ current_type = FLOAT_TYPE; printf("type_specifier->float\n")};
							| TVOID										{ current_type = VOID_TYPE;  semantic(15); };
function_name		        : TIDENT									{ current_func = $1; update_symbol_kind($1, FUNC); update_symbol_type($1,current_type); semantic(16); };	

abbreviated_param 			: TLPAREN dcl_spec_list TRPAREN				{ printf("abbreviated_param\n"); };						
formal_param		    	: TLPAREN opt_formal_param TRPAREN			{ semantic(17); };

opt_formal_param 	        : formal_param_list							{ semantic(18); }
							|											{ semantic(19); };
formal_param_list       	: param_dcl									{ semantic(20); }
							| formal_param_list TCOMMA param_dcl		{ semantic(21); };
param_dcl				    : dcl_spec declarator 		    			{ update_symbol_type($2,current_type); update_function_param(current_func,current_type); update_symbol_kind($2,PARAM); semantic(22); };
compound_st		        	: TLBRACE opt_dcl_list opt_stat_list TRBRACE { semantic(23); };
opt_dcl_list				: declaration_list							{ semantic(24); }
							|		 									{ semantic(25); };
declaration_list		    : declaration								{ semantic(26); }
							| declaration_list declaration				{ semantic(27); };

declaration                : dcl_spec init_dcl_list TSEMI                { current_type = NONE_TYPE; }
                           | function_declaration                        { semantic(28); }
                           | dcl_spec init_dcl_list error                {  yyerror("Missing semicolon after declaration");  current_type = NONE_TYPE; yyerrok; };
declaration_param 			: abbreviated_param | formal_param			;
function_declaration		: dcl_spec function_name declaration_param TSEMI {printf("function_declaration");};
dcl_spec_list 				: dcl_spec { semantic(98); update_function_param(current_func,current_type); }
							| dcl_spec_list TCOMMA dcl_spec  { semantic(99); update_function_param(current_func,current_type); };
init_dcl_list				: init_declarator							{ semantic(29); }
							| init_dcl_list TCOMMA init_declarator		{ semantic(30); };
init_declarator			    : declarator								{ update_symbol_type($1, current_type); semantic(31); }
							| declarator TASSIGN TNUMBER				{ if(current_type != INT_TYPE){  printf("line: %d,[ERROR!] Type Mismatched. Expected int but float.");  total_err_cnt++; }
																			else{update_symbol_type($1, current_type); } }
							| declarator TASSIGN TFNUMBER				{ if(current_type != FLOAT_TYPE){ printf("line: %d, [ERROR!] Type Mismatched. Expected float but int."); total_err_cnt++; } 
																			else{update_symbol_type($1, current_type); }  };

declarator				    : TIDENT									{ $$ = $1; update_symbol_kind($1,SCALAR); semantic(33); }
							| TIDENT TLBRACKET opt_number TRBRACKET		{ update_symbol_kind($1,ARRAY); semantic(34); };
opt_number				    : TNUMBER									{ semantic(35); }
							|											{ semantic(36); };
opt_stat_list				: statement_list							{ semantic(37); }
							|											{ semantic(38); };
statement_list		    	: statement									{ semantic(39); }
							| statement_list statement					{ semantic(40); };
statement					: compound_st								{ semantic(41); }
							| expression_st								{ semantic(42); }
							| if_st										{ semantic(43); }
							| while_st									{ semantic(44); }
							| return_st									{ semantic(45); }
							;
expression_st              : opt_expression TSEMI                        { semantic(46);  }
                           | opt_expression error                        { yyerror("Missing semicolon after expression"); yyerrok;};
opt_expression	        	: expression								{ semantic(47); }
							|											{ semantic(48); };

if_st
    : TIF TLPAREN expression TRPAREN statement %prec LOWER_THAN_ELSE { semantic(49); }
    | TIF TLPAREN expression TRPAREN statement TELSE statement { semantic(50); }
    | TIF error expression TRPAREN statement %prec LOWER_THAN_ELSE { yyerror("Missing opening parenthesis in if condition"); yyerrok; }
    | TIF TLPAREN expression error statement %prec LOWER_THAN_ELSE { yyerror("Missing closing parenthesis in if condition"); yyerrok; }
;

while_st
    : TWHILE TLPAREN expression TRPAREN statement { semantic(51); }
    | TWHILE error expression TRPAREN statement { yyerror("Missing opening parenthesis in while condition"); yyerrok; }
    | TWHILE TLPAREN expression error statement { yyerror("Missing closing parenthesis in while condition"); yyerrok; }
;

return_st					: TRETURN opt_expression TSEMI				{ semantic(52); };
expression			    	: assignment_exp							{ semantic(53); };
assignment_exp		        : logical_or_exp							{ semantic(54); }
							| unary_exp TASSIGN assignment_exp			{ semantic(55); }
							| unary_exp TADDASSIGN assignment_exp		{ semantic(56); }
							| unary_exp TSUBASSIGN assignment_exp		{ semantic(57); }
							| unary_exp TMULASSIGN assignment_exp		{ semantic(58); }
							| unary_exp TDIVASSIGN assignment_exp		{ semantic(59); }
							| unary_exp TMODASSIGN assignment_exp		{ semantic(60); }
							;
logical_or_exp   	    	: logical_and_exp         					{ semantic(61); }
   							| logical_or_exp TOR logical_and_exp   		{ semantic(62); };
logical_and_exp   	        : equality_exp         						{ semantic(63); }
     						| logical_and_exp TAND equality_exp   		{ semantic(64); };
equality_exp   			    : relational_exp         					{ semantic(65); }
      						| equality_exp TEQUAL relational_exp   		{ semantic(66); }
     						| equality_exp TNOTEQU relational_exp   	{ semantic(67); };
relational_exp              : additive_exp                             { semantic(68); }
      						| relational_exp '>' additive_exp   		{ semantic(69); }
      						| relational_exp '<' additive_exp   		{ semantic(70); }
      						| relational_exp TGREATE additive_exp   	{ semantic(71); }
      						| relational_exp TLESSE additive_exp   		{ semantic(72); };
additive_exp   	    		: multiplicative_exp         				{ semantic(73); }
      						| additive_exp TADD multiplicative_exp   	{ semantic(74); }
      						| additive_exp TSUB multiplicative_exp   	{ semantic(75); };
multiplicative_exp          : unary_exp         						{ semantic(76); }
     						| multiplicative_exp TMUL unary_exp      	{ semantic(77); }
      						| multiplicative_exp TDIV unary_exp   		{ semantic(78); }
      						| multiplicative_exp TMOD unary_exp   		{ semantic(79); };
unary_exp   				: postfix_exp         						{ semantic(80); }
      						| TSUB unary_exp         					{ semantic(81); }
      						| TNOT unary_exp        					{ semantic(82); }
      						| TINC unary_exp         					{ semantic(83); }
      						| TDEC unary_exp         					{ semantic(84); };
postfix_exp 				: primary_exp 								{ semantic(85); }
							| postfix_exp TLBRACKET expression TRBRACKET{ semantic(86); }
							| postfix_exp TLPAREN opt_actual_param TRPAREN { semantic(87); }
							| postfix_exp TINC 							{ semantic(88); }
							| postfix_exp TDEC							{ semantic(89); };
opt_actual_param 	        : actual_param 								{ semantic(90); }
							| 											{ semantic(91); };
actual_param 			    : actual_param_list 						{ semantic(92); };
actual_param_list 	        : assignment_exp 							{ semantic(93); }
							| actual_param_list TCOMMA assignment_exp 	{ semantic(94); };
primary_exp 			    : TIDENT 									{ semantic(95); }
							| TNUMBER 									{ semantic(96); }
							| TLPAREN expression TRPAREN 				{ semantic(97); };
%%

void yyerror(char *s)
{
    printf("line %d: %s\n", lineNumber, s);
}

void semantic(int n)
{
	printf("reduced rule number = %d\n", n);
}
