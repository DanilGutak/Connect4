/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:19:36 by cthaler           #+#    #+#             */
/*   Updated: 2023/09/06 10:19:38 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((const char *)s)[i] == (const char)c)
			return (((void *)s) + i);
		i++;
	}
	return (0);
}
/*
#include<stdio.h>
#include<string.h>
int	main(void)
{
	char s1[] = {0, 1, 2 ,3 ,4 ,5};
	char s2[] = {0, 1, 2 ,3 ,4 ,5};
	//ft_memchr(s, 1, 6);
	
	
	//printf("%s\n", s);
	printf("%s\n", ((unsigned char *)ft_memchr(s1, 2 + 256, 3)));
	printf("%s\n", ((unsigned char *)memchr(s2, 2 + 256, 3)));
	return(0);
}
*/
