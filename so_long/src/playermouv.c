/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playermouv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers42 <ctravers@student.42perpignan.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:58:28 by ctravers42        #+#    #+#             */
/*   Updated: 2025/02/26 13:18:59 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	can_move(t_data *data, int new_y, int new_x)
{
	char	pos;

	if (new_y < 0 || new_y >= data->map.height)
		return (0);
	if (new_x < 0 || new_x >= data->map.width)
		return (0);
	pos = data->map.grid[new_y][new_x];
	if (pos == '1')
		return (0);
	return (1);
}

int	key_press(int keysym, t_data *data)
{
	int	new_y;
	int	new_x;

	new_y = data->pos.y;
	new_x = data->pos.x;
	if (keysym == XK_Escape)
		close_win(data);
	else if (keysym == XK_w)
		new_y--;
	else if (keysym == XK_s)
		new_y++;
	else if (keysym == XK_a)
		new_x--;
	else if (keysym == XK_d)
		new_x++;
	if (can_move(data, new_y, new_x) && (keysym == XK_w
			|| keysym == XK_d || keysym == XK_a || keysym == XK_s))
		update_position(data, new_y, new_x);
	return (0);
}

void	update_position(t_data *data, int new_y, int new_x)
{
	char	current;

	current = data->map.grid[new_y][new_x];
	if (current == 'E' && !has_collectibles(data))
	{
		ft_printf("You won !!\n");
		close_win(data);
	}
	data->step_count++;
	ft_printf("Steps: %d\n", data->step_count);
	data->map.grid[data->pos.y][data->pos.x] = data->previous;
	if (current == 'C')
		data->previous = '0';
	if (current == 'E')
		data->previous = 'E';
	else if (current != 'C')
		data->previous = data->map.grid[new_y][new_x];
	data->map.grid[new_y][new_x] = 'P';
	data->pos.y = new_y;
	data->pos.x = new_x;
	render_map(data);
}

int	close_cross(t_data *data)
{
	close_win(data);
	return (0);
}
