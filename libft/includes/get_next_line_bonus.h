/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:10:43 by npentini          #+#    #+#             */
/*   Updated: 2024/07/07 18:52:40 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_gnl_blist
{
	char				*content;
	struct s_gnl_blist	*next;
}		t_gnl_blist;

char		*get_next_line_b(int fd);
void		fetching_b(t_gnl_blist **list, int fd);
void		ft_lstnewadd_back_b(t_gnl_blist **list, char *s, int fd);
void		reset_list_b(t_gnl_blist **list);
t_gnl_blist	*ft_lstlast_b(t_gnl_blist *list);
int			newline_tracker_b(t_gnl_blist *list);
int			consolidation_len_b(t_gnl_blist *list);
char		*transfer_str_b(t_gnl_blist *list, char *s);
void		ft_lstclear_b(t_gnl_blist **list, t_gnl_blist *clean_node, char *s);
#endif
