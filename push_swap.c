#include "push_swap.h"

int	tab_tried(int *tab, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	push_swap_1(t_value *v, char *av)
{
	v->str = ft_split(av, ' ');
	v->len = len_tab(v->str);
	check_sign(v);
	put_to_tab(v);
	if (tab_tried(v->tab_a, v->len))
	{
		free(v->tab_a);
		free(v->tab_b);
		exit(0);
	}
	else if (v->len <= 3)
		algo_len_3(v);
	else if (v->len == 5)
		algo_len_5(v);
	else
		algo(v);
//	free(v->tab_a);
//	free(v->tab_b);
}

void	push_swap_2(t_value *v, char **av, int ac)
{
	v->len = ac - 1;
	put_to_str(v, av);
	put_to_tab(v);
	if (tab_tried(v->tab_a, v->len))
	{
		free(v->tab_a);
		free(v->tab_b);
		exit(0);
	}
	else if (v->len <= 3)
		algo_len_3(v);
	else if (v->len == 5)
		algo_len_5(v);
	else
		algo(v);
//	free(v->tab_a);
//	free(v->tab_b);
}

int	main(int ac, char **av)
{
	t_value v;

	if (ac == 2)
		push_swap_1(&v, av[1]);
	else if (ac > 2)
		push_swap_2(&v, av, ac);
	else
		write(1, "ERROR\n", 6);
	int i = 0;
	while (i < v.len)
	{
		printf("%i\n", v.tab_a[i]);
		i++;
	}
	return (0);
}
