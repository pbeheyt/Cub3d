/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 23:17:42 by ilinhard          #+#    #+#             */
/*   Updated: 2023/01/25 02:56:10 by pbeheyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../mlx_linux/mlx.h"

# define BUFFER_SIZE 50

typedef struct s_image
{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	int		color_f;
	int		color_c;
}			t_image;

typedef struct s_game
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	int		color_f;
	int		color_c;
}			t_game;

/*image/clear*/
void	exit_clean(int status);

/*image/init*/
int		init_mlx(t_image *image);

/*libft*/
char	**ft_split(char const *s, char c);
void	*ft_memset(void *s, int c, size_t n);

/*parsing*/
char	**ft_init_parsing(char *file, t_game *game);
int		ft_strlen(char *str);
void	ft_free_tab(char **tab);
int		ft_search_tab(char **tab, char *to_find, int *pos);
char	*ft_cpy(char *str);
void	ft_free_data_game(t_game *game);
int		ft_make_color(char *str);
int		ft_atoi(char *str, int *pos);
int		ft_encode_rgb(int red, int green, int blue);
char	*ft_strjoin(char *s1, char *s2);
int		ft_find(char *str, char *to_find);

#endif