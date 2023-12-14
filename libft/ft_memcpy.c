/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashigema <ashigema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:56:43 by ashigema          #+#    #+#             */
/*   Updated: 2023/09/29 11:06:00 by ashigema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ud;
	unsigned char	*us;

	if (dst == NULL && src == NULL)
		return (NULL);
	ud = (unsigned char *)dst;
	us = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		ud[i] = us[i];
		i++;
	}
	return (ud);
}
