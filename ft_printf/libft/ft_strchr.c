/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoo <mkoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:02:14 by mkoo              #+#    #+#             */
/*   Updated: 2023/04/07 20:02:16 by mkoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*a;

	a = (char *)s;
	while (*a != 0)
	{
		if (*a == (char)c)
			return (a);
		a++;
	}
	if ((char)c == '\0')
		return (a);
	return (0);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// int main()
// {
// 	char *res = ft_strchr("teste", '\0');
// 	char *res_std = strchr("teste", 1024);
// }
