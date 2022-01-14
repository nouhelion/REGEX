// regex of having at least 2 'b' in a chaine is
//  => (a|b)* b (a|b)* b (a|b)*
// Write a program for this automaton that gives
// the number of 'b' in the string.

#include <cstring>
#include <iostream>
#include <stdlib.h>
using namespace std;
void twobAT(string chaine)
{
    int i = 0, b = 0, state = 0;
    while (1)
    {
        switch (state)
        {
        case 0:
        {
            if (chaine[i] == 'a')
            {
                state = 0;
                i++;
            }
            else if (chaine[i] == 'b')
            {
                state = 1;
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
        case 1:
        {
            if (chaine[i] == 'a')
            {
                state = 1;
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
                state = 2;
                i++;
            }
            else if (chaine[i] == 'b')
            {
                state = 2;
                i++;
                b++;
            }
            else if (chaine.length() == i)
            {
                cout << "le nombre de b est : " << b << endl;
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
    twobAT(chaine);
    return 0;
}