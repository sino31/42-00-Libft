/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashigema <ashigema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:48:07 by ashigema          #+#    #+#             */
/*   Updated: 2023/09/29 11:08:47 by ashigema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_str(char *s, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			cnt++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
		{
			while (s[i] == c)
				i++;
		}
	}
	return (cnt);
}

static size_t	count_len(char *s, char c, size_t str_i)
{
	size_t	j;

	j = 0;
	while (s[str_i + j] != c && s[str_i + j])
		j++;
	return (j);
}

static void	*free_result(char **result, size_t i)
{
	while (i >= 0)
		free(result[i--]);
	free(result);
	return (NULL);
}

static char	*dup_s(char *s, size_t len, size_t str_i)
{
	char	*dst;
	size_t	j;

	dst = (char *)malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	j = 0;
	while (j < len)
	{
		dst[j] = s[str_i + j];
		j++;
	}
	dst[j] = '\0';
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	len;
	size_t	str_i;

	if (s == NULL)
		return (NULL);
	result = (char **)malloc((count_str((char *)s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	str_i = 0;
	while (i < count_str((char *)s, c))
	{
		while (s[str_i] == c)
			str_i++;
		len = count_len((char *)s, c, str_i);
		result[i] = dup_s((char *)s, len, str_i);
		if (!result[i])
			return (free_result(result, i));
		str_i += len;
		i++;
	}
	result[i] = NULL;
	return (result);
}
