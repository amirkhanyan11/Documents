/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:46:10 by aamirkha          #+#    #+#             */
/*   Updated: 2023/11/26 18:46:46 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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
