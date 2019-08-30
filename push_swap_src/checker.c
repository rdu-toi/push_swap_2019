/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <rdu-toi@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 13:36:26 by rdu-toi           #+#    #+#             */
/*   Updated: 2019/08/30 15:12:41 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*create_node(int value)
{
	t_stack	*tmp;

	if (!(tmp = (t_stack *)ft_memalloc(sizeof(t_stack))))
		return (NULL);
	tmp->stk = value;
	tmp->next = NULL;
	return (tmp);
}

void	list_add(t_idk *isdk, char *v)
{
	t_stack	*list;
	int		i;

	i = 0;
	while (v[i])
		i++;
	i--;
	while (i >= 0)
	{
		if (v[i] == 'v')
			break;
		if (i == 0 || (v[i] == ' ' && v[i - 1] != ' '))
		{
			list = isdk->ahead;
			isdk->ahead = create_node(ft_atoi(&(v[i])));
			isdk->ahead->next = list;
			isdk->actr++;
		}
		i--;
	}
}

void	create_stacks(t_idk *isdk, int ac, char **av)
{
	isdk->error = 0;
	isdk->actr = 0;
	isdk->bctr = 0;
	isdk->KO = 0;
	while (ac > 1)
		list_add(isdk, av[ac-- - 1]);
}


int		main(int ac, char **av)
{
	t_idk	isdk;

	if (ac > 1 && check_args(&isdk, ac, av))
	{
		create_stacks(&isdk, ac, av);
		check_dbls(&isdk);
	}
	if (isdk.error)
		write(1, "error\n", 6);
	else
	{
		best_move(&isdk);
		push_all_b(&isdk);
	}
	free_error(&isdk);
}
