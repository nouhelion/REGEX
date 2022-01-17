%{
    #include <stdio.h>
%}
%%
\+|\-|\*|\/ {printf("%s is a valid string",yytext);}
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