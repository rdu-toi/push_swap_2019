/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 03:57:12 by rdu-toi           #+#    #+#             */
/*   Updated: 2019/09/19 03:57:13 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

void	check_order(t_main *main)
{
	main->temp = main->ahead;
	while (main->temp && main->temp->next)
	{
		if (main->temp->num > main->temp->next->num)
		{
			write(1, "KO\n", 3);
			return ;
		}
		main->temp = main->temp->next;
	}
	if (!main->bctr)
		write(1, "OK\n", 3);
}

t_stack	*create_node(int value)
{
	t_stack *tmp;

	if (!(tmp = (t_stack *)ft_memalloc(sizeof(t_stack))))
		return (NULL);
	tmp->num = value;
	tmp->next = NULL;
	return (tmp);
}

int		check_flags(t_main *main, char *arg)
{
	if (!ft_strcmp(arg, "-v"))
	{
		main->list_print = 1;
		return (1);
	}
	else if (!ft_strcmp(arg, "-o"))
	{
		main->ops_print = 1;
		return (1);
	}
	else if (!ft_strcmp(arg, "-c"))
	{
		main->col_print = 1;
		return (1);
	}
	return (0);
}

int		create_stacks(t_main *m, int count, char **args)
{
	while (count > 1)
	{
		if (!check_flags(m, args[count - 1]))
		{
			m->i = 0;
			m->split = ft_strsplit(args[count - 1], ' ');
			while (m->split[m->i])
				m->i++;
			m->i--;
			while (m->i >= 0)
			{
				if (ft_strcmp(m->split[m->i], ft_itoa(ft_atoi(m->split[m->i]))))
					return (0);
				m->temp = m->ahead;
				m->ahead = create_node(ft_atoi(m->split[m->i]));
				m->ahead->next = m->temp;
				m->actr++;
				m->i--;
				m->temp = NULL;
			}
			while (m->split[m->i])
				free(m->split[m->i++]);
			free(m->split);
		}
		count--;
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_main main;

	set_variables(&main);
	if (ac == 1)
		return (0);
	else if (create_stacks(&main, ac, av))
	{
		if (!check_multiples(&main))
			main.error = 1;
		if (main.list_print && !main.error)
			list_check(&main);
		while (!main.error)
		{
			if (get_next_line(0, &main.line) == 0)
				break ;
			ops(&main);
		}
	}
	if (main.error)
		write(1, "Error\n", 6);
	else
		check_order(&main);
	free_everything(&main);
	while (1);
}
