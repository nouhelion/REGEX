%{
    #include <stdio.h>
%}
%%
"cad" {printf("c'est à dire\n");}
"ssi" {printf("si et seulement si\n");}
"afd" {printf("automate à états finis déterministe\n");}
\n {exit(0);}
%%
int main() {
    printf("enter a string");
    yylex();
    return 0;
}
int yywrap(){
    return 1;
}
