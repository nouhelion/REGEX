//Write a program that implements a deterministic finite state machine
//which validates a C++-like comment and displays the contents of the
//remark.
//Example: // a comment body \n

#include <cstring>
#include <ctype.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
void email(string chaine)
{
    string comment;
    int i = 0, j = 0, state = 0;
    while (1)
    {
        switch (state)
        {
        case 0:
        {
            if (chaine[i] == '/')
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

            if (chaine[i] == '/')
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
            if (isalnum(chaine[i]))
            {
                state = 2;
                i++;
            }
            else if (chaine[i] == '\n' || i == chaine.length())
            {
                state = 3;
                i++;
            }
            else
            {
                comment[j] = chaine[i];
                j++;
                i++;
            }
            break;
        }
        case 3:
        {
            cout << "Le corps du commentaire est: ";
            for (int n = 0; n < j; n++)
                cout << comment[n];
            // for(i=2; i<chaine.size(); i++) cout<< chaine[i]);
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