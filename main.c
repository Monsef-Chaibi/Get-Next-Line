/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaibi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:47:57 by mchaibi           #+#    #+#             */
/*   Updated: 2024/12/19 11:49:38 by mchaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int main()
{
    int fd = open("test.txt", O_RDONLY);
    printf("%s" , get_next_line(fd));
    printf("%s" , get_next_line(fd));
    printf("%s" , get_next_line(fd));
    printf("%s" , get_next_line(fd));
}