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
int checkHorizontalWin(int board[BOARD_HEIGHT][BOARD_LENGTH]);
int checkVerticalWin(int board[BOARD_HEIGHT][BOARD_LENGTH]);
int checkDiagonalWin(int board[BOARD_HEIGHT][BOARD_LENGTH]);
int checkWin(int board[BOARD_HEIGHT][BOARD_LENGTH]);

int main(){
    int board[BOARD_HEIGHT][BOARD_LENGTH] = {EMPTY};
    bool gameOver = false;
    int columnInput;
    bool playerPlaying = false;
    int winner = EMPTY;

    drawBoard(board);

    while (gameOver == false) {

        cout << "Dans quelle colonne voulez-vous jouer ? ";
        cin >> columnInput;
        if (playableInput(columnInput, board)){
            fallDown(board, columnInput - 1, playerPlaying);
            drawBoard(board);
            if(checkWin(board) != EMPTY){
                gameOver = true;
                winner = checkWin(board);
            }
            playerPlaying = !playerPlaying;
        }
        else
            cout<< "invalid input";
    }
    cout<<"Le vainqueur est le joueur " <<winner;
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
    cout<<endl;
    for (int i = 0; i < BOARD_HEIGHT; ++i) {
        for (int j = 0; j < BOARD_LENGTH; ++j) {
            cout << " | " << board[i][j];
        }
        cout << " | \n";
        cout << "  ----------------------------" "\n";
    }
}

bool playableInput(int columnInput, int board[BOARD_HEIGHT][BOARD_LENGTH]){
    if (board[0][columnInput -1] != EMPTY)
        return false;
    else
        return true;
}

int checkHorizontalWin(int board[BOARD_HEIGHT][BOARD_LENGTH]){
    for (int l = 0; l < BOARD_HEIGHT; ++l) {
        for (int c = 0; c < BOARD_LENGTH-3; ++c) {
            if (board[l][c] == board[l][c+1] && board[l][c] == board[l][c+2] && board[l][c] == board[l][c+3] && board[l][c] != EMPTY)
                return board[l][c];
        }
    }
    return EMPTY;
}

int checkVerticalWin(int board[BOARD_HEIGHT][BOARD_LENGTH]){
    for (int l = 0; l < BOARD_HEIGHT-3; ++l) {
        for (int c = 0; c < BOARD_LENGTH; ++c) {
            if (board[l][c] == board[l+1][c] && board[l][c] == board[l+2][c] && board[l][c] == board[l+3][c] && board[l][c] != EMPTY)
                return board[l][c];
        }
    }
    return EMPTY;
}

int checkDiagonalWin(int board[BOARD_HEIGHT][BOARD_LENGTH]){
    for (int l = 0; l < BOARD_HEIGHT-3; ++l) {
        for (int c = 0; c < BOARD_LENGTH-3; ++c) {
            if (board[l][c] == board[l+1][c+1] && board[l][c] == board[l+2][c+2] && board[l][c] == board[l+3][c+3] && board[l][c] != EMPTY)
                return board[l][c];
        }
    }
    for (int l = BOARD_HEIGHT - 1; l > 3; --l) {
        for (int c = BOARD_LENGTH - 4; c >= 0 ; --c) {
            if (board[l][c] == board[l-1][c+1] && board[l][c] == board[l-2][c+2] && board[l][c] == board[l-3][c+3] && board[l][c] != EMPTY)
                return board[l][c];
        }
    }
    return EMPTY;
}

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
