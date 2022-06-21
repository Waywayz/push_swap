/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovillar <rovillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:06:28 by rovillar          #+#    #+#             */
/*   Updated: 2022/06/21 16:12:20 by rovillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fil_tab(int nbr, int *tab, int len)
{
	int	i;
	int	res;

	i = 0;
	res = -1;
	while (i < len)
	{
		if (nbr >= tab[i])
			res++;
		i++;
	}
	return (res);
}

int	*init_tab_a(int *tab, int len)
{
	int	i;
	int	*tab_a;

	i = 0;
	tab_a = ft_calloc(len + 1, sizeof(int));
	if (!tab_a)
		return (0);
	while (i < len)
	{
		tab_a[i] = fil_tab(tab[i], tab, len) + 1;
		i++;
	}
	return (tab_a);
}

int	*init_tab_b(int len)
{
	int	*tab_b;

	tab_b = ft_calloc(len + 1, sizeof(int));
	if (!tab_b)
		return (0);
	return (tab_b);
}

int	count_move(int *tab, int len)
{
	int	i;
	int	m;

	i = 0;
	m = 0;
	while (i < len)
	{
		if (tab[i])
			m++;
		else
			break ;
		i++;
	}
	return (m);
}

int	len_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i < 2)
	{
		while (i >= 0)
		{
			free(str[i]);
			i--;
		}
		free(str);
		write(1, "ERROR\n", 6);
		exit(0);
	}
	return (i);
}
