#include <unistd.h>
#include <stdio.h>
#define BOARD_SIZE 4
#define SUDOKU_SUM 6
#define ABSOLUTE_SUM 10

enum Side {UP, DOWN, LEFT, RIGHT};



int spacecount(const char Board[BOARD_SIZE][BOARD_SIZE])
{
    int i;
    int j;
    int count = 0;

    i = 0;
    while (i < BOARD_SIZE)
    {
        j = 0;

        while (j < BOARD_SIZE)
        {
            if (Board[i][j] == ' ')
            {
                count++;
            }
            j++;
        }  
        i++;
    }

    return (count);
}

int is_numeric(char c)
{
    return (c >= '0' && c <= '9');
}

int ft_strlen(char *str)
{
    int length;

    length = 0;
    while (*str)
    {
        length++;
        str++;
    }
    return (length);
}

void print_board(const char board[BOARD_SIZE][BOARD_SIZE])
{
    int i;
    int j;
    char line[] = "  - - - - - - - - - - -  \n";

    i = 0;
    write(1, "\n\n", 2);
    write(1, line, ft_strlen(line));
    while (i < BOARD_SIZE)
    {
        j = 0;
        write(1, " | ", 3);
        while (j < BOARD_SIZE)
        {
            write(1, &board[i][j], 1);
            write(1, "  |  ", 5);
            j++;
        }
        if (i != BOARD_SIZE - 1)
        {
            write(1, "\n\n\n", 3);
        }
        else
        {
            write(1, "\n", 1);
        }
        
        i++;
    }
    write(1, line, ft_strlen(line));
    write(1, "\n\n", 2);
    return;
}

// col -> 2/3, 3/1, 3/2, 1/2

// row -> 2/1, 1/3, 3/2, 2/2

int fill_if_one(char Board[BOARD_SIZE][BOARD_SIZE], const int UDLR[BOARD_SIZE][BOARD_SIZE])
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

int fill_if_four(char Board[BOARD_SIZE][BOARD_SIZE], const int UDLR[BOARD_SIZE][BOARD_SIZE])
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

int nice_case13(char Board[BOARD_SIZE][BOARD_SIZE], const int UDLR[BOARD_SIZE][BOARD_SIZE])
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

int nice_case23(char Board[BOARD_SIZE][BOARD_SIZE], const int UDLR[BOARD_SIZE][BOARD_SIZE])
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

void context_independent23(char Board[BOARD_SIZE][BOARD_SIZE], const int UDLR[BOARD_SIZE][BOARD_SIZE])
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
}

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
    i = 0;
    while (i < BOARD_SIZE)
    {
        int insertion_index = spaces_in_a_col(Board, i);
        printf("%d\n", insertion_index);
        if ((insertion_index != -1) && (UDLR[UP][i] == 3 || UDLR[DOWN][i] == 3))
        {
            Board[insertion_index][i] = '3';
        }
        i++;
    }
}

void board_init(char** argv, char Board[BOARD_SIZE][BOARD_SIZE], int UDLR[BOARD_SIZE][BOARD_SIZE])
{
    int i = 0;
    int j = 0;

    int current = 0;
    while (*argv[1]) 
    {
        if  (is_numeric(*argv[1]))
        {
            if (i == (BOARD_SIZE))
                break;
            current = (*argv[1] - '0');
            UDLR[i][j] = current;
            ++j;
            if (j == BOARD_SIZE)
            {
                j = 0;
                ++i;
            }
        }
        ++argv[1];
    }
    i = 0;

    while (i < BOARD_SIZE)
    {
        j = 0;
        while(j < BOARD_SIZE)
        {
            Board[i][j] = ' ';
            ++j;
        }
        ++i;
    }
}


int main(int argc, char** argv) {

    if (argc != 2)
        return 0;

    char Board[BOARD_SIZE][BOARD_SIZE];
    int UDLR[BOARD_SIZE][BOARD_SIZE];


    board_init(argv, Board, UDLR);
    fill_if_one(Board, UDLR);
    fill_if_four(Board, UDLR);
    context_independent23(Board, UDLR);
    sudoku_method(Board, '4');


    // nice_case23(Board, UDLR);
    // nice_case13(Board, UDLR);
    // scan_for_one_left(Board);
    // nice_case13(Board, UDLR);
    // nice_case23(Board, UDLR);

    // sudoku_method(Board, '1');
    // scan_for_one_left(Board);
    // sudoku_method(Board, '2');
    // scan_for_one_left(Board);

    int tries = 0;

    while(tries <= 5)
    {
        nice_case23(Board, UDLR);
        nice_case13(Board, UDLR);
        scan_for_one_left(Board);
        sudoku_method(Board, '1');
        sudoku_method(Board, '2');
        sudoku_method(Board, '3');
        inverse3(Board, UDLR);
        tries++;  
    }

    print_board(Board);
    return 0;
}