/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_design_2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:09:12 by ayajrhou          #+#    #+#             */
/*   Updated: 2021/02/03 17:09:14 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_design_morba3_2(int g_j, int i, int y_copy)
{
	if ((g_line[g_j][i] == 'N' || g_line[g_j][i] == 'E'
		|| g_line[g_j][i] == 'W' || g_line[g_j][i] == 'S') && g_none == 1)
	{
		g_X_player = i * 50 + 25;
		g_Y_player = g_j * 50 + 25;
		g_none++;
	}
	g_y = y_copy;
	g_x = g_x + g_wall;
}

int			design_morba3(int i, unsigned int color, int g_j)
{
	int save;
	int y_copy;

	y_copy = g_y;
	save = g_k;
	while (g_k < g_x)
	{
		g_k++;
		if (g_k == g_x)
		{
			g_k = save;
			g_y = g_y - 1;
			if (g_y == g_remaind - g_wall - 1)
			{
				g_k += g_wall;
				break ;
			}
		}
	}
	ft_design_morba3_2(g_j, i, y_copy);
	return (g_k);
}

void		ft_morba3_2(int color, int i, int g_j)
{
	color = 0xFFFFFF;
	design_morba3(i, color, g_j);
	if (g_line[g_j][i] == 'N' || g_line[g_j][i] == 'E'
	|| g_line[g_j][i] == 'W' || g_line[g_j][i] == 'S')
	{
		g_N++;
		ft_directions(g_j, i);
	}
}

void		ft_morba3_3(int color, int i, int g_j)
{
	if (g_line[g_j][i] == '1' || g_line[g_j][i] == ' ')
	{
		color = 0x6f665d;
		design_morba3(i, color, g_j);
	}
	else if (g_line[g_j][i] == '0'
		|| g_line[g_j][i] == 'N' || g_line[g_j][i] == 'E'
		|| g_line[g_j][i] == 'W' || g_line[g_j][i] == 'S')
		ft_morba3_2(color, i, g_j);
	else if (g_line[g_j][i] == '2')
	{
		color = 0xdcd3f6;
		design_morba3(i, color, g_j);
		g_sprite_number++;
	}
}

void		ft_morba3(void)
{
	int				i;
	unsigned int	color;

	i = 0;
	g_j = 0;
	while (g_j < inde && g_line[g_j][i])
	{
		ft_morba3_3(color, i, g_j);
		i++;
		if (g_line[g_j][i] == '\0')
		{
			i = 0;
			if (g_j < inde)
			{
				g_j++;
				g_y = g_y + g_wall;
				g_x = g_wall;
				g_remaind = g_remaind + g_wall;
				g_k = 0;
			}
			else
				break ;
		}
	}
}
