/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 10:32:09 by cglavieu          #+#    #+#             */
/*   Updated: 2015/05/19 19:11:58 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libmlx.h"

void		ft_get_tab(t_map *map)
{
	int		fd;
	int		i;
	char	*line;

	map->y = 0;
	i = 0;
	if ((fd = open(map->av[1], O_RDONLY)) < 0)
	{
		ft_putendl("Cannot open Map");
		exit(0);
	}
	while (get_next_line(fd, &line))
	{	
		map->y++;
		free(line);
	}
	close(fd);
	fd = open(map->av[1], O_RDONLY);
	if ((map->tab = (char **)malloc(sizeof(char *) * (map->y + 1))) == NULL)
		exit (0);
	while (get_next_line(fd, &line))
	{
		if (line[0] != '\0')
			map->tab[i++] = line;
		else
			map->y--;
	}
	close(fd);
	free(line);
}

t_coord		*ft_new_coord(int x, int y, int z, t_map *map)
{
	t_coord *coord;

	if ((coord = (t_coord *)malloc(sizeof(t_coord))) == NULL)
		exit(0);
	coord->size_x = (map->x);
	coord->size_y = (map->y);
	coord->z = z;
	coord->x = x - coord->size_x / 2;
	coord->y = y - map->y / 2;
	return (coord);
}

void		getch(int i, int j, t_map *map, t_coord ***coord)
{
	while (++j < map->x)
	{
		if (map->tmp[j] != '\0' && map->tmp[j][0] != '\n')
		{
			coord[i][j] = ft_new_coord(j, i, ft_atoi(map->tmp[j]), map);
			coord[i][j]->size_y = (map->y);
		}
		free(map->tmp[j]);
	}
}

t_coord		***ft_get_coord(t_map *map)
{
	int		i;
	int		j;
	t_coord	***coord;

	i = 0;
	ft_get_tab(map);
	if ((coord = (t_coord ***)malloc(sizeof(t_coord **) * map->y + 1)) == NULL)
		exit(0);
	while (i < map->y)
	{
		map->tmp = ft_strsplit(map->tab[i], ' ');
		free(map->tab[i]);
		map->x = 0;
		while (map->tmp[map->x] != '\0')
			map->x++;
		free(map->tmp[map->x]);
		j = -1;
		if ((coord[i] = (t_coord **)malloc(sizeof(t_coord*) * (map->x + 1))) == NULL)
			exit(0);
		getch(i, j, map, coord);
		i++;
		free(map->tmp);
	}
	free(map->tab);
	free(map);
	return (coord);
}
