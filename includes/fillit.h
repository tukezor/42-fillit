#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct			s_poslist
{
	int					position[4][2];
	int					usable;
	int					selected;
	struct s_poslist	*next;
}						t_poslist;

typedef struct			s_tetlist
{
	int					tetromino[4][2];
	struct s_poslist	*positions;
	struct s_tetlist	*next;
}						t_tetlist;

typedef struct			s_uplist
{
	int					xy[2];
	struct s_uplist		*next;
}						t_uplist;

int						print_error(char *str);
int						print_usage(void);
void					exit_error(char *str);
void					validate_tetromino(char **array);
int						read_file(int fd, t_tetlist **tetrominoes);
void					append_tetromino(char **array, t_tetlist **tetrominoes);
void					convert_tetromino(char **array, t_tetlist *tetrominoes);
void					append_position(int tetromino[4][2], t_poslist **positions);
void					calculate_positions(t_tetlist *tetrominoes, int sqr_size);
int						get_next_position(t_tetlist *tetrominoes, t_uplist **used_positions);
void					add_used_position(int xy[2], t_uplist **used_positions);
void					calculate_new_positions(t_tetlist *tetrominoes, int sqr_size);
t_poslist				*create_position(int tetromino[4][2]);


#endif
