/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mvmt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:04:13 by laube             #+#    #+#             */
/*   Updated: 2022/03/09 12:03:48 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycasting.h"

int	has_clipping(t_cub2d *cub2d, int newtile_x, int newtile_y)
{
	int	tile_y;
	int	tile_x;

	tile_y = cub2d->player.tile_y;
	tile_x = cub2d->player.tile_x;
	if (cub2d->map.map[tile_y][newtile_x]
			&& cub2d->map.map[newtile_y][tile_x] == '1')
		return (1);
	return (0);
}

int	check_all_collision(t_cub2d *cub2d, int newtile_x, int newtile_y)
{
	if (cub2d->map.map[newtile_y][newtile_x] == '1')
		return (1);
	if (has_clipping(cub2d, newtile_x, newtile_y))
		return (1);
	return (0);
}

int	check_collision(t_cub2d *cub2d, int newpos_x, int newpos_y)
{
	int	margin;

	//printf("newtile_x: %d | newtile_y: %d | value: %c\n", newtile_x, newtile_y, cub2d->map.map[newtile_y][newtile_x]);
	margin = 3;
	//newtile_x = newpos_x + margin / cub2d->tile_size;
	//newtile_y = newpos_y / cub2d->tile_size;
	if (check_all_collision(cub2d, (newpos_x + margin) / cub2d->tile_size,
		newpos_y / cub2d->tile_size))
		return (1);
	if (check_all_collision(cub2d, (newpos_x - margin) / cub2d->tile_size,
		newpos_y / cub2d->tile_size))
		return (1);
	if (check_all_collision(cub2d, newpos_x / cub2d->tile_size,
		(newpos_y + margin) / cub2d->tile_size))
		return (1);
	if (check_all_collision(cub2d, newpos_x / cub2d->tile_size,
		(newpos_y - margin) / cub2d->tile_size))
		return (1);
	if (check_all_collision(cub2d, newpos_x / cub2d->tile_size,
		newpos_y / cub2d->tile_size))
		return (1);
	return (0);
}

/*
int	has_collision(t_cub2d *cub2d, int mvmt)
{
	int	newpos_x;
	int	newpos_y;
	int collision_margin;
	// int	newtile_x;
	// int	newtile_y;

	collision_margin = 5;
	newpos_x = cub2d->player.circle.mid_x + mvmt * cub2d->player.dir_x;
	newpos_y = cub2d->player.circle.mid_y + mvmt * cub2d->player.dir_y;
	ft_print_matrice(cub2d->map.map);
	printf("has_collision1\n");
	if (check_collision(cub2d, newpos_x, newpos_y) == 1)
		return (1);
	// newtile_x = newpos_x / cub2d->tile_size;
	// newtile_y = newpos_y / cub2d->tile_size;
	// if (cub2d->map.map[newtile_y][newtile_x] == '1')
	// 	return (1);
	// if (has_clipping(cub2d, newtile_x, newtile_y))
	// 	return (1);
	newpos_x = cub2d->player.circle.mid_x + collision_margin + mvmt * cub2d->player.dir_x;
	newpos_y = cub2d->player.circle.mid_y + mvmt * cub2d->player.dir_y;
	// printf("has_collision2\n");
	if (check_collision(cub2d, newpos_x, newpos_y) == 1)
		return (1);
	newpos_x = cub2d->player.circle.mid_x + mvmt * cub2d->player.dir_x;
	newpos_y = cub2d->player.circle.mid_y + collision_margin + mvmt * cub2d->player.dir_y;
	// printf("has_collision3\n");
	if (check_collision(cub2d, newpos_x, newpos_y) == 1)
		return (1);
	newpos_x = cub2d->player.circle.mid_x - collision_margin + mvmt * cub2d->player.dir_x;
	newpos_y = cub2d->player.circle.mid_y + mvmt * cub2d->player.dir_y;
	// printf("has_collision4\n");
	if (check_collision(cub2d, newpos_x, newpos_y) == 1)
		return (1);
	newpos_x = cub2d->player.circle.mid_x + mvmt * cub2d->player.dir_x;
	newpos_y = cub2d->player.circle.mid_y - collision_margin + mvmt * cub2d->player.dir_y;
	// printf("has_collision4\n");
	if (check_collision(cub2d, newpos_x, newpos_y) == 1)
		return (1);
	return (0);
}
*/

int has_collision(t_cub2d *cub2d)
{
	double	newpos_x;
	double	newpos_y;

	newpos_x = cub2d->player.circle.mid_x + (cub2d->player.vel_u - cub2d->player.vel_d)
		* cub2d->player.dir_x;
	newpos_x += (cub2d->player.vel_r - cub2d->player.vel_l)
				* (1 * cos(deg_to_rad(cub2d->player.angle - 90)));
	newpos_y = cub2d->player.circle.mid_y + (cub2d->player.vel_u - cub2d->player.vel_d)
				* cub2d->player.dir_y;
	newpos_y += (cub2d->player.vel_r - cub2d->player.vel_l)
				* (-1 * sin(deg_to_rad(cub2d->player.angle - 90)));
	if (check_collision(cub2d, newpos_x, newpos_y) == 0)
		return (0);
	if (check_collision(cub2d, cub2d->player.circle.mid_x, newpos_y) == 0)
		return (1);
	if (check_collision(cub2d, newpos_x, cub2d->player.circle.mid_y) == 0)
		return (2);
	return (3);
}

void	player_mvmt(t_cub2d *cub2d)
{
    int move_possible;

    move_possible = has_collision(cub2d);
	if (move_possible % 2 == 0)
	{
		cub2d->player.circle.mid_x += (cub2d->player.vel_u - cub2d->player.vel_d)
			* cub2d->player.dir_x;
		cub2d->player.circle.mid_x += (cub2d->player.vel_r - cub2d->player.vel_l)
			* (1 * cos(deg_to_rad(cub2d->player.angle - 90)));
	}
	if (move_possible < 2)
	{
		cub2d->player.circle.mid_y += (cub2d->player.vel_u - cub2d->player.vel_d)
			* cub2d->player.dir_y;
		cub2d->player.circle.mid_y += (cub2d->player.vel_r - cub2d->player.vel_l)
			* (-1 * sin(deg_to_rad(cub2d->player.angle - 90)));
	}
	if (cub2d->player.rot_l == 1)
		cub2d->player.angle += 2;
	if (cub2d->player.rot_r == 1)
		cub2d->player.angle -= 2;
	if (cub2d->player.angle >= 360)
		cub2d->player.angle = 0;
	if (cub2d->player.angle < 0)
		cub2d->player.angle = 359;
}
