#include "push_swap.h"

void	ft_exit(t_value *v)
{
	int	i;

	i = v->len;
	while (i >= 0)
	{
		free(v->str[i]);
		i--;
	}
	free(v->str);
	write(1, "ERROR\n", 6);
	exit(0);
	return ;
}

void	check_same(t_value *v)
{
	int	i;
	int	j;

	i = 0;
	while (i < v->len)
	{
		j = i + 1;
		while (j < v->len)
		{
			if (v->tab_a[i] == v->tab_a[j])
			{
				write(1, "ERROR\n", 6);
				free(v->tab_a);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	check_nbrs(t_value *v)
{
	int	i;
	int	j;

	i = 0;
	while (v->str[i])
	{
		j = 1;
		if (v->str[i][0] == '-' && v->str[i][1] == '\0')
			ft_exit(v);
		if (v->str[i][0] == '-' || (v->str[i][0] >= '0' && v->str[i][0] <= '9'))
		{
			while (v->str[i][j])
			{
				if (v->str[i][j] < '0' || v->str[i][j] > '9')
					ft_exit(v);
				j++;
			}
		}
		else
			ft_exit(v);
		i++;
	}
}
