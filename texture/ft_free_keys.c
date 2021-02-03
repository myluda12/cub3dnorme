/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 18:31:05 by ayajrhou          #+#    #+#             */
/*   Updated: 2021/02/03 18:31:06 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_free_l3alam1(void)
{
	int		g_j;

	g_j = 0;
	while (g_check[g_j])
	{
		free(g_check[g_j]);
		g_j++;
	}
	free(g_check);
}

void		ft_free_l3alam(char **g_tab)
{
	int		g_j;

	g_j = 0;
	while (g_tab[g_j])
	{
		free(g_tab[g_j]);
		g_j++;
	}
	free(g_tab);
}

int			mlx_key_press(int key)
{
	if (key == 123)
		g_left = 1;
	if (key == 124)
		g_right = 1;
	if (key == 125)
		g_down = 1;
	if (key == 126)
		g_up = 1;
	if (key == 0)
		g_a = 1;
	if (key == 2)
		g_d = 1;
	if (key == 53)
		exit(0);
	return (0);
}

int			key_release(int key)
{
	if (key == 123)
		g_left = 0;
	if (key == 124)
		g_right = 0;
	if (key == 125)
		g_down = 0;
	if (key == 126)
		g_up = 0;
	if (key == 0)
		g_a = 0;
	if (key == 2)
		g_d = 0;
	return (0);
}

int			ft_exit(void)
{
	mlx_destroy_window(g_mlx_ptr, g_win_ptr);
	exit(0);
}

void		ft_exit1(void)
{
	ft_putstr("weird character");
	exit(0);
}
