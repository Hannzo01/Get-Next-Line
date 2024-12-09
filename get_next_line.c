/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemzouri <kemzouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:59:32 by kemzouri          #+#    #+#             */
/*   Updated: 2024/12/09 16:36:08 by kemzouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_one_line(int fd, char *store)
{
	char	buf[BUFFER_SIZE];
	ssize_t	rr;
	int		i;
	
	i = 0;
	store = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (store == NULL)
		return (NULL);
	rr = read(fd, buf, BUFFER_SIZE);
	if (rr == -1)
	 		return (NULL);
	if (rr == 0)
			return (store);
	while(rr >= 1)
	{
		while (i < rr)
		if (ft_strchr(buf, '\n'))
		{
			store = ft_strjoin(store, buf);
			return (store);
		}
		store = ft_strjoin(store, buf);
		printf("buf content : %s\n", buf);
		printf("store content : %s\n", store);
	}
	return (store);
}

char	*remove_after_newline(char *store)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (store[i] && store[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
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
	len = ft_strlen(store);
	while (store[i] && store[i] != '\n')
		i++;
	tmp = malloc(sizeof(char) * (len - i + 1));
	if (tmp = NULL)
		return (NULL);
	while (store[i])
		tmp[j++] = store[i++];
	free(store);
	printf("%s",tmp);
	return (tmp);
}
char	*get_next_line(int fd)
{
	static char	*store;
	char		*line;
	if (!fd || BUFFER_SIZE <= 0)
		return (NULL);
	store = get_one_line(fd, store);
	line = remove_after_newline(store);
	store = get_rest(store);
	return (line);
}
int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *store = get_next_line(fd);
	printf("%s", store);
	free(store);
}
