/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashigema <ashigema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:52:51 by ashigema          #+#    #+#             */
/*   Updated: 2023/09/29 11:04:37 by ashigema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_size(unsigned long n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		cnt++;
		n /= 10;
	}
	return (cnt);
}

static void	convert(char *result, long long m, int flag, int size)
{
	int	i;

	i = 0;
	if (flag)
	{
		result[0] = '-';
		i++;
	}
	result[size] = '\0';
	while (size > i)
	{
		size--;
		result[size] = m % 10 + '0';
		m /= 10;
	}
}

char	*ft_itoa(int n)
{
	int			size;
	int			flag;
	long long	m;
	char		*result;

	m = (long long)n;
	flag = 0;
	if (m < 0)
	{
		m *= -1;
		flag = 1;
	}
	size = count_size(m);
	result = malloc((size + flag + 1) * sizeof(char));
	if (!result)
		return (NULL);
	convert(result, m, flag, size + flag);
	return (result);
}
