%{
#include <math.h>
#include "b.tab.h"
%}
nombre [0-9]+
%%
{nombre} {yylval=atoi(yytext); return NOMBRE;}
"\n" {return FIN;}
"+" {return PLUS;}
"-" {return MOINS;}
. { }
%%
int yywrap(void) {
return 1;
}