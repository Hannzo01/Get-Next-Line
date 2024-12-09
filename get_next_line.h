#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 9
#endif

/* HEADERS */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/* FUNCTIONS */
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_substr(char *s, size_t start, int len);

#endif 