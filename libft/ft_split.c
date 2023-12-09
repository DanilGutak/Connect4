/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:58:10 by cthaler           #+#    #+#             */
/*   Updated: 2023/09/11 10:58:12 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_array(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args[i]);
	free(args);
}

static int	count_strs(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c)
		{
			j++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (j);
}

static void	fill_strs(char const *s, char c, char **dest)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c)
		{
			while (s[i] != c && s[i])
			{
				dest[j][k] = s[i];
				i++;
				k++;
			}
			dest[j][k] = '\0';
			j++;
			k = 0;
		}
	}
	dest[j] = 0;
}

char	**arr_malloc(char const *s, char c, int j, char **dest)
{
	int	i;

	while (*s)
	{
		if (*s == c)
			s++;
		else if (*s != c)
		{
			i = 0;
			while (s[i] && s[i] != c)
				i++;
			dest[j] = malloc(i + 1);
			if (!dest[j])
				return (dest[j] = 0, free_array(dest), NULL);
			while (*s != c && *s)
				s++;
			j++;
		}
	}
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		j;

	j = 0;
	dest = (char **)malloc(sizeof(*dest) * (count_strs(s, c) + 1));
	if (!dest)
		return (NULL);
	dest = arr_malloc(s, c, j, dest);
	if (!dest)
		return (NULL);
	fill_strs(s, c, dest);
	return (dest);
}
/*
#include<stdio.h>
int main(void)
{
	char	s[] = "1111111111111\n1111111111111\n1111111111111\";
	char	**args;
	args = ft_split(s, '\n');
	if (!args)
		return (0);
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args[i]);
	free(args);	
	return (0);
}
*/
