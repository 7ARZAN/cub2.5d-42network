/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 03:15:08 by elakhfif          #+#    #+#             */
/*   Updated: 2024/06/11 06:18:51 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*north_texture(char *line)
{
	int		i;
	char	*path;

	i = 0;
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		i += 3;
		while (ft_strchr(" \t", line[i]))
			i++;
		path = ft_strdup(&line[i]);
		return (path);
	}
	return (NULL);
}

char	*south_texture(char *line)
{
	int		i;
	char	*path;

	i = 0;
	if (ft_strncmp(line, "SO ", 3) == 0)
	{
		i += 3;
		while (ft_strchr(" \t", line[i]))
			i++;
		path = ft_strdup(&line[i]);
		return (path);
	}
	return (NULL);
}

char	*west_texture(char *line)
{
	int		i;
	char	*path;

	i = 0;
	if (ft_strncmp(line, "WE ", 3) == 0)
	{
		i += 3;
		while (ft_strchr(" \t", line[i]))
			i++;
		path = ft_strdup(&line[i]);
		return (path);
	}
	return (NULL);
}

char	*east_texture(char *line)
{
	int		i;
	char	*path;

	i = 0;
	if (ft_strncmp(line, "EA ", 3) == 0)
	{
		i += 3;
		while (ft_strchr(" \t", line[i]))
			i++;
		path = ft_strdup(&line[i]);
		return (path);
	}
	return (NULL);
}
