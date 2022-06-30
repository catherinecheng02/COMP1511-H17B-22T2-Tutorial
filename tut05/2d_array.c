#include <stdio.h>

#define SIZE 5

int did_player_win(char player, char board[SIZE][SIZE]) {
    // Check the diagonals, by keeping count of how many squares have been 
    // claimed by the player, and returning 1 if a whole diagonal has been claimed.
    int row = 0;
    int diag1_counter = 0;
    int diag2_counter = 0;
    while (row < SIZE) {
        
        int col = 0;
        while (col < SIZE) {
            if (row == col && board[row][col] == player) {
                diag1_counter++;
            }
            if (row + col == SIZE - 1 && board[row][col] == player) {
                diag2_counter++;
            }
            col++;
        }
        row++;
    }
    if (diag1_counter == SIZE || diag2_counter == SIZE) {
            return 1;
        }
    
    // Check the horizontals, using a 2D loop.
    row = 0;
    
    while (row < SIZE) {
        int counter = 0;
        int col = 0;
        while (col < SIZE) {
            if (board[row][col] == player) {
                counter++;
            }
            col++;
        }
        if (counter == SIZE) {
            return 1;
        }
        row++;
    }
    
    // Copy that code, and change it so it's checking vertical
    int col = 0;
    
    while (col < SIZE) {
        int counter = 0;
        int row = 0;
        while (row < SIZE) {
            if (board[row][col] == player) {
                counter++;
            }
            row++;
        }
        if (counter == SIZE) {
            return 1;
        }
        col++;
    }
    
    return 0;
}

int main(void) {
    char no_wins_board[SIZE][SIZE] = {
        {'O', 'X', ' ', ' ', 'X'},
        {' ', 'X', ' ', ' ', ' '},
        {' ', 'X', 'O', ' ', ' '},
        {'O', 'X', 'O', 'O', 'O'},
        {'X', ' ', ' ', ' ', 'O'},
    };

    char x_wins_board[SIZE][SIZE] = {
        {'O', 'X', ' ', ' ', 'X'},
        {' ', 'X', ' ', ' ', ' '},
        {' ', 'X', 'O', ' ', ' '},
        {'O', 'X', 'O', 'O', 'O'},
        {' ', 'X', ' ', ' ', 'O'},
    };
    char o_wins_board[SIZE][SIZE] = {
        {'O', 'X', ' ', ' ', 'X'},
        {' ', 'X', ' ', ' ', ' '},
        {' ', 'X', 'O', ' ', ' '},
        {'O', 'O', 'O', 'O', 'O'},
        {'X', 'X', ' ', ' ', 'O'},
    };

    if (did_player_win('X', no_wins_board)) {
        printf("X Won This Board!\n");
    } else if (did_player_win('O', no_wins_board)) {
        printf("O Won This Board!\n");
    } else {
        printf("Nobody has won this board!\n");
    }
}
