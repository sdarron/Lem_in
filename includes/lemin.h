/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:55:23 by warchiba          #+#    #+#             */
/*   Updated: 2020/11/19 15:55:26 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_int {
	int				data;
	struct s_int	*next;
}					t_int;

typedef struct		s_table {
	char			**table;
	int				size;
}					t_table;

typedef struct		s_map {
	t_table			*comments;
	t_table			*room_lines;
	t_table			*link_lines;
	int				number_of_ants;
	int				number_of_rooms;
	t_int			**links_list;
	char			**links_matrix;
	char			**room_names;
	int				flag_simplest_path;
	int				**shortest_paths;
	int				number_of_paths;
	int				*visited_rooms;
	char			**edmonds_karp_solution;
	int				edk_number_of_paths;
	int				*edk_real_sizes;
	int				**result_paths;
	int				result_number_of_paths;
}					t_map;

int					is_comment(char *line);
int					is_num(char *line);
int					is_good_link(t_map *map, char *line);
int					is_good_room_coord(char *line);
int					is_good_number_of_ants(char *line);
int					is_good_room_name(char *line);
void				exit_func(t_map *map, int flag_error);
int					add_to_table(t_table *table, char *line);
char				*read_links(t_map *map, char *line);
char				*read_rooms(t_map *map);
void				free_map(t_map *map);
void				free_char_table(char **table, int size);
void				free_int_table(int **table, int size);
t_map				*parse_room_names(t_map *map);
t_map				*parse_links(t_map *map);
int					**solution(t_map *map);
int					check_rooms(t_map *map);
char				*find_second_name(char *line);
int					find_in_room_names(t_map *map, char *line);
char				**edmonds_karp_solution(t_map *map);
char				**init_char_matrix(t_map *map, int size);
void				free_queue(t_int *queue);
t_int				*init_queue(t_map *map);
void				add_to_queue(t_int *queue, t_int *tmp,
					int *visited, t_map *map);
t_int				*pop_first_from_queue(t_int *queue);
int					*init_visited_array(t_map *map);
int					*init_visited_edk(t_map *map);
int					*init_paths_sizes_from_int(int **paths,
					t_map *map, int *len);
int					count_steps(int **paths, char **matrix,
					t_map *map, int **sizes);
int					**init_queues(t_map *map, int *sizes);
t_int				**init_list_matrix(t_map *map, int size);
char				**init_char_matrix(t_map *map, int size);
char				*find_second_name(char *line);
int					*init_int_array_with_zeros(t_map *map, int size);
int					*init_int_array(t_map *map, int size);
int					**init_array(t_map *map);
int					**init_paths_array(int **sizes,
					int number_of_paths, t_map *map);
void				ft_quicksort(int arr[], int beg, int end);
int					*copy_int_array(const int *array, int size, t_map *map);
void				write_solution(t_map *map, int **sizes, int steps);
void				choose_solution(t_map *map);
void				read_map(t_map *map);

#endif
