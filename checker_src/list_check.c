#include "checker.h"
#include <stdio.h>

void	space(t_idk *isdk, int flag, int end)
{
	int		spaces;

	spaces = 1;
	while (spaces <= ft_nbrlen(isdk->actr) && flag)
	{
		if (isdk->col_print)
			printf(COLOR_GREEN "=" COLOR_RESET);
		else
			printf("="); 
		spaces++;
	}
	if(end)
		printf("\n");
	while (spaces + ft_nbrlen(isdk->actr) <= 15 && !flag)
	{
			printf(" ");
		spaces++;
	}
}

void	end(t_idk *isdk)
{
	space(isdk, 1, 0);
	space(isdk, 0, 0);
	space(isdk, 1, 0);
	if (isdk->col_print)
		printf("\n" COLOR_RED "%d" COLOR_RESET, isdk->actr);
	else
		printf("\n%d", isdk->actr);
	space(isdk, 0, 0);
	if (isdk->col_print)
		printf(COLOR_BLUE "%d" COLOR_RESET "\n", isdk->bctr);
	else
		printf("%d\n", isdk->bctr);
	space(isdk, 1, 0);
	space(isdk, 0, 0);
	space(isdk, 1, 1);
	printf("\n");
}

void	lista(t_idk *isdk)
{
	if (isdk->col_print)
		printf(COLOR_MAGENTA "%d" COLOR_RESET, isdk->tempa->stk);
	else
		printf("%d", isdk->tempa->stk);
	isdk->a--;
	isdk->list_flag = 1;
}

void	listb(t_idk *isdk)
{
	int		spaces;

	spaces = 1;
	while (isdk->list_flag && spaces + ft_nbrlen(isdk->tempa->stk) <= 15)
	{
		printf(" ");
		spaces++;
	}
	while (!isdk->list_flag && spaces <= 15)
	{
		printf(" ");
		spaces++;
	}
	if (isdk->col_print)
		printf(COLOR_CYAN "%d" COLOR_RESET, isdk->tempb->stk);
	else
		printf("%d", isdk->tempb->stk);
	isdk->b--;
	isdk->tempb = isdk->tempb->next;
}

void	list_check(t_idk *isdk)
{
	isdk->tempa = isdk->ahead;
	isdk->tempb = isdk->bhead;
	isdk->a = isdk->actr;
	isdk->b = isdk->bctr;
	while (1)
	{
		isdk->list_flag = 0;
		if (isdk->a == 0 && isdk->b == 0)
		{
			end(isdk);
			break;
		}
		if (isdk->a >= isdk->b && isdk->a)
			lista(isdk);
		if (isdk->b > isdk->a && isdk->b)
			listb(isdk);
		if (isdk->list_flag)
			isdk->tempa = isdk->tempa->next;
		printf("\n");
	}
}