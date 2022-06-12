#include <stdio.h>
#include <stdlib.h>


static int intCompare(const void *p1, const void *p2)
{
    unsigned long int_a = * ( (unsigned long*) p1 );
    unsigned long int_b = * ( (unsigned long*) p2 );

    if ( int_a == int_b ) return 0;
    else if ( int_a < int_b ) return -1;
    else return 1;
}


int main()
{
    unsigned long m;
    unsigned long n;
    unsigned long *titans;
    unsigned long *humans;
    unsigned long *result;
    unsigned long count = 0;
    unsigned long i = 0;
    unsigned long j = 0;
    unsigned long k = 0;

    scanf("%lu", &m);
    scanf("%lu", &n);
	if(m > 1000000000 || n > 1000000000 ||m < 1 ||n < 1)
		return 0;
    titans = malloc(sizeof(unsigned long) * m);
    humans = malloc(sizeof(unsigned long) * n);
    result = malloc(sizeof(unsigned long) * m);
    while (i < m)
    {
        scanf("%lu", &titans[i]);
		if(titans[i] > 1000000000)
			return(0);
        i++;
    }
    i = 0;
    while (i < n)
    {
        scanf("%lu", &humans[i]);
		if(humans[i] > 1000000000)
			return (0);
		j = 0;

        while (j < m)
        {
            if(humans[i] > titans[j])
                count++;
			j++;
        }
        result[k++] = count;
		count = 0;

        i++;
    }
    qsort(result, n, sizeof(unsigned long), intCompare);
	for(i = 0; i < k; i++)
		printf("%lu ", result[i]);
	free(humans);
	free(titans);
	free(result);
}