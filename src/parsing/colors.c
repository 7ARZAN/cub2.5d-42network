#include "../../includes/cub3d.h"

int	parse_floor_color(char *line)
{
	int	rgb[3];
	int	i;
	int	k;

	i = 2;
	k = 0;
	while (k < 3)
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		rgb[k] = ft_atoi(line + i);
		if (rgb[k] < 0 || rgb[k] > 255)
			exit_on_error(false, "Error: Invalid floor color value");
		while (line[i] >= '0' && line[i] <= '9')
			i++;
		if (k < 2 && line[i] != ',')
			exit_on_error(false, "Error: Missing comma in floor color");
		i += (k < 2);
		k++;
	}
	return (create_rgba(rgb[0], rgb[1], rgb[2], 255));
}

int	parse_ceiling_color(char *line)
{
	int	rgb[3];
	int	i;
	int	k;

	i = 2;
	k = 0;
	while (k < 3)
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		rgb[k] = ft_atoi(line + i);
		if (rgb[k] < 0 || rgb[k] > 255)
			exit_on_error(false, "Error: Invalid ceiling color value");
		while (line[i] >= '0' && line[i] <= '9')
			i++;
		if (k < 2 && line[i] != ',')
			exit_on_error(false, "Error: Missing comma in ceiling color");
		i += (k < 2);
		k++;
	}
	return (create_rgba(rgb[0], rgb[1], rgb[2], 255));
}
