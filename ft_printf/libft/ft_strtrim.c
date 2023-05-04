/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoo <mkoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:06:45 by mkoo              #+#    #+#             */
/*   Updated: 2023/04/07 20:06:47 by mkoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != 0)
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*make_str(char *str, char *end)
{
	char	*res;

	if (end < str)
	{
		res = (char *)malloc(sizeof(char));
		if (res == 0)
			return (0);
		*res = 0;
	}
	else
	{
		res = (char *)malloc(sizeof(char) * (end - str + 2));
		if (res == 0)
			return (0);
		ft_strlcpy(res, str, (end - str + 2));
	}
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	char	*str;
	char	*end;

	if (*s1 == 0)
		return ((char *)ft_calloc(1, sizeof(char)));
	len = ft_strlen(s1);
	str = (char *)s1;
	end = (char *)s1 + len - 1;
	while (*str != 0)
	{
		if (is_set(*str, set) == 0)
			break ;
		str++;
	}
	while (end != (char *)s1)
	{
		if (is_set(*end, set) == 0)
			break ;
		end--;
	}
	return (make_str(str, end));
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	printf("%s\n",ft_strtrim("asdasdsda","asd"));
// }
