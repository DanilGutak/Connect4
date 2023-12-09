/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:07:13 by cthaler           #+#    #+#             */
/*   Updated: 2023/09/08 15:07:15 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_start(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (set[i])
	{
		if (set[i] == s1[j])
		{
			j++;
			i = 0;
		}
		else
			i++;
	}
	return (j);
}

static size_t	check_end(char const *s1, char const *set)
{
	size_t	s1_l;
	int		i;
	int		j;

	i = 0;
	j = 0;
	s1_l = ft_strlen(s1);
	while (set[i])
	{
		if (set[i] == s1[s1_l - 1 - j])
		{
			j++;
			i = 0;
		}
		else
			i++;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	dest_len;
	char	*dest;
	size_t	i;

	i = 0;
	start = check_start(s1, set);
	if (start == ft_strlen(s1))
		dest_len = 0;
	else
		dest_len = ft_strlen(s1) - check_end(s1, set) - start;
	dest = malloc(sizeof(*dest) * dest_len + 1);
	if (!dest)
		return (0);
	while (s1[start + i] && i < dest_len)
	{
		dest[i] = s1[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include<stdio.h>
int	main(void)
{
	char	s1[] = "   xxx   xxx";
	char	set[] = " x";
	char	*s;
	
	s = ft_strtrim(s1, set);
	printf("%s", s);
	free(s);
	return (0);
}
*/
