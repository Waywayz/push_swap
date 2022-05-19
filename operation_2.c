#include "push_swap.h"

void	op_pa(t_value *v)
{
	if (v->tab_b[0])
	{
		swipe_down(v->tab_a, v->len);
		v->tab_a[0] = v->tab_b[0];
		v->tab_b[0] = 0;
		swipe_up(v->tab_b, v->len);
		write(1, "pa\n", 3);
	}
}

void	op_pb(t_value *v)
{
	if (v->tab_a[0])
	{
		swipe_down(v->tab_b, v->len);
		v->tab_b[0] = v->tab_a[0];
		v->tab_a[0] = 0;
		swipe_up(v->tab_a, v->len);
		write(1, "pb\n", 3);
	}
}

void	op_ra(t_value *v)
{
	int	tmp;
	int	len;

	len = count_move(v->tab_a, v->len);
	if (len > 1)
	{
		tmp = v->tab_a[0];
		swipe_up(v->tab_a, v->len);
		v->tab_a[len - 1] = tmp;
		write(1, "ra\n", 3);
	}
}

void	op_rb(t_value *v)
{
	int	tmp;
	int	len;

	len = (count_move(v->tab_b, v->len));
	if (len > 1)
	{
		tmp = v->tab_b[0];
		swipe_up(v->tab_b, v->len);
		v->tab_b[len - 1] = tmp;
		write(1, "rb\n", 3);
	}
}

void	op_rr(t_value *v)
{
	op_ra(v);
	op_rb(v);
	write(1, "rr\n", 3);
}
