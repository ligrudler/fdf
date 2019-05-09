/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:55:00 by jmoucach          #+#    #+#             */
/*   Updated: 2019/05/03 13:50:59 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/fdf.h"

void	ft_free_map(t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < mlx->nblin)
	{
		free(mlx->map[i]);
		i++;
	}
	free(mlx->map);
}

void	ft_free_split(char **split)
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

void	ft_error_split(char **split)
{
	ft_free_split(split);
	ft_error();
}

void	ft_free_str(char *str)
{
	free(str);
	ft_error();
}
