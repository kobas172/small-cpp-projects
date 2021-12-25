#include <iostream>
#include <math.h>
#include <string>

struct Liczba {
    std::string liczba;
    int iloscZer;
};

std::string zamiana(int liczba, int n)
{
    char znaki[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string wynik, odpowiedz;
    while (wynik.length() < n)
    {
        int modulo = liczba % 2;
        liczba = liczba / 2;
        wynik += znaki[modulo];
    }
    for (int i = wynik.length()-1; i >= 0; i--)
    {
        odpowiedz += wynik[i];
    }
    return wynik;
}

void licznikZer(Liczba tablica[], int zakres)
{
    for (int i = 0; i < zakres; i++)
    {
        int temp = 0;
        for (int j = 0; j < tablica[i].liczba.length(); j++)
        {
            if (tablica[i].liczba[j] == '1')
                temp++;
        }
        tablica[i].iloscZer = temp;
    }
}

void wypisz (Liczba tablica[], int n, int zakres)
{
    for (int i = n; i >= 0; i--)
    {
         for (int j = zakres-1; j >= 0; j--)
         {
             if (tablica[j].iloscZer == i)
             {
                 std::cout << tablica[j].liczba << std::endl;
             }
         }
    }

}

int main()
{
    int n;
    scanf("%d", &n);
    int zakres = pow(2, n);
    Liczba *tablica = new Liczba[zakres];
    for (int i = 0; i < zakres; i++)
    {
        tablica[i].liczba = zamiana(i, n);
    }
    licznikZer(tablica, zakres);
    wypisz(tablica, n, zakres);

    delete[] tablica;
}