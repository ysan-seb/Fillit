/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 08:41:24 by ysan-seb          #+#    #+#             */
/*   Updated: 2016/12/19 10:58:18 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_struct
{
	int x;
	int y;
}					t_struct;

char				*read_file(char *av);
int					start_prog(char *av);

int					check_1(char *s);
int					check_2(char *s);
int					check_3(char *s);
int					check_4(char *s);
int					check_global(char *s);

char				**entry_split(char *s);
char				***tetri_split(char **tab, int nb_tetri);
t_struct			*check_pos(char **tab);
char				***tetri_move(char ***cub, int nb_tetri);

int					ft_sqrt(int nb);
char				**create_map(int map_size);
void				free_map(char **map);
void				fill_map(char **map, int map_size);
void				print_map(char **map);

void				ft_putchar(char c);
void				ft_putstr(char const *s);
size_t				ft_strlen(const char *str);
int					ft_ctw(char const *s, char c);
int					ft_ctl(char const *s, char c, int i);
char				**ft_strsplit(char const *s, char c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);

int					main(int ac, char **av);

int					solve_map(char ***cub, char **map, int map_size,
		int tetri_num);
int					place_tetri(char **tetri, char **map, t_struct pos,
		int tetri_num);
void				set_tetri(char **tetri, char **map, t_struct pos, char c);
int					cub_size(char ***cub);
char				**solver(char ***cub, int nb_tetri);
int					tetri_heigth(char **tetri);
int					tetri_width(char **t);
#endif
