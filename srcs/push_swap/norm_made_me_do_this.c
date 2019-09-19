/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_made_me_do_this.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 08:38:43 by rdu-toi           #+#    #+#             */
/*   Updated: 2019/09/16 08:38:44 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	norm_made_me_do_this_5(t_main *s)
{
	while (s->gra)
	{
		ra(s);
		s->gra--;
	}
	while (s->grra)
	{
		rra(s);
		s->grra--;
	}
}

void	norm_made_me_do_this_3(t_main *s)
{
	while (s->grb)
	{
		if (s->gra)
		{
			rr(s);
			s->gra--;
		}
		else
			rb(s);
		s->grb--;
	}
	while (s->grrb)
	{
		if (s->grra)
		{
			rrr(s);
			s->grra--;
		}
		else
			rrb(s);
		s->grrb--;
	}
	norm_made_me_do_this_5(s);
}

void	push_all_b(t_main *main)
{
	while (main->bctr)
		pb(main);
}

void	final_sort_b(t_main *main)
{
	while (main->tb != NULL)
	{
		if (main->tb->n == main->b_highest)
			break ;
		main->i++;
		main->tb = main->tb->next;
	}
	if (main->i + main->i > main->bctr)
	{
		main->i = main->bctr - main->i;
		while (main->i > 0)
		{
			rrb(main);
			main->i--;
		}
		return ;
	}
	while (main->i > 0)
	{
		rb(main);
		main->i--;
	}
}
