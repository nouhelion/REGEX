%{
#include <stdio.h>
%}
%% 
[ \t]+ {/*delete all the spaces and tabulations*/}
bslama {exit(0);}
%% 
int main()
{
    printf("enter a string");
    yylex();
    return 0;
}
int yywrap(){
    return 1;
}

