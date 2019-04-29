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
		*(int *)&mlx->canvas[mlx->bres.y1 * mlx->size_line + (mlx->bres.x1) * 4] = mlx->bres.color;
	else*/
		*(int *)&mlx->canvas[mlx->bres.y1 * mlx->size_line + (mlx->bres.x1) * 4] = mlx->color;
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
			mlx->bres.x1 = x * mlx->scale + mlx->xoff;
			mlx->bres.y1 = (y - (mlx->map[y][x].z * mlx->alt)) * mlx->scale + mlx->yoff;
			mlx->bres.color = mlx->map[y][x].color;
			if (y - 1 >= 0)
			{
				mlx->bres.x2 = x * mlx->scale + mlx->xoff;
				mlx->bres.y2 = (y - 1 - (mlx->map[y- 1][x].z * mlx->alt)) * mlx->scale + mlx->yoff;
				ft_bresenham(mlx); 
			}
			mlx->bres.x1 = x * mlx->scale + mlx->xoff;
			mlx->bres.y1 = (y - (mlx->map[y][x].z * mlx->alt)) * mlx->scale + mlx->yoff;
			if (x - 1 >= 0)
			{
				mlx->bres.x2 = (x - 1) * mlx->scale + mlx->xoff;
				mlx->bres.y2 = (y - (mlx->map[y][x - 1].z * mlx->alt)) * mlx->scale + mlx->yoff;
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
			mlx->bres.x1 = (x - y) * cos(0.46373398225489) * mlx->scale + mlx->xoff;
			mlx->bres.y1 = (-(mlx->map[y][x].z * mlx->alt) + (x + y) * sin(0.46373398225489))
				* mlx->scale + mlx->yoff;
			if (y - 1 >= 0)
			{
				mlx->bres.x2 = (x - (y - 1)) * cos(0.46373398225489) * mlx->scale + mlx->xoff;
				mlx->bres.y2 = (-(mlx->map[y - 1][x].z * mlx->alt) + (x + (y - 1)) * sin(0.46373398225489))
					* mlx->scale + mlx->yoff;
				ft_bresenham(mlx); 
			}
			mlx->bres.x1 = (x - y) * cos(0.46373398225489) * mlx->scale + mlx->xoff;
			mlx->bres.y1 = (-(mlx->map[y][x].z * mlx->alt) + (x + y) * sin(0.46373398225489))
				* mlx->scale + mlx->yoff;
			if (x - 1 >= 0)
			{
				mlx->bres.x2 = ((x - 1) - y) * cos(0.46373398225489) * mlx->scale + mlx->xoff;
				mlx->bres.y2 = (-(mlx->map[y][x - 1].z * mlx->alt) + (x + (y - 1)) * sin(0.46373398225489))
					* mlx->scale + mlx->yoff;
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
