#include "libft/libft.h"
#include <time.h>

char	*read_mapfile(int fd, int i_read);
int	monte_carlo(char **map, int line, int column);
int	input_move_sim(char **map, int move, int line, char player);
int find_best_move(char **map, int depth, int line, int column);
