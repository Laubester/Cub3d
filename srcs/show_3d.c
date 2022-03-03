/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 00:12:02 by laube             #+#    #+#             */
/*   Updated: 2022/03/03 13:41:40 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "graphics.h"
#include "raycasting.h"

void	show_3d(t_cub2d *cub2d)
{
	void	*img;

	put_background(&cub2d->mlx_inst, cub2d->screen);
	put_textures(cub2d);
	img = cub2d->mlx_inst.img;
	mlx_put_image_to_window(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win,
		img, 0, 0);
}
