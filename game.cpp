/*
 *  HEIG-VD
 *  Description: Configuration file
 *  Author(s): Bruno Vieira - David Berger
 *  Date: 23.10.2022
*/

#include <iostream>
#include "config.h"
#include "game.h"
#include "display.h"

void startGame(){
    // Game board
    int board[BOARD_HEIGHT][BOARD_LENGTH] = {EMPTY};
    // Match boolean
    bool gameOver = false;
    // User's column input
    int columnInput;
    // Boolean that allows to alternate between player 1 and 2
    bool alternatePlayer = false;
    // Winner
    int winner = EMPTY;
    // Draw boolean
    bool draw = false;

    // Display rules at start
    showRules();
    // Display board at start
    drawBoard(board);

    // Game loop
    while (gameOver == false) {
        std::cout << "Dans quelle colonne voulez-vous jouer ? ";
        // Get user input
        std::cin >> columnInput;
        // If valid input
        if (playableColumn(columnInput, board)){
            // Drop token
            fallDown(board, columnInput - 1, alternatePlayer);
            // Redraw board
            drawBoard(board);
            // Checks for winner
            if(checkWin(board) != EMPTY){
                gameOver = true;
                winner = checkWin(board);
            }
            // Checks for draw
            if (checkDraw(board)) {
                gameOver = true;
                draw = true;
                break;
            }
            // Switch players
            alternatePlayer = !alternatePlayer;
        }
        else
            std::cout<< "Colonne non valide"<<std::endl;
    }
    // Match draw
    if (draw) {
        std::cout << "Egalite" << std::endl;
    }
    // Match winner
    else {
        std::cout << "Le vainqueur est le joueur " << winner;
    }
}

// Drops token in board on the selected column
void fallDown(int board[BOARD_HEIGHT][BOARD_LENGTH], int column, int player) {
    for (int l = BOARD_HEIGHT -1; l >= 0; l--) {
        if (board[l][column] == EMPTY) {
            board[l][column] = player +1;
            break;
        }
    }

}

// Checks if the column is playable / not full to the top
bool playableColumn(int columnInput, int board[BOARD_HEIGHT][BOARD_LENGTH]){
    if (board[0][columnInput -1] != EMPTY)
        return false;
    else
        return true;
}

// Checks for winner horizontally
int checkHorizontalWin(int board[BOARD_HEIGHT][BOARD_LENGTH]){
    for (int l = 0; l < BOARD_HEIGHT; ++l) {
        for (int c = 0; c < BOARD_LENGTH-3; ++c) {
            if (board[l][c] == board[l][c+1] && board[l][c] == board[l][c+2] && board[l][c] == board[l][c+3] && board[l][c] != EMPTY)
                return board[l][c];
        }
    }
    return EMPTY;
}

// Checks for winner vertically
int checkVerticalWin(int board[BOARD_HEIGHT][BOARD_LENGTH]){
    for (int l = 0; l < BOARD_HEIGHT-3; ++l) {
        for (int c = 0; c < BOARD_LENGTH; ++c) {
            if (board[l][c] == board[l+1][c] && board[l][c] == board[l+2][c] && board[l][c] == board[l+3][c] && board[l][c] != EMPTY)
                return board[l][c];
        }
    }
    return EMPTY;
}

// Checks for winner diagonally
int checkDiagonalWin(int board[BOARD_HEIGHT][BOARD_LENGTH]){
    // Ascending diagonals
    for (int l = 0; l < BOARD_HEIGHT-3; ++l) {
        for (int c = 0; c < BOARD_LENGTH-3; ++c) {
            if (board[l][c] == board[l+1][c+1] && board[l][c] == board[l+2][c+2] && board[l][c] == board[l+3][c+3] && board[l][c] != EMPTY)
                return board[l][c];
        }
    }
    // Descending diagonals
    for (int l = BOARD_HEIGHT - 1; l > 3; --l) {
        for (int c = BOARD_LENGTH - 4; c >= 0 ; --c) {
            if (board[l][c] == board[l-1][c+1] && board[l][c] == board[l-2][c+2] && board[l][c] == board[l-3][c+3] && board[l][c] != EMPTY)
                return board[l][c];
        }
    }
    return EMPTY;
}

// Checks for winner in entire board
int checkWin(int board[BOARD_HEIGHT][BOARD_LENGTH]){
    if(checkHorizontalWin(board) != EMPTY)
        return checkHorizontalWin(board);
    else if(checkDiagonalWin(board) != EMPTY)
        return checkDiagonalWin(board);
    else if(checkVerticalWin(board) != EMPTY)
        return checkVerticalWin(board);
    else
        return EMPTY;
}

// Checks for draw
bool checkDraw(int board[BOARD_HEIGHT][BOARD_LENGTH]) {
    bool isDraw = false;
    for (int i; i < BOARD_LENGTH; i++) {
        isDraw |= playableColumn(i, board);
    }
    return isDraw;
}