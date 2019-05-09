/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:15:53 by lgrudler          #+#    #+#             */
/*   Updated: 2019/05/03 15:07:23 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/fdf.h"

void		check_col_lin(t_mlx *mlx, char *str)
{
	int		i;
	int		tmp;
	int		col;

	i = -1;
	while (str[++i])
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
			ft_free_str(str);
		mlx->nblin++;
	}
}

void		create_double_tab(t_mlx *mlx, char *str)
{
	int		i;

	if (!(mlx->map = (t_map**)malloc(sizeof(t_map*) * mlx->nblin)))
		ft_free_str(str);
	i = 0;
	while (i < mlx->nblin)
		if (!(mlx->map[i++] = (t_map*)malloc(sizeof(t_map) * mlx->nbcol)))
		{
			free(str);
			while (i-- >= 0)
				free(mlx->map[i]);
			free(mlx->map);
			ft_error();
		}
}

void		stock_in_tab(char *str, t_mlx *mlx)
{
	t_pars p;

	p.car.y = ' ';
	p.car.z = '\n';
	p.i = 0;
	p.lin = 0;
	p.split = ft_strsplit_2car(str, p.car);
	while (p.split[p.i] && !(p.col = 0))
	{
		while (p.split[p.i] && (p.col < mlx->nbcol))
		{
			if (ft_atol(p.split[p.i]) != ft_atoi(p.split[p.i]))
				ft_error_split(p.split);
			mlx->map[p.lin][p.col].z = ft_atoi(p.split[p.i]);
			if (ft_strchr(p.split[p.i], ','))
				mlx->map[p.lin][p.col].color = ft_htoi(ft_strchr(
					p.split[p.i], ',') + 1);
			else
				mlx->map[p.lin][p.col].color = ft_htoi(mlx->color);
			p.col++;
			p.i++;
		}
		p.lin++;
	}
	ft_free_split(p.split);
}

void		ft_parsing(int fd, t_mlx *mlx)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	*str;
	char	*tmp;
	int		i;

	str = NULL;
	i = -1;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = str;
		str = ft_strjoin_gnl(tmp, buf);
		free(tmp);
		while (str[++i])
			if (ft_isalnum(str[i]) != 1 && str[i] != ' ' && str[i] != '\n'
					&& str[i] != '-' && str[i] != ',' && str[i] != '+')
				ft_free_str(str);
	}
	if (ret <= -1 || str == NULL)
		ft_free_str(str);
	check_col_lin(mlx, str);
	create_double_tab(mlx, str);
	stock_in_tab(str, mlx);
	free(str);
}
