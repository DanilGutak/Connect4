/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:00:01 by cthaler           #+#    #+#             */
/*   Updated: 2023/09/05 17:00:02 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return (((char *)s) + i);
		i++;
	}
	if (((unsigned char *)s)[i] == (unsigned char)c)
		return (((char *)s) + i);
	else
		return (0);
}
/*
#include<stdio.h>
#include<string.h>
int	main(void)
{
	const char	s[] = "test123";
	printf("%s\n", ft_strchr(s, 49));
	printf("%s", strchr(s, 49));
	
	return(0);
}
*/
