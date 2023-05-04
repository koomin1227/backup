/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoo <mkoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:06:22 by mkoo              #+#    #+#             */
/*   Updated: 2023/04/07 20:06:24 by mkoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*a;
	char	*st;

	a = (char *)s;
	st = (char *)s;
	while (*a != 0)
		a++;
	while (a != st)
	{
		if (*a == (char)c)
			return (a);
		a--;
	}
	if (*a == (char)c)
		return (a);
	return (0);
}
