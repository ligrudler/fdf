/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:55:00 by jmoucach          #+#    #+#             */
/*   Updated: 2019/04/29 16:55:01 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/fdf.h"

void    ft_free_tab(t_mlx *mlx)
{
    int i;
    i = 0;
    while (i < mlx->nblin)
    {
        free(mlx->tab[i]);
        i++;
    }
    free(mlx->tab);
}

void    ft_free_split(char **split)
{
    int i;

    i = 0;
    while (split[i])
    {
        ft_strdel(&(split[i]));
        i++;
    }
    free(split);
}
