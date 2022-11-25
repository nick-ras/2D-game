/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:20:11 by nick              #+#    #+#             */
/*   Updated: 2022/11/25 13:45:59 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	no_event(void *data)
{
	(void) data;
	return (EXIT_SUCCESS);
}

void	result(t_map *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->winner_pic,
		data->columns * 40 / 2.4, data->rows * 40 / 4);
}

int	free_map(t_map *grid, int exit_func)
{
	int	i;

	i = 0;
	while (i < grid->rows)
	{
		if (grid->map[i] != NULL)
			free(grid->map[i]);
		if (grid->map[i] != NULL)
			free(grid->map2[i]);
		i++;
	}
	free(grid->map);
	free(grid->map2);
	if (grid->mlx_ptr)
		free(grid->mlx_ptr);
	if (grid->win_ptr)
		free(grid->win_ptr);
	free(grid);
	if (exit_func)
	{
		ft_printf("exits program with error\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

void	check_ptr(t_map *map, void *ptr)
{
	if (ptr == NULL)
	{
		free(ptr);
		ft_printf("grid->win_ptr error\n");
		free_map(map, 1);
	}
}
