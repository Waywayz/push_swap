#include "push_swap.h"

void	algo_len_3(t_value *v)
{
	if (v->len == 2)
	{
		op_sa(v);
		return ;
	}
	else if (v->tab_a[0] > v->tab_a[1])
		op_sa(v);
//	else if (v->tab_a[1] > v->tab_a[2])
//		op_rra(v);
}
