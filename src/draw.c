/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:32:19 by jmoucach          #+#    #+#             */
/*   Updated: 2019/04/26 15:32:20 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/fdf.h"

void	put_pixel(t_mlx *mlx)
{
	/*if (mlx->bres.color != 0)
		*(int *)&mlx->canvas[mlx->bres.p1.y * mlx->size_line + (mlx->bres.cur.x) * 4] = mlx->bres.color;
	else*/
		*(int *)&mlx->canvas[mlx->bres.cur.y * mlx->size_line + (mlx->bres.cur.x) * 4] = mlx->bres.cur.color;
}

void	print_grid_para(t_mlx *mlx)
{
	int x;
	int y;

	y = 0;
	while (y < mlx->nblin)
	{
		x = 0;
		while (x < mlx->nbcol)
		{
			mlx->bres.p1.x = x * mlx->scale + mlx->xoff;
			mlx->bres.p1.y = (y - (mlx->map[y][x].z * mlx->alt)) * mlx->scale + mlx->yoff;
			mlx->bres.p1.color = mlx->map[y][x].color;
			if (y - 1 >= 0)
			{
				mlx->bres.p2.x = x * mlx->scale + mlx->xoff;
				mlx->bres.p2.y = (y - 1 - (mlx->map[y- 1][x].z * mlx->alt)) * mlx->scale + mlx->yoff;
				mlx->bres.p2.color = mlx->map[y - 1][x].color;
				ft_bresenham(mlx); 
			}
			if (x - 1 >= 0)
			{
				mlx->bres.p2.x = (x - 1) * mlx->scale + mlx->xoff;
				mlx->bres.p2.y = (y - (mlx->map[y][x - 1].z * mlx->alt)) * mlx->scale + mlx->yoff;
				mlx->bres.p2.color = mlx->map[y][x - 1].color;
				ft_bresenham(mlx); 
			}
			x++;
		}
		y++;
	}
}

void	print_grid_iso(t_mlx *mlx)
{
	int x;
	int y;

	y = 0;
	while (y < mlx->nblin)
	{
		x = 0;
		while (x < mlx->nbcol)
		{
			mlx->bres.p1.x = (x - y) * cos(0.46373398225489) * mlx->scale + mlx->xoff;
			mlx->bres.p1.y = (-(mlx->map[y][x].z * mlx->alt) + (x + y) * sin(0.46373398225489))
				* mlx->scale + mlx->yoff;
			mlx->bres.p1.color = mlx->map[y][x].color;
			if (y - 1 >= 0)
			{
				mlx->bres.p2.x = (x - (y - 1)) * cos(0.46373398225489) * mlx->scale + mlx->xoff;
				mlx->bres.p2.y = (-(mlx->map[y - 1][x].z * mlx->alt) + (x + (y - 1)) * sin(0.46373398225489))
					* mlx->scale + mlx->yoff;
				mlx->bres.p2.color = mlx->map[y - 1][x].color;
				ft_bresenham(mlx); 
			}
			if (x - 1 >= 0)
			{
				mlx->bres.p2.x = ((x - 1) - y) * cos(0.46373398225489) * mlx->scale + mlx->xoff;
				mlx->bres.p2.y = (-(mlx->map[y][x - 1].z * mlx->alt) + (x + (y - 1)) * sin(0.46373398225489))
					* mlx->scale + mlx->yoff;
				mlx->bres.p2.color = mlx->map[y][x - 1].color;
				ft_bresenham(mlx); 
			}
			x++;
		}
		y++;
	} 
}

void	print_grid(t_mlx *mlx)
{
	if (mlx->iso)
		print_grid_iso(mlx);
	else
		print_grid_para(mlx);
}
