/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:22:31 by elakhfif          #+#    #+#             */
/*   Updated: 2024/06/11 07:22:33 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lenth1;
	size_t	lenth2;
	char	*result;

	lenth1 = ft_strlen((char *)s1);
	lenth2 = ft_strlen((char *)s2);
	result = malloc(lenth1 + lenth2 + 1);
	if (result)
	{
		ft_memcpy(result, s1, lenth1);
		ft_memcpy(result + lenth1, s2, lenth2 + 1);
	}
	return (result);
}
