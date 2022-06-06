#include "push_swap.h"

void	**put_to_str(t_value *v, char **av)
{
	char	*str;
	int	i;

	i = 1;
	str = "";
	str = malloc(sizeof(char) + 1);
	if (!str)
		return (0);
	while (av[i])
	{
	
		str = ft_strjoin(str, av[i]);
		str = ft_strjoin(str, "\n");
		i++;
	}
	v->str = ft_split(str, '\n');
	free(str);
	check_sign(v);
	return (0);
}

void	free_str(t_value *v)
{
	int	i;

	i = v->len - 1;
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
	v->tab = malloc(sizeof(int) * v->len);
	if (!v->tab)
		return (0);
	while (v->str[i])
	{
		if (ft_atoi(v->str[i]) > 2147483647 || ft_atoi(v->str[i]) < -2147483648)
		{
			write(1, "ERROR\n", 6);
			free(v->tab);
			exit(0);
		}
		v->tab[i] = ft_atoi(v->str[i]);
		i++;
	}
	free_str(v);
	check_same(v);
	return (0);
}
