//Write a program that validates the words recognized by on the alphabet {0, 1} of
//words that do not contain the string "011".
//Valid examples: "0100010", "1111", "11101", "ɛ"
//Invalid examples: "0101100", "1110110"

#include <cstring>
#include <iostream>
#include <stdlib.h>
using namespace std;
void not011(string chaine)
{
    int i = 0, state = 0;
    while (1)
    {
        switch (state)
        {
        case 0:
        {
            if (chaine.length()==i)
            {
                 cout << "valide" << endl;
                exit(0);
            }
            else if (chaine[i] == '0' )
            {
                state = 1;
                i++;
            }
            else if (chaine[i] == '1')
            {
                state = 0;
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
            if (chaine.length()==i)
            {
                 cout << "valide" << endl;
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
        case 2:
        {
            if (chaine.length()==i)
            {
                 cout << "valide" << endl;
                exit(0);
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
   not011(chaine);
    return 0;
}