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
#include <stdio.h>

char *get_next_line(int fd)
{
	static char	*st;
	char *line;
	if (!fd || BUFFER_SIZE <= 0)
		return (NULL);
	st = get_line(fd,st);
	line = ft_sub(st);
	st = get_rest();
}
