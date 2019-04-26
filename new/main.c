#include "fdf.h"

void	init_var(t_mlx *mlx)
{
	mlx->nblin = 0;
	mlx->color = 0x00000080;
	mlx->err = 0;
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
	ft_mlx(mlx);
}
