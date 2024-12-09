/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemzouri <kemzouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:59:32 by kemzouri          #+#    #+#             */
/*   Updated: 2024/12/09 23:54:30 by kemzouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_one_line(int fd, char *store)
{
	char	*buf;
	ssize_t	rr;

	buf = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	// rr = 1;  while (rr >= 1)
	while (1)
	{
		rr = read(fd, buf, BUFFER_SIZE);
		if (rr <= 0)
			break;
		buf[rr] = '\0';
		if (!store)
			store = ft_strdup("");
		store = ft_strjoin(store, buf);
		if (!store || ft_strchr(store, '\n'))
			break ;
	}
	free(buf);
	buf = NULL;
	if (rr < 0 || (rr == 0 && (!store || !*store)))
		return (free(store), store = NULL, NULL);
	return (store);
}

char	*remove_after_newline(char *store)
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
	while (store[i] && store[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	while (j < i + 1)
	{
		line[j] = store[j];
		j++;
 	}
	line[j] = '\0';
	return (line);
}
char	*get_rest(char *store)
{
	int		i;
	int		len;
	char	*tmp;
	int		j;

	i = 0;
	j = 0;
	if (!store)
		return (NULL);
	len = ft_strlen(store);
	while (store[i] && store[i] != '\n')
		i++;
	while (store[i] && store[i] == '\n')
		i++;
	tmp = malloc(sizeof(char) * (i + 1));
	if (tmp == NULL)
		return (NULL);
	while (store[i])
	{
		i++;
		tmp[j] = store[i];
		j++;
	}
	tmp[j] = '\0';
	free(store);
	return (tmp);
}
char	*get_next_line(int fd)
{
	static char	*store;
	char		*line;
	if (!fd || BUFFER_SIZE <= 0)
		return (NULL);
	store = get_one_line(fd, store);
	if (!store)
		return (free(store), store = NULL, NULL);
	line = remove_after_newline(store);
	store = get_rest(store);
	if (!line)
		return (free(store), store = NULL, NULL);
	return (line);
}
int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *store ;
	while ((store = get_next_line(fd)) != NULL)
	{

		printf("%s", store);
		free(store);
	}
	close(fd);
}
