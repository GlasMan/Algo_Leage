#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int len = 0;

typedef struct s_list
{
    int x;
    struct  s_list  *next;
}   t_list;


void create_list(t_list *list)
{
    int i;

    i = 1;
    while (i <= 5)
    {
        list->x = i;
        list->next = malloc(sizeof(t_list));
        list = list->next;
        i++;
    }
    list->next = NULL;
}

t_list  *get_last(t_list *list)
{
    while (list->next->next != NULL)
    {
        list = list->next;
        len++;
    }
    return (list);
}

t_list  *get_last2(t_list *list, int len)
{
    int i = 0;
    while (i < len - 1)
    {
        list = list->next;
        i++;
    }
    return(list);
}

t_list  *rev_list(t_list *list)
{
    int i;
    t_list *p, *last;

    last = get_last(list);
    p = last;
    i = 0;
    while (i < len)
    {
        last->next = get_last2(list, (len - i++));
        last = last->next;
    }
    last->next = NULL;
    list = p;
    return(list);
}

int main()
{
    int i;
    t_list  *list, *last;
    t_list  *p;

    i = 0;
    list = malloc(sizeof(t_list));
    create_list(list);
    list = rev_list(list);
    while (list)
    {
        printf("%d ", list->x);
        list = list->next;
    }
    free(list);
    return (0);
}