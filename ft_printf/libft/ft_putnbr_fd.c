/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoo <mkoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 12:40:19 by mkoo              #+#    #+#             */
/*   Updated: 2023/04/01 12:40:21 by mkoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_abs(int n, int fd)
{
	char	print_num;

	if (n != 0)
	{
		print_abs(n / 10, fd);
		print_num = '0' + n % 10;
		write(fd, &print_num, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == -2147483648)
			write(fd, "2147483648", 10);
		else
			print_abs(n * (-1), fd);
	}
	else if (n == 0)
	{
		write(fd, "0", 1);
	}
	else
	{
		print_abs(n, fd);
	}
}
