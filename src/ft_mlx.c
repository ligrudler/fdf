/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 13:56:41 by lgrudler          #+#    #+#             */
/*   Updated: 2019/05/03 16:19:41 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/fdf.h"

void	init_key(t_mlx *pmlx)
{
	if (pmlx->keyboard[KEY_PAD_SUB] || pmlx->keyboard[KEY_PAD_ADD])
		pmlx->alt += pmlx->keyboard[KEY_PAD_SUB] ? -0.1 : +0.1;
	if (pmlx->keyboard[KEY_UP] || (pmlx->keyboard[KEY_DOWN] && pmlx->scale > 0))
		pmlx->scale += pmlx->keyboard[KEY_UP] ? +1 : -1;
	if (pmlx->keyboard[KEY_SPACEBAR] && !(pmlx->alt = 0))
	{
		find_scale(pmlx);
		pmlx->off = 0;
	}
	if (pmlx->keyboard[KEY_P] && !(pmlx->keyboard[KEY_P] = 0))
		pmlx->iso = pmlx->iso ? 0 : 1;
	if (pmlx->keyboard[KEY_D] || pmlx->keyboard[KEY_A])
	{
		pmlx->off = 1;
		pmlx->xoff += pmlx->keyboard[KEY_D] ? 10 : -10;
	}
	if (pmlx->keyboard[KEY_W] || pmlx->keyboard[KEY_S])
	{
		pmlx->off = 1;
		pmlx->yoff += pmlx->keyboard[KEY_W] ? -10 : 10;
	}
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
	mlx_put_image_to_window(pmlx->mlx_ptr, pmlx->win_ptr, pmlx->img, 0, 0);
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
