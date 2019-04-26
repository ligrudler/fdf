/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:55:43 by jmoucach          #+#    #+#             */
/*   Updated: 2019/04/26 13:55:46 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/fdf.h"

void	init_var(t_mlx *mlx)
{
	mlx->nblin = 0;
	mlx->color = 0xffffff;
	mlx->bres.err = 0;
    mlx->alt = 0;
    ft_bzero(mlx->keyboard, 256);
}

void    init_img(t_mlx *mlx)
{
    if ((mlx->mlx_ptr = mlx_init()) == NULL)
		ft_error();
	if ((mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WINX, WINY, "FDF")) == NULL)
		ft_error();
	if ((mlx->img = mlx_new_image(mlx->mlx_ptr, WINX, WINY)) == NULL)
		ft_error();
	mlx->canvas = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size_line, &mlx->endian);

}
