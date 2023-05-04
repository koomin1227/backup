/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoo <mkoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 19:55:23 by mkoo              #+#    #+#             */
/*   Updated: 2023/04/07 19:55:26 by mkoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	i = 0;
	dest = (unsigned char *)s;
	while (i < n)
	{
		*(dest + i) = 0;
		i++;
	}
}

// #include <stdio.h>
// int main()
// {
// 	char a[20];

// 	ft_bzero(a,20);
// 	for(int i = 0; i< 20;i++)
// 		printf("%d",a[i]);
// }
