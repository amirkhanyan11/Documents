/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nice_cases.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:51:19 by aamirkha          #+#    #+#             */
/*   Updated: 2023/11/26 18:51:22 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int nice_case_13(char Board[BOARD_SIZE][BOARD_SIZE], const int UDLR[BOARD_SIZE][BOARD_SIZE])
{
    int row;
    int col;
    int signal;

    row = 0;
    signal = 0;
    while (row < BOARD_SIZE)
    {
        col = 0;
        while(col < BOARD_SIZE)
        {
            if  (UDLR[row][col] != 1)
            {
                col++;
                continue;
            }

            if (row == UP && UDLR[DOWN][col] == 3 && Board[1][col] == '3')
            {
                Board[2][col] = '1';
                Board[3][col] = '2';
                signal = 1;
            }

            else if(row == DOWN && UDLR[UP][col] == 3 && Board[2][col] == '3')
            {
                Board[1][col] = '1';
                Board[0][col] = '2';
            }

            else if (row == LEFT && UDLR[RIGHT][col] == 3 && Board[col][1] == '3')
            {
                Board[col][2] = '1';
                Board[col][3] = '2';
            }

            else if (row == RIGHT && UDLR[LEFT][col] == 3 && Board[col][2] == '3')
            {
                Board[col][1] = '1';
                Board[col][0] = '2';
            } 

            col++;
        }
        row++;
    }
    
    return signal;
}

int nice_case_23(char Board[BOARD_SIZE][BOARD_SIZE], const int UDLR[BOARD_SIZE][BOARD_SIZE])
{
    int row;
    int col;
    int signal;

    row = 0;
    signal = 0;
    while (row < BOARD_SIZE)
    {
        col = 0;
        while(col < BOARD_SIZE)
        {
            if  (UDLR[row][col] != 2)
            {
                col++;
                continue;
            }

            if (row == UP && UDLR[DOWN][col] == 3 && Board[0][col] == '3' && Board[1][col] == '4')
            {
                Board[2][col] = '2';
                Board[3][col] = '1';
                signal = 1;
            }

            else if(row == DOWN && UDLR[UP][col] == 3 && Board[3][col] == '3' && Board[2][col] == '4')
            {
                Board[1][col] = '2';
                Board[0][col] = '1';
            }

            else if (row == LEFT && UDLR[RIGHT][col] == 3 && Board[col][0] == '3' && Board[col][1] == '4')
            {
                Board[col][2] = '2';
                Board[col][3] = '1';
            }

            else if (row == RIGHT && UDLR[LEFT][col] == 3 && Board[col][3] == '3' && Board[col][2] == '4')
            {
                Board[col][1] = '2';
                Board[col][0] = '1';
            } 

            col++;
        }
        row++;
    }
    
    return signal;
}

