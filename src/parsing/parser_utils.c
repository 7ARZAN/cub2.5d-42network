/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarzan <elakhfif@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 02:06:43 by tarzan            #+#    #+#             */
/*   Updated: 2024/06/11 06:46:42 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	lerrx(bool condition, char *msg)
{
	if (condition == false)
	{
		fprintf(stderr, "%s\n", msg);
		exit(EXIT_FAILURE);
	}
}

void	skip_spaces(char *line, int *j)
{
	while (line[*j] == ' ')
		(*j)++;
}

unsigned int	create_rgba(int r, int g, int b, int a)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		printf("[failed: invalid color]\n");
		exit(EXIT_FAILURE);
	}
	return (r << 24 | g << 16 | b << 8 | a);
}

int	floor_color(char *line)
{
	int		i;
	int		color;
	char	**rgb;

	i = 0;
	if (ft_strncmp(line, "F ", 2) != 0)
		return (-1);
	i += 2;
	while (ft_strchr(" \t", line[i]))
		i++;
	rgb = ohmysplit(&line[i], ',');
	color = create_rgba(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]), 0);
	free2d(rgb);
	return (color);
}

int	ceiling_color(char *line)
{
	int		i;
	int		color;
	char	**rgb;

	i = 0;
	if (ft_strncmp(line, "C ", 2) != 0)
		return (-1);
	i += 2;
	while (ft_strchr(" \t", line[i]))
		i++;
	rgb = ohmysplit(&line[i], ',');
	color = create_rgba(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]), 0);
	free2d(rgb);
	return (color);
}
