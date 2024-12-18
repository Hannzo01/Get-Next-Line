/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemzouri <kemzouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:30:39 by kemzouri          #+#    #+#             */
/*   Updated: 2024/12/18 20:32:30 by kemzouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_one_line(int fd, char *store)
{
	char	*buf;
	ssize_t	rr;

	buf = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	while (1)
	{
		rr = read(fd, buf, BUFFER_SIZE);
		if (rr <= 0)
			break ;
		buf[rr] = '\0';
		store = handle_buffer(store, buf);
		if (!store || ft_strchr(store, '\n'))
			break ;
	}
	free(buf);
	if (rr < 0 || (rr == 0 && (store == NULL || *store == '\0')))
	{
		free(store);
		store = NULL;
		return (NULL);
	}
	return (store);
}

static char	*remove_after_newline(char *store)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!store)
		return (NULL);
	while (store[i] && store[i] != '\n')
		i++;
	if (store[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	while (j < i)
	{
		line[j] = store[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*get_remainder(char *store)
{
	int		i;
	char	*tmp;
	int		j;

	i = 0;
	j = 0;
	if (!store)
		return (NULL);
	while (store[i] && store[i] != '\n')
		i++;
	if (store[i] == '\n')
		i++;
	tmp = malloc((ft_strlen(store) - i + 1));
	if (!tmp)
		return (NULL);
	while (store[i])
	{
		tmp[j] = store[i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	free(store);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*store[1024];
	char		*line;

	if (fd < 0)
		return (NULL);
	store[fd] = get_one_line(fd, store[fd]);
	line = remove_after_newline(store[fd]);
	store[fd] = get_remainder(store[fd]);
	return (line);
}
// int main()
// {
//   int fd = open("file1.txt", O_RDONLY);
//   int fd2 = open("file2.txt", O_RDONLY);
//   char *s = get_next_line(fd);
//   printf("%s", s);
//   free(s);
//   s = get_next_line(fd2);
//   printf("%s", s);
//   free(s);
//   s = get_next_line(fd);
//   printf("%s", s);
//   free(s);
//   printf("\n");
//   close(fd);
//   close(fd2);
// }