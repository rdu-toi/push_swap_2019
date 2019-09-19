/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_below.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 09:57:04 by rdu-toi           #+#    #+#             */
/*   Updated: 2019/09/16 09:57:05 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_main *m)
{
	m->ta = m->ahead;
	if (!check_order(m))
	{
		if (m->ta->n < m->ta->next->n && m->ta->n < m->ta->next->next->n)
		{
			ra(m);
			sa(m);
			rra(m);
		}
		else if (m->ta->n > m->ta->next->n && m->ta->n < m->ta->next->next->n)
			sa(m);
		else if (m->ta->n < m->ta->next->n && m->ta->n > m->ta->next->next->n)
			rra(m);
		else if (m->ta->n > m->ta->next->n && m->ta->n > m->ta->next->next->n)
		{
			if (m->ta->next->n < m->ta->next->next->n)
				ra(m);
			else
			{
				sa(m);
				rra(m);
			}
		}
	}
}

void	sort_four(t_main *m)
{
	sort_three(m);
	if (m->bhead->n < m->ahead->n)
		pb(m);
	else if (m->bhead->n < m->ahead->next->n)
	{
		ra(m);
		pb(m);
		rra(m);
	}
	else if (m->bhead->n < m->ahead->next->next->n)
	{
		rra(m);
		pb(m);
		ra(m);
		ra(m);
	}
	else if (m->bhead->n > m->ahead->next->next->n)
	{
		pb(m);
		ra(m);
	}
}

void	sort_five(t_main *m)
{
	if (m->bhead->n < m->ahead->next->next->n)
	{
		ra(m);
		ra(m);
		pb(m);
		rra(m);
		rra(m);
	}
	else if (m->bhead->n < m->ahead->next->next->next->n)
	{
		rra(m);
		pb(m);
		ra(m);
		ra(m);
	}
	else if (m->bhead->n > m->ahead->next->next->next->n)
	{
		pb(m);
		ra(m);
	}
}

void	sort_the_rest(t_main *m)
{
	pa(m);
	if (m->actr == 3)
		sort_four(m);
	else if (m->actr == 4)
	{
		pa(m);
		sort_four(m);
		if (m->bhead->n < m->ahead->n)
			pb(m);
		else if (m->bhead->n < m->ahead->next->n)
		{
			ra(m);
			pb(m);
			rra(m);
		}
		else
			sort_five(m);
	}
}

void	sort_five_below(t_main *m)
{
	if (m->actr == 2)
	{
		sa(m);
		return ;
	}
	if (m->actr == 3)
		sort_three(m);
	else if (m->actr > 3)
		sort_the_rest(m);
}
