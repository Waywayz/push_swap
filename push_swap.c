#include "push_swap.h"
#include <stdio.h>
void	**put_to_str(t_value *v, char **av)
{
	char	*str;
	int	i;

	i = 1;
	str = "";
	v->str = malloc(sizeof(char *) * v->len);
	if (!v->str)
		return (0);
	while (av[i])
	{
	
		str = ft_strjoin(str, av[i]);
		str = ft_strjoin(str, "\n");
		i++;
	}
	v->str = ft_split(str, '\n');
	free (str);
	check_nbrs(v);
	return (0);
}

void	free_str(t_value *v)
{
	int	i;

	i = v->len;
	while (i >= 0)
	{
		free(v->str[i]);
		i--;
	}
	free(v->str);
}

void	*put_to_tab(t_value *v)
{
	int	i;

	i = 0;
	v->tab_a = malloc(sizeof(int) * v->len);
	if (!v->tab_a)
		return (0);
	while (v->str[i])
	{
		if (ft_atoi(v->str[i]) > 2147483647 || ft_atoi(v->str[i]) < -2147483648)
		{
			write(1, "ERROR\n", 6);
			free(v->tab_a);
			exit(0);
		}
		v->tab_a[i] = ft_atoi(v->str[i]);
		i++;
	}
	free_str(v);
	check_same(v);
	return (0);
}

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


int	main(int ac, char **av)
{
	t_value v;

	if (ac > 2)
	{
		v.len = ac - 1;
		put_to_str(&v, av);
		put_to_tab(&v);
/*		if (tab_tried(v.tab_a, v.len) == 1)
			free(v.tab_a);
		else if (v.len <= 3)
			algo_len_3(&v);
*/
		int i = 0;
		op_rra(&v);
		while (i < v.len)
		{
			printf("%i\n", v.tab_a[i]);
			i++;
		}
	}
	return (0);
}
