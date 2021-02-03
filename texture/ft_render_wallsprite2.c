/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_wallsprite2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 19:42:35 by ayajrhou          #+#    #+#             */
/*   Updated: 2021/02/03 19:42:36 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_render_map(int i)
{
	g_rotation = g_rotationAngle - M_PI / 8;
	g_rot = rad(45) / g_width;
	g_sprite_count = 0;
	while (i < g_width)
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
		i++;
	}
}

void		render_colomn(int i)
{
	int		start;
	int		g_j;

	g_j = 0;
	start = (g_height / 2) - (g_wallStripHeight / 2);
	while (g_j < start)
	{
		g_data[g_width * g_j + i] = g_color_c;
		g_j++;
	}
	while (g_j < start + g_wallStripHeight && g_j < g_height)
	{
		ft_render_walls(g_j, i, start);
		g_j++;
	}
	while (g_j < g_height)
	{
		g_data[g_width * g_j + i] = g_color_f;
		g_j++;
	}
}

void		ft_render_walls(int g_j, int i, int start)
{
	g_pourcent = (g_j - start) / g_wallStripHeight;
	g_yOffset = 50 * g_pourcent;
	if (g_rightleftupdown == 1)
	{
		g_data[g_width * g_j + i] =
			check_opacity(g_textu4[(int)g_yOffset * 50 + (int)g_xOfsset]);
	}
	else if (g_rightleftupdown == 2)
		g_data[g_width * g_j + i] =
			check_opacity(g_textu1[(int)g_yOffset * 50 + (int)g_xOfsset]);
	else if (g_rightleftupdown == 3)
		g_data[g_width * g_j + i] =
			check_opacity(g_textu2[(int)g_yOffset * 50 + (int)g_xOfsset]);
	else if (g_rightleftupdown == 4)
		g_data[g_width * g_j + i] =
			check_opacity(g_textu3[(int)g_yOffset * 50 + (int)g_xOfsset]);
}

void		render_column1(int i, int g_count)
{
	int		start;
	int		g_j;

	g_j = 0;
	start = (g_height / 2) - (g_wallStripHeight / 2);
	while (g_j < start)
	{
		g_data[g_width * g_j + i] = g_color_c;
		g_j++;
	}
	while (g_j < start + g_wallStripHeight && g_j < g_height)
	{
		ft_render_sprite(g_j, i, start);
		g_j++;
	}
	while (g_j < g_height)
	{
		g_data[g_width * g_j + i] = g_color_f;
		g_j++;
	}
}

void		ft_render_sprite(int g_j, int i, int start)
{
	g_pourcent = (g_j - start) / g_wallStripHeight;
	g_yOffset = 50 * g_pourcent;
	if (check_opacity(g_textu0[(int)g_yOffset * 50 +
		(int)g_sprites[g_count].xoff]) != 0x000000)
		g_data[g_width * g_j + i] = check_opacity(g_textu0[(int)g_yOffset *
			50 + (int)g_sprites[g_count].xoff]);
}
