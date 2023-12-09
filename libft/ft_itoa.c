/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:55:44 by cthaler           #+#    #+#             */
/*   Updated: 2023/09/11 10:55:46 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	check_len(long n)
{
	long	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*store_nr(long n, long j, long nb)
{
	char	*dest;
	int		str_len;

	str_len = check_len(n);
	dest = (char *)malloc(sizeof(*dest) * check_len(n) + 1);
	if (!dest)
		return (0);
	if (n < 0)
	{
		n *= -1;
		dest[j] = '-';
		j++;
	}
	dest[str_len] = '\0';
	str_len--;
	while (str_len >= j)
	{
		nb = n;
		nb %= 10;
		dest[str_len] = nb + 48;
		n /= 10;
		str_len--;
	}
	return (dest);
}

char	*ft_itoa(int n)
{
	char	*dest;
	long	j;
	long	n2;
	long	n3;

	j = 0;
	n2 = n;
	n3 = n2;
	dest = store_nr(n2, j, n3);
	return (dest);
}
/*
#include<stdio.h>
int	main(void)
{
	int	n;
	char	*dest;
	
	//n = -2147483648;
	n = 214748364;
	printf("Number of digits: %zu\n", check_len(n));
	dest = ft_itoa(n);
	printf("%s\n", dest);
	free(dest);
	
	return (0);
}
*/