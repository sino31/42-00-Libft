/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shigematsuaono <shigematsuaono@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:38:57 by ashigema          #+#    #+#             */
/*   Updated: 2023/09/24 18:57:52 by shigematsua      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ub;

	i = 0;
	ub = (unsigned char *)b;
	while (i < len)
	{
		ub[i] = (unsigned char)c;
		i++;
	}
	return (ub);
}
