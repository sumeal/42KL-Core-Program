/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:21:23 by muzz              #+#    #+#             */
/*   Updated: 2025/02/09 10:59:57 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map(t_data *data)
{
	if (data->height < 3 || data->width < 3)
		print_error("Error\nToo Small Map\n", data);
	if (!is_valid(data))
		print_error("Error\nNot Valid Map\n", data);
	if (!is_rectangular(data))
		print_error("Error\nNo Rectangular\n", data);
	if (!is_closed(data))
		print_error("Error\nNot Closed Map", data);
	if (!is_path_valid(data))
		print_error("Error\nNo Path\n", data);
}

int	is_valid(t_data *data)
{
	int		i;
	int		j;
	char	**map;

	map = data->map;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0'
				&& map[i][j] != 'P' && map[i][j] != 'C' && map[i][j] != 'E')
				return (0);
			j++;
		}
		i++;
	}
	if (!check_valid(data))
		return (0);
	return (1);
}

int	check_valid(t_data *data)
{
	int		i;
	int		j;

	i = -1;
	while ((data->map)[++i])
	{
		j = -1;
		while ((data->map)[i][++j])
		{
			if ((data->map)[i][j] == 'P')
			{
				(data->qty_player)++;
				data->player_x = j;
				data->player_y = i;
			}
			if ((data->map)[i][j] == 'C')
				(data->qty_collect)++;
			if ((data->map)[i][j] == 'E')
				(data->qty_exit)++;
		}
	}
	if (data->qty_player != 1
		|| data->qty_collect < 1 || data->qty_exit != 1)
		return (0);
	return (1);
}

int	is_rectangular(t_data *data)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(data->map[0]);
	while (data->map[++i])
	{
		if (ft_strlen(data->map[i]) != len)
			return (0);
	}
	return (1);
}

int	is_closed(t_data *data)
{
	int		i;
	int		j;
	char	**map;

	map = data->map;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0 || i == data->height - 1
				|| j == 0 || j == data->width - 1)
			{
				if (map[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
