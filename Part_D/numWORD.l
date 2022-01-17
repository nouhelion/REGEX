%{
    #include <stdio.h>
    int counter=0;
%}
%%
[^\t \n]+ {counter++;}
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
	printf("\nnumber of words : %d\n",counter);
	return 0;
 }
 int yywrap(){
     return 1;
 }