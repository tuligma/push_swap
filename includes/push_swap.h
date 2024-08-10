/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 00:44:08 by npentini          #+#    #+#             */
/*   Updated: 2024/08/10 11:38:51 by npentini         ###   ########.fr       */
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
	int		start;
	int		end;
	int		min;
	int		max;
	int		count;
	t_list	*head;
	t_list	*tail;
}	t_ps_stack;

typedef struct s_ps_series
{
	
	int	*series;
	int	start;
	int	end;
	int	length;
	t_ps_stack *x;
}	t_ps_series;

typedef struct s_ps_cost
{
	int best_step;
	int	reverse_a;
	int	reverse_b;
	int	pos_a;
	int	pos_b;
}	t_ps_cost;

typedef struct s_ps_hub
{
	t_ps_stack *a;
	t_ps_stack *b;
	t_ps_series *series;
	t_ps_cost *cost;
	int (**process)(struct s_ps_hub *);
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
# include "push_swap_algorithm.h"
# include "push_swap_partition.h"
# include "push_swap_merge.h"

int	(**process_init(void))(t_ps_hub *);
#endif