%{
    #include <stdio.h>
%}
%% 
\/\/(.)*\n {printf("comment correct in c++\n");}
\/\*(.|\n)*\*\/ {printf("comment correct in c\n");}
.+ {printf("comment not correct \n");}
%%
int main() {
FILE *file;
	printf("enter a comment\n");
    yylex();
    return 0;
}
int yywrap(){
    return 1;
}