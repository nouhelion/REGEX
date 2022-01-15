#include <iostream>
using namespace std;
int main()
{
    string chaine;
    int unsigned i = 0, etat = 0;
    cout << "donnez un commentaire en C ou C++ \n";
    getline(cin, chaine);
    while (true)
    {
        switch (etat)
        {
        case 0:
        {
            if (chaine[i] == '/')
            {
                etat = 1;
                i++;
            }
            else
            {
                cout << "!!! Erreur \n\t ";
                return 1;
            }
            break;
        }
        case 1:
        {
            if (chaine[i] == '*')
            {
                etat = 2;
                i++;
            }
            else if (chaine[i] == '/')
            {
                etat = 5;
                i++;
            }
            else
            {
                cout << "!!! Erreur ";
                return 1;
            }
            break;
        }
        case 2:
        {
            if (i == chaine.size())
            {
                cout << "!!! Erreur ";
                return 1;
            }
            else if (chaine[i] == '*')
            {
                etat = 3;
                i++;
            }
            else
            {
                i++;
            }
            break;
        }
        case 3:
        {
            if (i == chaine.size())
            {
                cout << "!!! Erreur ";
                return 1;
            }
            else if (chaine[i] == '*')
            {
                i++;
            }
            else if (chaine[i] == '/')
            {
                etat = 4;
                i++;
            }
            else
            {
                i++;
            }
            break;
        }
        case 4:
        {
            cout << "Le corps du commentaire est: ";
            for (int n = 2; n < i - 2; n++)
                cout << chaine[n];
            return 0;
        }
        case 5:
        {
            if (chaine[i] == '\n' || i == chaine.size())
            {
                etat = 6;
            }
            else
            {
                i++;
            }
            break;
        }
        case 6:
        {
            printf("Le corps du commentaire est: ");
            for (int n = 2; n <= i; n++)
                cout << chaine[n];
            cout << "\n\t";
            return 0;
        }
            
        }
    }
    return 0;
}