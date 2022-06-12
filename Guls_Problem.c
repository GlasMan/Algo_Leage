//Even our problem setter cannot nail this everytime. No giving up!
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <stdio.h>
#include <stdlib.h>

static int intCompare(const void *p1, const void *p2)
{
    unsigned int int_a = * ( (unsigned int*) p1 );
    unsigned int int_b = * ( (unsigned int*) p2 );

    if ( int_a == int_b ) return 0;
    else if ( int_a < int_b ) return -1;
    else return 1;
}



int main()
{
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int p = 0;
    unsigned int temp = 0;
    int c = 0;
    unsigned int keep = 0;
    unsigned int *arr = malloc(sizeof(unsigned int) * 7);
    unsigned int *k = malloc(sizeof(unsigned int) * 2);
    while (i < 7)
    {
        scanf("%d", &arr[i]);
        if(arr[i] > 1000000 ||arr[i] < 1)
            return (0);
        i++;
    }
    i = 0;
    //qsort(arr, 7, sizeof(unsigned int), intCompare);
    while (i < 7)
    {
        j = 0;
        while (j < 7)
        {
            keep = arr[i] + arr[j];
            temp = arr[j];
            p = 0;
            while (p < 8)
            {
                if(arr[p] == keep)
                {
                    k[0] = arr[i];
                    k[1] = temp;
                    c++;
                    break;
                }
                if(c == 7)
                {
                    if(k[1] > k[0])
                    {
                        printf("%d", k[1]);
                        return (0);
                    }
                    printf("%d", k[0]);
                    return(0);
                }
                p++;
            }
            j++;
        }
        i++;
    }
    if(k[1] > k[0])
    {
        printf("%d", k[1]);
        return (0);
    }
    printf("%d", k[0]);
}