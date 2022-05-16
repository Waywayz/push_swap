#include "push_swap.h"

char	**put_to_str(t_value v, char **av)
{
	char	*str;
	int	i;

	i = 1;
	str = "";
	v.str = malloc(sizeof(char *) * v.len);
	if (!v.str)
		return (0);
	while (av[i])
	{
	
		str = ft_strjoin(str, av[i]);
		str = ft_strjoin(str, "\n");
		i++;
	}
	v.str = ft_split(str, '\n');
	free (str);
	return (v.str);
}

void	free_str(t_value v)
{
	int	i;

	i = v.len;
	while (i >= 0)
	{
		free(v.str[i]);
		i--;
	}
	free(v.str);
}

int	*put_to_tab(t_value v, char **str)
{
	int	*tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * v.len);
	if (!tab)
		return (0);
	while (str[i])
	{
		if (ft_atoi(str[i]) > 2147483647 || ft_atoi(str[i]) < -2147483648)
		{
			ft_printf("ERROR\n");
			free(tab);
			exit(0);
		}
		tab[i] = ft_atoi(str[i]);
		i++;
	}
	free_str(v);
	check_same(tab, v);
	return (tab);
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
		v.str = put_to_str(v, av);
		check_nbrs(v);
		v.tab_a = put_to_tab(v, v.str);
		if (tab_tried(v.tab_a, v.len) == 1)
			free(v.tab_a);
		else if (v.len <= 3)
			algo_len_3(&v);
	}
	return (0);
}
