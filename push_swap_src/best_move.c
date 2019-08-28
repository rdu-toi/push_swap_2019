#include "checker.h"

void    push_all_b(t_idk *isdk)
{
    while (isdk->bctr)
        pb(isdk);
}

void    cycle_stacka(t_idk *isdk)
{
while (isdk->actr) {
        isdk->current_num_pos = 1;
        isdk->gr_a = 0;       // greatest ra
        isdk->grr_a = 0;      // greatest rra
        isdk->gr_b = 0;      // next greatest rb
        isdk->grr_b = isdk->bctr;     // next greatest rrb
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
                i++;
            }
            isdk->tempb = isdk->bhead;
            while (isdk->tempb != NULL)
            {
                if (isdk->tempa->stk > isdk->b_highest && isdk->b_highest == isdk->tempb->stk)
                    break;
                r_b++;
                rr_b--;
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
                gr_a = 0;
                grr_a = rr_a;
                gr_b = r_b;
                grr_b = 0;
            }
            if (num_of_moves_ra_rrb < best_num_of_moves)
            {
                best_num_of_moves = num_of_moves_ra_rrb;
                gr_a = r_a;
                grr_a = 0;
                gr_b = 0;
                grr_b = rr_b;
            }
            if (num_of_moves_rra_rrb < best_num_of_moves)
            {
                best_num_of_moves = num_of_moves_rra_rrb;
                gr_a = 0;
                grr_a = rr_a;
                gr_b = 0;
                grr_b = rr_b;
            }
            current_num_pos++;
        }
        while (gr_b)
        {
            if (gr_a)
            {
                rr(isdk);
                gr_a--;
            }
            else
                rb(isdk);
            gr_b--;
        }
        while (grr_b)
        {
            if (grr_a)
            {
                rrr(isdk);
                grr_a--;
            }
            else
                rrb(isdk);
            grr_b--;
        }
        while (gr_a)
        {
            ra(isdk);
            gr_a--;
        }
        while (grr_a)
        {
            rra(isdk);
            grr_a--;
        }
        pa(isdk);
        if (isdk->bhead->stk > isdk->b_highest)
            isdk->b_highest = isdk->bhead->stk;
        else if (isdk->bhead->stk < isdk->b_lowest)
            isdk->b_lowest = isdk->bhead->stk;
    }
    isdk->tempb = isdk->bhead;
    int i = 0;
    while (isdk->tempb != NULL)
    {
        if (isdk->tempb->stk == isdk->b_highest)
            break;
        i++;
        isdk->tempb = isdk->tempb->next;
    }
    if (i + i > isdk->bctr)
    {
        i = isdk->bctr - i;
        while (i > 0)
        {
            rrb(isdk);
            i--;
        }
    }
    else
    {
        while (i > 0)
        {
            rb(isdk);
            i--;
        }
    }
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