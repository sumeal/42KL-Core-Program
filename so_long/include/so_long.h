/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:20:31 by muzz              #+#    #+#             */
/*   Updated: 2025/02/09 10:34:29 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include <fcntl.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	*map_file;
	int		pixel_scale;
	int		width;
	int		height;
	int		res_x;
	int		res_y;
	char	**map;
	char	**visited;
	void	*play;
	void	*coll;
	void	*exit;
	void	*wall;
	void	*gras;
	void	*cros;
	int		qty_collect;
	int		qty_player;
	int		qty_exit;
	int		player_x;
	int		player_y;
	int		move;

}			t_data;

/*Error and free functions (error_free.c)*/
void	free_visited(t_data *data);
void	free_all(t_data *data);
void	print_error(char *str, t_data *data);
int		close_window(t_data *data);
void	check_pixel_scale(t_data *data);

/*Libft_sl functions (libft_sl.c)*/
int		ft_strnstr(const char *haystack, const char *needle);
char	*ft_strdup_sl(char *str);

/*Get map and data functions (get_map_data.c)*/
void	initialize_struct(t_data *data);
void	get_resolution(t_data *data);
void	get_data(t_data *data);

/*Check map(1) functions (check_map.c)*/
void	check_map(t_data *data);
int		is_valid(t_data *data);
int		check_valid(t_data *data);
int		is_rectangular(t_data *data);
int		is_closed(t_data *data);

/*Check map(2) functions (check_map2.c)*/
int		is_path_valid(t_data *data);
void	init_visited(t_data *data);
void	flood_fill(int x, int y, t_data *data);
int		is_valid_move(int x, int y, t_data *data);

/*Mechanism functions (mechanism.c)*/
int		handle_key(int keycode, t_data *data);
void	handle_key2(int new_x, int new_y, t_data *data);
void	handle_key3(int new_x, int new_y, t_data *data);

/*So_long functions (so_long.c)*/
void	load_texture(t_data *data);
void	render_map(int x, int y, t_data *data);
void	update_map(t_data *data, int new_x, int new_y);
void	update_map2(t_data *data, int new_x, int new_y);

#endif