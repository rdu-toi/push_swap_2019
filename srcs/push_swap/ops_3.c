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

// void	set_variables(t_main * m)
// {

// }

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
	return (1);
}

// void	free_everything(t_main *m)
// {

// }
