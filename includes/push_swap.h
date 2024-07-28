/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 00:44:08 by npentini          #+#    #+#             */
/*   Updated: 2024/07/29 03:29:22 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/includes/libft.h"

typedef struct s_ps_node
{
	int	*data;
	struct s_ps_sa *next;
	struct s_ps_sa *prev;
}	t_ps_node;

typedef struct s_ps_stack
{
	t_ps_node	*head;
	t_ps_node	*tail;
	int			min;
	int			median;
	int			max;
	int			size;
}	t_ps_stack;

typedef struct s_ps_hub
{
	t_ps_stack *a;
	t_ps_stack *b;
	int *args;
	int	arg_count;
	int	i;
	int	sorted;
}	t_ps_hub;

# include "push_swap_error_codes.h"
# include "push_swap_error.h"
# include "push_swap_init.h"
# include "push_swap_free.h"

#endif