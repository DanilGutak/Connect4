/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:50:26 by cthaler           #+#    #+#             */
/*   Updated: 2023/09/05 17:50:27 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	n2;

	n2 = 0;
	while ((s1[n2] || s2[n2]) && n2 < n)
	{
		if ((s1[n2] < s2[n2]))
			return (((unsigned char *)s1)[n2] -
			((unsigned char *)s2)[n2]);
		if (s1[n2] > s2[n2])
			return (((unsigned char *)s1)[n2] -
			((unsigned char *)s2)[n2]);
		n2++;
	}
	return (0);
}
/*
#include<stdio.h>
#include<string.h>
int	main(void)
{
	char s1[] = "test\200";
	char s2[] = "test\0";
	printf("%d\n", ft_strncmp(s1, s2, 10));
	printf("%d", strncmp(s1, s2, 10));
	return(0);
}
*/