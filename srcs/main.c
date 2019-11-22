

#include "fillit.h"

void	print_tetrominos(t_tetlist *tetrominoes)
{
	while (tetrominoes)
	{
		while (*tetrominoes->tetromino)
		{
			ft_putendl(*tetrominoes->tetromino);
			tetrominoes->tetromino++;
		}
		tetrominoes = tetrominoes->next;
	}
}

int	main(int argc, char **argv)
{
	int			fd;
	t_tetlist	*tetrominos;

	if (argc != 2)
		return (print_usage());
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (print_error("file open failed!"));
	tetrominos = NULL;
	if (!read_file(fd, &tetrominos))
		return (print_error("Read file failed!"));
	print_tetrominos(tetrominos);
	return (0);
}
