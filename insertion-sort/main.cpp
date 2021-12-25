#include <iostream>

void print(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void sortowanieWstawianie(int arr[], int len)
{
    for (int i = 1; i < len; i++)
    {
        int klucz = arr[i];
        int j = i;
        while(j > 0 && klucz < arr[j-1])
        {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = klucz;
        print(arr, len);
    }
}

int main() {
    int n;
    while (scanf("%d", &n) > 0)
    {
        int *arr = new int[n];
        int key;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &key);
            arr[i] = key;
        }
        sortowanieWstawianie(arr, n);
        printf("\n");
    }
}