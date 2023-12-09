/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:57:33 by cthaler           #+#    #+#             */
/*   Updated: 2023/09/11 10:57:35 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putlong_fd(long nb, int fd)
{
	if (nb < 0)
	{
		ft_putchar_fd(45, fd);
		nb *= -1;
		ft_putlong_fd(nb, fd);
	}
	else if (nb < 10)
	{
		ft_putchar_fd(nb + 48, fd);
	}
	else if (nb >= 10)
	{
		ft_putlong_fd(nb / 10, fd);
		ft_putlong_fd(nb % 10, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	ft_putlong_fd(nb, fd);
}
/*
int main(void)
{
	int	n;
	
	n = -2147483648;
	ft_putnbr_fd(n, 1);
	return (0);
}
*/
