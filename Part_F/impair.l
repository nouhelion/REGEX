%{
    #include <stdio.h>
%}
nb ((a)* b (a)* (b (a)* b (a)*)*)
%%
{nb} { printf("chaine valide");}
%%
int main(){
printf("enter a string : ");
yylex();
return 0;
}
int yywrap(){
return 1;
}