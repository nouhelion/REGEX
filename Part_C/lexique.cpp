//Spaces and tabs should be ignored.

#include <cstring>
#include <ctype.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
int delim(string chaine, int i);
void analyse(string chaine);
int identificateur(string chaine, int i);
//verifying if the delim exists in the string chaine
int delim(string chaine, int i){
 int state=0;
 while(1){
     switch(state){
         case 0: {
             if(chaine[i]==' '|| chaine[i] == '\t')
             {
                 state=1;
                 i++;
             }
             break;
         }
         case 1: {
             if(chaine[i]==' '|| chaine[i] == '\t')
             {
                 i++;
             }
             else 
             {
                state=2;
             }
             break;
         }
          case 2 : {
            return i;
         }
     }
 }
}
//analysing the chaine and only show the chaine without any \t or spaces 
void analyse(string chaine){
    int unsigned n;
    int k = 0;
    char copy[100];
    for(n=0;n<chaine.length();n++){
       if(chaine[n]==' '|| chaine[n] == '\t')
             {
                n=delim(chaine,n);
             }
             copy[k]=chaine[n];
             k++;
    }
    copy[n]='\0';
    cout<<copy<<endl;
}
int identificateur(string chaine, int i){
    
}
int main(int argc, char **argv)
{
    string chaine;
    cout << "Enter the phrase :" << endl;
    getline(cin, chaine);
    analyse(chaine);
    return 0;
}