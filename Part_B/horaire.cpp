//We want to recognize a schedule in the form:
//12:15 for noon and 15 minutes.
//Write a program that implements this automaton.
//regex => ((0|1)[0-9]|2[0-3]):[0-5][0-9]
//isdigit(c)        0-9

#include <cstring>
#include <iostream>
#include <stdlib.h>
using namespace std;
void horaire(string chaine)
{
    int i = 0, state = 0;
    while (1)
    {
        switch (state)
        {
        case 0:
        {
            if (chaine[i] == '0' || chaine[i] == '1')
            {
                state = 1;
                i++;
            }
            else if (chaine[i] == '2')
            {
                state = 2;
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
            if (isdigit(chaine[i]))
            {
                state = 3;
                i++;
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
            if (chaine[i] >= '0' && chaine[i] <= '3')
            {
                state = 3;
                i++;
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
            if (chaine[i] == ':' )
            {
                state = 4;
                i++;
            }
            else
            {
                cout << "erreur" << endl;
                exit(1);
            }
            break;
        }
        case 4:
        {
            if (chaine[i] >= '0' && chaine[i] <= '3')
            {
                state = 5;
                i++;
            }
            else
            {
                cout << "erreur" << endl;
                exit(1);
            }
            break;
        }
        case 5:
        {
            if (isdigit(chaine[i]))
            {
                state = 6;
                i++;
            }
            else
            {
                cout << "erreur" << endl;
                exit(1);
            }
            break;
        }
        case 6:
        {
            if (chaine.length() ==i)
            {
                cout << "valide" << endl;
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
    horaire(chaine);
    return 0;
}