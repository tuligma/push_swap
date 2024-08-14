/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 00:44:08 by npentini          #+#    #+#             */
/*   Updated: 2024/08/14 20:27:43 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/includes/libft.h"

# include "push_swap_data_structures.h"
# include "push_swap_error_codes.h"
# include "push_swap_error.h"
# include "push_swap_init.h"
# include "push_swap_free.h"
# include "push_swap_presort.h"
# include "push_swap_protocols.h"
# include "push_swap_algorithm.h"
# include "push_swap_partition.h"
# include "push_swap_merge.h"
# include "checker.h"

void	print_node_int(void *content);

#endif