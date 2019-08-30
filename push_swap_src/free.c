#include "checker.h"

void    ahead(t_idk *isdk)
{
    if (isdk->ahead)
    {
        t_stack *tmp;
        
        while (isdk->ahead->next)
        {
            tmp = isdk->ahead;
            isdk->ahead = isdk->ahead->next;
            free(tmp);
        }
        free(isdk->ahead);
    }
}

void    bhead(t_idk *isdk)
{
    if (isdk->bhead)
    {
        t_stack *tmp;
        
        while (isdk->bhead->next)
        {
            tmp = isdk->bhead;
            isdk->bhead = isdk->bhead->next;
            free(tmp);
        }
        free(isdk->bhead);
    }
}

void    split(t_idk *isdk)
{
    int     i;

    i = 0;
    if (isdk->s)
    {
        while (isdk->s[i])
        {
            free(isdk->s[i]);
            i++;
        }
        free(isdk->s);
    }
}

void	free_error(t_idk *isdk)
{
    ahead(isdk);
    bhead(isdk);
    split(isdk);
}