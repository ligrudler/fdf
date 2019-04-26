#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft/libft.h"

# define WINX 1920
# define WINY 1080

# define IMGX 
typedef struct	s_mlx
{
// Pour le parsing
	int nblin;
	int nbcol;
	int **tab;
// Pour la mlx
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*canvas;
	int			bpp;
	int			size_line;
	int			endian;

// Pour Bresenham
	int			err;
	int			x1;
	int			x2;
	int			y1;
	int			y2;

// Autre
	int			color;

}				t_mlx;

void		ft_parsing(int fd, t_mlx *mlx);
void		check_col_lin(t_mlx *mlx, char *str);
void		create_double_tab(t_mlx *mlx);
void		stock_in_tab(char *str, t_mlx *mlx);

int			ft_mlx(t_mlx mlx);
void		put_pixel(t_mlx * mlx);
int			ft_bresenham(t_mlx *mlx);
void		test(t_mlx *mlx);

#endif
