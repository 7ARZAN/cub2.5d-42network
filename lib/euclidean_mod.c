/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   euclidean_mod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:15:10 by elakhfif          #+#    #+#             */
/*   Updated: 2024/06/12 01:43:48 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	euclidean_mod(double a, double b)
{
	double	res;

	res = a - b * floor(a / b);
	return (res);
}
