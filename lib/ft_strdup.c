/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:22:24 by elakhfif          #+#    #+#             */
/*   Updated: 2024/06/11 07:22:26 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

char	*ft_strdup(const char *s1)
{
	int		indx;
	int		len;
	char	*str;

	indx = 0;
	len = ft_strlen((char *)s1);
	str = ((char *)malloc(sizeof(char) * (len +1)));
	if (str == NULL)
		return (NULL);
	while (indx < len)
	{
		str[indx] = s1[indx];
		indx++;
	}
	str[indx] = '\0';
	return (str);
}
