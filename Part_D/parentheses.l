%{
    #include <stdio.h>
    int counter=0;
%}
%%
"(" {counter++;}
")" {counter--;}
\n {
    if (counter==0)
     printf("\nCorret\n");
    else if (counter>0)
     printf("\n%d closed parentheses are missing \n",counter);
     else 
     printf("\n%d open parentheses are missing \n",-counter);
     exit(0);
}
%%
int main() {
    printf("enter a string");
    yylex();
    return 0;
}
int yywrap(){
    return 1;
}