#ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#ifndef OPEN_MAX
# define OPEN_MAX 1024
#endif

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

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
