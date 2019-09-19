/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 08:39:43 by rdu-toi           #+#    #+#             */
/*   Updated: 2019/09/16 08:39:44 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	norm_made_me_do_this(t_main *s)
{
	while (s->i < s->current_num_pos)
	{
		s->ta = s->ta->next;
		s->i++;
	}
	s->tb = s->bhead;
	while (s->tb != NULL)
	{
		if (s->ta->n > s->b_highest && s->b_highest == s->tb->n)
			break ;
		s->rb++;
		s->rrb--;
		if ((s->ta->n < s->tb->n && s->tb->next && s->ta->n > s->tb->next->n)
			|| (s->ta->n < s->b_lowest && s->b_lowest == s->tb->n))
			break ;
		s->tb = s->tb->next;
	}
	s->ra = s->current_num_pos - 1;
	s->rra = s->actr - s->current_num_pos + 1;
	s->nom_ra_rb = s->ra + s->rb - ((s->ra >= s->rb) ? s->rb : s->ra);
	s->nom_rra_rb = s->rra + s->rb;
	s->nom_ra_rrb = s->ra + s->rrb;
	s->nom_rra_rrb = s->rra + s->rrb - ((s->rra >= s->rrb) ? s->rrb : s->rra);
}

void	norm_made_me_do_this_4(t_main *s)
{
	if (s->nom_rra_rb < s->best_num_of_moves)
	{
		s->best_num_of_moves = s->nom_rra_rb;
		s->gra = 0;
		s->grra = s->rra;
		s->grb = s->rb;
		s->grrb = 0;
	}
	if (s->nom_ra_rrb < s->best_num_of_moves)
	{
		s->best_num_of_moves = s->nom_ra_rrb;
		s->gra = s->ra;
		s->grra = 0;
		s->grb = 0;
		s->grrb = s->rrb;
	}
	if (s->nom_rra_rrb < s->best_num_of_moves)
	{
		s->best_num_of_moves = s->nom_rra_rrb;
		s->gra = 0;
		s->grra = s->rra;
		s->grb = 0;
		s->grrb = s->rrb;
	}
	s->current_num_pos++;
}

void	norm_made_me_do_this_2(t_main *s)
{
	while (s->current_num_pos <= s->actr)
	{
		s->nom_ra_rb = 0;
		s->nom_rra_rb = 0;
		s->nom_ra_rrb = 0;
		s->nom_rra_rrb = 0;
		s->rb = 0;
		s->rrb = s->bctr;
		s->ta = s->ahead;
		s->i = 1;
		norm_made_me_do_this(s);
		if (s->nom_ra_rb < s->best_num_of_moves)
		{
			s->best_num_of_moves = s->nom_ra_rb;
			s->gra = s->ra;
			s->grra = 0;
			s->grb = s->rb;
			s->grrb = 0;
		}
		norm_made_me_do_this_4(s);
	}
}

void	cycle_stacka(t_main *main)
{
	while (main->actr)
	{
		main->current_num_pos = 1;
		main->gra = 0;
		main->grra = 0;
		main->grb = 0;
		main->grrb = main->bctr;
		main->best_num_of_moves = 2147483647;
		norm_made_me_do_this_2(main);
		norm_made_me_do_this_3(main);
		pa(main);
		if (main->bhead->n > main->b_highest)
			main->b_highest = main->bhead->n;
		else if (main->bhead->n < main->b_lowest)
			main->b_lowest = main->bhead->n;
	}
	main->tb = main->bhead;
	main->i = 0;
}

void	best_move(t_main *main)
{
	main->ss = 0;
	main->rr = 0;
	main->rrr = 0;
	pa(main);
	pa(main);
	main->bctr = 2;
	main->b_highest = 0;
	main->b_lowest = 2147483647;
	if (main->bhead->n > main->bhead->next->n)
	{
		main->b_highest = main->bhead->n;
		main->b_lowest = main->bhead->next->n;
	}
	else
	{
		main->b_lowest = main->bhead->n;
		main->b_highest = main->bhead->next->n;
	}
	if (main->bhead->n < main->bhead->next->n)
		sb(main);
	cycle_stacka(main);
	final_sort_b(main);
}
