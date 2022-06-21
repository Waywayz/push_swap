/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovillar <rovillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:05:36 by rovillar          #+#    #+#             */
/*   Updated: 2022/06/21 16:08:27 by rovillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			if (v->tab[i] == v->tab[j])
			{
				write(1, "ERROR\n", 6);
				free(v->tab);
				exit(0);
			}
			j++;
		}
		i++;
	}
	v->tab_a = init_tab_a(v->tab, v->len);
	v->tab_b = init_tab_b(v->len);
	free(v->tab);
}

void	check_nbrs(char *str, t_value *v)
{
	int	i;

	i = 0;
	while (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_exit(v);
		i++;
	}
}

void	check_sign(t_value *v)
{
	int	i;
	int	j;

	i = 0;
	while (v->str[i])
	{
		j = 0;
		while (v->str[i][j])
		{
			if ((v->str[i][j] == '-' || v->str[i][j] == '+')
				&& v->str[i][j + 1] == '\0')
				ft_exit(v);
			if (v->str[i][j] == '-' || v->str[i][j] == '+')
				j++;
			else if (v->str[i][j] >= 0 || v->str[i][j] <= 9)
			{
				check_nbrs(v->str[i], v);
				break ;
			}
			else
				ft_exit(v);
		}
		i++;
	}
}
