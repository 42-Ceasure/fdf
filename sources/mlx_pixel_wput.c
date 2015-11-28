/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_wput.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 21:00:28 by cglavieu          #+#    #+#             */
/*   Updated: 2015/05/19 19:12:48 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libmlx.h"

void				mlx_pxl_wputb(t_env *e, int x, int y, unsigned int place)
{
	place = y * (1920 * 4);
	place += x * 4;
	if (place < ((1920 * 1080) * (sizeof(char) * 4)))
	{
		if (e->inc->z <= 0 && e->inc->z2 <= 0 && e->inc->z3 <= 0)
		{
			e->data[place] = e->colorpix->b;
			e->data[place + 1] = e->colorpix->g;
			e->data[place + 2] = e->colorpix->r;
		}
		else
		{
			e->data[place] = e->colorpix->b2;
			e->data[place + 1] = e->colorpix->g2;
			e->data[place + 2] = e->colorpix->r2;
		}
	}
}

void				mlx_pixel_wput(t_env *e, int x, int y)
{
	unsigned int	place;

	e->colorpix = malloc(sizeof(t_color));
	place = y * (1920 * 4);
	place += x * 4;
	e->colorpix->r = (e->color & 0xFF0000) >> 16;
	e->colorpix->g = (e->color & 0xFF00) >> 8;
	e->colorpix->b = (e->color & 0xFF);
	e->colorpix->r2 = (e->color2 & 0xFF0000) >> 16;
	e->colorpix->g2 = (e->color2 & 0xFF00) >> 8;
	e->colorpix->b2 = (e->color2 & 0xFF);
	if (x > 0 && x < 1920)
		mlx_pxl_wputb(e, x, y, place);
	free(e->colorpix);
}
