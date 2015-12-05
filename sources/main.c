/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 17:28:05 by cglavieu          #+#    #+#             */
/*   Updated: 2015/05/19 19:12:44 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libmlx.h"

int			main(int ac, char **av)
{
	t_map *map;
	t_env *c;

	c = (t_env *)malloc(sizeof(t_env));
	map = (t_map *)malloc(sizeof(t_map));
	c->off = XCENTER;
	c->off2 = YCENTER;
	c->zoom = 42;
	c->zh = 1;
	c->rot = 0.5;
	c->roty = 0.6;
	if (ac == 2)
		c->coord = ft_get_coord(map, av[1]);
	else
		c->coord = ft_get_coord(map, "test_maps/42.fdf");
	ft_mlx(c);
	return (0);
}
