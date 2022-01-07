/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:54:22 by laube             #+#    #+#             */
/*   Updated: 2022/01/05 17:09:53 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#ifdef _LINUX
#include "key_codes_linux.h"
#else
#include "key_codes_mac.h"
#endif

// x and y represent the center of the circle
typedef struct	s_circle
{
    double	mid_x;
    double	mid_y;
    int radius;
    int color;
}	t_circle;

typedef struct s_player
{
	t_circle circle;
        char    orien;
        //Tile position
        int tile_x;
        int tile_y;
        //Direction vector
        int angle;
        double dir_x;
        double dir_y;
        //Camera plane vectors
        int r_plane_x;
        int r_plane_y;
        int l_plane_x;
        int l_plane_y;
} t_player;

typedef struct s_mlx
{
    void *mlx;
    void *win;
    void *img;
    char *addr;
    int bits_per_pixel;
    int	line_len;
    int	endian;
}	t_mlx;

typedef struct s_raycast
{
    int side;
    double  dist_x;
    double  dist_y;
    double  len;
    double  delta_x;
    double  delta_y;
    int step_x;
    int step_y;
    int map_x;
    int map_y;
}   t_raycast;

typedef struct s_cub2d
{
    t_mlx   mlx_inst;
    t_player    player;
    t_raycast   raycast;
} t_cub2d;

// These are the attributes that I need for the 2d part
typedef struct s_map_placeholder
{
    char **map;
    int map_width;
    int map_height;
    char    orientation;
} t_map_placeholder;

typedef struct s_game
{
    t_player player;
} t_game;

typedef struct s_line
{
    int	x1;
    int	y1;
    int	x2;
    int	y2;
    int	color;
} t_line;

// x and y represent the top-left corner of the rect
typedef struct s_rect
{
    int	x;
    int	y;
    int	width;
    int	heigth;
    int	color;
}	t_rect;

void    handle_2d(void);

#endif