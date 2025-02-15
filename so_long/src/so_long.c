/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:20:15 by muzz              #+#    #+#             */
/*   Updated: 2025/02/09 11:13:12 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_texture(t_data *data)
{
	int	wi;
	int	he;

	wi = 50;
	he = 50;
	data->wall = mlx_xpm_file_to_image(data->mlx, "textures/wa.xpm", &wi, &he);
	data->play = mlx_xpm_file_to_image(data->mlx, "textures/pl.xpm", &wi, &he);
	data->coll = mlx_xpm_file_to_image(data->mlx, "textures/co.xpm", &wi, &he);
	data->exit = mlx_xpm_file_to_image(data->mlx, "textures/ex.xpm", &wi, &he);
	data->gras = mlx_xpm_file_to_image(data->mlx, "textures/gr.xpm", &wi, &he);
	data->cros = mlx_xpm_file_to_image(data->mlx, "textures/cr.xpm", &wi, &he);
	if (!data->wall || !data->play || !data->coll
		|| !data->exit || !data->gras || !data->cros)
		print_error("Error\nNo Texture\n", data);
}

void	render_map(int x, int y, t_data *data)
{
	int		s;
	void	*mlx;
	void	*win;

	mlx = data->mlx;
	win = data->win;
	check_pixel_scale(data);
	s = data->pixel_scale;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (data->map[y][x] == '1')
				mlx_put_image_to_window(mlx, win, data->wall, x * s, y * s);
			else if (data->map[y][x] == 'P')
				mlx_put_image_to_window(mlx, win, data->play, x * s, y * s);
			else if (data->map[y][x] == 'C')
				mlx_put_image_to_window(mlx, win, data->coll, x * s, y * s);
			else if (data->map[y][x] == 'E')
				mlx_put_image_to_window(mlx, win, data->exit, x * s, y * s);
			else if (data->map[y][x] == '0')
				mlx_put_image_to_window(mlx, win, data->gras, x * s, y * s);
		}
	}
}

void	update_map(t_data *data, int new_x, int new_y)
{
	int		s;
	void	*mlx;
	void	*win;
	int		old_y;
	int		old_x;

	old_y = data->player_y;
	old_x = data->player_x;
	mlx = data->mlx;
	win = data->win;
	s = data->pixel_scale;
	if (data->map[new_y][new_x] == 'E')
	{
		mlx_put_image_to_window(mlx, win, data->cros, new_x * s, new_y * s);
		mlx_put_image_to_window(mlx, win, data->gras, old_x * s, old_y * s);
	}
	else if (data->map[old_y][old_x] == 'E')
	{
		mlx_put_image_to_window(mlx, win, data->exit, old_x * s, old_y * s);
		mlx_put_image_to_window(mlx, win, data->play, new_x * s, new_y * s);
	}
	else
		update_map2(data, new_x, new_y);
}

void	update_map2(t_data *data, int new_x, int new_y)
{
	int		s;
	void	*mlx;
	void	*win;
	int		old_y;
	int		old_x;

	old_y = data->player_y;
	old_x = data->player_x;
	mlx = data->mlx;
	win = data->win;
	s = data->pixel_scale;
	mlx_put_image_to_window(mlx, win, data->gras, old_x * s, old_y * s);
	mlx_put_image_to_window(mlx, win, data->play, new_x * s, new_y * s);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data = (t_data){0};
	if (argc != 2)
	{
		ft_printf("Error\nWrong number of arguments\n");
		exit(1);
	}
	data.map_file = argv[1];
	if (!ft_strnstr(data.map_file, ".ber"))
		print_error("Error\nBad extension\n", NULL);
	if (argv[1][5] == '.')
		print_error("Error\nBad extension\n", NULL);
	get_data(&data);
	check_map(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.res_x, data.res_y, "So_Long");
	load_texture(&data);
	render_map(-1, -1, &data);
	mlx_key_hook(data.win, handle_key, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
}
