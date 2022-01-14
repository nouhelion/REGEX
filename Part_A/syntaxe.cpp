// Write a program that has the effect of synthesizing
// arithmetic expressions composed of the single digit 4,
// four operators +, -, *, / and parentheses (,).
// For example: we can write: "2 = (4+4)/4" and "5=4+(4/4)".
// We test this program for the integers from 1 to 19.
#include <cstring>
#include <iostream>
#include <stdlib.h>
using namespace std;
void Reste(int n)
{
    switch (n)
    {
    case 1:
        cout << "4/4";
        break;
    case 2:
        cout << "(4+4)/4";
        break;
    case 3:
        cout << "4-(4/4)";
        break;
    case 4:
        cout << "4";
        break;
    }
}
void synthese_4(int n)
{
    if (n <= 4)
        Reste(n);
    else if (n > 4)
    {
        if (n < 8)
            cout << "4";
        else
        {
            cout << "4*(";
            synthese_4(n / 4);
            cout << ")";
        }
        if (n % 4)
        {
            cout << "+(";
            Reste(n % 4);
            cout << ")";
        }
    }
}
int main(int argc, char **argv)
{
    int n;
    cout << "Donner un entier : ";
    cin >> n;
    cout << "Sa synthese avec 4 est : ";
    synthese_4(n);
    cout << "\n";
    return 0;
}