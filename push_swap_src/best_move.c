/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <rdu-toi@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 22:39:28 by rdu-toi           #+#    #+#             */
/*   Updated: 2019/08/30 11:01:49 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    push_all_b(t_idk *isdk)
{
    while (isdk->bctr)
        pb(isdk);
}

void    final_sort_b(t_idk *isdk)
{
    while (isdk->tempb != NULL)
    {
        if (isdk->tempb->stk == isdk->b_highest)
            break;
        isdk->i++;
        isdk->tempb = isdk->tempb->next;
    }
    if (isdk->i + isdk->i > isdk->bctr)
    {
        isdk->i = isdk->bctr - isdk->i;
        while (isdk->i > 0)
        {
            rrb(isdk);
            isdk->i--;
        }
        return ;
    }
    while (isdk->i > 0)
    {
        rb(isdk);
        isdk->i--;
    }
}

void norm_made_me_do_this(t_idk *s)
{
    while (s->i < s->current_num_pos) {
        s->tempa = s->tempa->next;
        s->i++;
    }
    s->tempb = s->bhead;
    while (s->tempb != NULL)
    {
        if (s->tempa->stk > s->b_highest && s->b_highest == s->tempb->stk)
            break;
        s->r_b++;
        s->rr_b--;
        if ((s->tempa->stk < s->tempb->stk && s->tempb->next && s->tempa->stk > s->tempb->next->stk)
            || (s->tempa->stk < s->b_lowest && s->b_lowest == s->tempb->stk))
            break;
        s->tempb = s->tempb->next;
    }
    s->r_a = s->current_num_pos - 1;
    s->rr_a = s->actr - s->current_num_pos + 1;
    s->num_of_moves_ra_rb = s->r_a + s->r_b - ((s->r_a >= s->r_b) ? s->r_b : s->r_a);
    s->num_of_moves_rra_rb = s->rr_a + s->r_b;
    s->num_of_moves_ra_rrb = s->r_a + s->rr_b;
    s->num_of_moves_rra_rrb = s->rr_a + s->rr_b - ((s->rr_a >= s->rr_b) ? s->rr_b : s->rr_a);
}

void    norm_made_me_do_this_4(t_idk *s)
{
    if (s->num_of_moves_rra_rb < s->best_num_of_moves)
    {
        s->best_num_of_moves = s->num_of_moves_rra_rb;
        s->gr_a = 0;
        s->grr_a = s->rr_a;
        s->gr_b = s->r_b;
        s->grr_b = 0;
    }
    if (s->num_of_moves_ra_rrb < s->best_num_of_moves)
    {
        s->best_num_of_moves = s->num_of_moves_ra_rrb;
        s->gr_a = s->r_a;
        s->grr_a = 0;
        s->gr_b = 0;
        s->grr_b = s->rr_b;
    }
    if (s->num_of_moves_rra_rrb < s->best_num_of_moves)
    {
        s->best_num_of_moves = s->num_of_moves_rra_rrb;
        s->gr_a = 0;
        s->grr_a = s->rr_a;
        s->gr_b = 0;
        s->grr_b = s->rr_b;
    }
    s->current_num_pos++;
}

void    norm_made_me_do_this_2(t_idk *s)
{
    while (s->current_num_pos <= s->actr) {
        s->num_of_moves_ra_rb = 0;
        s->num_of_moves_rra_rb = 0;
        s->num_of_moves_ra_rrb = 0;
        s->num_of_moves_rra_rrb = 0;
        s->r_b = 0;
        s->rr_b = s->bctr;
        s->tempa = s->ahead;
        s->i = 1;
        norm_made_me_do_this(s);
        if (s->num_of_moves_ra_rb < s->best_num_of_moves)
        {
            s->best_num_of_moves = s->num_of_moves_ra_rb;
            s->gr_a = s->r_a;
            s->grr_a = 0;
            s->gr_b = s->r_b;
            s->grr_b = 0;
        }
        norm_made_me_do_this_4(s);
    }
}

void    norm_made_me_do_this_3(t_idk *s)
{
    while (s->gr_b)
    {
        if (s->gr_a)
        {
            rr(s);
            s->gr_a--;
        }
        else
            rb(s);
        s->gr_b--;
    }
    while (s->grr_b)
    {
        if (s->grr_a)
        {
            rrr(s);
            s->grr_a--;
        }
        else
            rrb(s);
        s->grr_b--;
    }
    while (s->gr_a)
    {
        ra(s);
        s->gr_a--;
    }
}

void    cycle_stacka(t_idk *isdk)
{
    while (isdk->actr) {
        isdk->current_num_pos = 1;
        isdk->gr_a = 0;
        isdk->grr_a = 0;
        isdk->gr_b = 0;
        isdk->grr_b = isdk->bctr;
        isdk->best_num_of_moves = 2147483647;
        norm_made_me_do_this_2(isdk);
        norm_made_me_do_this_3(isdk);
        while (isdk->grr_a)
        {
            rra(isdk);
            isdk->grr_a--;
        }
        pa(isdk);
        if (isdk->bhead->stk > isdk->b_highest)
            isdk->b_highest = isdk->bhead->stk;
        else if (isdk->bhead->stk < isdk->b_lowest)
            isdk->b_lowest = isdk->bhead->stk;
    }
    isdk->tempb = isdk->bhead;
    isdk->i = 0;
    final_sort_b(isdk);
}

void    best_move(t_idk *isdk)
{
    isdk->ss = 0;
    isdk->rr = 0;
    isdk->rrr = 0;
    pa(isdk);
    pa(isdk);
    isdk->bctr = 2;
    isdk->b_highest = 0;
    isdk->b_lowest = 2147483647;
    if (isdk->bhead->stk > isdk->bhead->next->stk)
    {
        isdk->b_highest = isdk->bhead->stk;
        isdk->b_lowest = isdk->bhead->next->stk;
    }
    else
    {
        isdk->b_lowest = isdk->bhead->stk;
        isdk->b_highest = isdk->bhead->next->stk;
    }
    if (isdk->bhead->stk < isdk->bhead->next->stk)
        sb(isdk);
    cycle_stacka(isdk);
}