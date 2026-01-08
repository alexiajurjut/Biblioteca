// Tema 22. Aplicație pentru gestionarea unei biblioteci mici

// Veți crea un sistem complet de management pentru o bibliotecă personală sau mică, cu împrumuturi, returnări și căutări avansate.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Carte {
    string titlu;
    string autor;
    bool imprumutata;
};
//obiecte tip "Carte" in lista "carti"
vector<Carte> carti;


int main()
{
    int opt;

    while (true)
    {
        cout << "\nBiblioteca\n";
        cout << "1. Adauga carte\n";
        cout << "2. Listeaza carti\n";
        cout << "3. Imprumuta o carte\n";
        cout << "4. Returneaza o carte\n";
        cout << "0. Iesire din meniu\n";
        cout << "Alege optiunea: \n";
        cin >> opt;

        if (opt == 1)
        {
            cin.ignore(); //Clean enter

            cout << "Titlu: ";
            Carte c;
            getline(cin, c.titlu);

            cout << "Autor: ";
            getline(cin, c.autor);

            c.imprumutata = false;

            carti.push_back(c);
            cout << "Cartea a fost adaugata";
        }
        else if (opt == 2)
        {
            if (carti.size() == 0)
            {
                cout << "Nu exista carti de listat";
            }
            else
            {
                for (int i = 0; i < carti.size(); i++)
                {
                    cout << i << ". Titlu: " << carti[i].titlu << "\n";
                    cout << "Autor : " << carti[i].autor << "\n";
                    cout << "Stare: ";
                    if (carti[i].imprumutata)
                        cout << "Imprumutata\n";
                    else
                        cout << "Disponibila pt imprumut\n";
                    cout << "\n";
                }
            }
        }
        else if (opt == 3)
        {
            cin.ignore();
            string titlu;
            string autor;

            cout << "Introduceti datele cartii pe care doriti sa o imprumutati\n";
            cout << "Titlu: ";
            getline(cin, titlu);
            cout << "Autor: ";
            getline(cin, autor);

            bool gasita = false;

            for (int i = 0; i < carti.size(); i++)
            {
                if (carti[i].titlu == titlu && carti[i].autor == autor)
                {
                    gasita = true;
                    if (carti[i].imprumutata == false)
                    {
                        carti[i].imprumutata = true;
                        cout << "Ai imprumutat cartea cu succes.\n";
                    }
                    else
                        cout << "Ne pare rau, cartea a fost deja imprumutata\n";
                }
            }
            if (!gasita)
                cout << "Cartea dvs. nu a fost gasita\n";
        }
        //retur carte
        else if (opt == 4)
        {
            cin.ignore();
            string titlu;
            string autor;
            cout << "Introduceti datele cartii pe care doriti sa o returnati\n";
            cout << "Titlu: ";
            getline(cin, titlu);
            cout << "Autor: ";
            getline(cin, autor);

            bool gasita = false;

            for (int i = 0; i < carti.size(); i++)
            {
                if (carti[i].titlu == titlu && carti[i].autor == autor)
                {
                    gasita = true;
                    if (carti[i].imprumutata == true)
                    {
                        carti[i].imprumutata = false;
                        cout << "Ai returnat cartea cu succes\n";
                    }
                    else
                        cout << "Cartea introdusa nu este imprumutata\n";
                }
            }
            if (!gasita)
                cout << "Cartea dvs. nu a fost gasita\n";
        }
    }
}
