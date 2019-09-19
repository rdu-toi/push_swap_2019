/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 04:08:18 by rdu-toi           #+#    #+#             */
/*   Updated: 2019/09/19 04:08:19 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define COLOR_RED		"\x1b[31m"
# define COLOR_GREEN	"\x1b[32m"
# define COLOR_YELLOW	"\x1b[33m"
# define COLOR_BLUE		"\x1b[34m"
# define COLOR_MAGENTA	"\x1b[35m"
# define COLOR_CYAN		"\x1b[36m"
# define COLOR_RESET	"\x1b[0m"

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct		s_stack
{
	int				num;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_main
{
	int				i;
	int				actr;
	int				bctr;
	int				error;
	char			*line;
	int				*duplicate_table;
	int				col_print;
	int				list_print;
	int				ops_print;
	int				list_flag;
	int				a;
	int				b;
	int				ss;
	int				rr;
	int				rrr;
	char			**split;
	t_stack			*temp;
	t_stack			*tempa;
	t_stack			*tempb;
	t_stack			*ahead;
	t_stack			*bhead;
	t_stack			*temp_head;
	t_stack			*temp_tail;
}					t_main;

void				ops(t_main *main);
void				sa(t_main *main);
void				sb(t_main *main);
void				ss(t_main *main);
void				ra(t_main *main);
void				rb(t_main *main);
void				rr(t_main *main);
void				rra(t_main *main);
void				rrb(t_main *main);
void				rrr(t_main *main);
void				list_check(t_main *main);

#endif
