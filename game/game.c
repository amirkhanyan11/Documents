#include "macro.h"
#include "board_initialize.h"
#include "context_independent_cases.h"
#include "logical_piece.h"
#include "nice_cases.h"
#include "inverse3_method.h"
#include "printing_functions.h"




int main(int argc, char** argv) {

    if (argc != 2)
        return 0;

    char Board[BOARD_SIZE][BOARD_SIZE];
    int UDLR[BOARD_SIZE][BOARD_SIZE];


    board_initialize(argv, Board, UDLR);
    // context_independent_1(Board, UDLR);
    // context_independent_4(Board, UDLR);
    // context_independent_23(Board, UDLR);
    // sudoku_method(Board, '4');

    // int tries = 0;

    // while(tries <= 5)
    // {
    //     nice_case_23(Board, UDLR);
    //     nice_case_13(Board, UDLR);
    //     scan_for_one_left(Board);
    //     sudoku_method(Board, '1');
    //     sudoku_method(Board, '2');
    //     sudoku_method(Board, '3');
    //     //inverse3(Board, UDLR);
    //     tries++;  
    // }

    print_board(Board);
    return 0;
}


