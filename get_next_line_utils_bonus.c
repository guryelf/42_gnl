/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguryel <fguryel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 09:51:31 by fguryel           #+#    #+#             */
/*   Updated: 2026/03/17 09:51:32 by fguryel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
** Returns the length of string s (NULL-safe).
*/
size_t	ft_strlen(const char *s)
{
	const char	*p;

	if (!s)
		return (0);
	p = s;
	while (*p)
		p++;
	return ((size_t)(p - s));
}

/*
** Appends [buf_start, buf_end) to the existing line and returns the new string.
** Frees the old line and returns NULL on allocation failure.
*/
char	*ft_strjoin(char *line, char *buf_start, char *buf_end)
{
	char	*new_line;
	char	*dst;
	char	*src;

	new_line = malloc(ft_strlen(line) + (size_t)(buf_end - buf_start) + 1);
	if (!new_line)
	{
		free(line);
		return (NULL);
	}
	dst = new_line;
	src = line;
	while (src && *src)
		*dst++ = *src++;
	while (buf_start < buf_end)
		*dst++ = *buf_start++;
	*dst = '\0';
	free(line);
	return (new_line);
}
