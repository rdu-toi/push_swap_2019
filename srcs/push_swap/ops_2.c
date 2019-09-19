/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 23:02:04 by rdu-toi           #+#    #+#             */
/*   Updated: 2019/09/15 23:02:05 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_main *isdk)
{
	t_stack *temp_tail;
	t_stack *temp_head;

	if (isdk->actr >= 2)
	{
		temp_tail = isdk->ahead;
		temp_head = isdk->ahead;
		isdk->ahead = isdk->ahead->next;
		while (temp_tail->next)
			temp_tail = temp_tail->next;
		temp_tail->next = temp_head;
		temp_head->next = NULL;
		if (!isdk->rr)
			write(1, "ra\n", 3);
	}
}

void	rb(t_main *isdk)
{
	t_stack *temp_tail;
	t_stack *temp_head;

	if (isdk->bctr >= 2)
	{
		temp_tail = isdk->bhead;
		temp_head = isdk->bhead;
		isdk->bhead = isdk->bhead->next;
		while (temp_tail->next)
			temp_tail = temp_tail->next;
		temp_tail->next = temp_head;
		temp_head->next = NULL;
		if (!isdk->rr)
			write(1, "rb\n", 3);
	}
}

void	rr(t_main *isdk)
{
	isdk->rr = 1;
	ra(isdk);
	rb(isdk);
	write(1, "rr\n", 3);
	isdk->rr = 0;
}

void	rra(t_main *isdk)
{
	t_stack *temp_head;
	t_stack *temp_tail;

	if (isdk->actr >= 2)
	{
		temp_head = isdk->ahead;
		while (isdk->ahead->next)
		{
			temp_tail = isdk->ahead;
			isdk->ahead = isdk->ahead->next;
		}
		isdk->ahead->next = temp_head;
		temp_tail->next = NULL;
		if (!isdk->rrr)
			write(1, "rra\n", 4);
	}
}

void	rrb(t_main *isdk)
{
	t_stack *temp_head;
	t_stack *temp_tail;

	if (isdk->bctr >= 2)
	{
		temp_head = isdk->bhead;
		while (isdk->bhead->next)
		{
			temp_tail = isdk->bhead;
			isdk->bhead = isdk->bhead->next;
		}
		isdk->bhead->next = temp_head;
		temp_tail->next = NULL;
		if (!isdk->rrr)
			write(1, "rrb\n", 4);
	}
}
