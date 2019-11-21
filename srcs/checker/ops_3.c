/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 03:57:36 by rdu-toi           #+#    #+#             */
/*   Updated: 2019/09/19 03:57:37 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rrr(t_main *main)
{
	main->rrr = 1;
	rra(main);
	if (main->ops_print)
		write(1, "rrr\n", 4);
	rrb(main);
	main->rrr = 0;
}

void	ss(t_main *main)
{
	main->ss = 1;
	sa(main);
	if (main->ops_print)
		write(1, "ss\n", 3);
	sb(main);
	main->ss = 0;
}

void	set_variables(t_main *main)
{
	main->error = 0;
	main->list_print = 0;
	main->ops_print = 0;
	main->col_print = 0;
	main->actr = 0;
	main->bctr = 0;
	main->ss = 0;
	main->rr = 0;
	main->rrr = 0;
	main->line = NULL;
	main->split = NULL;
	main->temp = NULL;
	main->tempa = NULL;
	main->tempb = NULL;
	main->ahead = NULL;
	main->bhead = NULL;
	main->temp_tail = NULL;
}

int		check_multiples(t_main *main)
{
	main->tempa = main->ahead;

	while (main->tempa)
	{
		main->temp = main->tempa->next;
		while (main->temp)
		{
			if (main->tempa->num == main->temp->num)
				return (0);
			main->temp = main->temp->next;
		}
		main->tempa = main->tempa->next;
	}
	main->tempa = NULL;
	main->temp = NULL;
	return (1);
}

int		create_stacks_2(t_main *m) {
	while (m->i >= 0)
	{
		m->line = ft_itoa(ft_atoi(m->split[m->i]));
		if (ft_strcmp(m->split[m->i], m->line))
			return (0);
		free(m->line);
		m->temp = m->ahead;
		m->ahead = create_node(ft_atoi(m->split[m->i]));
		m->ahead->next = m->temp;
		m->actr++;
		m->i--;
	}
	return (1);
}
