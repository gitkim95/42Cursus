/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 23:06:42 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/20 15:54:57 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1200
# define HEIGHT 800
# define UPPERHEX "0123456789ABCDEF"
# define LOWERHEX "0123456789abcdef"

typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
}	t_bresenham;

typedef struct s_map_list
{
	char				**list;
	struct s_map_list	*next;
}	t_map_list;

typedef struct s_point
{
	int	x;
	int	y;
	int	color;
}	t_point;

typedef struct s_coord
{
	float	x;
	float	y;
	float	z;
	int		color;
}	t_coord;

typedef struct s_map
{
	int		height;
	int		width;
	int		z_max;
	int		z_min;
	t_coord	**data;
}	t_map;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		color;
	int		x_offset;
	int		y_offset;
	int		scale;
	t_map	map;
}	t_fdf;

//fdf_bresenham.c
void				draw_line_to_img(t_fdf *fdf, t_point p1, t_point p2);

//fdf_close.c
int					close_win2(t_fdf *fdf);
int					close_win1(int keycode, t_fdf *fdf);

//fdf_draw.c
t_point				isomatric_projection(t_fdf *fdf, t_coord coord);
int					refresh_image(t_fdf *fdf);

//fdf_init_struct.c
void				set_struct_zero(t_fdf *fdf);

//fdf_list_util.c
t_map_list			*fdf_maplist_last(t_map_list *node);
void				fdf_maplist_addback(t_map_list **head, \
					t_map_list *new_node);
t_map_list			*fdf_maplist_newnode(char **maplist);

//fdf_set_map_1.c
void				set_coord_data(t_fdf *fdf, t_map_list **head);
void				set_coord_map(t_fdf *fdf, t_map_list **head);
int					get_map_width(char **buf_split);
void				set_map_size_n_list(t_fdf *fdf, t_map_list **temp, int fd);
void				set_map_struct(t_fdf *fdf, char *file_path);

//fdf_set_map_2.c
void				set_coord_center(t_fdf *fdf);
void				set_min_max(t_fdf *fdf);
int					hex_to_int(char *hex);
void				set_map_color(t_coord *coord, char *data);

//fdf_terminator.c
void				free_fdf_coord(t_fdf *fdf);
void				free_split(char **c_split, int **i_split, int i_size);
void				free_fdf_maplist(t_map_list *node);
void				terminator(int flag, void *data, int errnum, char *msg);

//fdf_utils.c
int					fdf_abs(int num);
void				my_mlx_pixel_put(t_fdf *fdf, int x, int y, \
					unsigned int color);
void				init_fdf_struct(t_fdf	*fdf, char *file_path);

//fdf_valid_file.c
void				valid_fdf_file(char *file_path);
void				init_fdf_struct(t_fdf	*fdf, char *file_path);

#endif