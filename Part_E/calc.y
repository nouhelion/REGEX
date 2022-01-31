%{
#include <stdio.h>
int yyerror(char *s);
int yylex();
%}
%token FIN NOMBRE
%left PLUS MOINS
%start R
%%
R : E FIN {printf(" Resultat = %d",$1);return 0;}
;
E : E PLUS T {$$=$1+$3;}
| E MOINS T {$$=$1-$3;}
| T {$$=$1;}
;
T : NOMBRE
;
%%
int yyerror(char *s) {
printf("%s",s);
return 1;
}
int main() {
printf(" Donner une expression arithmetique : ");
yyparse();
return 0;
}