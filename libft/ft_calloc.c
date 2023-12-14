/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashigema <ashigema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:36:03 by ashigema          #+#    #+#             */
/*   Updated: 2023/09/29 11:36:26 by ashigema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*result;

	if (count == 0 || size == 0)
	{
		result = malloc(1 * sizeof(char));
		if (!result)
			return (NULL);
		ft_bzero(result, 1);
		return (result);
	}
	if (size > SIZE_MAX / count)
		return (NULL);
	result = malloc(size * count);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, size * count);
	return (result);
}
