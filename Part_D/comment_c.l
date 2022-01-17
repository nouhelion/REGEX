%{
    #include <stdio.h>
%}
%% 
\/\/(.)*\n {printf("comment correct in c++\n");}
\/\*(.|\n)*\*\/ {printf("comment correct in c++\n");}
.+ {printf("comment not correct in c++\n");}
%%
int main() {
printf("enter a string \n");
yylex();
return 0;
}
int yywrap(){
    return 1;
}