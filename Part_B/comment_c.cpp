// Write a program that implements a deterministic finite state machine
// which validates a C-style comment and displays the content of the comment.
// Example:
/* a body of remark */
// Examples: /***/ /*a**b*/ /**A*/

#include <cstring>
#include <ctype.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
void comment(string chaine)
{
    string com;
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
                cout << "!!! Erreur \n\t ";
                exit(1);
            }
            break;
        }

        case 1:
        {
            if (chaine[i] == '*')
            {
                state = 2;
                i++;
            }
            else
            {
                cout << "!!! Erreur ";
                exit(1);
            }
            break;
        }
        case 2:
        {
            if (i == chaine.size())
            {
                cout << "!!! Erreur ";
                exit(1);
            }
            else if (chaine[i] == '*')
            {
                state = 3;
                i++;
            }
            else
            {
                com[j] = chaine[i];
                j++;
                i++;
            }
            break;
        }
        case 3:
        {
            if (i == chaine.size())
            {
                cout << "!!! Erreur ";
                exit(1);
            }
            else if (chaine[i] == '*')
            {
                com[j] = chaine[i];
                j++;
                i++;
            }
            else if (chaine[i] == '/')
            {
                state = 4;
            }
            else
            {
                state = 2;
                com[j] = '*', j++;
                com[j] = chaine[i];
                j++;
                i++;
            }
            break;
        }
        case 4:
        {
            cout << "Le corps du commentaire est: ";
            for (int n = 0; n < j; n++)
                cout << com[n];
            exit(0);
        }
        }
    }
}

int main(int argc, char **argv)
{
    string chaine;
    cout << "Enter the phrase :" << endl;
    getline(cin, chaine);
   comment(chaine);
    return 0;
}