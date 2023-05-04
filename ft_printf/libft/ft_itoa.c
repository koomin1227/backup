/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoo <mkoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 11:22:15 by mkoo              #+#    #+#             */
/*   Updated: 2023/04/01 11:22:18 by mkoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_num(char *res, int n, int cnt)
{
	unsigned int	tmp;
	int				i;

	if (n < 0)
	{
		tmp = n * -1;
		res[0] = '-';
	}
	else
		tmp = n;
	i = cnt - 1;
	while (tmp != 0)
	{
		res[i] = (tmp % 10) + '0';
		i--;
		tmp = tmp / 10;
	}
	res[cnt] = 0;
}

static int	num_cnt(int n)
{
	int				cnt;
	unsigned int	tmp;

	tmp = 0;
	if (n == 0)
		return (1);
	cnt = 0;
	if (n < 0)
	{
		cnt += 1;
		tmp = n * -1;
	}
	else if (n > 0)
		tmp = n;
	while (tmp != 0)
	{
		tmp = tmp / 10;
		cnt += 1;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	int				cnt;
	char			*res;

	cnt = num_cnt(n);
	res = (char *)malloc(sizeof(char) * (cnt + 1));
	if (res == 0)
		return (0);
	if (n == 0)
	{
		res[0] = '0';
		res[1] = 0;
	}
	else
	{
		fill_num(res, n, cnt);
	}
	return (res);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char *a = ft_itoa(-2147483648);
// }
