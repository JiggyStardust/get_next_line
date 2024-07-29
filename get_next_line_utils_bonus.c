/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:08:42 by sniemela          #+#    #+#             */
/*   Updated: 2024/07/29 14:35:47 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (s_len - start > len)
		s_len = len;
	else
		s_len = s_len - start;
	subs = (char *)malloc(sizeof(char) * s_len + 1);
	if (!subs)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		subs[i] = (char)s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}

char	*ft_strdup(const char *s1)
{
	char	*target;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1);
	target = (char *)malloc(sizeof(char) * (len + 1));
	if (!target)
		return (NULL);
	while (s1[i] != '\0')
	{
		target[i] = s1[i];
		i++;
	}
	target[i] = '\0';
	return (target);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_joined;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str_joined = (char *)malloc(sizeof(char) * (len + 1));
	if (!str_joined)
		return (NULL);
	while (s1[i] != '\0')
	{
		str_joined[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str_joined[i] = s2[j];
		i++;
		j++;
	}
	str_joined[i] = '\0';
	return (str_joined);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != '\0')
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if ((char)c == 0)
		return (str);
	return (NULL);
}
