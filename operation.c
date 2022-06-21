/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovillar <rovillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:06:10 by rovillar          #+#    #+#             */
/*   Updated: 2022/06/21 16:06:11 by rovillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swipe_up(int *tab, int len)
{
	int	i;

	i = 0;
	if (len > 1)
	{
		while (i < len)
		{
			tab[i] = tab[i + 1];
			i++;
		}
	}
}

void	swipe_down(int *tab, int len)
{
	int	i;

	i = len;
	if (len > 1)
	{
		while (i >= 0)
		{
			tab[i] = tab[i - 1];
			i--;
		}
	}
}

void	op_sa(t_value *v)
{
	int	tmp;

	if (v->tab_a[0] && v->tab_a[1])
	{
		tmp = v->tab_a[0];
		v->tab_a[0] = v->tab_a[1];
		v->tab_a[1] = tmp;
		write(1, "sa\n", 3);
	}
}

void	op_sb(t_value *v)
{
	int	tmp;

	if (v->tab_b[0] && v->tab_b[1])
	{
		tmp = v->tab_b[0];
		v->tab_b[0] = v->tab_b[1];
		v->tab_b[1] = tmp;
		write(1, "sb\n", 3);
	}
}

void	op_ss(t_value *v)
{
	op_sa(v);
	op_sb(v);
	write(1, "ss\n", 3);
}
