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
	*(int *)&mlx->canvas[mlx->bres.y1 * mlx->size_line + (mlx->bres.x1 * 4)] = mlx->color;
}

void	print_grid(t_mlx *mlx)
{
	int x;
	int y;

	y = 0;
	while (y < mlx->nblin)
	{
		x = 0;
		while (x < mlx->nbcol)
		{
			mlx->bres.x1 = x * 10 + WINX/4;
			mlx->bres.y1 = (y - (mlx->tab[y][x] * mlx->alt)) * 10 + WINY/4; 
			if (y - 1 >= 0)
			{
				mlx->bres.x2 = x * 10 + WINX/4;
				mlx->bres.y2 = (y - 1 - (mlx->tab[y- 1][x] * mlx->alt)) * 10 + WINY/4; 
				mlx->bres.err = 0;
				ft_bresenham(mlx); 
			}
			mlx->bres.x1 = x * 10 + WINX/4;
			mlx->bres.y1 = (y - (mlx->tab[y][x] * mlx->alt)) * 10 + WINY/4;
			if (x - 1 >= 0)
			{
				mlx->bres.x2 = (x - 1) * 10 + WINX/4;
				mlx->bres.y2 = (y - (mlx->tab[y][x - 1] * mlx->alt)) * 10 + WINY/4;
				mlx->bres.err = 0;
				ft_bresenham(mlx); 
			}
			
			x++;
		}
		y++;
	}
}

