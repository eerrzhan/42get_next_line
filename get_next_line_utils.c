/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etoktona <etoktona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 13:09:45 by etoktona          #+#    #+#             */
/*   Updated: 2025/12/25 13:09:54 by etoktona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*s;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	i = -1;
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	s = (char *)malloc(size);
	if (s)
	{
		while (s1[++i])
			s[i] = s1[i];
		i = -1;
		while (s2[++i])
			s[i + ft_strlen(s1)] = s2[i];
		s[i + ft_strlen(s1)] = '\0';
	}
	return (s);
}

char	*ft_strdup(const char *s)
{
	char	*dup;

	dup = (char *)malloc(ft_strlen(s) + 1);
	if (dup)
		ft_strlcpy(dup, s, ft_strlen(s) + 1);
	return (dup);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	i;

	srclen = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (srclen);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	space_left;
	char	*cpy;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	space_left = slen - start;
	if (!(start < slen) || !slen)
		return (ft_calloc(1, 1));
	if (space_left > len)
		space_left = len;
	cpy = (char *)ft_calloc(space_left + 1, 1);
	if (cpy)
		ft_strlcpy(cpy, &s[start], space_left + 1);
	return (cpy);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned char	*memptr;
	size_t			len;

	if (size != 0 && nmemb != 0)
	{
		if (size > SIZE_MAX / nmemb)
			return (NULL);
		len = size * nmemb;
		ptr = (void *)malloc(len);
		if (ptr)
		{
			memptr = (unsigned char *)ptr;
			while (len--)
				*memptr++ = (unsigned char)0;
		}
	}
	else
		ptr = (void *)malloc(1);
	return (ptr);
}
