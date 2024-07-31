/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 00:44:08 by npentini          #+#    #+#             */
/*   Updated: 2024/07/31 23:37:45 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/includes/libft.h"

typedef struct s_ps_stack
{
	int		count;
	t_list	*head;
	t_list	*tail;
}	t_ps_stack;

typedef struct s_ps_move
{
	char	*sa;
	char	*sb;
	char	*ss;
	char	*pa;
	char	*pb;
	char	*ra;
	char	*rb;
	char	*rr;
	char	*rra;
	char	*rrb;
	char	*rrr;
}	t_ps_move;

typedef struct s_ps_hub
{
	t_ps_stack *a;
	t_ps_stack *b;
	t_list		*moves;
	t_ps_move *protocols;
	int *args;
	int	arg_count;
	int	i;
	int	sorted;
	int	min;
	int	median;
	int	max;
	int	d_min_mid;
	int	d_mid_max;
	int	total_moves;
}	t_ps_hub;

# include "push_swap_error_codes.h"
# include "push_swap_error.h"
# include "push_swap_init.h"
# include "push_swap_free.h"
# include "push_swap_presort.h"
# include "push_swap_protocols.h"

int	push_args_to_node(t_ps_hub *data);
void	print_node(void *content);
void	print_protocols(void **moves);

#endif