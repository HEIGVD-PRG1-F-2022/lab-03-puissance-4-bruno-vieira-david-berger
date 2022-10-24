/*
 *  HEIG-VD
 *  Description: Configuration file
 *  Author(s): Bruno Vieira - David Berger
 *  Date: 23.10.2022
*/

#include "config.h"

// Game function
void startGame();
// Drops token in board on the selected column
void fallDown(int board[BOARD_HEIGHT][BOARD_LENGTH], int column, int player);
// Checks if the column is playable / not full to the top
bool playableColumn(int columnInput, int board[BOARD_HEIGHT][BOARD_LENGTH]);
// Checks for winner horizontally
int checkHorizontalWin(int board[BOARD_HEIGHT][BOARD_LENGTH]);
// Checks for winner vertically
int checkVerticalWin(int board[BOARD_HEIGHT][BOARD_LENGTH]);
// Checks for winner diagonally
int checkDiagonalWin(int board[BOARD_HEIGHT][BOARD_LENGTH]);
// Checks for winner in entire board
int checkWin(int board[BOARD_HEIGHT][BOARD_LENGTH]);
// Checks for draw
bool checkDraw(int board[BOARD_HEIGHT][BOARD_LENGTH]);