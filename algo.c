/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovillar <rovillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:05:25 by rovillar          #+#    #+#             */
/*   Updated: 2022/06/21 16:51:32 by rovillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_len_3(t_value *v)
{
	if (v->len == 2)
	{
		op_sa(v);
		return ;
	}
	if (v->tab_a[0] > v->tab_a[1])
		op_sa(v);
	if (v->tab_a[1] > v->tab_a[2])
		op_rra(v);
	if (v->tab_a[0] > v->tab_a[1])
		op_sa(v);
}

void	algo_len_5(t_value *v)
{
	int	i;

	i = 0;
	while (i < v->len && count_move(v->tab_b, v->len) < 2)
	{
		if (v->tab_a[0] == 1 || v->tab_a[0] == 2)
			op_pb(v);
		else
			op_ra(v);
		i++;
	}
	algo_len_3(v);
	if (v->tab_b[0] < v->tab_b[1])
		op_sb(v);
	op_pa(v);
	op_pa(v);
}

void	all_in_a(t_value *v)
{
	while (count_move(v->tab_b, v->len) >= 1)
		op_pa(v);
}

int	bit_decal(t_value *v)
{
	int	nbr;
	int	i;

	i = 0;
	nbr = v->len;
	while (nbr / 2 >= 1)
	{
		nbr /= 2;
		i++;
	}
	return (i + 2);
}

void	algo(t_value *v)
{
	int	i;
	int	j;
	int	bit;

	i = -1;
	bit = bit_decal(v);
	while (i++ < bit && !tab_tried(v->tab_a, v->len))
	{
		j = count_move(v->tab_a, v->len);
		while (j > 0)
		{
			if (v->tab_a[0] >> i & 1)
				op_ra(v);
			else
				op_pb(v);
			j--;
		}
		j = count_move(v->tab_b, v->len);
		while (j > 0)
		{
			op_pa(v);
			j--;
		}
	}
	all_in_a(v);
}
