#include "checker.h"

void	ra(t_idk *isdk)
{
	if (isdk->actr >= 2)
	{
		t_stack		*temp_tail;
		t_stack		*temp_head;

		temp_tail = isdk->ahead;
		temp_head = isdk->ahead;
		isdk->ahead = isdk->ahead->next;
		while (temp_tail->next)
			temp_tail = temp_tail->next;
		temp_tail->next = temp_head;
		temp_head->next = NULL;
        write(1, "ra\n", 3);
	}
}

void	rb(t_idk *isdk)
{
	if (isdk->bctr >= 2)
	{
		t_stack		*temp_tail;
		t_stack		*temp_head;

		temp_tail = isdk->bhead;
		temp_head = isdk->bhead;
		isdk->bhead = isdk->bhead->next;
		while (temp_tail->next)
			temp_tail = temp_tail->next;
		temp_tail->next = temp_head;
		temp_head->next = NULL;
	    write(1, "rb\n", 3);
	}
}

void	rr(t_idk *isdk)
{
	isdk->rr = 1;
	ra(isdk);
	rb(isdk);
	write(1, "rr\n", 3);
}

void	rra(t_idk *isdk)
{
	if (isdk->actr >= 2)
	{
		t_stack		*temp_head;
		t_stack		*temp_tail;

		temp_head = isdk->ahead;
		while (isdk->ahead->next)
		{
			temp_tail = isdk->ahead;
			isdk->ahead = isdk->ahead->next;
		}
		isdk->ahead->next = temp_head;
		temp_tail->next = NULL;
	    write(1, "rra\n", 4);
	}
}

void	rrb(t_idk *isdk)
{
	if (isdk->bctr >= 2)
	{
		t_stack		*temp_head;
		t_stack		*temp_tail;

		temp_head = isdk->bhead;
		while (isdk->bhead->next)
		{
			temp_tail = isdk->bhead;
			isdk->bhead = isdk->bhead->next;
		}
		isdk->bhead->next = temp_head;
		temp_tail->next = NULL;
	    write(1, "rrb\n", 4);
	}
}