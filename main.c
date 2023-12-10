#include "connect4.h"
#include <stdlib.h>

void	free_array(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return ;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args[i]);
	free(args);
}

// check for overflow
int	check_arg(char *arg, int line)
{
	char	*line_a;

	line_a = ft_itoa(line);
	if (ft_strncmp(line_a, arg, ft_strlen(arg)))
		return (free(line_a), 0);
	return (free(line_a), 1);
}

// check for overflow
int	check_args(char **argv, int line, int column)
{
	char	*line_a;
	char	*column_a;

	line_a = ft_itoa(line);
	column_a = ft_itoa(column);
	if (ft_strncmp(line_a, argv[1], 10) || ft_strncmp(column_a, argv[2], 10))
		return (free(line_a), free(column_a), 0);
	return (free(line_a), free(column_a), 1);
}

void	init_map(char **map, int line, int column)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < line)
	{
		j = 0;
		map[i] = malloc(column + 1);
		while (j < column)
		{
			map[i][j] = 'x';
			j++;
		}
		map[i][j] = 0;
		i++;
	}
	map[i] = 0;
}

void	render_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_putstr_fd(map[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}

int	input_move(char **map, int move, int line, char player)
{
	line--;
	while (line >= 0)
	{
		if (map[line][move - 1] == 'x' && map[line][move - 1] != '1'
			&& map[line][move - 1] != '2')
		{
			map[line][move - 1] = player;
			render_map(map);
			return (line);
		}
		line--;
	}
	ft_putstr_fd("\ncolumn is full", 1);
	return (-1);
}

// check path for winning move
char	end_game(char **map, int i, int j, char c, int line)
{
	int	check;
	int	k;

	k = 0;
	int check_full = 1;
	while (map[0][k])
	{
		if (map[0][k] == 'x')
			check_full = 0;
		k++;
	}
	if (check_full)
		return 'x';
	// check downwards
	check = 1;
	k = 1;
	while (i + 3 < line && k <= 3)
	{
		if (map[i + k][j] == c)
			check++;
		else
			check = 0;
		k++;
	}
	if (check == 4)
		return (c);
	// check left to right
	check = 0;
	k = -3;
	while (k <= 3)
	{
		if (j + k >= 0 && map[i][j + k] == c)
		{
			check++;
			if (check == 4)
				return (c);
		}
		else
			check = 0;
		if (j + k >= 0 && !map[i][j + k])
			break ;
		k++;
	}
	// check top left to bottom right
	check = 0;
	k = -3;
	while (k <= 3 && i + k < line)
	{
		if (j + k >= 0 && i + k >= 0 && map[i + k][j + k] == c)
		{
			check++;
			if (check == 4)
				return (c);
		}
		else
			check = 0;
		if (i + k >= 0 && j + k >= 0 && !map[i + k][j + k])
			break ;
		k++;
	}
	// check bottom left to top right
	check = 0;
	k = -3;
	while (k <= 3 && i - k < line)
	{
		if (i - k >= 0 && j + k >= 0 && map[i - k][j + k] == c)
		{
			check++;
			if (check == 4)
				return (c);
		}
		else
			check = 0;
		if (i - k >= 0 && j + k >= 0 && !map[i - k][j + k])
			break ;
		k++;
	}
	return (0);
}

void	game_loop(char **map, int line, int column)
{
	int		game_over;
	char	*move;
	int		next_move;
	int		turn;
	int		i;
	char	player_won;

	game_over = 0;
	turn = rand() % 2;
	i = 0;
	player_won = 0;
	while (!game_over)
	{
		if (turn)
		{
			turn = 0;
			ft_putstr_fd("\nPlayer1 type your move: ", 1);
			move = read_mapfile(0, 1);
			if (!move)
		{
			turn = 1;
			ft_putstr_fd("\nInvalid move. Choose a Number between 1 and ", 1);
			ft_putnbr_fd(column, 1);
			continue;
		}
			next_move = ft_atoi(move);
			if (!check_arg(move, next_move) || next_move > column
				|| next_move < 1)
			{
				ft_putstr_fd("\nInvalid move. Choose a Number between 1 and ",
					1);
				ft_putnbr_fd(column, 1);
				turn = 1;
			}
			else
			{
				
				i = input_move(map, next_move, line, '1');
				if (i == -1)
				{
					turn = 1;
					continue ;
				}
				player_won = end_game(map, i, next_move - 1, '1', line);
				if (player_won)
					game_over = 1;
			}
			free(move);
		}
		else
		{
			turn = 1;
			ft_putstr_fd("\nPlayer2 \n", 1);
			i = -1;
			while (i == -1)
			{
				next_move = rand() % column;
				i = input_move(map, next_move, line, '2');
			}

			player_won = end_game(map, i, next_move, '2', line);
			if (player_won)
				game_over = 1;
		}
	}
	if (player_won == 'x')
		ft_putstr_fd("It's a draw");
	else
	{
		ft_putstr_fd("Player ", 1);
		ft_putchar_fd(player_won, 1);
		ft_putstr_fd(" has won the game", 1);
	}
}

int	main(int argc, char **argv)
{
	int		line;
	int		column;
	char	**map;

	// handle args
	if (argc != 3)
	{
		ft_putstr_fd("invalid number of arguments", 1);
		return (1);
	}
	line = ft_atoi(argv[1]);
	column = ft_atoi(argv[2]);
	if (!check_args(argv, line, column))
	{
		ft_putstr_fd("invalid numbers", 1);
		return (1);
	}
	if (line < 6 || column < 7)
	{
		ft_putstr_fd("size of grid too small", 1);
		return (1);
	}
	// create map
	map = malloc(sizeof(map) * (line + 1));
	init_map(map, line, column);
	render_map(map);
	// gameloop
	game_loop(map, line, column);
	free_array(map);
	return (0);
}
