/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:47:15 by pbeheyt           #+#    #+#             */
/*   Updated: 2023/01/28 05:39:04 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	keyboard_input(int keycode, t_image *image)
{
	if (keycode == 65307)
		exit_clean(image);
	// if (keycode == 'W' || keycode == 'w')
	// if (keycode == 'S' || keycode == 's')
	// if (keycode == 'A' || keycode == 'a')
	// if (keycode == 'D' || keycode == 'd')
	return (0);
}

t_texture	*file_to_image(t_image *image, char *path)
{
	t_texture	*txt;
	
	if (!path)
		return (exit_clean(image), NULL);
	txt = malloc(sizeof(t_texture));
	if (!txt)
		return (exit_clean(image), NULL);
	ft_memset(txt, 0, sizeof(t_texture));
	txt->path = path;
	txt->content = mlx_xpm_file_to_image(image->mlx, txt->path,
				&txt->size.width, &txt->size.height);
	if (!txt->content)
			return (free(txt), exit_clean(image), NULL);
	return (txt);
}

void	init_image(t_image *image, t_game *game)
{
	ft_memset(image, 0, sizeof(t_image));
	image->mlx = mlx_init();
	if (!image->mlx)
		exit_clean(image);
	image->game = game;
	image->size.height = 720;
	image->size.width = 1480;
	image->north = file_to_image(image, game->north);
	image->south = file_to_image(image, game->south);
	image->west = file_to_image(image, game->west);
	image->east = file_to_image(image, game->east);
}

int	init_mlx(t_image *image, t_game *game)
{
	init_image(image, game);
	image->win = mlx_new_window(image->mlx, image->size.width,
			image->size.height, "CUBE3D");
	mlx_key_hook(image->win, keyboard_input, image);
	mlx_loop_hook(image->mlx, &display, image);
	mlx_hook(image->win, 17, 0, exit_clean, image);
	mlx_loop(image->mlx);
	return (0);
}