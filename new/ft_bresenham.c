/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 23:41:21 by lgrudler          #+#    #+#             */
/*   Updated: 2019/03/11 16:40:02 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_bresenham(t_mlx *mlx)
{
	int dx;
	int dy;
	int sx;
	int sy;
	int e2;

	dx = ft_abs(mlx->x2 - mlx->x1);
	sx = mlx->x1 < mlx->x2 ? 1 : -1;
	dy = ft_abs(mlx->y2 - mlx->y1);
	sy = mlx->y1 < mlx->y2 ? 1 : -1;
	if (dx > dy)
		mlx->err = dx / 2;
	else if (dx < dy)
		mlx->err = -dy / 2;
	while (1)
	{
		put_pixel(mlx);
		if (mlx->x1 == mlx->x2 && mlx->y1 == mlx->y2)
			return (0);
		e2 = mlx->err;
		if (e2 > -dx)
		{
			mlx->err -= dy;
			mlx->x1 += sx;
		}
		if (e2 < dy)
		{
			mlx->err += dx;
			mlx->y1 += sy;
		}
	}
}
