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




%}

%token TEOF TERROR TCOMMENT
%token TCONST TELSE TIF TINT TFLOAT TRETURN TVOID TWHILE
%token TADD TSUB TMUL TDIV TMOD TASSIGN 
%token TADDASSIGN TSUBASSIGN TMULASSIGN TDIVASSIGN TMODASSIGN
%token TNOT TAND TOR TEQUAL TNOTEQU TLESS TLESSE TGREAT TGREATE TINC TDEC 
%token TLPAREN TRPAREN TRBRACE TLBRACKET TRBRACKET TSEMI TCOMMA TLBRACE

%union{
 	int ival;
    float fval;
    char *sval;
    int type;
	Params* params;
}


%nonassoc LOWER_THAN_ELSE
%nonassoc TELSE


%token <sval> TIDENT
%token <ival> TNUMBER
%token <fval> TFNUMBER

%type <ival> opt_number

%type <type> type_specifier
%type <type> dcl_specifiers
%type <type> dcl_specifier
%type <type> dcl_spec

%type <type> postfix_exp 
%type <type> unary_exp
%type <type> multiplicative_exp 
%type <type> additive_exp  
%type <type> relational_exp 
%type <type> equality_exp
%type <type> logical_and_exp
%type <type> logical_or_exp 


%type <type> assignment_exp
%type <type> expression 


%type <sval> function_name
%type <sval> declarator
%type <sval> init_dcl_list
%type <sval> init_declarator
%type <sval> primary_exp

%type <params> opt_actual_param;
%type <params> actual_param ;
%type <params> actual_param_list;



%%
mini_c						: translation_unit							{};
translation_unit	    	: external_dcl								{}
							| translation_unit external_dcl			    {};
external_dcl				: function_def								{}
							| declaration								{};
function_def				: function_header compound_st 	     		{};
function_header	        	: dcl_spec function_name formal_param		{ current_func = NULL; };
dcl_spec					: dcl_specifiers							{};
dcl_specifiers			    : dcl_specifier								{}
							| dcl_specifiers dcl_specifier				{};
dcl_specifier			    : type_qualifier							{}
							| type_specifier							{};					
type_qualifier		    	: TCONST									{};
type_specifier			    : TINT										{ current_type = INT_TYPE; }
							| TFLOAT									{ current_type = FLOAT_TYPE; }
							| TVOID										{ current_type = VOID_TYPE; };
function_name		        : TIDENT									{ current_func = $1; update_symbol_kind($1, FUNC); update_symbol_type($1,current_type); };	

abbreviated_param 			: TLPAREN dcl_spec_list TRPAREN				{ printf("abbreviated_param\n"); };						
formal_param		    	: TLPAREN opt_formal_param TRPAREN			{};

opt_formal_param 	        : formal_param_list							{}
							|											{};
formal_param_list       	: param_dcl									{}
							| formal_param_list TCOMMA param_dcl		{};
param_dcl				    : dcl_spec declarator 		    			{ update_symbol_type($2,current_type); update_function_param(current_func,current_type); update_symbol_kind($2,PARAM); };
compound_st		        	: TLBRACE opt_dcl_list opt_stat_list TRBRACE {};
opt_dcl_list				: declaration_list							{}
							|		 									{};
declaration_list		    : declaration								{}
							| declaration_list declaration				{};

declaration				    : dcl_spec init_dcl_list TSEMI				{ current_type = NONE_TYPE; }
							| function_declaration					    {};
declaration_param 			: abbreviated_param | formal_param			{};
function_declaration		: dcl_spec function_name declaration_param TSEMI { printf("function_declaration"); };
dcl_spec_list 				: dcl_spec 									{ update_function_param(current_func,current_type); }
							| dcl_spec_list TCOMMA dcl_spec  			{ update_function_param(current_func,current_type); };
init_dcl_list				: init_declarator							{}
							| init_dcl_list TCOMMA init_declarator		{};
init_declarator			    : declarator								{ update_symbol_type($1, current_type); }
							| declarator TASSIGN TNUMBER				{ if(current_type != INT_TYPE){ yyerror("Type Mismatched. Expected int but float."); }
																			else{ update_symbol_type($1, current_type); } }
							| declarator TASSIGN TFNUMBER 				{ if(current_type != FLOAT_TYPE){ yyerror("Type Mismatched. Expected float but int."); } 
																			else{ update_symbol_type($1, current_type); } };

declarator				    : TIDENT									{ $$ = $1; if(is_declared($1)){ char error_message[256]; 
																				sprintf(error_message, "Aleardy declared identifier %s", $1);
																				yyerror(error_message); } else { update_symbol_kind($1,SCALAR); } }
														| TIDENT TLBRACKET opt_number TRBRACKET		{
																			if ($3 < 0) {
																				yyerror("Error: Array size cannot be negative.");
																			} else {
																				$$ = $1;
																				update_symbol_kind($1, ARRAY);
																			
																			}
																		}
																	;

opt_number				    : TNUMBER { if ($1 < 0) { yyerror("Error: Array size cannot be negative."); $$ = 0; } else { $$ = $1; }}
							|	{ 
									$$ = 0; // 배열 크기 정해지지 않았을 경우 디폴트 크기 0으로 설정
								
								};
							

opt_stat_list				: statement_list							{}
							|											{};
statement_list		    	: statement									{}
							| statement_list statement					{};
statement					: compound_st								{}
							| expression_st								{}
							| if_st										{}
							| while_st									{}
							| return_st									{};
expression_st	    		: opt_expression TSEMI						{};

opt_expression	        	: expression								{}
							|											{};
if_st						: TIF TLPAREN expression TRPAREN statement %prec LOWER_THAN_ELSE		{}
							| TIF TLPAREN expression TRPAREN statement TELSE statement			{};
while_st		    		: TWHILE TLPAREN expression TRPAREN statement{};
return_st					: TRETURN opt_expression TSEMI				{};
expression			    	: assignment_exp							{};
assignment_exp		        : logical_or_exp							{ $$ = $1; }
							| unary_exp TASSIGN assignment_exp			{}
							| unary_exp TADDASSIGN assignment_exp		{}
							| unary_exp TSUBASSIGN assignment_exp		{}
							| unary_exp TMULASSIGN assignment_exp		{}
							| unary_exp TDIVASSIGN assignment_exp		{}
							| unary_exp TMODASSIGN assignment_exp		{};
logical_or_exp   	    	: logical_and_exp         					{ $$ = $1; }
   							| logical_or_exp TOR logical_and_exp   		{};
logical_and_exp   	        : equality_exp         						{ $$ = $1; }
     						| logical_and_exp TAND equality_exp   		{};
equality_exp   			    : relational_exp         					{ $$ = $1; }
      						| equality_exp TEQUAL relational_exp   		{}
     						| equality_exp TNOTEQU relational_exp   	{};
relational_exp              : additive_exp                             { $$ = $1; }
      						| relational_exp '>' additive_exp   		{}
      						| relational_exp '<' additive_exp   		{}
      						| relational_exp TGREATE additive_exp   	{}
      						| relational_exp TLESSE additive_exp   		{};
additive_exp   	    		: multiplicative_exp         				{ $$ = $1; }
      						| additive_exp TADD multiplicative_exp   	{}
      						| additive_exp TSUB multiplicative_exp   	{};
multiplicative_exp          : unary_exp         						{ $$ = $1; }
     						| multiplicative_exp TMUL unary_exp      	{}
      						| multiplicative_exp TDIV unary_exp   		{}
      						| multiplicative_exp TMOD unary_exp   		{};
unary_exp   				: postfix_exp         						{ $$ = $1; }
      						| TSUB unary_exp         					{}
      						| TNOT unary_exp        					{}
      						| TINC unary_exp         					{}
      						| TDEC unary_exp         					{};
postfix_exp 				: primary_exp 								{ $$ = $1; }
							| postfix_exp TLBRACKET expression TRBRACKET{}
							| postfix_exp TLPAREN opt_actual_param TRPAREN { if(!is_func(current_func)){ yyerror("Attempt to call a non-function"); } 
																								else if(!check_param_match(current_func,$3))
																								{
																									yyerror("Parameter not match");
																								} }
							| postfix_exp TINC 							{}
							| postfix_exp TDEC							{};
opt_actual_param 	        : actual_param 								{ $$ = $1; }
							| 											{ $$ = NULL; };
actual_param 			    : actual_param_list 						{ $$ = $1; };
actual_param_list 	        : assignment_exp 							{ Params* new_params = malloc(sizeof(Params));
																			new_params->types[0] = $1; new_params->param_cnt++; $$ = new_params; }
							| actual_param_list TCOMMA assignment_exp 	{ $1->types[$1->param_cnt++] = $3; $$ = $1; };
primary_exp 			    : TIDENT 									{ $$ = get_symbol_type($1); if(!is_declared($1)){
																				char error_message[256]; 
																				sprintf(error_message, "Undeclared identifier %s", $1);
																				yyerror(error_message);
																							} 

																				if(is_func($1)){
																					current_func = $1; 
																				}}
							| TNUMBER 									{ $$ = INT_TYPE; }
							| TFNUMBER 									{ $$ = FLOAT_TYPE; }
							| TLPAREN expression TRPAREN 				{};
%%

void yyerror(char *s)
{
   printf("Error at line %d: %s\n", lineNumber, s);
    total_err_cnt++; 
}

void semantic(int n)
{
	printf("reduced rule number = %d\n", n);
}


