/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoo <mkoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 19:59:25 by mkoo              #+#    #+#             */
/*   Updated: 2023/04/07 19:59:27 by mkoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	t;
	size_t			i;

	t = (unsigned char)c;
	a = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (a[i] == t)
			return ((void *)s + i);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// int main()
// {
// 	char a[20] = "qosmdnsdcni";
// 	printf("%s",(char *)ft_memchr(a,'d',10));
// }
