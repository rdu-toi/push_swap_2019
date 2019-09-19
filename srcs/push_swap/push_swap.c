/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 23:49:39 by rdu-toi           #+#    #+#             */
/*   Updated: 2019/09/14 23:49:41 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int		check_order(t_main *main)
{
	t_stack *temp;

	temp = main->ahead;
	while (temp && temp->next)
	{
		if (temp->n > temp->next->n)
			return (0);
		temp = temp->next;
	}
	free(temp);
	return (1);
}

t_stack	*create_node(int value)
{
	t_stack *tmp;

	if (!(tmp = (t_stack *)ft_memalloc(sizeof(t_stack))))
		return (NULL);
	tmp->n = value;
	tmp->next = NULL;
	return (tmp);
}

int		create_stacks(t_main *main, int count, char **args)
{
	int		i;
	t_stack	*list;

	while (count > 1)
	{
		i = 0;
		main->split = ft_strsplit(args[count - 1], ' ');
		while (main->split[i])
			i++;
		i--;
		while (i >= 0)
		{
			if (ft_strcmp(main->split[i], ft_itoa(ft_atoi(main->split[i]))))
				return (0);
			list = main->ahead;
			main->ahead = create_node(ft_atoi(main->split[i]));
			main->ahead->next = list;
			main->actr++;
			i--;
		}
		count--;
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_main main;

	main.ss = 0;
	main.rr = 0;
	main.rrr = 0;
	main.actr = 0;
	main.bctr = 0;
	if (ac == 1)
		return (0);
	else if (create_stacks(&main, ac, av))
	{
		if (!check_order(&main))
		{
			if (main.actr <= 5)
				sort_five_below(&main);
			else
			{
				best_move(&main);
				push_all_b(&main);
			}
		}
	}
	else
		write(1, "Error\n", 6);
	// free_everything();
}
