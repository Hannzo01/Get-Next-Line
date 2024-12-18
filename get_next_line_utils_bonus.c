/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemzouri <kemzouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:30:33 by kemzouri          #+#    #+#             */
/*   Updated: 2024/12/18 20:43:45 by kemzouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (c == '\0')
		return (s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	l1;
	size_t	l2;
	size_t	j;
	size_t	i;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	str = (char *)malloc(l1 + l2 + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (++i < l1)
		str[i] = s1[i];
	j = 0;
	while (j < l2)
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_strdup(char *str)
{
	size_t	len;
	int		i;
	char	*p;

	i = 0;
	len = ft_strlen(str);
	p = malloc(sizeof(char) * len + 1);
	if (p == NULL)
		return (NULL);
	while (str[i])
	{
		p[i] = str[i];
		i++;
	}
	p[len] = '\0';
	return (p);
}

char	*handle_buffer(char *store, char *buf)
{
	char	*tmp;

	if (!store)
		store = ft_strdup(buf);
	else
	{
		tmp = ft_strjoin(store, buf);
		free(store);
		store = tmp;
	}
	return (store);
}
