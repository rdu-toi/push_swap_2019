#include "checker.h"

void    push_all_b(t_idk *isdk)
{
    while (isdk->bctr)
        pb(isdk);
}

void    best_move(t_idk *isdk)
{
    pa(isdk);
    pa(isdk);
    isdk->bctr = 2;
    int b_highest = 0;
    int b_lowest = 2147483647;
    if (isdk->bhead->stk > isdk->bhead->next->stk)
    {
        b_highest = isdk->bhead->stk;
        b_lowest = isdk->bhead->next->stk;
    }
    else
    {
        b_lowest = isdk->bhead->stk;
        b_highest = isdk->bhead->next->stk;
    }
    
    if (isdk->bhead->stk < isdk->bhead->next->stk)
        sb(isdk);
    while (isdk->actr) {
        int current_num_pos = 1;
        int gr_a = 0;       // greatest ra
        int grr_a = 0;      // greatest rra
        int gr_b = 0;      // next greatest rb
        int grr_b = isdk->bctr;     // next greatest rrb
        int best_num_of_moves = 2147483647;
        while (current_num_pos <= isdk->actr) {
            int num_of_moves_ra_rb = 0;
            int num_of_moves_rra_rb = 0;
            int num_of_moves_ra_rrb = 0;
            int num_of_moves_rra_rrb = 0;
            int r_b = 0;
            int rr_b = isdk->bctr;
            isdk->tempa = isdk->ahead;
            int i = 1;
            while (i < current_num_pos) {
                isdk->tempa = isdk->tempa->next;
                i++;
            }
            isdk->tempb = isdk->bhead;
            fprintf(stderr, "stack a num: %d at pos: %d\n1st num stack b: %d, 2nd num stack b: %d\n", isdk->tempa->stk, current_num_pos, isdk->tempb->stk, isdk->tempb->next->stk);
            while (isdk->tempb != NULL)
            {
                if (isdk->tempa->stk > b_highest && b_highest == isdk->tempb->stk)
                    break;
                r_b++;
                rr_b--;
                if ((isdk->tempa->stk < isdk->tempb->stk && isdk->tempb->next && isdk->tempa->stk > isdk->tempb->next->stk) ||
                    (isdk->tempa->stk < b_lowest && b_lowest == isdk->tempb->stk))
                    break;
                isdk->tempb = isdk->tempb->next;
            }
            printf("r_b = %d, rr_b = %d\n", r_b, rr_b);
            int r_a = current_num_pos - 1;
            int rr_a = isdk->actr - current_num_pos + 1;
            num_of_moves_ra_rb = r_a + r_b - ((r_a >= r_b) ? r_b : r_a);
            num_of_moves_rra_rb = rr_a + r_b;
            num_of_moves_ra_rrb = r_a + rr_b;
            num_of_moves_rra_rrb = rr_a + rr_b - ((rr_a >= rr_b) ? rr_b : rr_a);
            if (num_of_moves_ra_rb < best_num_of_moves)
            {
                best_num_of_moves = num_of_moves_ra_rb;
                gr_a = r_a;
                grr_a = 0;
                gr_b = r_b;
                grr_b = 0;
            }
            if (num_of_moves_rra_rb < best_num_of_moves)
            {
                best_num_of_moves = num_of_moves_rra_rb;
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
        if (isdk->bhead->stk > b_highest)
            b_highest = isdk->bhead->stk;
        else if (isdk->bhead->stk < b_lowest)
            b_lowest = isdk->bhead->stk;
    }
}