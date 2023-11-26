/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_piece.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:55:53 by aamirkha          #+#    #+#             */
/*   Updated: 2023/11/26 18:55:55 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int sudoku_method(char Board[BOARD_SIZE][BOARD_SIZE], const char element)
{
    int final_row;
    int final_col;
    int flag;
    int row;
    int col;

    final_row = SUDOKU_SUM;
    final_col = SUDOKU_SUM;
    flag = BOARD_SIZE - 1;
    row = 0;
    while (row < BOARD_SIZE)
    {
        col = 0;
        while (col < BOARD_SIZE)
        {
            if (Board[row][col] == element)
            {
                final_col -= col;
                final_row -= row;
                flag--;
            }

            col++;
        }
        row++;
    }

    if (!flag && Board[final_row][final_col] == ' ')
    {
        Board[final_row][final_col] = element;

    }

    return (!flag);

}



int one_left(const char current_row[BOARD_SIZE])
{
    int white_spaces = BOARD_SIZE;
    int index = SUDOKU_SUM;
    int value = ABSOLUTE_SUM;
    int col;

    col = 0;
    while(col < BOARD_SIZE)
    {
        if(current_row[col] != ' ')
        {
            white_spaces--;
            index -= col;
            value -= (current_row[col] - '0');
        }
        col++;
    }
    if(white_spaces == 1)
    {
        return ((index * 10) + value);
    }
    return -1;
}

void scan_for_one_left(char Board[BOARD_SIZE][BOARD_SIZE])
{
    int current;
    int row;

    current = 0;
    row = 0;
    while (row < BOARD_SIZE)
    {
        current = one_left(Board[row]);
        if (current != -1 && Board[row][(current / 10)] == ' ')
        {
            Board[row][(current / 10)] = ((current % 10) + '0');
        }
        row++;
    }

    // row = 0;
    // while (row < BOARD_SIZE)
    // {
    //     current = one_left(Board)
    // }