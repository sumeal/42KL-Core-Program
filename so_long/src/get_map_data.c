/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:18:40 by muzz              #+#    #+#             */
/*   Updated: 2025/02/09 09:17:19 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_data(t_data *data)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	initialize_struct(data);
	get_resolution(data);
	fd = open(data->map_file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nPermission denied\n");
		exit(1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		data->map[i++] = ft_strdup_sl(line);
		if (!data->map[i - 1])
			print_error("Malloc failed\n", data);
		free(line);
	}
	data->map[i] = NULL;
	close(fd);
}

void	initialize_struct(t_data *data)
{
	data->pixel_scale = 50;
	data->height = 0;
	data->width = 0;
	data->move = -1;
	data->qty_player = 0;
	data->qty_collect = 0;
	data->qty_exit = 0;
}

void	get_resolution(t_data *data)
{
	int		fd;
	char	*line;

	fd = open(data->map_file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nPermission denied\n");
		exit(1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		data->width = (int)ft_strlen(line);
		free(line);
		data->height++;
	}
	close(fd);
	data->map = malloc(sizeof(char *) * ((data->height) + 1));
	if (!data->map)
		print_error("Malloc failed\n", data);
	data->res_x = data->width * data->pixel_scale;
	data->res_y = data->height * data->pixel_scale;
}
