#include "push_swap.h"

void	op_rra(t_value *v)
{
	int	tmp;

	tmp = v->tab_a[v->len - 1];
	swipe_down(v->tab_a, v->len);
	v->tab_a[0] = tmp;
	write(1, "rra\n", 4);
}

void	op_rrb(t_value *v)
{
	int	tmp;

	tmp = v->tab_b[v->len - 1];
	swipe_down(v->tab_b, v->len);
	v->tab_b[0] = tmp;
	write(1, "rrb\n", 4);
}

void	op_rrr(t_value *v)
{
	op_rra(v);
	op_rrb(v);
	write(1, "rrr\n", 4);
}