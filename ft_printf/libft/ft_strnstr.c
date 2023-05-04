/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoo <mkoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:05:57 by mkoo              #+#    #+#             */
/*   Updated: 2023/04/07 20:05:58 by mkoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = i + 1;
			while (haystack[j] != '\0' && needle[j - i] != '\0' && j < len)
			{
				if (haystack[j] != needle[j - i])
					break ;
				j++;
			}
			if (needle[j - i] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char a[20]="aidcnisdioio";
// 	char b[20]="dcn";
// 	//printf("%s",ft_strnstr(a,b,4));
// 	char *c,*d,*e,*f;
// 	c = ft_strnstr("asdf", "", 0);
// 	d = strnstr("asdf","",0);
// }
