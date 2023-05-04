/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoo <mkoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:23:13 by mkoo              #+#    #+#             */
/*   Updated: 2023/03/31 18:23:19 by mkoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	int		s1_len;
	int		s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	tmp = (char *) malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (tmp == 0)
		return (0);
	ft_strlcpy(tmp, s1, s1_len + 1);
	ft_strlcat(tmp, s2, s1_len + s2_len + 1);
	return (tmp);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char *s1 = "my favorite animal is ";
//     char *s2 = s1 + 20;

//     char *res = ft_strjoin(s2, s1);
// }