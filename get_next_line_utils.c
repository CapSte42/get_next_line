/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:43:35 by smontuor          #+#    #+#             */
/*   Updated: 2023/11/08 16:31:42 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			tot;
	void			*s;
	unsigned char	*buffer;

	tot = nmemb * size;
	if (nmemb != 0 && tot / nmemb != size)
		return (NULL);
	s = malloc(tot);
	if (s == NULL)
		return (NULL);
	buffer = (unsigned char *)s;
	while (tot > 0)
	{
		*buffer = 0;
		buffer++;
		tot--;
	}
	return (s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*string;
	size_t	length;

	length = ft_strlen(s1);
	if (!s1 || !s2)
		return (NULL);
	string = ft_calloc(length + ft_strlen(s2) + 1, sizeof(char));
	if (!string)
		return (NULL);
	ft_strlcpy(string, s1, length + 1);
	while (*s2)
		string[length++] = *s2++;
	return (string);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	index;

	index = 0;
	while ((index + 1) < size && src[index])
	{
		dst[index] = src[index];
		index++;
	}
	if (size)
		dst[index] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	c = (unsigned char)c;
	while (*s)
	{
		if ((unsigned char)*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}
