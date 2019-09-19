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
