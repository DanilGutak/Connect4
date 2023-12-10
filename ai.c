#include "connect4.h"
#include <stdio.h>
char **copy_map(char **map, int line, int column)
{
    char **new_map = malloc(line * sizeof(char *));
    if (new_map == NULL)
        return NULL;
    for (int i = 0; i < line; i++)
    {
        new_map[i] = malloc(column * sizeof(char));
        if (new_map[i] == NULL)
            return NULL;
        for (int j = 0; j < column; j++)
            new_map[i][j] = map[i][j];
    }

    return new_map;
}
int score_game(char **map, int line, int column)
{
    int directions[4][2] = {{0, 1}, {1, 0}, {1, 1}, {-1, 1}};
    int score = 0;

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
                        int count = 0;
                        for (int i = 0; i < 4; i++)
                        {
                            int x = j + i * directions[d][0];
                            int y = k + i * directions[d][1];

                            if (x >= 0 && x < line && y >= 0 && y < column && map[x][y] == player + '0')
                            {
                                count++;
                            }
                        }

                        if (player == 2)
                        {
                            if (count == 4)
                                score += 100;
                            else if (count == 3)
                                score += 5;
                            else if (count == 2)
                                score += 2;
                        }
                        else
                        {
                            if (count == 4)
                                score -= 500;
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

    return score;
}


int minimax(char **map, int depth, int isMaximizingPlayer, int line, int column)
{
    int score = score_game(map, line, column);
    if (score != 0 || depth == 0)
        return score;
    if (isMaximizingPlayer)
    {
        int maxEval = -20000000;
        for (int i = 1; i <= column; i++)
        {
            char **new_map = copy_map(map, line, column);
            input_move_sim(new_map, i, line, '2');

            int eval = minimax(new_map, depth - 1, 0, line, column);
            maxEval = maxEval < eval? eval : maxEval;
        }
        return maxEval;
    }
    else
    {
        int minEval = 2000000000;
        for (int i = 1; i <= column; i++)
        {
            // Make a copy of the game state and make the move.
            char **new_map = copy_map(map, line, column);
            input_move_sim(new_map, i, line, '1');

            int eval = minimax(new_map, depth - 1, 1, line, column);
            minEval = minEval > eval? eval : minEval;

        }
        return minEval;
    }
}

int find_best_move(char **map, int depth, int line, int column)
{
    int bestMove = -1;
    int bestScore = -20000000;

    for (int i = 1; i <= column; i++)
    {
        char **new_map = copy_map(map, line, column);
        if (input_move_sim(new_map, i, line, '2') == -1)
            continue;
        int score = minimax(new_map, depth - 1, 0, line, column);
        if (score > bestScore)
        {
            bestScore = score;
            bestMove = i;
        }
        printf("Move %d: %d\n", i, score);
    }
    return bestMove;
}