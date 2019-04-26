#include "../hdr/fdf.h"

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
		pmlx->alt += 0.1;
    if (pmlx->keyboard[KEY_UP])
        pmlx->scale += 1;
    if (pmlx->keyboard[KEY_DOWN] && pmlx->scale > 0)
        pmlx->scale -= 1;
    if (pmlx->keyboard[KEY_SPACEBAR])
    {
        find_scale(pmlx);
        pmlx->alt = 0;
    }
	find_offset(pmlx);
    ft_bzero(pmlx->canvas, 4 * WINX * WINY);
	print_grid(pmlx);
	mlx_put_image_to_window(pmlx->mlx_ptr, pmlx->win_ptr, pmlx->img, 0, 0);
    return (0);
}

int		ft_mlx(t_mlx mlx)
{
	init_img(&mlx);
    mlx_hook(mlx.win_ptr, KEYPRESS, KEYPRESSMASK, key_press, &mlx);
    mlx_hook(mlx.win_ptr, KEYRELEASE, KEYRELEASEMASK, key_release, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, deal_key, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
