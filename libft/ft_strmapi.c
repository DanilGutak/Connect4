/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:32:10 by cthaler           #+#    #+#             */
/*   Updated: 2023/09/11 10:32:13 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dest;
	int		i;
	char	c;

	i = 0;
	dest = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!dest)
		return (0);
	while (s[i])
	{
		c = f(i, s[i]);
		if (c)
			dest[i] = c;
		else
			dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
char addOne(unsigned int i, char c) {return (i + c);}

#include<stdio.h>
int main(void)
{
	char *dest;
	char s[] = "test123";
	
	dest = ft_strmapi("1234", addOne);
	printf("%s\n", dest);
	free(dest);
	return (0);
}
*/
