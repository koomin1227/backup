/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoo <mkoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:00:35 by mkoo              #+#    #+#             */
/*   Updated: 2023/04/07 20:00:37 by mkoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ndst;
	char	*nsrc;
	size_t	i;

	ndst = (char *)dst;
	nsrc = (char *)src;
	if (ndst < nsrc)
	{
		i = 0;
		while (i < len)
		{
			*(ndst + i) = *(nsrc + i);
			i++;
		}
	}
	else if (ndst > nsrc)
	{
		i = 0;
		while (i < len)
		{
			*(ndst + (len - 1 - i)) = *(nsrc + (len - 1 - i));
			i++;
		}
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char a[20]="123456";
// 	char *b = a + 2;
// 	char c[20]="123456";
// 	char *d = c + 2;
// 	// strcpy(b,"123456");
// 	// strcpy(d,"123456");
// 	ft_memmove(((void *)0), ((void *)0), 5);
// 	memmove(((void *)0), ((void *)0), 5);
// 	printf("%s\n",b);
// 	printf("%s",d);
// }
