#include <iostream>

void zamiana(int liczba, int system)
{
    if (system == 10)
    {
        printf("%i", liczba);
        return;
    }

    if (system == 1)
    {
        for (int i = 0; i < liczba; ++i)
            printf("1");
        return;
    }

    char znaki[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    std::string wynik;
    while (liczba)
    {
        int modulo = liczba % system;
        liczba = liczba / system;
        wynik += znaki[modulo];
    }
    for (int i = wynik.length() - 1; i >= 0; i--)
    {
        printf("%c", wynik[i]);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    int ilosc;
    int liczba, podstawa;
    scanf("%d", &ilosc);
    for (int i = 0; i < ilosc; i++)
    {
        scanf("%d %d", &liczba, &podstawa);
        zamiana(liczba, podstawa);
        printf("%s", "\n");
    }
}