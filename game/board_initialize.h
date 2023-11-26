/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_initialize.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:59:12 by aamirkha          #+#    #+#             */
/*   Updated: 2023/11/26 18:59:14 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void board_initialize(char** argv, char Board[BOARD_SIZE][BOARD_SIZE], int UDLR[BOARD_SIZE][BOARD_SIZE])
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