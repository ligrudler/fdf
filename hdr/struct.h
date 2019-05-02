/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:43:25 by jmoucach          #+#    #+#             */
/*   Updated: 2019/04/26 15:43:27 by jmoucach         ###   ########.fr       */
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
	int dx;
	int dy;
	int sx;
	int sy;
	int e2;
}				t_bress;

typedef	struct s_map
{
	int		z;
	int		color;
}				t_map;

typedef struct	s_mlx
{
// Pour le parsing
	int nblin;
	int nbcol;
	t_map		**map;
// Pour la mlx
	void		*mlx_ptr;
	void		*win_ptr;
// Pour l'image
	void		*img;
	char		*canvas;
	int			bpp;
	int			size_line;
	int			endian;
	int			scale;
	int			xoff;
	int			yoff;
// Pour Bresenham
	t_bress		bres;
	double		alt;
// Autre
	char		*color;
	int			keyboard[256];
	int		iso;

}				t_mlx;

#endif
