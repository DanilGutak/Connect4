#include "../includes/connect4.h"

char	**copy_map(char **map, int line, int column)
{
	char	**new_map;

	new_map = malloc(line * sizeof(char *));
	if (new_map == NULL)
		return (NULL);
	for (int i = 0; i < line; i++)
	{
		new_map[i] = malloc(column * sizeof(char));
		if (new_map[i] == NULL)
		{
			for (int j = 0; j < i; j++)
				free(new_map[j]);
			free(new_map);
			return (NULL);
		}
		for (int j = 0; j < column; j++)
			new_map[i][j] = map[i][j];
	}
	return (new_map);
}
int	score_game(char **map, int line, int column)
{
	int	directions[4][2] = {{0, 1}, {1, 0}, {1, 1}, {-1, 1}};
	int	score;
	int	count;
	int	x;
	int	y;

	score = 0;
	for (int player = 1; player <= 2; player++)
	{
		for (int j = 0; j < line; j++)
		{
			for (int k = 0; k < column; k++)
			{
				if (map[j][k] == player + '0')
				{
					for (int d = 0; d < 4; d++)
					{
						count = 0;
						for (int i = 0; i < 4; i++)
						{
							x = j + i * directions[d][0];
							y = k + i * directions[d][1];
							if (x >= 0 && x < line && y >= 0 && y < column)
								if (map[x][y] == player + '0')
									count++;
						}
						if (player == 2)
						{
							if (count == 4)
								score += 100000000;
							else if (count == 3)
								score += 500;
							else if (count == 2)
								score += 200;
						}
						else
						{
							if (count == 4)
								score -= 50;
							else if (count == 3)
								score -= 50;
							else if (count == 2)
								score -= 5;
						}
					}
				}
			}
		}
	}
	return (score);
}
void	free_map(char **map, int line)
{
	for (int i = 0; i < line; i++)
	{
		free(map[i]);
	}
	free(map);
}

int	minimax(char **map, int depth, int isMaximizingPlayer, int line, int column)
{
	int		score;
	char	**new_map;
	int		maxEval;
	int		eval;
	int		minEval;

	score = score_game(map, line, column);
	if (score != 0 || depth == 0)
		return (score);
	if (isMaximizingPlayer)
	{
		maxEval = -20000000;
		for (int i = 1; i <= column; i++)
		{
			new_map = copy_map(map, line, column);
			if (input_move_sim(new_map, i, line, '2') == -1)
			{
				free_map(new_map, line);
				continue ;
			}
			eval = minimax(new_map, depth - 1, 0, line, column);
			maxEval = maxEval < eval ? eval : maxEval;
			free_map(new_map, line);
		}
		return (maxEval);
	}
	else
	{
		minEval = 2000000000;
		for (int i = 1; i <= column; i++)
		{
			new_map = copy_map(map, line, column);
			if (input_move_sim(new_map, i, line, '1') == -1)
			{
				free_map(new_map, line);
				continue ;
			}
			eval = minimax(new_map, depth - 1, 1, line, column);
			minEval = minEval > eval ? eval : minEval;
			free_map(new_map, line);
		}
		return (minEval);
	}
}
int	find_blocking_move(char **map, int line, int column)
{
	int	directions[4][2] = {{0, 1}, {1, 0}, {1, 1}, {-1, 1}};
	int	count;
	int	x;
	int	y;
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	for (int j = 0; j < line; j++)
	{
		for (int k = 0; k < column; k++)
		{
			if (map[j][k] == '1')
			{
				for (int d = 0; d < 4; d++)
				{
					count = 0;
					for (int i = 0; i < 3; i++)
					{
						x = j + i * directions[d][0];
						y = k + i * directions[d][1];
						if (x >= 0 && x < line && y >= 0 && y < column
							&& map[x][y] == '1')
							count++;
						else
							break ;
					}
					if (count == 3)
					{
						x1 = j - directions[d][0];
						y1 = k - directions[d][1];
						x2 = j + 3 * directions[d][0];
						y2 = k + 3 * directions[d][1];
						if (x1 >= 0 && x1 < line && y1 >= 0 && y1 < column
							&& map[x1][y1] == 'x')
							return ((d == 0 || d == 1) ? y1 + 1 : x1 + 1);
						if (x2 >= 0 && x2 < line && y2 >= 0 && y2 < column
							&& map[x2][y2] == 'x')
							return ((d == 0 || d == 1) ? y2 + 1 : x2 + 1);
					}
				}
			}
		}
	}
	return (-1);
}

int	find_best_move(char **map, int depth, int line, int column)
{
	int bestMove = -1;
	int bestScore = -20000000;

	for (int i = 1; i <= column; i++)
	{
		char **new_map = copy_map(map, line, column);
		if (input_move_sim(new_map, i, line, '2') == -1)
		{
			free_map(new_map, line);
			continue ;
		}
		int score = minimax(new_map, depth - 1, 0, line, column);
		if (score > bestScore)
		{
			bestScore = score;
			bestMove = i;
		}
		free_map(new_map, line);
	}
	if (bestScore > 500000)
		return (bestMove);
	int block = find_blocking_move(map, line, column);
	if (block != -1)
		return (block);
	return (bestMove);
}