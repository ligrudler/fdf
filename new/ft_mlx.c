#include "fdf.h"

void	put_pixel(t_mlx *mlx)
{
	*(int *)&mlx->canvas[mlx->y1 * mlx->size_line + (mlx->x1 * 4)] = mlx->color;
}

void	test(t_mlx *mlx)
{
		int i;
		int j;

		j = 0;
		while ( j < mlx->nbcol)
		{
			i = 0;
			while (i < mlx->nblin)
			{
				
			}
		}
}

int		deal_key(void *param)
{
	t_mlx	*pmlx;
	int		i;

	pmlx = (t_mlx *)param;
	test(pmlx);
	mlx_put_image_to_window(pmlx->mlx_ptr, pmlx->win_ptr, pmlx->img, WINX, WINY);
	return (0);
}

int		ft_mlx(t_mlx mlx)
{
	if ((mlx.mlx_ptr = mlx_init()) == NULL)
		ft_error();
	if ((mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WINX, WINY, "FDF")) == NULL)
		ft_error();
	if ((mlx.img = mlx_new_image(mlx.mlx_ptr, WINX, WINY)) == NULL)
		ft_error();
	mlx.canvas = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.size_line, &mlx.endian);
	mlx_loop_hook(mlx.mlx_ptr, deal_key, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
