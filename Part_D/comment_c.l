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
	char name[100];
	printf("name of the file : ");
	gets(name);
	file = fopen(name,"r+");
	yyin=file;
	yylex();
	fclose(file);
	return 0;
}
int yywrap(){
    return 1;
}