/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:14:35 by cthaler           #+#    #+#             */
/*   Updated: 2023/09/06 12:14:37 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_string(char a, int check_flag)
{
	if (check_flag == 1)
		if ((a >= 9 && a <= 13) || a == 32)
			return (1);
	if (check_flag == 2)
		if (a == 43 || a == 45)
			return (1);
	return (0);
}

static int	get_nr(const char *str, int negative)
{
	int	n;
	int	n_return;

	n = 0;
	n_return = 0;
	while (str[n] >= '0' && str[n] <= '9')
	{
		n_return *= 10;
		if (negative == 1)
			n_return += (str[n] - 48) % 10;
		else
			n_return -= (str[n] - 48) % 10;
		n++;
	}
	return (n_return);
}

int	ft_atoi(const char *nptr)
{
	int	n;
	int	n_return;
	int	negative;

	negative = 1;
	n = 0;
	n_return = 0;
	while (check_string(nptr[n], 1))
	{
		n++;
	}
	if (check_string(nptr[n], 2))
	{
		if (nptr[n] == 45)
			negative *= -1;
		n++;
	}
	if (nptr[n] >= '0' && nptr[n] <= '9')
		n_return = get_nr(nptr + n, negative);
	return (n_return);
}
/*
#include<stdlib.h>
#include<stdio.h>
int	main(void)
{
	const char a[] = "\f\n\r\t\v   +2147483647asas443";
	printf("%d\n", ft_atoi(a));
	printf("%d\n", atoi(a));
	return(0);
}
*/
