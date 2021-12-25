#include <iostream>

void print(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void zamianaSort(int arr[], int len)
{
    bool toPrint = false;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                toPrint = true;
            }
        }
        if (toPrint)
        {
            print(arr, len);
            toPrint = false;
        }
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
        zamianaSort(arr, n);
        printf("\n");
    }
}