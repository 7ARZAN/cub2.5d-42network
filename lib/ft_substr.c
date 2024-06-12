/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:23:16 by elakhfif          #+#    #+#             */
/*   Updated: 2024/06/12 01:46:39 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	int		i;
	char	*str;

	if (!s)
		return (NULL);
	else if ((size_t) ft_strlen((char *)s + start) < len)
		str = malloc(sizeof(char) * (ft_strlen((char *)s + start + 1)));
	else
		str = malloc(sizeof(char) * ((int)len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[start] && i < (int)len && (unsigned int)
		ft_strlen((char *)s) >= start)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
