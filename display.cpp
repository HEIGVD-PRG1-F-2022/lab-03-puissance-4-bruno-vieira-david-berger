/*
 *  HEIG-VD
 *  Description: Configuration file
 *  Author(s): Bruno Vieira - David Berger
 *  Date: 23.10.2022
*/

#include <iostream>
#include "config.h"
#include "display.h"

// Shows game's rules
void showRules(){
    std::cout<<"Bienvenue au puissance 4\n"
               "Pour gagner une partie de puissance 4, il faut aligner 4 jetons de sa couleur horizontalement, verticalement ou diagonalement.\n"
               "Si a la fin de la partie tous les jetons sont joues et quil ny a pas dalignement la partie est nulle.\n"
               "Pour jouer il suffit de choisir le numero de la colonne(1-"<<BOARD_LENGTH<<") voulue suivi de la touche ENTER pour poser son jeton et les joueurs alternent a chaque tour\n"
               "Le joueur 1 est represente par \""<<PLAYER1_CHAR<<"\" et le joueur 2 par \""<<PLAYER2_CHAR<<"\"" << std::endl;
}

// Draws game board
void drawBoard(int board[BOARD_HEIGHT][BOARD_LENGTH]) {
    std::cout<<std::endl;
    std::cout<<"Choisissez une colonne (1-"<<BOARD_LENGTH<<"):"<<std::endl;
    for (int i = 0; i < BOARD_HEIGHT; ++i) {
        for (int j = 0; j < BOARD_LENGTH; ++j) {
            switch (board[i][j]) {
                case PLAYER1:
                    std::cout << " | " << PLAYER1_CHAR;
                    break;
                case PLAYER2:
                    std::cout << " | " << PLAYER2_CHAR;
                    break;
                default:
                    std::cout << " | " << EMPTY_CHAR;
                    break;
            }
        }
        std::cout << " | \n";
        std::cout << "  ----------------------------" "\n";
    }
}