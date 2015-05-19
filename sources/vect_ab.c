/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 11:03:51 by cglavieu          #+#    #+#             */
/*   Updated: 2015/05/19 19:12:52 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libmlx.h"

void vect_ab(t_box *b, t_env *c)
{
	int dx;
	int dy;

	dx = b->x2 - b->x1;
	dy = b->y2 - b->y1;
	if (dx == 0 || dy == 0)
		crux(b, c);
	if (dx > 0 && dy > 0 && dx >= dy)
		octant_1(b, c);
	if (dx > 0 && dy > 0 && dx < dy)
		octant_2(b, c);
	if (dx < 0 && dy > 0 && -dx < dy)
		octant_3(b, c);
	if (dx < 0 && dy > 0 && -dx >= dy)
		octant_4(b, c);
	if (dx < 0 && dy < 0 && dx <= dy)
		octant_5(b, c);
	if (dx < 0 && dy < 0 && dx > dy)
		octant_6(b, c);
	if (dx > 0 && dy < 0 && dx < -dy)
		octant_7(b, c);
	if (dx > 0 && dy < 0 && dx >= -dy)
		octant_8(b, c);
}
