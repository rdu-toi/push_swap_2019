/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 23:01:16 by rdu-toi           #+#    #+#             */
/*   Updated: 2019/09/15 23:01:16 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_main *isdk)
{
	int temp;

	if (isdk->actr > 1)
	{
		temp = isdk->ahead->n;
		isdk->ahead->n = isdk->ahead->next->n;
		isdk->ahead->next->n = temp;
		if (!isdk->ss)
			write(1, "sa\n", 3);
	}
}

void	sb(t_main *isdk)
{
	int temp;

	if (isdk->bctr > 1)
	{
		temp = isdk->bhead->n;
		isdk->bhead->n = isdk->bhead->next->n;
		isdk->bhead->next->n = temp;
		if (!isdk->ss)
			write(1, "sb\n", 3);
	}
}

void	ss(t_main *isdk)
{
	isdk->ss = 1;
	sa(isdk);
	sb(isdk);
	write(1, "ss\n", 3);
	isdk->ss = 0;
}

void	pa(t_main *isdk)
{
	t_stack *temp;

	if (isdk->actr)
	{
		temp = isdk->ahead;
		isdk->ahead = isdk->ahead->next;
		temp->next = isdk->bhead;
		isdk->bhead = temp;
		isdk->actr--;
		isdk->bctr++;
		write(1, "pb\n", 3);
	}
}

void	pb(t_main *isdk)
{
	t_stack *temp;

	if (isdk->bctr)
	{
		temp = isdk->bhead;
		isdk->bhead = isdk->bhead->next;
		temp->next = isdk->ahead;
		isdk->ahead = temp;
		isdk->actr++;
		isdk->bctr--;
		write(1, "pa\n", 3);
	}
}
