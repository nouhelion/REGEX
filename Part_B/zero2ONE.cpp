//Write a program that validates words recognized 
//by the alphabet {0, 1}
//of words that contain the string "011".
//Valid examples: "011", "10101100", "110101100", "01011"
#include <cstring>
#include <iostream>
#include <stdlib.h>
using namespace std;
void ZERO(string chaine)
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
        case 2:
        {
            if (chaine[i] == '0')
            {
                state = 1;
                i++;
            }
            else if (chaine[i] == '1')
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
    ZERO(chaine);
    return 0;
}