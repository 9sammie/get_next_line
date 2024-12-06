/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:23:33 by maballet          #+#    #+#             */
/*   Updated: 2024/12/06 16:31:31 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnjoin(char const *line, char const *buffer, size_t n)
{
	size_t	i;
	size_t	j;
	char	*join;

	i = 0;
	if (!line && !buffer)
		return (NULL);
	if (!line)
		line = "";
	join = malloc(sizeof(char) * (ft_strlen(line) + n + 1));
	if (!join)
		return (NULL);
	while (line[i])
	{
		join[i] = line[i];
		i++;
	}
	j = 0;
	while (j < n && buffer[j])
		join[i++] = buffer[j++];
	join[i] = '\0';
	return (join);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char) c)
		{
			return (&str[i]);
		}
		i++;
	}
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = '\0';
		i++;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*s;
	unsigned char		*d;

	i = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (!d && !s)
		return (NULL);
	while (i < n)
	{
		if (d > s)
			d[n - (i + 1)] = s[n - (i + 1)];
		else
			d[i] = s[i];
		i++;
	}
	return (dest);
}
