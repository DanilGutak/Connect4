/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toupper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:44:40 by cthaler           #+#    #+#             */
/*   Updated: 2023/09/05 16:44:41 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}
/*
#include<stdio.h>
#include<ctype.h>
int	main(void)
{
	printf("%d\n", ft_toupper(98));
	printf("%d\n", toupper(98));
	return (0);
}
*/
