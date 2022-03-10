/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 21:49:30 by laube             #+#    #+#             */
/*   Updated: 2022/03/10 10:47:36 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycasting.h"

int	key_press(int keycode, t_cub2d *cub2d)
{
	if (keycode == MAIN_ESC)
	{
		free_map(cub2d->map_ptr);
		destroy_mlx(cub2d);
		exit(0);
	}
	else if (keycode == MAIN_W)
		cub2d->player.vel_u = 1;
	else if (keycode == MAIN_S)
		cub2d->player.vel_d = 1;
	else if (keycode == MAIN_A)
		cub2d->player.vel_l = 1;
	else if (keycode == MAIN_D)
		cub2d->player.vel_r = 1;
	else if (keycode == ARROW_LEFT)
		cub2d->player.rot_l = 1;
	else if (keycode == ARROW_RIGHT)
		cub2d->player.rot_r = 1;
	/*
	else if (keycode == MAIN_W || keycode == MAIN_A
		|| keycode == MAIN_S || keycode == MAIN_D
		|| keycode == ARROW_LEFT || keycode == ARROW_RIGHT)
	{
		player_mvmt(keycode, cub2d);
		update_vectors(cub2d, &cub2d->player);
	}
	game_loop(cub2d);
	*/
	return (0);
}

int	key_release(int keycode, t_cub2d *cub2d)
{
	if (keycode == MAIN_W)
		cub2d->player.vel_u = 0;
	if (keycode == MAIN_S)
		cub2d->player.vel_d = 0;
	if (keycode == MAIN_A)
		cub2d->player.vel_l = 0;
	if (keycode == MAIN_D)
		cub2d->player.vel_r = 0;
	if (keycode == ARROW_LEFT)
		cub2d->player.rot_l = 0;
	if (keycode == ARROW_RIGHT)
		cub2d->player.rot_r = 0;
	return (0);
}

int	click_close(void *param)
{
	t_cub2d	*cub2d;

	cub2d = param;
	free_map(cub2d->map_ptr);
	destroy_mlx(cub2d);
	exit(0);
}

int	mouse_mvmt(int x, int y, t_cub2d *cub2d)
{
	cub2d->mouse_x = x;
	cub2d->mouse_y = y;
	return (0);
}

int	main_loop(t_cub2d *cub2d)
{
	(void)cub2d;

	player_mvmt(cub2d);
	update_vectors(cub2d, &cub2d->player);
	game_loop(cub2d);
	return (0);
}

int	hook_handler(t_cub2d *cub2d)
{
	mlx_hook(cub2d->mlx_inst.win, 6, 1L << 6, mouse_mvmt, cub2d);
	mlx_hook(cub2d->mlx_inst.win, 2, 1L << 0, key_press, cub2d);
	mlx_hook(cub2d->mlx_inst.win, 3, 1L << 1, key_release, cub2d);
	mlx_hook(cub2d->mlx_inst.win, 17, 0, click_close, cub2d);
	mlx_loop_hook(cub2d->mlx_inst.mlx, main_loop, cub2d);
	return (0);
}
