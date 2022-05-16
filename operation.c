#include "push_swap.h"

void	op_sa(t_value *v)
{
	int	tmp;

	tmp = v->tab_a[0];
	v->tab_a[0] = v->tab_a[1];
	v->tab_a[1] = tmp;
	ft_printf("sa\n");
}
/*
void	op_rra(t_value v)
{
	int	tmp;
	int	tmp_2;
	int	i;

	i = 0;
	tmp_2 = v.tab[len - 1];
	while (i < v.len - 1)
	{
		tmp = v.tab_a[i + 1];
		v.tab_a[i + 1] = v.tab_a[i];
		v.tab_a[i] = tmp;
		i++;
	}
	tmp = tab[0];
}
*/
