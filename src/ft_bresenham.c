/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 23:41:21 by lgrudler          #+#    #+#             */
/*   Updated: 2019/05/03 13:56:25 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/fdf.h"

int	is_inside_win(t_mlx mlx)
{
	if (mlx.bres.cur.x <= 0 || mlx.bres.cur.x >= WINX
		|| mlx.bres.cur.y <= 0 || mlx.bres.cur.y >= WINY)
		return (0);
	else if ((mlx.bres.cur.x <= 300 && mlx.bres.cur.x >= 40)
		&& (mlx.bres.cur.y <= 340 && mlx.bres.cur.y >= 40))
		return (0);
	return (1);
}

int	ft_bresenham(t_mlx *mlx)
{
	init_bres(mlx);
	if (mlx->bres.dx > mlx->bres.dy)
		mlx->bres.err = mlx->bres.dx / 2;
	else if (mlx->bres.dx < mlx->bres.dy)
		mlx->bres.err = -(mlx->bres.dy) / 2;
	while (1)
	{
		mlx->bres.cur.color = get_co(mlx->bres.cur, mlx->bres.p1, mlx->bres.p2);
		if (is_inside_win(*mlx))
			put_pixel(mlx);
		if (mlx->bres.cur.x == mlx->bres.p2.x
			&& mlx->bres.cur.y == mlx->bres.p2.y)
			return (0);
		mlx->bres.e2 = mlx->bres.err;
		if (mlx->bres.e2 > -(mlx->bres.dx))
		{
			mlx->bres.err -= mlx->bres.dy;
			mlx->bres.cur.x += mlx->bres.sx;
		}
		if (mlx->bres.e2 < mlx->bres.dy)
		{
			mlx->bres.err += mlx->bres.dx;
			mlx->bres.cur.y += mlx->bres.sy;
		}
	}
}
