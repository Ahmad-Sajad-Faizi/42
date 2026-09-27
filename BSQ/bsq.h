#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_map
{
	int		rows;
	int		cols;
	char	empty;
	char	obs;
	char	full;
	char	*buffer;
	int		buffer_size;
	int		first_line_len;
}	t_map;

char	*read_all(int fd, int *out_size);
int		parse_map(char *buffer, int size, t_map *map);
void	solve_map(t_map *map);
int		ft_is_printable(char c);
void	ft_puterror(void);

#endif
