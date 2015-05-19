/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_octant_5_8.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 12:08:17 by cglavieu          #+#    #+#             */
/*   Updated: 2015/05/19 19:13:06 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libmlx.h"

void octant_5(t_box *b, t_env *c)
{
	int dx;
	int dy;
	int e;

	dx = b->x2 - b->x1;
	dy = b->y2 - b->y1;
	e = dx;
	dx = e * 2;
	dy = dy * 2;
	while (b->x1 != b->x2)
	{
		mlx_pixel_wput(c, b->x1, b->y1);
		e = e - dy;
		if (e >= 0)
		{
			b->y1--;
			e = e + dx;
		}
		b->x1--;
	}
}

void octant_6(t_box *b, t_env *c)
{
	int dx;
	int dy;
	int e;

	dx = b->x2 - b->x1;
	dy = b->y2 - b->y1;
	e = dy;
	dy = e * 2;
	dx = dx * 2;
	while (b->y1 != b->y2)
	{
		mlx_pixel_wput(c, b->x1, b->y1);
		e = e - dx;
		if (e >= 0)
		{
			b->x1--;
			e = e + dy;
		}
		b->y1--;
	}
}

void octant_7(t_box *b, t_env *c)
{
	int dx;
	int dy;
	int e;

	dx = b->x2 - b->x1;
	dy = b->y2 - b->y1;
	e = dy;
	dy = e * 2;
	dx = dx * 2;
	while (b->y1 != b->y2)
	{
		mlx_pixel_wput(c, b->x1, b->y1);
		e = e + dx;
		if (e > 0)
		{
			b->x1++;
			e = e + dy;
		}
		b->y1--;
	}
}

void octant_8(t_box *b, t_env *c)
{
	int dx;
	int dy;
	int e;

	dx = b->x2 - b->x1;
	dy = b->y2 - b->y1;
	e = dx;
	dx = e * 2;
	dy = dy * 2;
	while (b->x1 != b->x2)
	{
		mlx_pixel_wput(c, b->x1, b->y1);
		e = e + dy;
		if (e < 0)
		{
			b->y1--;
			e = e + dx;
		}
		b->x1++;
	}
}
