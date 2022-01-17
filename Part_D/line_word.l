%{
    #include <stdio.h>
    int lines=1;
    int characters=0;
%}
%% 
[ ^\t ] {characters++;}
\n     {lines++;}
%%
int main() {
    FILE *file;
    char name[100];
    printf("enter name of file : ");
    gets(name);
    file=fopen(name, "r+");
    yyin=file;
    yylex();
    fclose(file);
    printf("\nnumber of characters : %d\n",characters);
    printf("\nnumber of lines : %d\n",lines);
	return 0;
}
int yywrap(){
    return 1;
}