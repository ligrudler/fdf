/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:26:10 by jmoucach          #+#    #+#             */
/*   Updated: 2019/04/29 17:26:12 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/fdf.h"

void    ft_stock_color(t_mlx *mlx, char *str, int col, int lin)
{
   // int i;

   /* i = 0;
    while (i++ < 3)
        mlx->map[lin][col].color[i] = 0;
    i--;*/
    mlx->map[lin][col].color = ft_htoi(str);
   /* mlx->map[lin][col].color[0] = c / (256 * 256);
    mlx->map[lin][col].color[1] = c / 256 % 256;
    mlx->map[lin][col].color[2] = c % 256;*/
}
