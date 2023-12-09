/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:35:23 by cthaler           #+#    #+#             */
/*   Updated: 2023/09/05 17:35:25 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (((const char *)s)[i] == (const char)c)
			j = i;
		i++;
	}
	if (((const char *)s)[j] == (const char)c)
		return (((char *)s) + j);
	else if (((const char *)s)[i] == (const char)c)
		return (((char *)s) + i);
	else
		return (0);
}
/*
#include<stdio.h>
#include<string.h>
int	main(void)
{
	char s[] = "tripouille";
	printf("%s\n", ft_strrchr(s, 't' + 256));
	printf("%s", strrchr(s, 't' + 256));
	
	return(0);
}
*/
