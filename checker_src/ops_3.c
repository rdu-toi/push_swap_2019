#include "checker.h"

void	rrr(t_idk *isdk)
{
	isdk->rrr = 1;
	rra(isdk);
	if (isdk->ops_print)
		write(1, "rrr\n", 4);
	rrb(isdk);
	isdk->rrr = 0;
}

void	KO_error(t_idk *isdk)
{
	if (!ft_strcmp("end", isdk->line))
	{
		write(1, "KO\n", 3);
		isdk->KO = 1;
	}
	else
		isdk->error = 1;
}