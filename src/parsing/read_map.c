/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarzan <elakhfif@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 01:55:38 by tarzan            #+#    #+#             */
/*   Updated: 2024/06/11 05:58:08 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	rows_number(char *file)
{
	int		rows;
	int		fd;
	char	*tmp;
	char	*tmp1;

	rows = 0;
	fd = open(file, O_RDONLY);
	tmp = gnl(fd);
	while (1)
	{
		tmp1 = ft_strtrim(tmp, " \n\t\v\f\r");
		if (ft_strlen(tmp1))
			rows++;
		free(tmp);
		free(tmp1);
		tmp = gnl(fd);
		if (!tmp)
			break ;
	}
	close(fd);
	return (rows);
}

static int	extract_map(int fd, char **res)
{
	int		i;
	int		lline;
	char	*tmp[2];

	i = 0;
	lline = 0;
	tmp[0] = gnl(fd);
	while (tmp[0])
	{
		tmp[1] = ft_strtrim(tmp[0], " \n\t\v\f\r");
		if (ft_strlen(tmp[1]))
			res[i++] = ft_strtrim(tmp[0], " \n");
		if (lline < ft_strlen(res[i - 1]))
			lline = ft_strlen(res[i - 1]);
		free(tmp[0]);
		free(tmp[1]);
		tmp[0] = gnl(fd);
	}
	return (lline);
}

void	read_map(t_map *data, char *file, int skipped)
{
	int		fd;
	char	**res;
	int		i;

	data->map_y = rows_number(file) - 6;
	if (data->map_y < 3)
	{
		printf("failed: Map is too small\n");
		exit(EXIT_FAILURE);
	}
	fd = open(file, O_RDONLY);
	lerrx(fd != -1, "can't open the map file");
	i = -1;
	while (++i < skipped)
		free(gnl(fd));
	res = ft_calloc((data->map_y + 7), sizeof(char *));
	data->map_x = extract_map(fd, res);
	data->map = res;
	close(fd);
}
