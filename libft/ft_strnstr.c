/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:52:00 by cthaler           #+#    #+#             */
/*   Updated: 2023/09/06 11:52:01 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		while (big[i + j] == little[j] && big[i + j]
			&& little[j] && i + j < len)
		{
			if (little[j + 1] == '\0')
				return (((char *)big) + i);
			j++;
		}
		if (!big[i])
			return (0);
		j = 0;
		i++;
	}
	return (0);
}
/*
#include<stdio.h>
#include<bsd/string.h>
int	main(void)
{
	const char big[] = "aaabcabcd";
	const char little[] = "abcd";
	printf("%s\n", ft_strnstr(big, little, -1));
	printf("%s\n", strnstr(big, little, -1));
	return(0);
}
*/
