/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoo <mkoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 19:54:47 by mkoo              #+#    #+#             */
/*   Updated: 2023/04/07 19:54:53 by mkoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	make_num(const char *str, int *num, int i)
{
	if (str[i] >= '0' && str[i] <= '9')
	{
		*num = (*num * 10) + str[i] - '0';
		make_num(str, num, i + 1);
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	nega;

	nega = 1;
	num = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		nega = -1;
	}
	make_num(str, &num, i);
	num = num * nega;
	return (num);
}

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// int main()
// {
// 	printf("%d\n",atoi("\t+12e3"));
// 	printf("%d\n",ft_atoi("\t+12e3"));
// }
