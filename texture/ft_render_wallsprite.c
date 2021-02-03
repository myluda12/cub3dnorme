/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_wallsprite.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 19:24:08 by ayajrhou          #+#    #+#             */
/*   Updated: 2021/02/03 19:24:10 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_collect_info_sprite(void)
{
	double	diss;

	g_angle_sghira = atan2(g_Y_player - g_sprites[g_count].ycentre,
		g_X_player - g_sprites[g_count].xcentre);
	g_angle_wanted = g_sprites[g_count].g_rotation - g_angle_sghira;
	g_point_x = g_X_player + (g_sprites[g_count].xcentre - g_X_player) *
		cos(g_angle_wanted) - (g_sprites[g_count].ycentre -
		g_Y_player) * sin(g_angle_wanted);
	g_point_y = g_Y_player + (g_sprites[g_count].xcentre - g_X_player) *
		sin(g_angle_wanted) + (g_sprites[g_count].ycentre -
		g_Y_player) * cos(g_angle_wanted);
	g_angle_jdida = M_PI / 2 + g_angle_sghira;
	g_point_distance_x = g_sprites[g_count].xcentre +
		(50 / 2) * cos(g_angle_jdida);
	g_point_distance_y = g_sprites[g_count].ycentre +
		(50 / 2) * sin(g_angle_jdida);
	g_sprites[g_count].xoff = sqrtf(powf(g_point_distance_y - g_point_y, 2) +
		powf(g_point_distance_x - g_point_x, 2));
	diss = sqrtf(powf(g_point_x - g_sprites[g_count].xcentre, 2) +
		powf(g_point_y - g_sprites[g_count].ycentre, 2));
	if (diss > 25)
		g_sprites[g_count].xoff = 0;
	g_correctWallDistance = sqrtf(powf((g_Y_player -
		g_sprites[g_count].ycentre), 2) + powf((g_X_player -
		g_sprites[g_count].xcentre), 2));
}

void		render_sprite(int i)
{
	if (g_sprite_indicator == 1)
	{
		g_count = g_sprite_count - 1;
		while (g_count >= 0)
		{
			ft_collect_info_sprite();
			g_distanceProjectionPlan = (g_width / 2) / tan(rad(45) / 2);
			g_wallStripHeight = (50 / g_correctWallDistance) *
				g_distanceProjectionPlan;
			ft_nizar_calcul();
			if (swiitch == 1)
			{
				if (g_sprites[g_count].g_distance < g_distance)
					render_column1(i, g_count);
			}
			g_count--;
		}
	}
}

void		ft_info_render(int i)
{
	if (g_rotation > 2 * M_PI || g_rotation < 0)
		g_rotation = ft_normalize_angle(g_rotation);
	ft_cast_ray();
	g_rotation += g_rot;
	render_map3d(i);
	sorting();
	if (g_sprite_indicator == 1)
	{
		if (g_sprites[0].g_distance < g_distance)
			render_sprite(i);
		g_sprite_count = 0;
	}
}

int			deal_key(void)
{
	int		i;

	g_x = g_wall;
	g_y = g_wall;
	g_k = 0;
	i = 0;
	g_rotation = g_rotationAngle - M_PI / 8;
	g_sprite_count = 0;
	if (g_rotationAngle > 2 * M_PI || g_rotationAngle < 0)
		g_rotationAngle = ft_normalize_angle(g_rotationAngle);
	while (i < g_width)
	{
		ft_info_render(i);
		i++;
	}
	ft_all_mouvement();
	return (0);
}

void		render_map3d(int i)
{
	g_correctWallDistance = g_distance * cos(g_rotation - g_rotationAngle);
	g_distanceProjectionPlan = (g_width / 2) / tan(rad(45) / 2);
	g_wallStripHeight = (50 / g_correctWallDistance) * g_distanceProjectionPlan;
	g_xOfsset = g_mhah == 1 ? fmod(g_WallHitX, 50) : fmod(g_WallHitY, 50);
	ft_nizar_calcul();
	if (swiitch == 1)
		render_colomn(i);
}
