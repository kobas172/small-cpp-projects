#include <iostream>

std::string zamiana(int liczba, int system)
{
    std::string odpowiedz;

    if (liczba == 0)
        return "0";

    if (system == 1)
    {
        for (int i = 0; i < liczba; ++i)
            odpowiedz += "1";

        return odpowiedz;
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
        odpowiedz += wynik[i];
    }

    return odpowiedz;
}

int main()
{
    int limit;
    scanf("%i", &limit);

    std::string najwieksza = zamiana(limit - 1, 2);

    int limit_dlugosc = najwieksza.length();

    for (int i = 0; i < limit; ++i)
    {
        std::string x = zamiana(i, 2);

        for (int j = 0; j < limit_dlugosc - x.length(); ++j)
            printf(".");

        printf("%s %i\n", x.c_str(), i);
    }
}