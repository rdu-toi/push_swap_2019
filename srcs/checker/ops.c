/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 03:57:26 by rdu-toi           #+#    #+#             */
/*   Updated: 2019/09/19 03:57:27 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_main *main)
{
	int temp;

	if (main->actr > 1)
	{
		temp = main->ahead->num;
		main->ahead->num = main->ahead->next->num;
		main->ahead->next->num = temp;
		if (main->ops_print && !main->ss)
			write(1, "sa\n", 3);
		if (main->list_print && !main->ss)
			list_check(main);
	}
}

void	sb(t_main *main)
{
	int temp;

	if (main->bctr > 1)
	{
		temp = main->bhead->num;
		main->bhead->num = main->bhead->next->num;
		main->bhead->next->num = temp;
		if (main->ops_print && !main->ss)
			write(1, "sb\n", 3);
		if (main->list_print)
			list_check(main);
	}
}

void	pa(t_main *main)
{
	if (main->actr)
	{
		main->temp_head = main->ahead;
		main->ahead = main->ahead->next;
		main->temp_head->next = main->bhead;
		main->bhead = main->temp_head;
		main->actr--;
		main->bctr++;
		if (main->ops_print)
			write(1, "pa\n", 3);
		if (main->list_print)
			list_check(main);
	}
}

void	pb(t_main *main)
{
	if (main->bctr)
	{
		main->temp_head = main->bhead;
		main->bhead = main->bhead->next;
		main->temp_head->next = main->ahead;
		main->ahead = main->temp_head;
		main->actr++;
		main->bctr--;
		if (main->ops_print)
			write(1, "pb\n", 3);
		if (main->list_print)
			list_check(main);
	}
}

void	ops(t_main *main)
{
	if (!ft_strcmp("sa", main->line))
		sa(main);
	else if (!ft_strcmp("sb", main->line))
		sb(main);
	else if (!ft_strcmp("ss", main->line))
		ss(main);
	else if (!ft_strcmp("pa", main->line))
		pa(main);
	else if (!ft_strcmp("pb", main->line))
		pb(main);
	else if (!ft_strcmp("ra", main->line))
		ra(main);
	else if (!ft_strcmp("rb", main->line))
		rb(main);
	else if (!ft_strcmp("rr", main->line))
		rr(main);
	else if (!ft_strcmp("rra", main->line))
		rra(main);
	else if (!ft_strcmp("rrb", main->line))
		rrb(main);
	else if (!ft_strcmp("rrr", main->line))
		rrr(main);
	else
		main->error = 1;
}
