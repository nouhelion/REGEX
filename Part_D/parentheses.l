%{
    #include <stdio.h>
    int counter=0;
%}
%%
"(" {counter++;}
")" {counter--;}
%%