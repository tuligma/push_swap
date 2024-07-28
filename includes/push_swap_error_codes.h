/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error_codes.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 03:00:05 by npentini          #+#    #+#             */
/*   Updated: 2024/07/28 15:23:31 by npentini         ###   ########.fr       */
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


// error messages
#define EMSG_EPSARG "Insufficient arguments!!!"
#define EMSG_EPSINA "Invalid Argument/s!!!"
# define EMSG_EPSMAL "Memory allocation fails!!!"
# define EMSG_EPSALM "Arguments are greater/less than INT limit!!!"
# define EMSG_EPSDUP "Arguments has a duplicate numbers!!!"

#endif