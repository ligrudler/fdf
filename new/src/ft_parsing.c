#include "../hdr/fdf.h"

void		check_col_lin(t_mlx *mlx, char *str)
{
	int i;
	int tmp;
	int col;

	i = 0;
	while (str[i])
	{
		col = mlx->nbcol;
		mlx->nbcol = 0;
		tmp = 0;
		while (str[i] && str[i] != '\n')
		{
			if (tmp == 1 && str[i] == ' ')
				tmp = 0;
			if (tmp == 0 && str[i] != ' ')
			{
				tmp = 1;
				mlx->nbcol++;
			}
			i++;
		}
		if ((mlx->nbcol != col) && (mlx->nblin != 0))
			ft_error();
		mlx->nblin++;
		i++;
	}
}

void		create_double_tab(t_mlx *mlx)
{
	int i;
	
	if (!(mlx->tab = (int**)malloc(sizeof(int*) * mlx->nblin)))
		ft_error();
	i = 0;
	while ( i < mlx->nblin)
		if (!(mlx->tab[i++] = (int*)malloc(sizeof(**mlx->tab) * mlx->nbcol)))
			ft_error();
}

void		stock_in_tab(char *str, t_mlx *mlx)
{
	int col;
	int lin;
	int i;
	char **split;
	t_car car;

	car.y = ' ';
	car.z = '\n';
	i = 0;
	lin = 0;
	split = ft_strsplit_2car(str, car);
	while (split[i])
	{
		col = 0;
		while (split[i] && (col < mlx->nbcol))
		{
			if (ft_atol(split[i]) != ft_atoi(split[i]))
				ft_error();
			mlx->tab[lin][col] = ft_atoi(split[i]);
			col++;
			i++;
		}
		lin++;
	}
	ft_free_split(split);
}

void	ft_parsing(int fd, t_mlx *mlx)
{
	char buf[BUFF_SIZE + 1];
	int ret;
	char *str;
	char *tmp;
	int i;

	str = NULL;
	i = -1;
	while (( ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = str;
		str = ft_strjoin_gnl(tmp, buf);
		free(tmp);
		while (str[++i])
			if (ft_isalnum(str[i]) != 1 && str[i] != ' ' && str[i] != '\n' && str[i] != '-'&& str[i] != '\t' && str[i] != ',' && str[i] != '+')
				ft_error();
	}
	if (ret <= -1 || str == NULL)
		ft_error();
	check_col_lin(mlx, str);
	create_double_tab(mlx);
	stock_in_tab(str, mlx);
	free(str);
}
