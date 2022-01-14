// Write a program that implements an automaton that indicates if a string
// of ‘a’ consists of an even or odd number of ‘a’.
#include <cstring>
#include <iostream>
#include <stdlib.h>
using namespace std;
void number(string chaine)
{
    int i = 0, state = 0;
    while (1)
    {
        switch (state)
        {
        case 0:
            {if (chaine[i] == 'a')
            {
                state = 1;
                i++;
            }
            else if (i == chaine.length())
            {
                cout << "It consists of an even number of a" << endl;
                exit(0);
            }
            else{
                cout << "It's not < a > " << endl;
                exit(1);
            }
            break;}
        case 1:
            {if (chaine[i] == 'a')
            {
                state = 0;
                i++;
            }
            else if (i == chaine.length())
            {
                cout << "It consists of an odd number of a" << endl;
                exit(0);
            }
            else{
                cout << "It's not < a > " << endl;
                exit(1);
            }
            break;}
        }
    }
}

int main(int argc, char **argv)
{
    string chaine;
    cout << "Enter the phrase :" << endl;
    getline(cin, chaine);
    number(chaine);
    return 0;
}