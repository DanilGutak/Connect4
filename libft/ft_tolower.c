/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:55:44 by cthaler           #+#    #+#             */
/*   Updated: 2023/09/05 16:55:45 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}
/*
#include<stdio.h>
#include<ctype.h>
int	main(void)
{
	printf("%d\n", ft_tolower(66));
	printf("%d\n", tolower(66));
	return (0);
}
*/
