//Write a program that implements positive integers multiple of 10, without zeros
//unnecessary.
//Valid integers: "0", "1000", "30050", "1500"
//Invalid integer: "00340"
//REGEX 0|[1-9][0-9]*0

#include <cstring>
#include <iostream>
#include <stdlib.h>
using namespace std;
void UNZero(string chaine)
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
                state = 3;
                i++;
            }
            else if (chaine[i] >= '1' && chaine[i] <= '9')
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
          if (chaine[i] >= '1' && chaine[i] <= '9')
            {
                state = 1;
                i++;
            }
            else if (chaine[i] == '0')
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
                state = 2;
                i++;
            }
             else if (chaine[i] >= '1' && chaine[i] <= '9')
            {
                state = 1;
                i++;
            }
            else if (i==chaine.length())
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
    UNZero(chaine);
    return 0;
}