/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_traitement2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:32:52 by ayajrhou          #+#    #+#             */
/*   Updated: 2021/02/03 18:19:29 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_check_ea(void)
{
	g_direction.ea++;
	if (counter != 2)
	{
		ft_putstr("missing parameter");
		exit(0);
	}
	g_f = check_valid(g_check[1]);
	if (g_f == 1)
		g_textu4 = ft_texture(g_check[1], g_textu4);
	if (g_f == 0)
	{
		ft_putstr("invalidmap\n");
		exit(0);
	}
	g_calcul_parameter++;
}

void		ft_check_s(void)
{
	g_direction.s++;
	if (counter != 2)
	{
		ft_putstr("missing parameter");
		exit(0);
	}
	g_f = check_valid(g_check[1]);
	if (g_f == 1)
		g_textu0 = ft_texture(g_check[1], g_textu0);
	if (g_f == 0)
	{
		ft_putstr("invalidmap\n");
		exit(0);
	}
	g_calcul_parameter++;
}

void		ft_check_c1(void)
{
	if (counter != 3 || ft_atoi(g_check[0]) > 255 || ft_atoi(g_check[0]) < 0
		|| ft_atoi(g_check[1]) > 255 || ft_atoi(g_check[1]) < 0
		|| ft_atoi(g_check[2]) > 255 || ft_atoi(g_check[2]) < 0)
	{
		ft_putstr("INVALID g_map\n");
		exit(0);
	}
}

void		ft_check_f1(void)
{
	if (counter != 3 || ft_atoi(g_check[0]) > 255 || ft_atoi(g_check[0]) < 0
	|| ft_atoi(g_check[1]) > 255 || ft_atoi(g_check[1]) < 0
	|| ft_atoi(g_check[2]) > 255 || ft_atoi(g_check[2]) < 0)
	{
		ft_putstr("INVALID g_map\n");
		exit(0);
	}
}

void		ft_check_c(void)
{
	char	*tmp;

	g_direction.c++;
	if (counter != 2)
	{
		ft_putstr("missing parameter");
		exit(0);
	}
	ft_check_weird();
	ft_check_virg();
	tmp = ft_strdup(g_check[1]);
	free(g_check[0]);
	free(g_check[1]);
	free(g_check);
	if (g_split != 2)
	{
		ft_putstr("error in parameter");
		exit(0);
	}
	g_check = ft_split(tmp, ',');
	free(tmp);
	ft_check_c1();
	g_color_c = convert_rgb(ft_atoi(g_check[0]),
	ft_atoi(g_check[1]), ft_atoi(g_check[2]));
	g_calcul_parameter++;
}

void		ft_check_f(void)
{
	char	*tmp;

	g_direction.f++;
	ft_check_weird();
	if (counter != 2)
	{
		ft_putstr("missing parameter");
		exit(0);
	}
	ft_check_virg();
	if (g_split != 2)
	{
		ft_putstr("error in parameter");
		exit(0);
	}
	tmp = ft_strdup(g_check[1]);
	free(g_check[0]);
	free(g_check[1]);
	free(g_check);
	g_check = ft_split(tmp, ',');
	free(tmp);
	ft_check_f1();
	g_color_f = convert_rgb(ft_atoi(g_check[0]),
		ft_atoi(g_check[1]), ft_atoi(g_check[2]));
	g_calcul_parameter++;
}

void		ft_check_resolution(void)
{
	if (g_width > 2560 || g_height > 1440)
	{
		if (g_width > 2560)
			g_width = 2560;
		else
			g_height = 1440;
	}
}
