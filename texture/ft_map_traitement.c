/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_traitement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 18:41:18 by ayajrhou          #+#    #+#             */
/*   Updated: 2021/02/03 18:41:19 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_switch_space(void)
{
	int		i;
	int		f;
	int		variable;
	char	*tmp;
	char	*str;

	i = 0;
	f = 0;
	variable = ft_strlen(g_map[g_y_len]);
	i = g_mapcount[0].lenghtx - variable;
	str = malloc(sizeof(char) * i + 1);
	f = 0;
	while (i > f)
	{
		str[f] = ' ';
		f++;
	}
	str[f] = '\0';
	tmp = ft_strdup(g_map[g_y_len]);
	free(g_map[g_y_len]);
	g_map[g_y_len] = ft_strjoin(tmp, str);
	free(tmp);
	free(str);
}

void		bubblesort(int inde)
{
	int		i;
	int		g_j;
	int		temp;

	g_j = 0;
	i = 0;
	while (i < (inde - 1))
	{
		while (g_j < inde - 1 - i)
		{
			if (g_mapcount[g_j].lenghtx < g_mapcount[g_j + 1].lenghtx)
			{
				temp = g_mapcount[g_j + 1].lenghtx;
				g_mapcount[g_j + 1].lenghtx = g_mapcount[g_j].lenghtx;
				g_mapcount[g_j].lenghtx = temp;
			}
			g_j++;
		}
		i++;
	}
}

void		fd_tab2(void)
{
	int			c;

	c = ft_valid_map();
	if (c == 1)
		g_line[inde] = ft_strdup(g_map[g_y_len]);
	else
	{
		ft_putstr("error in g_map");
		exit(0);
	}
}

void		ft_check_virg(void)
{
	int		i;

	i = 0;
	while (g_check[1][i])
	{
		if (g_check[1][i] == ',')
			g_split++;
		i++;
	}
}

void		ft_check_errormap1(void)
{
	if (g_dontenteragain == 10 && g_mapcount[g_t - 1].mapx == 0)
	{
		ft_putstr("invalid mapox");
		exit(0);
	}
}

void		ft_check_errormap(int p)
{
	if (strchr("1 0", g_map[g_y_len][0]) && g_mapcount[g_t].mapx > 0)
	{
		ft_return();
		ft_switch_space();
		ft_check_errormap1();
		if (g_dontenteragain == 0)
		{
			g_k = ft_first_line();
			if (g_k == 0)
			{
				ft_putstr("invalid mape");
				exit(0);
			}
			else if (g_k == 1)
			{
				g_line[inde] = ft_strdup(g_map[g_y_len]);
				g_dontenteragain = 10;
			}
		}
		else
			fd_tab2();
		g_mapcount[p].linex = ft_strlen(g_line[inde]);
		inde++;
		p++;
	}
}
