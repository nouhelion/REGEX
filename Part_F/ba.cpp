// regex of (ba) +b

#include <cstring>
#include <ctype.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
void ba(string chaine){
int etat ,i=0;
int n=0;
while(1){
    switch(etat){
        case 0 :{
            if (chaine[i]=='a'){
                  etat =0;
                  i++;
            }
            else if (chaine[i]=='b'){
                  etat =1;
                  i++;
            }
            else{
                cout<<"error";
                exit(1);
            }
        }
        case 1 :{
            if (chaine[i]=='a'){
                  etat =2;
                  n++;
                  i++;
            }
            else{
                cout<<"error";
                exit(1);
            }
        }
        case 2 :{
            if (chaine[i]=='b'){
                  etat =3;
                  i++;
            }
            else{
                cout<<"chaine valide :non";
                exit(1);
            }
        }
        case 3 :{
            if (chaine[i]=='b'){
                  etat =1;
                  i++;
            }
            else if (chaine[i]=='a'){
                  etat =0;
                  n++;
                  i++;
            }
            else if(chaine.length() ==i){
                cout<<"chaine valide et contient : "<<n<<" ba "<<endl;
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
    ba(cha);
}