/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_offset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:44:59 by jmoucach          #+#    #+#             */
/*   Updated: 2019/05/03 17:06:13 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/fdf.h"

void	find_offset_para(t_mlx *mlx)
{
	mlx->xoff = (WINX / 2) - ((mlx->nbcol / 2) * mlx->scale);
	mlx->yoff = (WINY / 2) - ((mlx->nblin / 2) * mlx->scale);
}

void	find_offset_iso(t_mlx *mlx)
{
	mlx->xoff = (WINX / 2) - ((mlx->nbcol / 2) * mlx->scale * 0.46373398225489);
	mlx->yoff = (WINY / 3) - ((mlx->nblin / 2) * mlx->scale * 0.46373398225489);
}

void	find_offset(t_mlx *mlx)
{
	if (mlx->iso)
		find_offset_iso(mlx);
	else
		find_offset_para(mlx);
}
