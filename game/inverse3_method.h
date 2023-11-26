/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse3_method.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:55:03 by aamirkha          #+#    #+#             */
/*   Updated: 2023/11/26 18:55:05 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int spaces_in_a_row(const char ROW[BOARD_SIZE])
{
    int i;
    int count = 0;

    if (ROW[0] == ' ')
    {
        i = 1;
        int insertion_index = SUDOKU_SUM;
        while(i < BOARD_SIZE)
        {
            if(ROW[i] == ' ')
            {
                count++;
            }
            else
                insertion_index -= i;
            i++;
        }
        
        return (count == 1) ? insertion_index : -1;
    }

    if(ROW[3] == ' ')
    {
        i = 0;
        int insertion_index = SUDOKU_SUM - 3;
        while(i < BOARD_SIZE - 1)
        {
            if(ROW[i] == ' ')
            {
                count++;
            }
            else
                insertion_index -= i;
            i++;
        }
        
        return (count == 1) ? (insertion_index) : -1;   
    }
    return -1;
}

int spaces_in_a_col(const char Board[BOARD_SIZE][BOARD_SIZE], int col)
{
    int row;
    int count = 0;
    int insertion_index = 99;

    if (Board[0][col] == ' ')
    {
  
        row = 1;
        insertion_index = SUDOKU_SUM;
        while (row < BOARD_SIZE)
        {
            if (Board[row][col] == ' ')
            {
                count++;
            }
            else
                insertion_index -= row;

            row++;
            
        }

        return (count == 1) ? (insertion_index) : -1;
    }

    else if (Board[BOARD_SIZE - 1][col] == ' ')
    {
        row = 0;
        count = 0;
        insertion_index = SUDOKU_SUM - 3;
        while (row < BOARD_SIZE - 1)
        {
            if (Board[row][col] == ' ')
            {
                count++;
            }
            else
                insertion_index -= row;
           
            row++;
            
        }
        
        return (count == 1) ? (insertion_index) : -1;
    }

    return -1;
}

void inverse3(char Board[BOARD_SIZE][BOARD_SIZE], const int UDLR[BOARD_SIZE][BOARD_SIZE])
{
    int i;

    i = 0;
    while (i < BOARD_SIZE)
    {
        int insertion_index = spaces_in_a_row(Board[i]);
        if ((insertion_index != -1) && (UDLR[LEFT][i] == 3 || UDLR[RIGHT][i] == 3))
        {
            Board[i][insertion_index] = '3';
        }
        i++;
    }
    // i = 0;
    // while (i < BOARD_SIZE)
    // {
    //     int insertion_index = spaces_in_a_col(Board, i);
    //     if ( (insertion_index != -1) && ( (UDLR[UP][i] == 3 && Board[UP][i] == ' ') || (UDLR[DOWN][i] == 3 && Board[BOARD_SIZE - 1][i] == ' ') ) )
    //     {
    //         printf("%c\n", Board[insertion_index][i]);
    //         Board[i][insertion_index] = '3';
    //     }
    //     i++;
    // }
}

