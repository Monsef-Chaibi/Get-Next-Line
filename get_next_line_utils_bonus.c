/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaibi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:54:38 by mchaibi           #+#    #+#             */
/*   Updated: 2024/12/22 21:56:59 by mchaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_tmp;
	int		i;
	int		s1_len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	str_tmp = malloc(s1_len + ft_strlen(s2) + 1);
	if (!str_tmp)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str_tmp[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str_tmp[s1_len + i] = s2[i];
		i++;
	}
	str_tmp[i + s1_len] = '\0';
	return (str_tmp);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char			*s_new;
	unsigned int	i;

	s_new = malloc(ft_strlen(s) + 1);
	i = 0;
	if (!s_new)
		return (NULL);
	while (s[i] != '\0')
	{
		s_new[i] = s[i];
		i++;
	}
	s_new[i] = '\0';
	return (s_new);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str_tmp;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if ((size_t)start >= s_len)
		len = 0;
	else if (len > s_len - (size_t)start)
		len = s_len - (size_t)start;
	str_tmp = malloc(len + 1);
	if (!str_tmp)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str_tmp[i] = s[start + i];
		i++;
	}
	str_tmp[i] = '\0';
	return (str_tmp);
}
