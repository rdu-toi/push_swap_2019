/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 03:57:19 by rdu-toi           #+#    #+#             */
/*   Updated: 2019/09/19 03:57:20 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

void	space(t_main *main, int flag, int end)
{
	int spaces;

	spaces = 1;
	while (spaces <= ft_nbrlen(main->actr) && flag)
	{
		if (main->col_print)
			printf(COLOR_GREEN "=" COLOR_RESET);
		else
			printf("=");
		spaces++;
	}
	if (end)
		printf("\n");
	while (spaces + ft_nbrlen(main->actr) <= 15 && !flag)
	{
		printf(" ");
		spaces++;
	}
}

void	end(t_main *main)
{
	space(main, 1, 0);
	space(main, 0, 0);
	space(main, 1, 0);
	if (main->col_print)
		printf("\n" COLOR_RED "%d" COLOR_RESET, main->actr);
	else
		printf("\n%d", main->actr);
	space(main, 0, 0);
	if (main->col_print)
		printf(COLOR_BLUE "%d" COLOR_RESET "\n", main->bctr);
	else
		printf("%d\n", main->bctr);
	space(main, 1, 0);
	space(main, 0, 0);
	space(main, 1, 1);
	printf("\n");
}

void	lista(t_main *main)
{
	if (main->col_print)
		printf(COLOR_MAGENTA "%d" COLOR_RESET, main->tempa->num);
	else
		printf("%d", main->tempa->num);
	main->a--;
	main->list_flag = 1;
}

void	listb(t_main *main)
{
	int spaces;

	spaces = 1;
	while (main->list_flag && spaces + ft_nbrlen(main->tempa->num) <= 15)
	{
		printf(" ");
		spaces++;
	}
	while (!main->list_flag && spaces <= 15)
	{
		printf(" ");
		spaces++;
	}
	if (main->col_print)
		printf(COLOR_CYAN "%d" COLOR_RESET, main->tempb->num);
	else
		printf("%d", main->tempb->num);
	main->b--;
	main->tempb = main->tempb->next;
}

void	list_check(t_main *main)
{
	main->tempa = main->ahead;
	main->tempb = main->bhead;
	main->a = main->actr;
	main->b = main->bctr;
	while (1)
	{
		main->list_flag = 0;
		if (main->a == 0 && main->b == 0)
		{
			end(main);
			break ;
		}
		if (main->a >= main->b && main->a)
			lista(main);
		if (main->b > main->a && main->b)
			listb(main);
		if (main->list_flag)
			main->tempa = main->tempa->next;
		printf("\n");
	}
	main->tempa = NULL;
	main->tempb = NULL;
}
