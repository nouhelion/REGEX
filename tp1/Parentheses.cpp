//
// Created by HP Omen on 11/01/2022.
//

#include<stdio.h>
#include<conio.h> // pour getch()
#include<string.h>
int main() {
    int i, // indice pour parcourir la chaine
    j=0; //entier qui s'incrémente s'il rencontre '('
// et se decremente si ')'
    ch[30]; //la chaine lue au clavier
    printf("Donnez votre chaine a analyser:\t");
    gets(ch);
    i=0;
    while (i<strlen(ch)){//boucle qui teste la fin de la chaine
        if (ch[i]=='(') ++j;
        else if (c==')') --j;
        i++;
    }
    if(!j) printf("les parenthses sont bien equilibrees");
    else if(j<0)
        printf("il manque %d parenthese ouvrante",-j);
    else printf("il manque %d parenthese fermante",j);
    getch();
    return 0;
}

