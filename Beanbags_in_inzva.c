#include <stdio.h>
#include <stdlib.h>


int main()
{
    unsigned long n;
    unsigned long *arr;
    unsigned long i = 0;
    unsigned long min = 0;

    scanf("%lu", &n);
    arr = malloc(sizeof(unsigned long) * n);
    while (i < n)
    {
        scanf("%lu", &arr[i]);
        if(arr[i] < 1 || arr[i] > 100000000)
            return 0;
        i++;
    }
    i = 0;
    min = arr[i];
    while (i < n)
    {
        if (min > (arr[i] & arr[i + 1]) && (i + 1 < n))
            min = arr[i] & arr[i + 1];
        i++;
    }
    printf("%lu\n", min);    
}