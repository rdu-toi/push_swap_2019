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
		if (isdk->ops_print && !isdk->rr)
			write(1, "ra\n", 3);
		if (isdk->list_print && !isdk->rr)
			list_check(isdk);
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
		if (isdk->ops_print && !isdk->rr)
			write(1, "rb\n", 3);
		if (isdk->list_print)
			list_check(isdk);
	}
}

void	rr(t_idk *isdk)
{
	isdk->rr = 1;
	ra(isdk);
	if (isdk->ops_print)
		write(1, "rr\n", 3);
	rb(isdk);
	isdk->rr = 0;
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
		if (isdk->ops_print && !isdk->rr)
			write(1, "rra\n", 4);
		if (isdk->list_print && !isdk->rr)
			list_check(isdk);
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
		if (isdk->ops_print && !isdk->rr)
			write(1, "rrb\n", 4);
		if (isdk->list_print)
			list_check(isdk);
	}
}