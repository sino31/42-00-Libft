/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashigema <ashigema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:12:06 by ashigema          #+#    #+#             */
/*   Updated: 2023/09/27 15:27:43 by ashigema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	num;
	long long	sig;

	num = 0;
	sig = 1;
	while (*str == ' ' || ('\t' <= *str && *str <= '\r'))
		str++;
	if (*str == '-')
	{
		sig = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str == '0')
		str++;
	while (ft_isdigit(*str))
	{
		if ((num * sig) > (LONG_MAX - (*str - '0')) / 10)
			return ((int)LONG_MAX);
		else if ((num * sig) < (LONG_MIN + (*str - '0')) / 10)
			return ((int)LONG_MIN);
		num = num * 10 + *str++ - '0';
	}
	return (sig * num);
}
