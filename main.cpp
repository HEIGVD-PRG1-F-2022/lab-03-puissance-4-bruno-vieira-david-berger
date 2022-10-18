/*
 *  HEIG-VD
 *  Description: PRG1 Labo3 - Puissance 4
 *  Author(s): Bruno Vieira - David Berger
 *  Date: 18.10.2022
*/

#include <iostream>
#include "config.h"

using namespace std;

void drawBoard(int board[BOARD_HEIGHT][BOARD_LENGTH]);
void fallDown(int board[BOARD_HEIGHT][BOARD_LENGTH], int column, int player);

int main(){
    int board[BOARD_HEIGHT][BOARD_LENGTH] = {EMPTY};
    bool winner = false;
    int columnImput;

    drawBoard(board);

    while (winner == false) {

        cout << "Dans quelle colonne voulez-vous jouer ? ";
        cin >> columnImput;
        fallDown(board, columnImput - 1, PLAYER1);
        drawBoard(board);



    }

    return 0;

}

void fallDown(int board[BOARD_HEIGHT][BOARD_LENGTH], int column, int player) {

    for (int l = BOARD_HEIGHT -1; l > 0; l--) {
        if (board[l][column] == EMPTY) {
            board[l][column] = player;
            break;
        }
    }

}

void drawBoard(int board[BOARD_HEIGHT][BOARD_LENGTH]) {

    // print board for testing
    for (int i = 0; i < BOARD_HEIGHT; ++i) {
        for (int j = 0; j < BOARD_LENGTH; ++j) {
            cout << " | " << board[i][j];
        }
        cout << " | \n";
        cout << "  ----------------------------" "\n";
    }
}