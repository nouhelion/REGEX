// regex of a* b a* (b a* b a* a)

#include <cstring>
#include <ctype.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
void impair(string chaine){
int etat ,i=0;
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
            if (chaine[i]=='b'){
                  etat =0;
                  i++;
            }
            else if (chaine[i]=='a'){
                  etat =1;
                  i++;
            }
            else if(chaine.length() ==i)
            {
                cout<<"valide";
                exit(0);
            }
            else{
                cout<<"error";
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
    impair(cha);
}