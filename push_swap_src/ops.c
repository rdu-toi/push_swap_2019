#include "checker.h"

void	sa(t_idk *isdk)
{
	if (isdk->actr > 1)
	{
		int		temp;

		temp = isdk->ahead->stk;
		isdk->ahead->stk = isdk->ahead->next->stk;
		isdk->ahead->next->stk = temp;
		if (!isdk->ss)
        	write(1, "sa\n", 3);
	}
}

void	sb(t_idk *isdk)
{
	if (isdk->bctr > 1)
	{
		int		temp;

		temp = isdk->bhead->stk;
		isdk->bhead->stk = isdk->bhead->next->stk;
		isdk->bhead->next->stk = temp;
		if (!isdk->ss)
        	write(1, "sb\n", 3);
	}
}

void	ss(t_idk *isdk)
{
	isdk->ss = 1;
	sa(isdk);
	sb(isdk);
	write(1, "ss\n", 3);
	isdk->ss = 0;
}

void	pa(t_idk *isdk)
{
	if (isdk->actr)
	{
		t_stack		*temp;

		temp = isdk->ahead;
		isdk->ahead = isdk->ahead->next;
		temp->next = isdk->bhead;
		isdk->bhead = temp;
		isdk->actr--;
		isdk->bctr++;
        write(1, "pa\n", 3);
	}
}

void	pb(t_idk *isdk)
{
	if (isdk->bctr)
	{
		t_stack		*temp;

		temp = isdk->bhead;
		isdk->bhead = isdk->bhead->next;
		temp->next = isdk->ahead;
		isdk->ahead = temp;
		isdk->actr++;
		isdk->bctr--;
        write(1, "pb\n", 3);
	}
}