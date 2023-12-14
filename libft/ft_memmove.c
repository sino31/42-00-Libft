/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashigema <ashigema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:23:38 by ashigema          #+#    #+#             */
/*   Updated: 2023/09/29 11:52:08 by ashigema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ud;
	unsigned char	*us;

	if (dst == NULL && src == NULL)
		return (NULL);
	ud = (unsigned char *)dst;
	us = (unsigned char *)src;
	if (us < ud)
	{
		while (len > 0)
		{
			len--;
			ud[len] = us[len];
		}
	}
	else
	{
		while (len > 0)
		{
			*ud++ = *us++;
			len--;
		}
	}
	return (dst);
}
