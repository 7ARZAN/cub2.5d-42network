/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ohmysplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:23:39 by elakhfif          #+#    #+#             */
/*   Updated: 2024/06/11 07:23:45 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

char	**ohmysplit(char const *s, char sep)
{
	char	**split;
	size_t	start;
	size_t	end;
	size_t	i;

	split = (char **)ft_calloc((count_words(s, sep) + 1), (sizeof(char *)));
	if (!split)
		return (NULL);
	start = 0;
	end = 0;
	i = 0;
	while (i < count_words(s, sep))
	{
		while (s[start] == sep)
			start++;
		end = start;
		while (s[end] != sep && s[end])
			end++;
		split[i] = ft_substr(s, start, (end - start));
		start = end;
		i++;
	}
	split[i] = 0;
	return (split);
}

