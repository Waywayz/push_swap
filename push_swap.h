#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "./libft/libft.h"

typedef struct	s_value
{
	int	len;
	char	**str;
	int	*tab_a;
	int	*tab_b;
}		t_value;

int	ft_printf(const char *input, ...);
void	check_nbrs(t_value v);
void	check_same(int *tab, t_value v);
void	algo_len_3(t_value *v);
void	op_sa(t_value *v);
void	op_sb(t_value v);
void	op_ss(t_value v);

#endif
