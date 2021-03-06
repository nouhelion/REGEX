// what we supposed to do is below here
// Write a program that checks that the
// parentheses of a string, typed on the keyboard, are
// well balanced.
//  The program should display one of 3 messages:
//  Parentheses are well balanced
//  Missing, 'n' opening parentheses
//  missing, 'n' closing parentheses
#include <cstring>
#include <iostream>
#include <stdlib.h>
using namespace std;
void parentheses(string chaine)
{
    int i = 0, j = 0;
    while (i < chaine.length())
    {
        if (chaine[i] == '(')
            ++j;
        else if (chaine[i] == ')')
            --j;
        i++;
    }
    if (!j)
        cout << "Parentheses are well balanced" << endl;
    else if (j < 0)
        cout << "missing, " << -j << " opening parentheses " << endl;
    else
        cout << "missing, " << j << " closing parentheses " << endl;
}
int main(int argc, char **argv)
{
    string chaine;
    cout << "Enter the phrase :" << endl;
    getline(cin, chaine);
    parentheses(chaine);
    return 0;
}