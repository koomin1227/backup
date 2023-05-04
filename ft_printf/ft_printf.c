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

#include "ft_printf.h"
#include <stdio.h>

int	print_format(va_list ap, const char *format)
{
	int	len;

	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	ap;
	va_start(ap, format);

	va_end(ap);
	return (len);
}

int test(int num, ...)
{
	int res = 0;
	va_list ap;
	int i;

	va_start(ap,num);
	for(i = 0;i < num;i++)
	{
		res += va_arg(ap,int);
	}
	va_end(ap);
	return (res);
}

int main()
{
	printf("%d",test(3,1, 2, 3));
}