#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_gnl_buf	buf[OPEN_MAX];
	char				*line;
	char				*p;
	int					n;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (buf[fd].head == buf[fd].tail)
		{
			n = (int)read(fd, buf[fd].data, BUFFER_SIZE);
			if (n <= 0)
			{
				buf[fd].head = buf[fd].tail = buf[fd].data;
				if (n == 0 && line && *line)
					return (line);
				free(line);
				return (NULL);
			}
			buf[fd].head = buf[fd].data;
			buf[fd].tail = buf[fd].data + n;
		}
		p = buf[fd].head;
		while (p < buf[fd].tail && *p != '\n')
			p++;
		line = ft_strjoin(line, buf[fd].head, p + (p < buf[fd].tail));
		if (!line)
			return (NULL);
		if (p < buf[fd].tail)
		{
			buf[fd].head = p + 1;
			return (line);
		}
		buf[fd].head = buf[fd].tail;
	}
}
