/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashigema <ashigema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:48:06 by ashigema          #+#    #+#             */
/*   Updated: 2023/09/29 11:25:02 by ashigema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	is_last(char *s, char *set, int i)
{
	while (s[i])
	{
		if (!is_in_set(s[i], set))
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	if (set == NULL || set[i] == '\0')
		return (ft_strdup(s1));
	while (s1[i] && is_in_set(s1[i], (char *)set))
		i++;
	j = 0;
	while (s1[i + j] && !is_last((char *)s1, (char *)set, i + j))
		j++;
	result = malloc((j + 1) * sizeof(char));
	if (!result)
		return (NULL);
	j = 0;
	while (s1[i + j] && !is_last((char *)s1, (char *)set, i + j))
	{
		result[j] = s1[i + j];
		j++;
	}
	result[j] = '\0';
	return (result);
}
