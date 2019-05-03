/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <lgrudler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:26:10 by jmoucach          #+#    #+#             */
/*   Updated: 2019/05/03 13:56:19 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/fdf.h"

double	ft_percent(int start, int end, int current)
{
	double		distance;
	double		placement;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

double	get_percent(t_pt start, t_pt end, t_pt current)
{
	int			deltax;
	int			deltay;

	deltax = ft_abs(end.x - start.x);
	deltay = ft_abs(end.y - start.y);
	if (deltax > deltay)
		return (ft_percent(end.x, start.x, current.x));
	else
		return (ft_percent(end.y, start.y, current.y));
}

int		get_light(int start, int end, double percentage)
{
	return ((int)(percentage * start + (1 - percentage) * end));
}

int		get_co(t_pt current, t_pt start, t_pt end)
{
	double		percentage;
	int			red;
	int			green;
	int			blue;

	if (start.color == end.color)
		return (start.color);
	percentage = get_percent(start, end, current);
	red = get_light(start.color >> 16 & 0xFF, end.color >> 16 & 0xFF,
		percentage);
	green = get_light(start.color >> 8 & 0xFF, end.color >> 8 & 0xFF,
		percentage);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
