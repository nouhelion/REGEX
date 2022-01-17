%{
    #include <stdio.h>
    int counter=0;
%}
%%
[^\t \n]+ {counter++;}
\n   {printf("%d words exist",counter);
exit(0);}
%%
 int main(){
     printf("enter a string");
     yylex();
     return 0;
 }
 int yywrap(){
     return 1;
 }