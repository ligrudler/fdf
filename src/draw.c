/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:32:19 by jmoucach          #+#    #+#             */
/*   Updated: 2019/05/03 14:57:27 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/fdf.h"

void	put_pixel(t_mlx *mlx)
{
	*(int *)&mlx->canvas[mlx->bres.cur.y * mlx->size_line
		+ (mlx->bres.cur.x) * 4] = mlx->bres.cur.color;
}

void	give_value(t_mlx *mlx, int x, int y)
{
	if (mlx->iso)
	{
		mlx->bres.p2.x = (x - y) * cos(0.46373398225489) * mlx->scale
			+ mlx->xoff;
		mlx->bres.p2.y = (-(mlx->map[y][x].z * mlx->alt) + (x + y)
			* sin(0.46373398225489)) * mlx->scale + mlx->yoff;
		mlx->bres.p2.color = mlx->map[y][x].color;
	}
	else
	{
		mlx->bres.p2.x = x * mlx->scale + mlx->xoff;
		mlx->bres.p2.y = (y - (mlx->map[y][x].z * mlx->alt))
			* mlx->scale + mlx->yoff;
		mlx->bres.p2.color = mlx->map[y][x].color;
	}
}

void	print_grid_para(t_mlx *mlx)
{
	int	x;
	int	y;

	y = -1;
	while (++y < mlx->nblin)
	{
		x = -1;
		while (++x < mlx->nbcol)
		{
			mlx->bres.p1.x = x * mlx->scale + mlx->xoff;
			mlx->bres.p1.y = (y - (mlx->map[y][x].z * mlx->alt))
				* mlx->scale + mlx->yoff;
			mlx->bres.p1.color = mlx->map[y][x].color;
			if (y - 1 >= 0)
			{
				give_value(mlx, x, y - 1);
				ft_bresenham(mlx);
			}
			if (x - 1 >= 0)
			{
				give_value(mlx, x - 1, y);
				ft_bresenham(mlx);
			}
		}
	}
}

void	print_grid_iso(t_mlx *mlx)
{
	int	x;
	int	y;

	y = -1;
	while (++y < mlx->nblin && (x = -1))
	{
		while (++x < mlx->nbcol)
		{
			mlx->bres.p1.x = (x - y) * cos(0.46373398225489)
				* mlx->scale + mlx->xoff;
			mlx->bres.p1.y = (-(mlx->map[y][x].z * mlx->alt)
				+ (x + y) * sin(0.46373398225489)) * mlx->scale + mlx->yoff;
			mlx->bres.p1.color = mlx->map[y][x].color;
			if (y - 1 >= 0)
			{
				give_value(mlx, x, y - 1);
				ft_bresenham(mlx);
			}
			if (x - 1 >= 0)
			{
				give_value(mlx, x - 1, y);
				ft_bresenham(mlx);
			}
		}
	}
}

void	print_grid(t_mlx *mlx)
{
	if (mlx->iso)
		print_grid_iso(mlx);
	else
		print_grid_para(mlx);
}
