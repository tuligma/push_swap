/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 00:44:08 by npentini          #+#    #+#             */
/*   Updated: 2024/07/28 05:36:21 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../lib/src/ft_printf/includes/ft_printf.h"
# include "../lib/includes/push_swap_lib.h"

typedef struct s_ps_sa
{
	int	*data;
	struct s_ps_sa *next;
	struct s_ps_sa *prev;
}	t_ps_sa;

typedef struct s_ps_sb
{
	int	*data;
	struct s_ps_sb *next;
	struct s_ps_sb *prev;
}	t_ps_sb;

typedef struct s_ps_hub
{
	int *args;
	int	arg_count;
	int	i;
	t_ps_sa *sa;
	t_ps_sb *sb;
}	t_ps_hub;

# include "push_swap_error_codes.h"
# include "push_swap_error.h"
# include "push_swap_init.h"
# include "push_swap_free.h"

#endif