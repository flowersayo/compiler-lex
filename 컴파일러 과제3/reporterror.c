#include "tn.h"

#define MAX_ERROR_MSG 100
char error_message[MAX_ERROR_MSG]; // 에러 메세지를 담는 변수 (메인에서 error_message를 출력한다.)

void ReportError(ERRORtypes err)
{
	switch (err)
	{
	case overst:
		strncpy(error_message, "overflow", MAX_ERROR_MSG);
		break;
	case illid_long:
		strncpy(error_message, "too long identifier", MAX_ERROR_MSG);
		break;
	case illch:
		snprintf(error_message, MAX_ERROR_MSG, "%s illegal character", yytext); // 허용되지 않은 문자가 들어올 경우 에러 발생
		break;
	case illid_digit:
		snprintf(error_message, MAX_ERROR_MSG, "%s start with digit", yytext);
		break;
	case real_num:
		strncpy(error_message, "real number is not allowed", MAX_ERROR_MSG);
		// 실수가 들어올 경우 에러 발생. Floating Point 경우는 제외하였음.
	}
}