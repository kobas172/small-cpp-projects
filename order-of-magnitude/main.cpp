#include <iostream>
#include <string>

void wypiszrzad(std::string liczby[], int rzedy)
{
    for (int i = 1; i < rzedy; i++)
    {
        std::string pomoc = liczby[i];
        int j = i - 1;
        while (liczby[j].length() > pomoc.length() && j >= 0) {
            liczby[j + 1] = liczby[j];
            j--;

        }
        liczby[j + 1] = pomoc;

    }
}

int main()
{
    int testy, rzedy;
    std::string liczby[50];
    std::cin >> testy;


    for (int i = 0; i < testy; i++)
    {
        std::cin >> rzedy;
        for (int j = 0; j < rzedy; j++) {
            std::cin >> liczby[j];

        }

        wypiszrzad(liczby, rzedy);
        for (int j = 0; j < rzedy; j++)
        {
            std::cout << liczby[j] << " ";
        }
        std::cout << std::endl;
    }
}