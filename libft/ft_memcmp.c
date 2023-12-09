/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:25:44 by cthaler           #+#    #+#             */
/*   Updated: 2023/09/07 17:25:45 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((((unsigned char *)s1)[i] != ((unsigned char *)s2)[i]))
			return (((unsigned char *)s1)[i] -
			((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
/*
#include<string.h>
#include<stdio.h>
int	main(void)
{
	unsigned char	s1[] = {-128, 0, 127, 0};
	unsigned char	s2[] = {-128, 0, 127, 0};
	unsigned char	s3[] = "1234";
	unsigned char	s4[] = "1334";
	printf("%d\n", ft_memcmp(s1, s2, 4));
	printf("%d\n", memcmp(s1, s2, 4));
	return(0);
}
*/
