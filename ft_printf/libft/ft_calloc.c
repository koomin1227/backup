/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoo <mkoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 19:56:33 by mkoo              #+#    #+#             */
/*   Updated: 2023/04/07 19:56:34 by mkoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	tmp = malloc(size * count);
	if (tmp == NULL)
		return (NULL);
	ft_memset(tmp, 0, count * size);
	return (tmp);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	int size = 8539;
//     void * d1 = ft_calloc(0, sizeof(int));
//     void * d2 = calloc(0, sizeof(int));
//         if (memcmp(d1, d2, size * sizeof(int)))
//                 printf("fail");
//         free(d1);
//         free(d2);
//         printf("suc");
// }
