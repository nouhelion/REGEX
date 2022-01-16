//Spaces and tabs should be ignored.

#include <cstring>
#include <ctype.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
int delim(string chaine, int i);
void analyse(string chaine);
int identificateur(string chaine, int i);
int reel(string chaine, int i);
int operel(string chaine, int i);
//verifying if the delim exists in the string chaine
int delim(string chaine, int i)
{
    int state = 0;
    while (1)
    {
        switch (state)
        {
        case 0:
        {
            if (chaine[i] == ' ' || chaine[i] == '\t')
            {
                state = 1;
                i++;
            }
            break;
        }
        case 1:
        {
            if (chaine[i] == ' ' || chaine[i] == '\t')
            {
                i++;
            }
            else
            {
                state = 2;
            }
            break;
        }
        case 2:
        {
            return i;
        }
        }
    }
}
//analysing the chaine and only show the chaine without any \t or spaces
void analyse(string chaine)
{
    int unsigned i;
    int k = 0;
    char copy[100];
    cout << "\n\n les mots et leurs classes de la chaine sont : "
         << "\n\n";
    for (i = 0; i < chaine.length(); i++)
    {
        if (chaine[i] == ' ' || chaine[i] == '\t')
        {
            i = delim(chaine, i);
        }
        copy[k] = chaine[i];
        k++;
    }
    copy[k] = '\0';
    for (i = 0; i < chaine.length(); i++)
    {
        if (isalpha(chaine[i]))
        { 
            i = identificateur(chaine, i);
        }
        if (isdigit(chaine[i]) || (chaine[i] == '+' || chaine[i] == '-'))
        {
            i = reel(chaine, i);
        }
        if (chaine[i] == '>' || chaine[i] == '<' || chaine[i] == '=')
        {
            i = operel(chaine, i);
        }
    }

    cout << "\n\t la chaine traitee est : " << copy << "\n\n";
}
int identificateur(string chaine, int i)
{
    int j, k = i;
    int state = 0;
    while (1)
    {
        switch (state)
        {
        case 0:
        {
            if (isalpha(chaine[i]))
            {
                state = 1;
                i++;
            }
            break;
        }
        case 1:
        {
            if (isalnum(chaine[i]))
            {
                i++;
            }
            else
            {
                state = 2;
            }
            break;
        }
        case 2:
        {
            cout << "\t****> identificateur : ";
            for (j = k; j < i; j++)
            {
                cout << chaine[j];
            }
            cout << endl;
            return i;
        }
        }
    }
}
int reel(string chaine, int i)
{
    int state = 0;
    while (1)
    {
        switch (state)
        {
        case 0:
        {
            if (isdigit(chaine[i]) || (chaine[i] == '-' || chaine[i] == '+'))
            {
                if (isdigit(chaine[i]))
                {
                    state = 2;
                    i++;
                }
                else
                {
                    state = 1;
                    i++;
                }
            }
            break;
        }
        case 1:
        {
            if (isdigit(chaine[i]))
            {
                state = 2;
                i++;
            }
            break;
        }
        case 2:
        {
            if (isdigit(chaine[i]))
            {
                state = 2;
                i++;
            }
            else if (chaine[i] == '.')
            {
                state = 3;
                i++;
            }
            else if (chaine[i] == 'e' || chaine[i] == 'E')
            {
                state = 5;
                i++;
            }
            else
            {
                state = 8;
            }
            break;
        }
        case 3:
        {
            if (isdigit(chaine[i]))
            {
                state = 4;
                i++;
            }
            break;
        }
        case 4:
        {
            if (isdigit(chaine[i]))
            {
                state = 4;
                i++;
            }
            else if (chaine[i] == 'e' || chaine[i] == 'E')
            {
                state = 5;
                i++;
            }
            else
            {
                state = 8;
            }
            break;
        }
        case 5:
        {
            if (isdigit(chaine[i]))
            {
                state = 7;
                i++;
            }
            else if (chaine[i] == '-' || chaine[i] == '+')
            {
                state = 6;
                i++;
            }
            break;
        }
        case 6:
        {
            if (isdigit(chaine[i]))
            {
                state = 7;
                i++;
            }
            break;
        }
        case 7:
        {
            if (isdigit(chaine[i]))
            {
                state = 7;
                i++;
            }
            else
            {
                state = 8;
            }
            break;
        }
        case 8:
        {
            cout << "\t==== NOMBRE : " << endl;
            for (j = k; j < i; j++)
            {
                cout << chaine[j];
            }
            cout << endl;
            return i;
            break;
        }
        }
    }
}
int operel(string chaine, int i)
{
    int state = 0;
    while (1)
    {
        switch (state)
        {
        case 0:
        {
            if (chaine[i] == '>')
            {
                state = 1;
                i++;
            }
            else if (chaine[i] == '<')
            {
                state = 6;
                i++;
            }
            else if (chaine[i] == '=')
            {
                state = 4;
                i++;
            }
            break;
        }
        case 1:
        {
            if (chaine[i] == '=')
            {
                state = 2;
            }
            else
            {
                state = 3;
            }
            break;
        }
        case 2:
        {
            cout << "\t*** OPEREL: PGE\n";
            return i;
            break;
        }
        case 3:
        {
            cout << "\t*** OPEREL: PGQ\n";
            return --i;
        }
        case 4:
        {
            if (chaine[i] == '=')
            {
                state = 5;
            }
            break;
        }
        case 5:
        {
            cout << "\t*** OPEREL: EGA\n";
            return i;
            break;
        }
        case 6:
        {
            if (chaine[i] == '=')
            {
                state = 8;
            }
            else if (chaine[i] == '>')
            {
                state = 7;
            }
            else
            {
                state = 9;
            }
        }
        case 7:
        {

            cout << "\t*** OPEREL: DIF\n";
            return i;
            break;
        }
        case 8:
        {

            cout << "\t*** OPEREL: PPE\n";
            return i;
            break;
        }
        case 9:
        {

            cout << "\t*** OPEREL: PPQ\n";
            return --i;
        }
        }
    }
}
int main(int argc, char **argv)
{
    string chaine;
    cout << "Enter the phrase :" << endl;
    getline(cin, chaine);
    analyse(chaine);
    return 0;
}