/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:01:33 by cthaler           #+#    #+#             */
/*   Updated: 2023/09/05 11:01:35 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	const char s[] = "string";
	printf("%zu\n", ft_strlen(s));
	printf("%zu", strlen(s));
}
*/
