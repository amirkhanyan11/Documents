/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_independent_cases.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:53:49 by aamirkha          #+#    #+#             */
/*   Updated: 2023/11/26 18:53:51 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int context_independent_1(char Board[BOARD_SIZE][BOARD_SIZE], const int UDLR[BOARD_SIZE][BOARD_SIZE])
{
    int row = 0;
    int col = 0;

    while (row < BOARD_SIZE)
    {
        col = 0;
        while (col < BOARD_SIZE)
        {
            if (UDLR[row][col] != 1)
            {
                ++col;
                continue;
            }

            if (row == UP)
            {
                Board[row][col] = '4';
                Board[BOARD_SIZE - 1][col] = (UDLR[row + 1][col] == 2) ? ('3') : Board[BOARD_SIZE - 1][col];
                
            }
                
            else if (row == DOWN)
            {
                Board[BOARD_SIZE - 1][col] = '4';
                Board[0][col] = (UDLR[row - 1][col] == 2) ? ('3') : Board[row][col];
                
            }
                

            else if (row == LEFT)
            {
                Board[col][0] = '4';
                Board[col][BOARD_SIZE - 1] = (UDLR[row + 1][col] == 2) ? ('3') : Board[col][BOARD_SIZE - 1];
                

            }
                

            else if (row == RIGHT)
            {
                Board[col][BOARD_SIZE - 1] = '4';
                Board[col][0] = (UDLR[row - 1][col] == 2) ? ('3') : Board[col][0];
                
            }

            ++col;
        }
        ++row;
    }
    return 0;
}

int context_independent_4(char Board[BOARD_SIZE][BOARD_SIZE], const int UDLR[BOARD_SIZE][BOARD_SIZE])
{
    int row = 0;
    int col = 0;

    while (row < BOARD_SIZE)
    {
        col = 0;
        while (col < BOARD_SIZE)
        {
            if (UDLR[row][col] != 4)
            {
                ++col;
                continue;
            }

            int index = 0;

            if (row == UP)
            {
                while(index < BOARD_SIZE)
                {
                    Board[index][col] = (char)(index + '1');
                    index++;
                }
             
            }

            else if (row == DOWN)
            {
                // Board[BOARD_SIZE - 1][col] = 4 + '0';
                while (index < BOARD_SIZE)
                {
                    Board[BOARD_SIZE - 1 - index][col] = (char)(index + '1');
                    index++;
                }

            }   
            
            else if (row == LEFT)
            {
                while (index < BOARD_SIZE)
                {
                    Board[col][index] = (char)(index + '1');
                    index++;
                }

            }

            else if (row == RIGHT)
            {
                while (index < BOARD_SIZE)
                {
                    
                    Board[col][BOARD_SIZE - 1 - index] = (char)(index + '1');
                    index++;
                }

            }

            ++col;
        }
        ++row;
    }
    return 0;
}

void context_independent_23(char Board[BOARD_SIZE][BOARD_SIZE], const int UDLR[BOARD_SIZE][BOARD_SIZE])
{
    int row = 0;
    int col = 0;

    while (row < BOARD_SIZE)
    {
        col = 0;
        while (col < BOARD_SIZE)
        {
            if (UDLR[row][col] != 2)
            {
                ++col;
                continue;
            }

            if (row == UP && UDLR[DOWN][col] == 3)
            {
                Board[1][col] = '4';
            }
                
            else if (row == DOWN && UDLR[UP][col] == 3)
            {
                Board[2][col] = '4';
                
            }
                

            else if (row == LEFT && UDLR[RIGHT][col] == 3)
            {
                Board[col][1] = '4';
                
            }
                

            else if (row == RIGHT && UDLR[LEFT][col] == 3)
            {
                Board[col][2] = '4';
                
            }

            ++col;
        }
        ++row;
    } 
}

