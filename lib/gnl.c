/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:23:25 by elakhfif          #+#    #+#             */
/*   Updated: 2024/06/11 07:23:27 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

static int	find_new_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*linefun(char *rest)
{
	char	*line;
	int		index;
	int		i;

	i = 0;
	if (ft_strlen(rest) <= 0)
		return (NULL);
	index = find_new_line(rest);
	if (index == -1)
	{
		line = ft_strdup(rest);
		return (line);
	}
	line = (char *)malloc(sizeof(char) * (index + 2));
	if (!line)
		return (NULL);
	while (rest[i] != '\n')
	{
		line[i] = rest[i];
		i++;
	}
	line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}

char	*restfun(char *rest)
{
	int		len;
	int		index;
	char	*tmp;

	if (!rest)
		return (NULL);
	len = ft_strlen(rest);
	index = find_new_line(rest);
	if (index != -1)
	{
		tmp = ft_substr(rest, (index + 1), (len - index - 1));
		free (rest);
		rest = tmp;
		return (rest);
	}
	free (rest);
	return (NULL);
}

char	*ft_read(int fd, char *buff, char *rest)
{
	char	*tmp;
	int		n;

	n = 1;
	while (n > 0 && find_new_line(rest) == -1)
	{
		n = read (fd, buff, BUFFER_SIZE);
		if (n > 0)
		{
			buff[n] = '\0';
			tmp = ft_strjoin(rest, buff);
			if (rest)
				free(rest);
			rest = NULL;
			rest = tmp;
		}
	}
	free (buff);
	buff = NULL;
	if (n == -1)
	{
		free(rest);
		return (NULL);
	}
	return (rest);
}

char	*gnl(int fd)
{
	char		*buff;
	char		*line;
	static char	*rest[1024];

	if (BUFFER_SIZE <= 0 || (fd != 0 && fd <= 2))
		return (NULL);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	rest[fd] = ft_read(fd, buff, rest[fd]);
	line = linefun(rest[fd]);
	rest[fd] = restfun(rest[fd]);
	return (line);
}
