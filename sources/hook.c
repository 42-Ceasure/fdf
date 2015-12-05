/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 10:29:54 by cglavieu          #+#    #+#             */
/*   Updated: 2015/05/19 19:12:32 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libmlx.h"

int		loop_hook(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_line),
								&(e->endian));
	e->rot += (2 * M_PI / WIDTH);
	draw(e);
	return (0);
}

int		expose_hook(t_env *e)
{
	draw(e);
	return (0);
}

void	key_hook2(int keycode, t_env *e)
{
	if (keycode == 123)
		e->off -= 20;
	if (keycode == 124)
		e->off += 20;
	if (keycode == 126)
		e->off2 -= 20;
	if (keycode == 125)
		e->off2 += 20;
	if (keycode == 27)
		e->zoom -= 5;
	if (keycode == 24)
		e->zoom += 5;
	if (keycode == 47)
		e->zh += 5;
	if (keycode == 43)
		e->zh -= 5;
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	key_hook2(keycode, e);
	if (keycode == 0)
		e->rot += (2 * M_PI / 180);
	if (keycode == 2)
		e->rot -= (2 * M_PI / 180);
	if (keycode == 1)
		e->roty += (2 * M_PI / 90);
	if (keycode == 13)
		e->roty -= (2 * M_PI / 90);
	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_line),
								&(e->endian));
	expose_hook(e);
	return (0);
}

void	ft_mlx(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "fdf");
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->bpp = 4;
	e->endian = 1;
	e->s_line = WIDTH;
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_line), &(e->endian));
	e->color = mlx_get_color_value(e->mlx, 0x3498db);
	e->color2 = mlx_get_color_value(e->mlx, 0x00561b);
	mlx_key_hook(e->win, key_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
}
