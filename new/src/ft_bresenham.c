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

#include "../hdr/fdf.h"


int is_inside_win(t_mlx mlx)
{
	if (mlx.bres.x1 <= 0 || mlx.bres.x1 >= WINX 
	 || mlx.bres.y1 <= 0 || mlx.bres.y1 >= WINY)
	 	return (0);
	return (1);
}

int		ft_bresenham(t_mlx *mlx)
{
	int dx;
	int dy;
	int sx;
	int sy;
	int e2;

	dx = ft_abs(mlx->bres.x2 - mlx->bres.x1);
	sx = mlx->bres.x1 < mlx->bres.x2 ? 1 : -1;
	dy = ft_abs(mlx->bres.y2 - mlx->bres.y1);
	sy = mlx->bres.y1 < mlx->bres.y2 ? 1 : -1;
	if (dx > dy)
		mlx->bres.err = dx / 2;
	else if (dx < dy)
		mlx->bres.err = -dy / 2;
	while (1)
	{
		if (is_inside_win(*mlx))
			put_pixel(mlx);
		if (mlx->bres.x1 == mlx->bres.x2 && mlx->bres.y1 == mlx->bres.y2)
			return (0);
		e2 = mlx->bres.err;
		if (e2 > -dx)
		{
			mlx->bres.err -= dy;
			mlx->bres.x1 += sx;
		}
		if (e2 < dy)
		{
			mlx->bres.err += dx;
			mlx->bres.y1 += sy;
		}
	}
}
