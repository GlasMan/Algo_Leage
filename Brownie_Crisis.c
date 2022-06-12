#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int n;
    unsigned int i;
    unsigned int j;
    unsigned int s;
    char *arr;

    scanf("%d", &n);
    if(n < 1 || n > 100000)
        return 0;
    arr = malloc(sizeof(char) * n);
    scanf("%s", arr);
    i = 0;
    j = 0;
    s = 1;
    while (arr[i])
    {
        if(arr[i] < arr[i + 1] && arr[i + 1])
        {
            printf("%d", s);
            return (0);
        }
        i++;
        s++;
    }
}