/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:14:39 by cthaler           #+#    #+#             */
/*   Updated: 2023/09/05 11:14:40 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	if (size != 0)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
		while (src[len])
			len++;
		return (len);
	}
	else
		return (ft_strlen(src));
}
/*
#include<string.h>
#include<stdio.h>
#include<bsd/string.h>
int main(void)
{
	char src[] = "test111111";
	char dest[] = "test222";
	char src2[] = "test111111";
	char dest2[] = "test222";
	size_t size = 0;
	printf("%zu\n", ft_strlcpy(dest, "1", size));
	printf("%zu\n", strlcpy(dest2, "1", size));

	return(0);
}
*/
