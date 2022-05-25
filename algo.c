#include "push_swap.h"

void	algo_len_3(t_value *v)
{
	if (v->len == 2)
	{
		op_sa(v);
		return ;
	}
	if (v->tab_a[0] > v->tab_a[1])
		op_sa(v);
	if (v->tab_a[1] > v->tab_a[2])
		op_rra(v);
	if (v->tab_a[0] > v->tab_a[1])
		op_sa(v);
}

void	algo_len_5(t_value *v)
{
	int	i;

	i = 0;
	while (i < v->len && count_move(v->tab_b, v->len) < 2)
	{
		if (v->tab_a[0] == 1 || v->tab_a[0] == 2)
			op_pb(v);
		else
			op_ra(v);
		i++;
	}
	algo_len_3(v);
	if (v->tab_b[0] < v->tab_b[1])
		op_sb(v);
	op_pa(v);
	op_pa(v);
}

void	all_in_a(t_value *v)
{
	while (count_move(v->tab_b, v->len) >= 1)
		op_pa(v);
}

void	algo(t_value *v)
{
	int	j;

	j = 1;
	while (count_move(v->tab_b, v->len) < v->len - 3)
	{
		if (v->tab_a[0] == j)
		{
			op_pb(v);
			j++;
		}
		else
			op_ra(v);
	}
	algo_len_3(v);
	all_in_a(v);
}
