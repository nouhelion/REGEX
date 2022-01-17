%{
    #include <stdio.h>
%}
%% 
^[\t ]+\n { }
[\t ]+ {printf(" ");}
[^\t\n ]+ { }
[\t ]+\n { }
%%
int main(){
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