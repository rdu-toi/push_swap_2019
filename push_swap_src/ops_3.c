#include "checker.h"

void	rrr(t_idk *isdk)
{
	isdk->rrr = 1;
	rra(isdk);
	rrb(isdk);
	write(1, "rrr\n", 4);
	isdk->rrr = 0;
}