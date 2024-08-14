/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error_codes.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 03:00:05 by npentini          #+#    #+#             */
/*   Updated: 2024/08/14 18:36:51 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_ERROR_CODES_H
# define PUSH_SWAP_ERROR_CODES_H

// error codes
# define ERR_ONE_ARG 999// only one argument
# define EPSARG 1000 // insufficient argument
# define ERR_OTHR_EL 1001 // argument/s has other element aside what instructed
# define ERR_MALLOC_FAILED 1003 // Memory allocation fails.
# define ERR_INT_LIMIT 1004 // Argument is more than int limits
# define ERR_DUP_ARG 1005 // Argument has duplicates.
# define ERR_SORTED_ARGS 1006 // Argument is sorted.
# define ERR_INVALID_PROTOCOL 1999 //null between the head and tail protocols
// error messages
# define EMSG_EPSARG "Insufficient arguments!!!"
# define EMSG_EPSINA "Invalid Argument/s!!!"
# define EMSG_EPSMAL "Memory allocation fails!!!"
# define EMSG_EPSALM "Arguments are greater/less than INT limit!!!"
# define EMSG_EPSDUP "Arguments has a duplicate numbers!!!"
# define EMSG_EPSSRT "Argument is already sorted 😉!"
// protocol strings
# define STR_SA "sa"
# define STR_SB "sb"
# define STR_SS "ss"
# define STR_PA "pa"
# define STR_PB "pb"
# define STR_RA "ra"
# define STR_RB "rb"
# define STR_RR "rr"
# define STR_RRA "rra"
# define STR_RRB "rrb"
# define STR_RRR "rrr"
# define STR_COUNT 11
# define PROCESS_COUNT 7
# define CPROCESS_COUNT 5

#endif