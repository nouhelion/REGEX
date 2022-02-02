%{
    #include <stdio.h>
%}
%%
^\n {/* supprimer les lignes vides */}
"mauvais" {printf("bon");}
[+-]?[0-9]+(.[0-9]+)?((e|E)(+|-)?[0-9]+)?  { printf("nombre reel valide");}
\"(.)*\" { printf("chaine valide dans c++");}
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