/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoo <mkoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:07:44 by mkoo              #+#    #+#             */
/*   Updated: 2023/04/07 20:07:46 by mkoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;

	if (ft_strlen(s) <= start)
	{
		tmp = (char *) malloc(sizeof(char));
		if (tmp == 0)
			return (0);
		*tmp = '\0';
		return (tmp);
	}
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	tmp = (char *) malloc(sizeof(char) * (len + 1));
	if (tmp == 0)
		return (0);
	ft_strlcpy(tmp, s + start, len + 1);
	return (tmp);
}

// #include <stdio.h>
// int main()
// {
// 	char *s = "malloc protection !";
// 	char *ret = ft_substr("hola", 0, -1);
// 	// if (ret == ((void *)0))
// 	// 		printf("succ");
// 	// printf("fail");
// }
