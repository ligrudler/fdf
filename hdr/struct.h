/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:43:25 by jmoucach          #+#    #+#             */
/*   Updated: 2019/05/03 16:09:40 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "fdf.h"

typedef struct	s_pt
{
	int			x;
	int			y;
	int			color;
}				t_pt;

typedef struct	s_bress
{
	int			err;
	int			color;
	t_pt		p1;
	t_pt		p2;
	t_pt		cur;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			e2;
}				t_bress;

typedef struct	s_pars
{
	int			col;
	int			lin;
	int			i;
	char		**split;
	t_car		car;
}				t_pars;

typedef	struct	s_map
{
	int			z;
	int			color;
}				t_map;

typedef struct	s_mlx
{
	int			nblin;
	int			nbcol;
	t_map		**map;

	void		*mlx_ptr;
	void		*win_ptr;

	void		*img;
	char		*canvas;
	int			bpp;
	int			size_line;
	int			endian;
	int			scale;
	int			xoff;
	int			yoff;

	t_bress		bres;
	double		alt;

	char		*color;
	int			keyboard[512];
	int			iso;
	int			off;

}				t_mlx;

#endif
