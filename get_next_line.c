/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemzouri <kemzouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:59:32 by kemzouri          #+#    #+#             */
/*   Updated: 2024/12/08 12:08:46 by kemzouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_one_line(int fd, char *store)
{
	char	buf[BUFFER_SIZE];
	ssize_t	rr;

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
char	*get_next_line(int fd)
{
	static char	*store;
	char		*line;
	if (!fd || BUFFER_SIZE <= 0)
		return (NULL);
	store = get_one_line(fd, store);
	// line = remove_after_newline(store);
	// store = get_rest(store);
	return (store);
}
int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *store = get_next_line(fd);
	printf("%s", store);
}
