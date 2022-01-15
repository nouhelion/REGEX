//Écrire un programme qui implante cet automate et donne
//le nombre de ‘b’ dans la chaine.
//Exemples de mots valides : "aa", "aba", "a"
//Mots non valides : "abb", "ab"
//REGEX a(b)*a|a

#include <cstring>
#include <iostream>
#include <stdlib.h>
using namespace std;
void bNUM(string chaine)
{
    int i = 0,b=0, state = 0;
    while (1)
    {
        switch (state)
        {
        case 0:
        {
            if (chaine[i] == 'a')
            {
                state = 1;
                i++;
            }
            else
            {
                cout << "erreur" << endl;
                exit(1);
            }
            break;
        }
        case 1:
        {
            if (i==chaine.length())
            {
                cout << "valide with "<<b<<" b" << endl;
                exit(0);
            }
            else if (chaine[i] == 'a')
            {
                 state = 3;
                i++;
            }
             else if (chaine[i] == 'b')
            {
                 state = 2;
                 i++;
                 b++;
            }
            else
            {
                cout << "erreur" << endl;
                exit(1);
            }
            break;
        }
        case 2:
        {
           if (chaine[i] == 'a')
            {
                 state = 3;
                i++;
            }
             else if (chaine[i] == 'b')
            {
                 state = 2;
                 i++;
                 b++;
            }
            else
            {
                cout << "erreur" << endl;
                exit(1);
            }
            break;
        }
        case 3:
        {
             if (i==chaine.length())
            {
               cout << "valide with "<<b<<" b" << endl;
                exit(0);
            }
            else
            {
                cout << "erreur" << endl;
                exit(1);
            }
            break;
        }
        }
    }
}

int main(int argc, char **argv)
{
    string chaine;
    cout << "Enter the phrase :" << endl;
    getline(cin, chaine);
    bNUM(chaine);
    return 0;
}