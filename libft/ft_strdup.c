/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:03:24 by cthaler           #+#    #+#             */
/*   Updated: 2023/09/06 13:03:26 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(sizeof(*dest) * ft_strlen(s) + 1);
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return ((char *)dest);
}
/*
#include<stdio.h>
#include<string.h>
int main(void)
{
	char src[] = "1234567";
	char src2[] = "1234567";
	char *test = ft_strdup(src);
	char *test2 = strdup(src2);
	//printf("%s\n", test);
	//printf("%s\n", test2);
	if (test)
		free(test);
	if (test2)
		free(test2);
	//printf("Next%s\n", test);
	//printf("Next%s\n", test2);
	return (0);
}
*/
