// regex of ab (c)*

#include <cstring>
#include <ctype.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
void chaine(string chaine){
int etat ,i=0;
while(1){
    switch(etat){
        case 0 :{
            if (chaine[i]=='a'){
                  etat =1;
                  i++;
            }
            else{
                cout<<"chaine valide :non";
                exit(1);
            }
        }
        case 1 :{
            if (chaine[i]=='b'){
                  etat =2;
                  i++;
            }
            else{
                cout<<"chaine valide :non";
                exit(1);
            }
        }
        case 2 :{
            if (chaine[i]=='c'){
                  i++;
            }
            else if(chaine.length() ==i){
                cout<<"chaine valide :oui";
                exit(0);
            }
            else{
                cout<<"chaine valide :non";
                exit(1);
            }
        }
    }
}
}
int main(int argc, char **argv){
    string cha;
    cout << "Enter the phrase"<<endl;
    getline(cin, cha);
    chaine(cha);
}