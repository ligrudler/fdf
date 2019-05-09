/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:55:43 by jmoucach          #+#    #+#             */
/*   Updated: 2019/05/03 16:22:47 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/fdf.h"

void	find_scale(t_mlx *mlx)
{
	int	big;

	big = (mlx->nbcol > mlx->nblin) ? mlx->nbcol : mlx->nblin;
	if (big >= 0 && big <= 20)
		mlx->scale = 50;
	else if (big > 20 && big <= 50)
		mlx->scale = 20;
	else
		mlx->scale = 5;
}

void	init_var(t_mlx *mlx)
{
	mlx->nblin = 0;
	mlx->color = "0xffffff";
	mlx->bres.err = 0;
	mlx->alt = 0;
	ft_bzero(mlx->keyboard, 256);
	mlx->xoff = 0;
	mlx->yoff = 0;
	mlx->scale = 10;
	mlx->off = 0;
}

void	init_bres(t_mlx *mlx)
{
	mlx->bres.err = 0;
	mlx->bres.dx = ft_abs(mlx->bres.p2.x - mlx->bres.p1.x);
	mlx->bres.sx = mlx->bres.p1.x < mlx->bres.p2.x ? 1 : -1;
	mlx->bres.dy = ft_abs(mlx->bres.p2.y - mlx->bres.p1.y);
	mlx->bres.sy = mlx->bres.p1.y < mlx->bres.p2.y ? 1 : -1;
	mlx->bres.cur.x = mlx->bres.p1.x;
	mlx->bres.cur.y = mlx->bres.p1.y;
}

void	init_img(t_mlx *mlx)
{
	if ((mlx->mlx_ptr = mlx_init()) == NULL)
	{
		ft_free_map(mlx);
		ft_error();
	}
	if ((mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WINX, WINY, "FDF"))
		== NULL)
	{
		ft_free_map(mlx);
		ft_error();
	}
	if ((mlx->img = mlx_new_image(mlx->mlx_ptr, WINX, WINY)) == NULL)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		ft_error();
	}
	mlx->canvas = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size_line,
		&mlx->endian);
}
