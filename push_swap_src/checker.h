/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <rdu-toi@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 13:36:31 by rdu-toi           #+#    #+#             */
/*   Updated: 2019/08/30 14:44:43 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include <stdio.h>			/////////////////////

typedef struct		s_stack
{
	int				stk;
	int				index;
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
	int				ss;
	int				rr;
	int				rrr;
	int				flag;
	int				ba_dif;
	int				bb_dif;
	int				fbb_dif;
	int				ra_flag;
	int				rb_flag;
	int				ra_true;
	int				rb_true;
	int				a_dif;
	int				b_dif;
	int				stack_pos;
	char			**s;
	t_stack			*tempa;
	t_stack			*tempb;
	t_stack			*ahead;
	t_stack			*bhead;
	t_stack			*move_find_a;
	t_stack			*move_find_b;

    int				b_highest;
    int				b_lowest;
	int				current_num_pos;
	int				gr_a;
	int				grr_a;
	int				gr_b;
	int				grr_b;
	int				best_num_of_moves;
	int				num_of_moves_ra_rb;
	int				num_of_moves_rra_rb;
	int				num_of_moves_ra_rrb;
	int				num_of_moves_rra_rrb;
	int				r_b;
	int				rr_b;
	int				i;
	int				r_a;
	int				rr_a;
}					t_idk;

int		check_args(t_idk *isdk, int ac, char **v);
void	error(void);
void	check_dbls(t_idk *isdk);
int		check_odr(t_idk *isdk);
int		check_flags(t_idk *isdk, char *v, int j);
void	sa(t_idk *isdk);
void	sb(t_idk *isdk);
void	ss(t_idk *isdk);
void	pa(t_idk *isdk);
void	pb(t_idk *isdk);
void	ra(t_idk *isdk);
void	rb(t_idk *isdk);
void	rr(t_idk *isdk);
void	rra(t_idk *isdk);
void	rrb(t_idk *isdk);
void	rrr(t_idk *isdk);
void	KO_error(t_idk *isdk);
void	free_error(t_idk *isdk);
void    best_move(t_idk *isdk);
// void    print_ops(t_idk *isdk);
void    push_all_b(t_idk *isdk);

#endif
