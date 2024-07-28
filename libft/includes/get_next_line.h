/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:10:43 by npentini          #+#    #+#             */
/*   Updated: 2024/07/07 18:52:54 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_gnl_mlist
{
	char				*content;
	struct s_gnl_mlist	*next;
}		t_gnl_mlist;

char		*get_next_line(int fd);
void		fetching_m(t_gnl_mlist **list, int fd);
void		ft_lstnewadd_back_m(t_gnl_mlist **list, char *s);
void		reset_list_m(t_gnl_mlist **list);
t_gnl_mlist	*ft_lstlast_m(t_gnl_mlist *list);
int			newline_tracker_m(t_gnl_mlist *list);
int			consolidation_len_m(t_gnl_mlist *list);
char		*transfer_str_m(t_gnl_mlist *list, char *s);
void		ft_lstclear_m(t_gnl_mlist **list, t_gnl_mlist *clean_node, char *s);
#endif
