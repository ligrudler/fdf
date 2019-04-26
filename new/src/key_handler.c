/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:30:49 by jmoucach          #+#    #+#             */
/*   Updated: 2019/04/26 15:30:53 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../hdr/fdf.h"

int key_press(int key, void *param)
{
    t_mlx *pmlx;

    pmlx = (t_mlx *)param;
    pmlx->keyboard[key] = 1;
    return (0);
}

int key_release(int key, void *param)
{
    t_mlx *pmlx;

    pmlx = (t_mlx *)param;
    pmlx->keyboard[key] = 0;
    return (0);
}
