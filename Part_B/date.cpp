//We want to recognize a date in the form:
//03/02 for February 3, limited to the current year.
//For simplicity, we consider that each month is made up
//30 days.
//Write a program that implements this automaton.
//regex => (0[1-9])|([1-2][0-9])|(30)) / (0[1-9] | 1[0-2])
//isdigit(c)        0-9

#include <cstring>
#include <iostream>
#include <stdlib.h>
using namespace std;
void date(string chaine)
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
                state = 2;
                i++;
            }
            else if (chaine[i] == '1' || chaine[i] == '2')
            {
                state = 1;
                i++;
            }
            else if (chaine[i] == '3')
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
        case 1:
        {
            if (isdigit(chaine[i]))
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
        case 2:
        {
            if (chaine[i] >= '1' && chaine[i] <= '9')
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
        case 3:
        {
            if (chaine[i] == '0' )
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
            if (chaine[i] == '/')
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
            if (chaine[i] == '0')
            {
                state = 6;
                i++;
            }
            else if (chaine[i] == '1')
            {
                state = 7;
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
             if (chaine[i] >= '1' && chaine[i] <= '9')
            {
                state = 8;
                i++;
            }
            else
            {
                cout << "erreur" << endl;
                exit(1);
            }
            break;
        }
        case 7:
        {
             if (chaine[i] >= '0' && chaine[i] <= '2')
            {
                state = 8;
                i++;
            }
            else
            {
                cout << "erreur" << endl;
                exit(1);
            }
            break;
        }
        case 8:
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
    date(chaine);
    return 0;
}