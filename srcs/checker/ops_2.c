/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 03:57:31 by rdu-toi           #+#    #+#             */
/*   Updated: 2019/09/19 03:57:32 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_main *main)
{
	if (main->actr >= 2)
	{
		main->temp_tail = main->ahead;
		main->temp_head = main->ahead;
		main->ahead = main->ahead->next;
		while (main->temp_tail->next)
			main->temp_tail = main->temp_tail->next;
		main->temp_tail->next = main->temp_head;
		main->temp_head->next = NULL;
		if (main->ops_print && !main->rr)
			write(1, "ra\n", 3);
		if (main->list_print && !main->rr)
			list_check(main);
	}
}

void	rb(t_main *main)
{
	if (main->bctr >= 2)
	{
		main->temp_tail = main->bhead;
		main->temp_head = main->bhead;
		main->bhead = main->bhead->next;
		while (main->temp_tail->next)
			main->temp_tail = main->temp_tail->next;
		main->temp_tail->next = main->temp_head;
		main->temp_head->next = NULL;
		if (main->ops_print && !main->rr)
			write(1, "rb\n", 3);
		if (main->list_print)
			list_check(main);
	}
}

void	rr(t_main *main)
{
	main->rr = 1;
	ra(main);
	if (main->ops_print)
		write(1, "rr\n", 3);
	rb(main);
	main->rr = 0;
}

void	rra(t_main *main)
{
	if (main->actr >= 2)
	{
		main->temp_head = main->ahead;
		while (main->ahead->next)
		{
			main->temp_tail = main->ahead;
			main->ahead = main->ahead->next;
		}
		main->ahead->next = main->temp_head;
		main->temp_tail->next = NULL;
		if (main->ops_print && !main->rr)
			write(1, "rra\n", 4);
		if (main->list_print && !main->rr)
			list_check(main);
	}
}

void	rrb(t_main *main)
{
	if (main->bctr >= 2)
	{
		main->temp_head = main->bhead;
		while (main->bhead->next)
		{
			main->temp_tail = main->bhead;
			main->bhead = main->bhead->next;
		}
		main->bhead->next = main->temp_head;
		main->temp_tail->next = NULL;
		if (main->ops_print && !main->rr)
			write(1, "rrb\n", 4);
		if (main->list_print)
			list_check(main);
	}
}
