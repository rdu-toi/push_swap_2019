/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 22:52:44 by rdu-toi           #+#    #+#             */
/*   Updated: 2019/09/15 22:52:46 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <stdio.h>

typedef struct		s_stack
{
	int				n;
	int				index;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_main
{
	int				actr;
	int				bctr;
	int				ss;
	int				rr;
	int				rrr;
	char			**split;
	char			*line;
	t_stack			*ta;
	t_stack			*tb;
	t_stack			*ahead;
	t_stack			*bhead;
	int				b_highest;
	int				b_lowest;
	int				current_num_pos;
	int				gra;
	int				grra;
	int				grb;
	int				grrb;
	int				best_num_of_moves;
	int				nom_ra_rb;
	int				nom_rra_rb;
	int				nom_ra_rrb;
	int				nom_rra_rrb;
	int				rb;
	int				rrb;
	int				i;
	int				ra;
	int				rra;
}					t_main;

void				best_move(t_main *main);
void				push_all_b(t_main *main);
void				sa(t_main *main);
void				sb(t_main *main);
void				ss(t_main *main);
void				pa(t_main *main);
void				pb(t_main *main);
void				ra(t_main *main);
void				rb(t_main *main);
void				rr(t_main *main);
void				rra(t_main *main);
void				rrb(t_main *main);
void				rrr(t_main *main);
void				final_sort_b(t_main *main);
void				push_all_b(t_main *main);
void				norm_made_me_do_this_3(t_main *s);
void				sort_five_below(t_main *m);
void				set_variables(t_main *main);
int					check_order(t_main *main);
int					check_multiples(t_main *main);
int					create_stack_2(t_main *m);
t_stack				*create_node(int value);

#endif
