/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:02:12 by cthaler           #+#    #+#             */
/*   Updated: 2023/09/05 13:02:15 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char s[] = "test123";
	char s2[] = "test123";
	ft_bzero(s, 5);
	bzero(s2, 5);
	printf("%c\n", s[5]);
	printf("%c\n", s2[5]);
	return (0);
}
*/
