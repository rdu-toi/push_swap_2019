/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 13:36:31 by rdu-toi           #+#    #+#             */
/*   Updated: 2018/09/04 13:36:31 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"

typedef struct		s_stack
{
	int				stk;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_idk
{
	int				actr;
	int				bctr;
	int				error;
	int				KO;
	int				a;
	int				b;
	int				flag;
	int				list_flag;
	int				list_print;
	int				ops_print;
	int				ss;
	int				rr;
	int				rrr;
	int				col_print;
	char			*line;
	char			**s;
	t_stack			*tempa;
	t_stack			*tempb;
	t_stack			*ahead;
	t_stack			*bhead;
}					t_idk;

int		check_args(t_idk *isdk, int ac, char **v);
void	ops(t_idk *isdk);
void	error(void);
void	check_dbls(t_idk *isdk);
int		check_odr(t_idk *isdk);
int		check_flags(t_idk *isdk, char *v, int j);
void	ra(t_idk *isdk);
void	rb(t_idk *isdk);
void	rr(t_idk *isdk);
void	rra(t_idk *isdk);
void	rrb(t_idk *isdk);
void	rrr(t_idk *isdk);
void	KO_error(t_idk *isdk);
void	free_error(t_idk *isdk);
void	list_check(t_idk *isdk);

#endif
