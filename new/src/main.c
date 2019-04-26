#include "../hdr/fdf.h"

void	print_tab(t_mlx *mlx)
{
	int i;
	int j;

	j = 0;
	while (j < mlx->nblin)
	{
		i = 0;
		while (i < mlx->nbcol)
		{
			ft_putnbr(mlx->tab[j][i]);
			ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}

int		main(int argc, char **argv)
{
	int fd;
	t_mlx mlx;

	init_var(&mlx);
	if (argc != 2)
	{
		ft_putstr("Need one and only one argument");
		return (-1);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (-1);
	ft_parsing(fd, &mlx);
	print_tab(&mlx);
	find_scale(&mlx);
	find_offset(&mlx);
	ft_mlx(mlx);
	close(fd);
	return (0);
}
