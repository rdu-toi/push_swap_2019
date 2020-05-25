/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 23:00:08 by rdu-toi           #+#    #+#             */
/*   Updated: 2019/09/15 23:00:10 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_main *isdk)
{
	isdk->rrr = 1;
	rra(isdk);
	rrb(isdk);
	write(1, "rrr\n", 4);
	isdk->rrr = 0;
}

int		check_multiples(t_main *main)
{
	main->ta = main->ahead;

	while (main->ta)
	{
		main->tb = main->ta->next;
		while (main->tb)
		{
			if (main->ta->n == main->tb->n)
				return (0);
			main->tb = main->tb->next;
		}
		main->ta = main->ta->next;
	}
	main->ta = NULL;
	main->tb = NULL;
	return (1);
}

int		create_stack_2(t_main *m) {
	while (m->i >= 0)
	{
		m->line = ft_itoa(ft_atoi(m->split[m->i]));
		if (ft_strcmp(m->split[m->i], m->line))
			return (0);
		free(m->line);
		m->ta = m->ahead;
		m->ahead = create_node(ft_atoi(m->split[m->i]));
		m->ahead->next = m->ta;
		m->actr++;
		m->i--;
	}
	return (1);
}

void	set_variables(t_main *main)
{
	main->actr = 0;
	main->bctr = 0;
	main->ss = 0;
	main->rr = 0;
	main->rrr = 0;
	main->line = NULL;
	main->split = NULL;
	main->ta = NULL;
	main->tb = NULL;
	main->ahead = NULL;
	main->bhead = NULL;
	main->b_highest = 0;
	main->b_lowest = 0;
	set_variables_2(main);
}

void	set_variables_2(t_main *main)
{
	main->current_num_pos = 0;
	main->gra = 0;
	main->grra = 0;
	main->grb = 0;
	main->grrb = 0;
	main->best_num_of_moves = 0;
	main->nom_ra_rb = 0;
	main->nom_rra_rb = 0;
	main->nom_ra_rrb = 0;
	main->nom_rra_rrb = 0;
	main->rb = 0;
	main->rrb = 0;
	main->i = 0;
	main->ra = 0;
	main->rra = 0;
}
