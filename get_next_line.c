/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaibi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:08:04 by mchaibi           #+#    #+#             */
/*   Updated: 2024/12/19 11:50:50 by mchaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int check_new_line(char *str)
{
    int i;

    i = 0;
    while (i < ft_strlen(str))
    {
        if(str[i] == '\n')
        	return (1);
        i++;
    }
    return 0;
}
char *ft_put_value(char *str_global)
{
    char *str;
	int len;
	int i;

	len = 0;
	i = 0;
	while (str_global[i] != '\0')
	{
		if(str_global[i] == '\n')
			break;
		i++;
	}
	str = malloc(len + 2);
	if (!str)
		return (NULL);
	
	while (len <= i)
	{
		str[len] = str_global[len];
		len++;
	}
	str[len] = '\0';
	str_global = ft_strdup(str_global + i + 1);
	return (str);
}

char *get_next_line(int fd)
{
    char *str;
    int byte_read;
    static char *str_global = "";

    byte_read = 0;
	if (str_global[0] != '\0' && check_new_line(str_global))
    {
        return (ft_put_value(str_global));
    }
    str = malloc(BUFFER_SIZE + 1);
    if (!str)
        return (NULL);
    byte_read = read(fd, str, BUFFER_SIZE);
    str_global = ft_strjoin(str_global, str);
    if (check_new_line(str_global))
    {
        return (ft_put_value(str_global));
    }
    return("hj");
}