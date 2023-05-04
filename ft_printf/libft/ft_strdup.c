/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoo <mkoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:02:40 by mkoo              #+#    #+#             */
/*   Updated: 2023/04/07 20:02:42 by mkoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*a;
	int		len;
	int		i;

	len = ft_strlen((char *)s1);
	a = (char *) malloc(sizeof(char) * (len + 1));
	if (a == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		a[i] = s1[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}
