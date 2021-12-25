#include <iostream>

void printQS(int arr[], int len, int l, int q, int r)
{
    printf("%d-%d-%d ", l, q, r);
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int partition(int arr[], int first, int len)
{
    int pivot = arr[first];
    int index = first-1;
    int second = len+1;
    while (true)
    {
        while (true)
        {
            index++;
            if (arr[index] >= pivot)
                break;
        }
        while (true)
        {
            second--;
            if (arr[second] <= pivot)
                break;
        }
        if (index < second)
        {
            int temp = arr[index];
            arr[index] = arr[second];
            arr[second] = temp;
        }
        else
        {
            return second;
        }
    }
}

void sortowanieSzybkie(int arr[], int first, int len)
{
    if (first < len)
    {
        int q = partition(arr, first, len);
        //printQS(arr, len+1, first, q, len);
        printf("%d-%d-%d ", first, q, len);
        for(int i = first; i <= len; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        sortowanieSzybkie(arr, first, q);
        sortowanieSzybkie(arr, q+1, len);
    }
    else if (first == len)
    {
        int q = partition(arr, first, len);
        printf("%d %d\n", q, arr[q]);
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
        sortowanieSzybkie(arr,0, n-1);
        printf("\n");
    }
}