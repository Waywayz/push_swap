#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

# include <stdio.h>

typedef struct	s_value
{
	int	len;
	char	**str;
	int	*tab;
	int	*tab_a;
	int	*tab_b;
}		t_value;

void	check_sign(t_value *v);
void	check_same(t_value *v);
int	*init_tab_a(int *tab, int len);
int	*init_tab_b(int len);
int	len_tab(char **str);
int	count_move(int *tab, int len);
void	algo_len_3(t_value *v);
void	algo_len_5(t_value *v);
void	algo(t_value *v);
void	swipe_up(int *tab, int len);
void	swipe_down(int *tab, int len);
void	op_sa(t_value *v);
void	op_sb(t_value *v);
void	op_ss(t_value *v);
void	op_pa(t_value *v);
void	op_pb(t_value *v);
void	op_ra(t_value *v);
void	op_rb(t_value *v);
void	op_rr(t_value *v);
void	op_rra(t_value *v);
void	op_rrb(t_value *v);
void	op_rrr(t_value *v);

#endif
