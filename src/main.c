/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:32:29 by lgrudler          #+#    #+#             */
/*   Updated: 2019/05/03 14:33:02 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/fdf.h"

void	print_tab(t_mlx *mlx)
{
	int		i;
	int		j;

	j = 0;
	while (j < mlx->nblin)
	{
		i = 0;
		while (i < mlx->nbcol)
		{
			ft_putnbr(mlx->map[j][i].z);
			ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}

int		main(int argc, char **argv)
{
	int		fd;
	t_mlx	mlx;

	init_var(&mlx);
	if (argc != 2)
	{
		ft_putstr("Need one and only one argument");
		return (-1);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_error();
	ft_parsing(fd, &mlx);
	print_tab(&mlx);
	find_scale(&mlx);
	ft_mlx(mlx);
	close(fd);
	return (0);
}
