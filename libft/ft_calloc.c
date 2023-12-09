/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:28:42 by cthaler           #+#    #+#             */
/*   Updated: 2023/09/07 16:28:43 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;

	if (nmemb == 0 || size == 0)
	{
		return (malloc(0));
	}
	if (size > 2147483648 / nmemb)
		return (NULL);
	dest = malloc(nmemb * size);
	if (!dest)
		return (NULL);
	else
		ft_bzero(dest, nmemb * size);
	return (dest);
}
/*
#include<stdio.h>
int	main(void)
{
	char *s;
	char *t;
	
	s = ft_calloc(4,2);
	t = calloc(4,2);
	//printf("%c\n", s[8]);
	//printf("%c\n", t[8]);
	if (s)
		free(s);
	if (t)
		free(t);
	return (0);
}
*/
