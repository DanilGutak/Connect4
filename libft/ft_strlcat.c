/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:25:31 by cthaler           #+#    #+#             */
/*   Updated: 2023/09/05 16:25:32 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = ft_strlen(dst);
	if (j >= size)
		k = size + ft_strlen(src);
	else
		k = ft_strlen(src) + ft_strlen(dst);
	while (src[i] && j + 1 < size)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (k);
}
/*
#include<stdio.h>
int	main(void)
{
	char dest_str[] = "test1";
	const char src_str[] = "test2";
	size_t size = 11; 
	size_t n = ft_strlcat(dest_str, src_str, size);
	//strlcat(dest_str2, src_str2, size2);
	//printf("Return: %zu\n", n);
	printf ("%s", dest_str);
	return(0);
}
*/
