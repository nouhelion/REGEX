%{
#include <stdio.h>    
%}
delim [ \t]
bl    {delim}+
lettre [a-zA-Z]
chiffre [0-9]
id {lettre}({lettre}|{chiffre})*
nb (\+|\-)?{chiffre}+(\.{chiffre}+)?((e|E)(\+|\-)?{chiffre}+)?
%%
{bl} {/* supprimer de la sortie */}
sinon {printf("\n Mot cle: ELSE\n");}
si {printf("\n Mot cle: IF\n");}
alors {printf("\n Mot cle: THEN\n");}
{id} {printf("\n Identificateur:%s\n",yytext);}
{nb} {printf("\n Nombre:%s\n",yytext);}
"<=" {printf("\n Operateur relationnel: PPE\n");}
"<>" {printf("\n Operateur relationnel: DIF\n");}
"<" {printf("\n Operateur relationnel: PPQ\n");}
">=" {printf("\n Operateur relationnel: PGE\n");}
">" {printf("\n Operateur relationnel: PGQ\n");}
"==" {printf("\n Operateur relationnel: EGA\n");}
"(" {printf("\n PO\n");}
")" {printf("\n PF\n");}
\n {return 0;}
. {printf("\n%s: Caractère non reconnu\n",yytext);}
%%
int main(){
printf("enter a string : ");
yylex();
return 0;
}
int yywrap(){
return 1;
}