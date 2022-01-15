//Write a program that implements the automaton associated with a shape
//simplified to an email address.
//l for letter and c for number with (l|c)+ = (l|c) (l|c)*
//Examples of valid addresses: a@b , lastname.firstname@gmail.com,
//a4.b45.fg@12A.fg.DD4.C6
//Using the <ctype.h> library with isalnum(car_a_traiter);
//REGEX => (l|c)+(.(l|c)+)*@(l|c)+(.(l|c)+)*
//isalpha(c)        A-Z, a-z
//isalnum(c)        0-9, A-Z, a-z

#include <cstring>
#include <ctype.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
void email(string chaine)
{
    int i = 0, state = 0;
    while (1)
    {
        switch (state)
        {
        case 0:
        {
            if (isalnum(chaine[i]))
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
            
            if (isalnum(chaine[i]))
            {
                state = 1;
                i++;
            }
            else if (chaine[i]=='.')
            {
                state = 0;
                i++;
            }
            else if (chaine[i]=='@')
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
            if (isalnum(chaine[i]))
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
            else if (isalnum(chaine[i]))
            {
                state = 3;
                i++;
            }
            else if (chaine[i] == '.')
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
        }
    }
}

int main(int argc, char **argv)
{
    string chaine;
    cout << "Enter the phrase :" << endl;
    getline(cin, chaine);
    email(chaine);
    return 0;
}