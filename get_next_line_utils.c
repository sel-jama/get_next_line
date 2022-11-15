/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:23:53 by sel-jama          #+#    #+#             */
/*   Updated: 2022/11/15 15:32:53 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		join[i++] = s2[j];
		j++;
	}
	join[i] = '\0';
	free((void *)s1);
	return (join);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*subs;

	if (!s)
		return (NULL);
	j = 0;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
			len = ft_strlen(s) - start;
	else if (start + len > ft_strlen(s))
			len = len - 1;
	subs = (char *)malloc(sizeof(char) * (len + 1));
	if (!subs)
		return (NULL);
	while (j < len && s[start + j] != '\0' && (start + j) < ft_strlen(s))
	{
		subs[j] = s[start + j];
		j++;
	}
	subs[j] = '\0';
	return (subs);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	char	*str;
	int		i;

	str = (char *)s1;
	p = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (str[i])
	{
		*(p + i) = str[i];
		i++;
	}
	*(p + i) = '\0';
	return (p);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&str[i]);
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	i;

	if (size && count >= SIZE_MAX / size)
		return (NULL);
	p = malloc(count * size);
	if (!p)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		p[i] = '\0';
		i++;
	}
	return (p);
}