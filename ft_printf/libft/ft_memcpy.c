/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoo <mkoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:00:13 by mkoo              #+#    #+#             */
/*   Updated: 2023/04/07 20:00:14 by mkoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dst, const void *src, size_t n)
{
	size_t		i;
	char		*n_dest;
	char		*n_src;

	n_dest = (char *)dst;
	n_src = (char *)src;
	i = 0;
	if (n_dest == 0 && n_src == 0)
		return (dst);
	while (i < n)
	{
		*n_dest = *n_src;
		n_dest++;
		n_src++;
		i++;
	}
	return (dst);
}

// #include <string.h>
// #include <stdio.h>
// int main(void)
// {
//         memcpy(((void *)0), ((void *)0), 3);
//         return 0;
// }
