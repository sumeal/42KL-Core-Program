/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:37:58 by muzz              #+#    #+#             */
/*   Updated: 2025/02/08 13:42:55 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_path_valid(t_data *data)
{
	int	i;
	int	j;

	init_visited(data);
	flood_fill(data->player_x, data->player_y, data);
	i = -1;
	while (++i < data->height)
	{
		j = -1;
		while (++j < data->width)
			if (data->map[i][j] == 'C' && !data->visited[i][j])
				return (0);
	}
	i = -1;
	while (++i < data->height)
	{
		j = -1;
		while (++j < data->width)
			if (data->map[i][j] == 'E' && !data->visited[i][j])
				return (0);
	}
	return (1);
}

void	init_visited(t_data *data)
{
	int	i;
	int	j;

	data->visited = malloc(sizeof(char *) * data->height);
	if (!data->visited)
		print_error("Malloc failed\n", data);
	i = -1;
	while (++i < data->height)
	{
		data->visited[i] = malloc(sizeof(char) * data->width);
		if (!data->visited[i])
			print_error("Malloc failed\n", data);
		j = -1;
		while (++j < data->width)
			data->visited[i][j] = 0;
	}
}

void	flood_fill(int x, int y, t_data *data)
{
	if (!is_valid_move(x, y, data))
		return ;
	data->visited[y][x] = 1;
	flood_fill(x + 1, y, data);
	flood_fill(x - 1, y, data);
	flood_fill(x, y + 1, data);
	flood_fill(x, y - 1, data);
}

int	is_valid_move(int x, int y, t_data *data)
{
	if (x < 0 || y < 0 || x >= data->width || y >= data->height)
		return (0);
	if (data->map[y][x] == '1' || data->visited[y][x] == 1)
		return (0);
	return (1);
}
