/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 18:35:34 by ayajrhou          #+#    #+#             */
/*   Updated: 2021/02/03 18:35:35 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_check_arg(char **argv, int argc)
{
	int		len;

	len = ft_strlen(argv[1]);
	len = len - 4;
	g_mapo = &argv[1][len];
	if (argc == 2)
		g_chorfi = ft_strdup("");
	else
		g_chorfi = argv[2];
	if (strcmp(g_mapo, ".cub") != 0)
	{
		ft_putstr("error in .cub");
		exit(0);
	}
}

void		ft_calcul_lenght(void)
{
	char	*str;

	g_indexo = 0;
	while (get_next_line(g_fd, &str))
	{
		free(str);
		g_indexo++;
	}
	free(str);
}

void		ft_variable_init_calcul_lengh(char **argv)
{
	g_x = g_wall;
	g_y = g_wall;
	direction_global();
	g_mlx_ptr = mlx_init();
	g_fd = open(argv[1], O_RDONLY, O_RDWR);
	inde = 0;
	if (g_fd == -1)
	{
		ft_putstr("error in file descriptor");
		exit(0);
	}
	ft_calcul_lenght();
}

void		ft_map_traitement(char **argv)
{
	int fd;

	g_line = malloc(sizeof(char *) * (g_indexo));
	close(g_fd);
	fd = open(argv[1], O_RDONLY, O_RDWR);
	if (fd == -1)
	{
		ft_putstr("error g_mapo");
		exit(0);
	}
	if (!fd_tab(fd))
	{
		ft_putstr("Error in g_map fd");
		exit(0);
	}
	ft_check_zero();
}

void		ft_graphic_variable(int argc)
{
	if (strcmp(g_chorfi, "--save") != 0 && argc == 3)
	{
		ft_putstr("error in parameter");
		exit(0);
	}
	if (strcmp(g_chorfi, "--save") != 0)
		g_win_ptr = mlx_new_window(g_mlx_ptr, g_width, g_height, "mlx 42");
	g_image = mlx_new_image(g_mlx_ptr, g_width, g_height);
	g_data = (int *)mlx_get_data_addr(g_image, &g_b, &g_a, &g_c);
	ft_morba3();
	if (g_N > 1 || g_N == 0)
	{
		ft_putstr("error multi or miss player\n");
		exit(0);
	}
}
