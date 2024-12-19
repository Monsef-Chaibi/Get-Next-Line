/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaibi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:16:19 by mchaibi           #+#    #+#             */
/*   Updated: 2024/12/17 12:39:06 by mchaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
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
