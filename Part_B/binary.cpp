//Write a program that implements the finite state machine
//deterministic on the alphabet {0, 1} of the words defined by
//Valid words: "01", "10", "01010110"
//Invalid words: "011", "011110", "100"
//REGEX (01|10)+.

#include <cstring>
#include <iostream>
#include <stdlib.h>
using namespace std;
void bNUM(string chaine)
{
    int i = 0, state = 0;
    while (1)
    {
        switch (state)
        {
        case 0:
        {
            if (chaine[i] == '0')
            {
                state = 1;
                i++;
            }
            else if (chaine[i] == '1')
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
            
            if (chaine[i] == '1')
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
            if (chaine[i] == '0')
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
            if (i==chaine.length())
            {
               cout << "valide"<< endl;
                exit(0);
            }
            else if (chaine[i] == '1')
            {
                state = 2;
                i++;
            }
            else if (chaine[i] == '0')
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