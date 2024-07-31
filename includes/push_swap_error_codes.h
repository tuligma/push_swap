/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error_codes.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 03:00:05 by npentini          #+#    #+#             */
/*   Updated: 2024/07/31 22:59:54 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_ERROR_CODES_H
# define PUSH_SWAP_ERROR_CODES_H

// error codes
# define EPSARG 1000 // insufficient argument
# define EPSINA 1001 // argument/s has other element aside what instructed
# define EPSMAL 1003 // Memory allocation fails.
# define EPSALM 1004 // Argument is more than int limits
# define EPSDUP 1005 // Argument has duplicates.
# define EPSSRT 1006 // Argument is sorted.


// error messages
#define EMSG_EPSARG "Insufficient arguments!!!"
#define EMSG_EPSINA "Invalid Argument/s!!!"
# define EMSG_EPSMAL "Memory allocation fails!!!"
# define EMSG_EPSALM "Arguments are greater/less than INT limit!!!"
# define EMSG_EPSDUP "Arguments has a duplicate numbers!!!"
# define EMSG_EPSSRT "Argument is already sorted 😉!"

#define SA 11
#define SB 12
#define SS 13
#define PA 21
#define PB 22
#define RA 31
#define RB 32
#define RR 33
#define RRA 41
#define RRB 42
#define RRR 43

#define STR_SA "sa"
#define STR_SB "sb"
#define STR_SS "ss"
#define STR_PA "pa"
#define STR_PB "pb"
#define STR_RA "ra"
#define STR_RB "rb"
#define STR_RR "rr"
#define STR_RRA "rra"
#define STR_RRB "rrb"
#define STR_RRR "rrr"
#define PROTO_COUNT 11

#endif