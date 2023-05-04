/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoo <mkoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:01:41 by mkoo              #+#    #+#             */
/*   Updated: 2023/04/07 20:01:42 by mkoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*make_str(char const *str, char c, int *i)
{
	char	*tmp;
	int		cnt;
	int		j;

	cnt = 0;
	j = *i;
	while (str[j] != c && str[j] != 0)
	{
		cnt++;
		j++;
	}
	tmp = (char *) malloc(sizeof(char) * (cnt + 1));
	if (tmp == NULL)
		return (NULL);
	j = 0;
	while (str[*i] != c && str[*i] != 0)
	{
		tmp[j] = str[*i];
		j++;
		(*i)++;
	}
	tmp[j] = '\0';
	return (tmp);
}

static int	str_len(char const *str, char c)
{
	int	cnt;
	int	i;

	i = 0;
	cnt = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && str[i] != c)
			cnt++;
		else if (str[i] != c && str[i - 1] == c)
			cnt++;
		i++;
	}
	return (cnt);
}

static char	**make_strs(char const *str, char c, char **res)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (str[i] != 0)
	{
		if ((i == 0 && str[i] != c) || \
		(i != 0 && str[i] != c && str[i - 1] == c))
		{
			res[cnt] = make_str(str, c, &i);
			if (res[cnt] == NULL)
				return (NULL);
			cnt++;
		}
		if (str[i] == 0)
			break ;
		i++;
	}
	return (res);
}

char	**ft_split(char const *str, char c)
{
	char	**res;
	char	**tmp;
	int		str_cnt;
	int		i;

	str_cnt = str_len(str, c);
	res = (char **) malloc(sizeof(char *) * (str_cnt + 1));
	if (res == NULL)
		return (NULL);
	tmp = make_strs(str, c, res);
	if (tmp == NULL)
	{
		i = 0;
		while (res[i])
		{
			free(res[i]);
			i++;
		}
		free(res);
		return (NULL);
	}
	res[str_cnt] = 0;
	return (res);
}

// #include <stdio.h>
// int main()
// {
// 	free(0);
// // 	char **res;
// // 	// res = ft_split("y9v8nSCKhrtU4rrCm7UbsWhcEVmrGFKcKHB7WIM", "o0Fty7");
// // 	res = ft_split("asdf, asdfq, qwr", ',');
// // 	for(int i=0; i<3;i++)
// // 	 	printf("%s\n",res[i]);
// // //	a = str_len(",qwe, asd zxc 12", " ");
// 	char *s = "                  olol";
//     char **res = ft_split("hellfif isf sdf sf  sdf", 32);
// 	for(int i=0; i<5;i++)
// 	 	printf("%s\n",res[i]);
// }
