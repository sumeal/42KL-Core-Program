/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:11:59 by muzz              #+#    #+#             */
/*   Updated: 2025/02/09 10:34:14 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_visited(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		free(data->visited[i]);
		i++;
	}
	free(data->visited);
}

void	free_all(t_data *data)
{
	int	i;

	i = -1;
	while (data->map[++i])
		free(data->map[i]);
	free(data->map);
	if (data->visited)
		free_visited(data);
	if (data->wall)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->play)
		mlx_destroy_image(data->mlx, data->play);
	if (data->coll)
		mlx_destroy_image(data->mlx, data->coll);
	if (data->exit)
		mlx_destroy_image(data->mlx, data->exit);
	if (data->gras)
		mlx_destroy_image(data->mlx, data->gras);
	if (data->cros)
		mlx_destroy_image(data->mlx, data->cros);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
}

void	print_error(char *str, t_data *data)
{
	ft_printf("%s", str);
	if (data)
		free_all(data);
	exit(1);
}

int	close_window(t_data *data)
{
	free_all(data);
	ft_printf("Exiting...\n");
	exit(0);
}

void	check_pixel_scale(t_data *data)
{
	if ((data->pixel_scale) * (data->width) > 1920
		|| (data->pixel_scale) * (data->height) > 1080)
		print_error("Error\nMap Too Big\n", data);
}
