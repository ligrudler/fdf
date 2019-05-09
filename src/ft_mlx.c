/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 13:56:41 by lgrudler          #+#    #+#             */
/*   Updated: 2019/05/03 17:05:12 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/fdf.h"

void	init_key(t_mlx *pmlx)
{
	if ((pmlx->keyboard[KEY_PAD_SUB] && !pmlx->keyboard[KEY_PAD_ADD])
		|| (pmlx->keyboard[KEY_PAD_ADD] && !pmlx->keyboard[KEY_PAD_SUB]))
		pmlx->alt += pmlx->keyboard[KEY_PAD_SUB] ? -0.1 : +0.1;
	if ((pmlx->keyboard[KEY_UP] && !pmlx->keyboard[KEY_DOWN]) || (pmlx->
		keyboard[KEY_DOWN] && pmlx->scale > 0 && !pmlx->keyboard[KEY_UP]))
		pmlx->scale += pmlx->keyboard[KEY_UP] ? +1 : -1;
	if (pmlx->keyboard[KEY_SPACEBAR] && !(pmlx->alt = 0))
	{
		find_scale(pmlx);
		pmlx->off = 0;
	}
	if (pmlx->keyboard[KEY_P] && !(pmlx->keyboard[KEY_P] = 0))
		pmlx->iso = pmlx->iso ? 0 : 1;
	if ((pmlx->keyboard[KEY_D] && !pmlx->keyboard[KEY_A])
		|| (pmlx->keyboard[KEY_A] && !pmlx->keyboard[KEY_D]))
	{
		pmlx->off = 1;
		pmlx->xoff += pmlx->keyboard[KEY_D] ? 10 : -10;
	}
	if ((pmlx->keyboard[KEY_W] && !pmlx->keyboard[KEY_S])
		|| (pmlx->keyboard[KEY_S] && !pmlx->keyboard[KEY_W]))
	{
		pmlx->off = 1;
		pmlx->yoff += pmlx->keyboard[KEY_W] ? -10 : 10;
	}
}

void	frame_legend(t_mlx *pmlx)
{
	pmlx->bres.p1.x = 39;
	pmlx->bres.p1.y = 39;
	pmlx->bres.p1.color = 0x2821DD;
	pmlx->bres.p2.x = 39;
	pmlx->bres.p2.y = 341;
	pmlx->bres.p2.color = 0x2821DD;
	ft_bresenham(pmlx);
	pmlx->bres.p2.x = 301;
	pmlx->bres.p2.y = 39;
	pmlx->bres.p2.color = 0x2821DD;
	ft_bresenham(pmlx);
	pmlx->bres.p1.x = 301;
	pmlx->bres.p1.y = 341;
	pmlx->bres.p1.color = 0x2821DD;
	pmlx->bres.p2.x = 39;
	pmlx->bres.p2.y = 341;
	pmlx->bres.p2.color = 0x2821DD;
	ft_bresenham(pmlx);
	pmlx->bres.p2.x = 301;
	pmlx->bres.p2.y = 39;
	pmlx->bres.p2.color = 0x2821DD;
	ft_bresenham(pmlx);
}

void	print_legend(t_mlx *pmlx)
{
	mlx_string_put(pmlx->mlx_ptr, pmlx->win_ptr, 50, 50, 0x42cbf4,
		"ALTITUDE : + / -");
	mlx_string_put(pmlx->mlx_ptr, pmlx->win_ptr, 50, 100, 0x42cbf4,
		"ZOOM : haut / bas");
	mlx_string_put(pmlx->mlx_ptr, pmlx->win_ptr, 50, 150, 0x42cbf4,
		"POSITION : w / s / a / d");
	mlx_string_put(pmlx->mlx_ptr, pmlx->win_ptr, 50, 200, 0x42cbf4,
		"PROJECTION : P");
	mlx_string_put(pmlx->mlx_ptr, pmlx->win_ptr, 50, 250, 0x42cbf4,
		"RECOMMENCER : spacebar");
	mlx_string_put(pmlx->mlx_ptr, pmlx->win_ptr, 50, 300, 0x42cbf4,
		"QUITTER : echap");
}

int		deal_key(void *param)
{
	t_mlx	*pmlx;

	pmlx = (t_mlx *)param;
	if (pmlx->keyboard[KEY_ESCAPE])
	{
		mlx_destroy_image(pmlx->mlx_ptr, pmlx->img);
		mlx_destroy_window(pmlx->mlx_ptr, pmlx->win_ptr);
		ft_free_map(pmlx);
		exit(0);
	}
	init_key(pmlx);
	if (pmlx->off == 0)
		find_offset(pmlx);
	ft_bzero(pmlx->canvas, 4 * WINX * WINY);
	print_grid(pmlx);
	frame_legend(pmlx);
	mlx_put_image_to_window(pmlx->mlx_ptr, pmlx->win_ptr, pmlx->img, 0, 0);
	print_legend(pmlx);
	return (0);
}

int		ft_mlx(t_mlx mlx)
{
	init_img(&mlx);
	mlx_hook(mlx.win_ptr, KEYPRESS, KEYPRESSMASK, key_press, &mlx);
	mlx_hook(mlx.win_ptr, KEYRELEASE, KEYRELEASEMASK, key_release, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, deal_key, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
