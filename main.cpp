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
bool playableInput(int columnInput, int board[BOARD_HEIGHT][BOARD_LENGTH]);

int main(){
    int board[BOARD_HEIGHT][BOARD_LENGTH] = {EMPTY};
    bool winner = false;
    int columnImput;
    bool playerPlaying = false;

    drawBoard(board);

    while (winner == false) {

        cout << "Dans quelle colonne voulez-vous jouer ? ";
        cin >> columnImput;
        if (playableInput(columnImput, board)){
            fallDown(board, columnImput - 1, playerPlaying);
            drawBoard(board);
            playerPlaying = !playerPlaying;
        }
    }
    return 0;
}

void fallDown(int board[BOARD_HEIGHT][BOARD_LENGTH], int column, int player) {

    for (int l = BOARD_HEIGHT -1; l >= 0; l--) {
        if (board[l][column] == EMPTY) {
            board[l][column] = player +1;
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

bool playableInput(int columnInput, int board[BOARD_HEIGHT][BOARD_LENGTH]){
    if (board[0][columnInput] != EMPTY)
        return false;
    else
        return true;
}