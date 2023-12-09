/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:11:49 by cthaler           #+#    #+#             */
/*   Updated: 2023/09/05 13:11:50 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_overlap(char *dest, char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < n)
	{
		while (j < n)
		{
			if (&dest[i] == &src[j])
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest || !src)
		return (dest);
	i = 0;
	if (ft_check_overlap((char *)dest, (char *)src, n))
		return (ft_memmove(dest, src, n));
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}
/*
#include<string.h>
#include<stdio.h>
int	main(void)
{
	char	src[] = "test";
	char	dest[] = "1234";
	char	src2[] = "test";
	char	dest2[] = "1234";
	printf("%s\n", ((char *)ft_memcpy(dest, src, 4)));
	printf("%s\n", ((char *)memcpy(dest2, src2, 4)));
	return(0);
}
*/
