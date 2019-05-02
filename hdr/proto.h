/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:33:29 by jmoucach          #+#    #+#             */
/*   Updated: 2019/04/26 15:33:30 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

# include "fdf.h"
/*
**  Init
*/

void    init_img(t_mlx *mlx);
void	init_var(t_mlx *mlx);
void	init_bres(t_mlx *mlx);
void	find_scale(t_mlx *mlx);

/*
**
*/

void	find_offset(t_mlx *mlx);
void	find_offset_para(t_mlx *mlx);
void	find_offset_iso(t_mlx *mlx);

/*
**  Draw
*/

void	print_grid_iso(t_mlx *mlx);
void	print_grid_para(t_mlx *mlx);
void	print_grid(t_mlx *mlx);
void	put_pixel(t_mlx *mlx);


/*
**  Key handler
*/

int key_press(int key, void *param);
int key_release(int key, void *param);

/*
**  Parsing
*/

void	ft_parsing(int fd, t_mlx *mlx);
void	check_col_lin(t_mlx *mlx, char *str);
void	create_double_tab(t_mlx *mlx);
void	stock_in_tab(char *str, t_mlx *mlx);

/*
**  Bressenham
*/

int		ft_mlx(t_mlx mlx);
int		ft_bresenham(t_mlx *mlx);

/*
** Color
*/

double  ft_percent(int start, int end, int current);
double  get_percent(t_pt start, t_pt end, t_pt current);
int     get_light(int start, int end, double percentage);
int     get_color(t_pt current, t_pt start, t_pt end);


/*
** Free
*/

void    ft_free_split(char **split);
void    ft_free_map(t_mlx *mlx);

/*
**  Misc
*/

void	print_tab(t_mlx *mlx);

#endif
