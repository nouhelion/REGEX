%{
    #include <stdio.h>
%}
%%
\+|\-|\*|\/ {printf("%s is a valid string",yytext);}
FF+ {printf("%s is a valid string with minimum of 2 F",yytext);}
(ab)(ab)+ {printf("%s is a valid string of two ab minimum",yytext);}
[A-Za-z0-9]{3} {printf("%s is a valid string of numbers and lettes of 3 length",yytext);}
\"(.)*\" {printf("%s is a valid string in c",yytext);}
. {printf("%s is not a valid string");}
%%
int main(){
printf("enter a string : ");
yylex();
return 0;
}
int yywrap(){
return 1;
}