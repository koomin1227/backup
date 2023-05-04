/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoo <mkoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:05:29 by mkoo              #+#    #+#             */
/*   Updated: 2023/04/07 20:05:31 by mkoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	if (n == 0)
		return (0);
	i = 0;
	while (i + 1 < n)
	{
		if ((unsigned char)s1[i] == '\0' || (unsigned char)s2[i] == '\0')
			break ;
		if ((unsigned char)s1[i] == (unsigned char)s2[i])
			i++;
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// #include <string.h>
// int main()
// {
// 	char *s1 = "\x12\xff\x65\x12\xbd\xde\xad";
//     char *s2 = "\x12\x02";

// 	 size_t size = 6;

// 	int a = ft_strncmp("abcdef", "abc\375xx", 5);
// 	int b = strncmp("abcdef", "abcgef", 5);
// }
