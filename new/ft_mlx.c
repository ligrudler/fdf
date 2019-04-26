#include "fdf.h"

void	put_pixel(t_mlx *mlx)
{
	*(int *)&mlx->canvas[mlx->bres.y1 * mlx->size_line + (mlx->bres.x1 * 4)] = mlx->color;
}

void	print_grid(t_mlx *mlx)
{
	int x;
	int y;

	y = 0;
	while (y < mlx->nblin)
	{
		x = 0;
		while (x < mlx->nbcol)
		{
			mlx->bres.x1 = x * 10 + WINX/2;
			mlx->bres.y1 = (y - (mlx->tab[y][x] * mlx->alt)) * 10 + WINY/2; 
			if (y - 1 >= 0)
			{
				mlx->bres.x2 = x * 10 + WINX/2;
				mlx->bres.y2 = (y - 1 - (mlx->tab[y- 1][x] * mlx->alt)) * 10 + WINY/2; 
				mlx->bres.err = 0;
				ft_bresenham(mlx); 
			}
			mlx->bres.x1 = x * 10 + WINX/2;
			mlx->bres.y1 = (y - (mlx->tab[y][x] * mlx->alt)) * 10 + WINY/2;
			if (x - 1 >= 0)
			{
				mlx->bres.x2 = (x - 1) * 10 + WINX/2;
				mlx->bres.y2 = (y - (mlx->tab[y][x - 1] * mlx->alt)) * 10 + WINY/2;
				mlx->bres.err = 0;
				ft_bresenham(mlx); 
			}
			
			x++;
		}
		y++;
	}
}

int deal_key(void *param)
{
    t_mlx   *pmlx;

    pmlx = (t_mlx *)param;
    if (pmlx->keyboard[KEY_ESCAPE])
    {
        mlx_destroy_image(pmlx->mlx_ptr, pmlx->img);
        mlx_destroy_window(pmlx->mlx_ptr, pmlx->win_ptr);
        exit(0);
    }
    if (pmlx->keyboard[KEY_PAD_SUB])
		pmlx->alt -= 0.1;
    if (pmlx->keyboard[KEY_PAD_ADD])
	{
		pmlx->alt += 0.1;
	}
    ft_bzero(pmlx->canvas, 4 * WINX * WINY);
	print_grid(pmlx);
	mlx_put_image_to_window(pmlx->mlx_ptr, pmlx->win_ptr, pmlx->img, 0, 0);
    return (0);
}

int key_press(int key, void *param)
{
    t_mlx *pmlx;

//  ft_putnbr(key);
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

#include <stdio.h>


int		ft_mlx(t_mlx mlx)
{
	init_img(&mlx);
    mlx_hook(mlx.win_ptr, KEYPRESS, KEYPRESSMASK, key_press, &mlx);
    mlx_hook(mlx.win_ptr, KEYRELEASE, KEYRELEASEMASK, key_release, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, deal_key, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
