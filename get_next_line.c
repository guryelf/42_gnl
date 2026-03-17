/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguryel <fguryel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 09:51:24 by fguryel           #+#    #+#             */
/*   Updated: 2026/03/17 09:51:25 by fguryel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Core idea:
**   Two pointers track where we are inside the static buffer:
**     head – next unread byte
**     tail – one past the last valid byte
**
**   Each call to get_next_line():
**     1. If head == tail (empty / initial), refill the buffer from fd.
**     2. Scan forward from head looking for '\n'.
**     3. Extend line with ft_strjoin(line, head, p + includes_newline).
**     4. If '\n' was found: set head = p + 1 and return line.
**        Otherwise:          set head = tail to trigger a refill
**                            on the next iteration, then loop.
*/

char	*get_next_line(int fd)
{
	static t_gnl_buf	buf;
	char				*line;
	char				*p;
	int					n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (buf.head == buf.tail)
		{
			n = (int)read(fd, buf.data, BUFFER_SIZE);
			if (n <= 0)
			{
				buf.head = buf.tail = buf.data;
				if (n == 0 && line && *line)
					return (line);
				free(line);
				return (NULL);
			}
			buf.head = buf.data;
			buf.tail = buf.data + n;
		}
		p = buf.head;
		while (p < buf.tail && *p != '\n')
			p++;
		line = ft_strjoin(line, buf.head, p + (p < buf.tail));
		if (!line)
			return (NULL);
		if (p < buf.tail)
		{
			buf.head = p + 1;
			return (line);
		}
		buf.head = buf.tail;
	}
}
