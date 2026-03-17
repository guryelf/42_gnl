/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguryel <fguryel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 09:51:39 by fguryel           #+#    #+#             */
/*   Updated: 2026/03/17 09:51:40 by fguryel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_gnl_buf
{
	char	data[BUFFER_SIZE + 1];
	char	*head;
	char	*tail;
}	t_gnl_buf;

char	*get_next_line(int fd);
char	*ft_strjoin(char *line, char *buf_start, char *buf_end);
size_t	ft_strlen(const char *s);

#endif
