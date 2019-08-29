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

void    cycle_stacka(t_idk *isdk)
{
while (isdk->actr) {
        isdk->current_num_pos = 1;
        isdk->gr_a = 0;
        isdk->grr_a = 0;
        isdk->gr_b = 0;
        isdk->grr_b = isdk->bctr;
        isdk->best_num_of_moves = 2147483647;
        while (isdk->current_num_pos <= isdk->actr) {
            isdk->num_of_moves_ra_rb = 0;
            isdk->num_of_moves_rra_rb = 0;
            isdk->num_of_moves_ra_rrb = 0;
            isdk->num_of_moves_rra_rrb = 0;
            isdk->r_b = 0;
            isdk->rr_b = isdk->bctr;
            isdk->tempa = isdk->ahead;
            isdk->i = 1;
            while (isdk->i < isdk->current_num_pos) {
                isdk->tempa = isdk->tempa->next;
                isdk->i++;
            }
            isdk->tempb = isdk->bhead;
            while (isdk->tempb != NULL)
            {
                if (isdk->tempa->stk > isdk->b_highest && isdk->b_highest == isdk->tempb->stk)
                    break;
                isdk->r_b++;
                isdk->rr_b--;
                if ((isdk->tempa->stk < isdk->tempb->stk && isdk->tempb->next && isdk->tempa->stk > isdk->tempb->next->stk) ||
                    (isdk->tempa->stk < isdk->b_lowest && isdk->b_lowest == isdk->tempb->stk))
                    break;
                isdk->tempb = isdk->tempb->next;
            }
            isdk->r_a = isdk->current_num_pos - 1;
            isdk->rr_a = isdk->actr - isdk->current_num_pos + 1;
            isdk->num_of_moves_ra_rb = isdk->r_a + isdk->r_b - ((isdk->r_a >= isdk->r_b) ? isdk->r_b : isdk->r_a);
            isdk->num_of_moves_rra_rb = isdk->rr_a + isdk->r_b;
            isdk->num_of_moves_ra_rrb = isdk->r_a + isdk->rr_b;
            isdk->num_of_moves_rra_rrb = isdk->rr_a + isdk->rr_b - ((isdk->rr_a >= isdk->rr_b) ? isdk->rr_b : isdk->rr_a);
            if (isdk->num_of_moves_ra_rb < isdk->best_num_of_moves)
            {
                isdk->best_num_of_moves = isdk->num_of_moves_ra_rb;
                isdk->gr_a = isdk->r_a;
                isdk->grr_a = 0;
                isdk->gr_b = isdk->r_b;
                isdk->grr_b = 0;
            }
            if (isdk->num_of_moves_rra_rb < isdk->best_num_of_moves)
            {
                isdk->best_num_of_moves = isdk->num_of_moves_rra_rb;
                isdk->gr_a = 0;
                isdk->grr_a = isdk->rr_a;
                isdk->gr_b = isdk->r_b;
                isdk->grr_b = 0;
            }
            if (isdk->num_of_moves_ra_rrb < isdk->best_num_of_moves)
            {
                isdk->best_num_of_moves = isdk->num_of_moves_ra_rrb;
                isdk->gr_a = isdk->r_a;
                isdk->grr_a = 0;
                isdk->gr_b = 0;
                isdk->grr_b = isdk->rr_b;
            }
            if (isdk->num_of_moves_rra_rrb < isdk->best_num_of_moves)
            {
                isdk->best_num_of_moves = isdk->num_of_moves_rra_rrb;
                isdk->gr_a = 0;
                isdk->grr_a = isdk->rr_a;
                isdk->gr_b = 0;
                isdk->grr_b = isdk->rr_b;
            }
            isdk->current_num_pos++;
        }
        while (isdk->gr_b)
        {
            if (isdk->gr_a)
            {
                rr(isdk);
                isdk->gr_a--;
            }
            else
                rb(isdk);
            isdk->gr_b--;
        }
        while (isdk->grr_b)
        {
            if (isdk->grr_a)
            {
                rrr(isdk);
                isdk->grr_a--;
            }
            else
                rrb(isdk);
            isdk->grr_b--;
        }
        while (isdk->gr_a)
        {
            ra(isdk);
            isdk->gr_a--;
        }
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