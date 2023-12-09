/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:56:11 by cthaler           #+#    #+#             */
/*   Updated: 2023/09/11 10:56:12 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
/*
#include<stdio.h>
int main(void)
{
	char	c;
	
	c = 'a';
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
	//printf("\n");
	return (0);
}
*/
