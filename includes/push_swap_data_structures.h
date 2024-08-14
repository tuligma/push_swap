/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_data_structures.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 20:25:49 by npentini          #+#    #+#             */
/*   Updated: 2024/08/14 20:37:36 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_DATA_STRUCTURES_H
# define PUSH_SWAP_DATA_STRUCTURES_H

typedef struct s_ps_stack
{
	int		start;
	int		end;
	int		count;
	t_list	*head;
	t_list	*tail;
}	t_ps_stack;

typedef struct s_ps_series
{
	int			*series;
	int			start;
	int			end;
	int			length;
	t_ps_stack	*x;
}	t_ps_series;

typedef struct s_ps_cost
{
	int	best_step;
	int	reverse_a;
	int	reverse_b;
	int	pos_a;
	int	pos_b;
}	t_ps_cost;

typedef struct s_ps_hub
{
	t_ps_stack	*a;
	t_ps_stack	*b;
	t_ps_stack	*checker;
	t_ps_series	*series;
	t_ps_cost	*cost;
	int			(**process)(struct s_ps_hub *);
	int			*args;
	int			arg_count;
	int			i;
	int			min;
	int			max;
	int			total_moves;
}	t_ps_hub;

#endif