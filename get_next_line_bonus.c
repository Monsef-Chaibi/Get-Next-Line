/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaibi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:53:43 by mchaibi           #+#    #+#             */
/*   Updated: 2024/12/22 21:55:47 by mchaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_read(int fd, char *str, char *str_global)
{
	int		byte_read;
	char	*temp;

	byte_read = 1;
	while (byte_read > 0 && !ft_strchr(str_global, '\n'))
	{
		byte_read = read(fd, str, BUFFER_SIZE);
		if (byte_read <= 0)
			break ;
		str[byte_read] = '\0';
		temp = str_global;
		str_global = ft_strjoin (str_global, str);
		free (temp);
	}
	if (byte_read == -1
		|| (byte_read <= 0 && str_global && str_global[0] == '\0'))
	{
		free(str_global);
		str_global = NULL;
		return (NULL);
	}
	return (str_global);
}

static char	*ft_get_line(char **str_global, int i)
{
	char	*temp;
	char	*next_line;

	while ((*str_global)[i] != '\n' && (*str_global)[i] != '\0')
		i++;
	if ((*str_global)[i] == '\n')
	{
		next_line = ft_substr(*str_global, 0, i + 1);
		temp = *str_global;
		*str_global = ft_strdup(*str_global + i + 1);
		free (temp);
		if ((*str_global)[0] == '\0')
		{
			free (*str_global);
			*str_global = NULL;
		}
	}
	else
	{
		next_line = ft_strdup(*str_global);
		free (*str_global);
		*str_global = NULL;
	}
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*str_global;
	char		*str;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = malloc(BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	if (!str_global)
		str_global = ft_strdup ("");
	str_global = ft_read(fd, str, str_global);
	free(str);
	if (!str_global)
		return (NULL);
	next_line = ft_get_line(&str_global, 0);
	if (!next_line)
	{
		free (str_global);
		str_global = NULL;
	}
	return (next_line);
}
