#include <bits/stdc++.h>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE];
char currentPlayer = 'X';

void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '1' + i * SIZE + j;
        }
    }
}

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << "\n";
        if (i < SIZE - 1) cout << "--|---|--\n";
    }
    cout << "\n";
}

bool isValidMove(int move) {
    int row = (move - 1) / SIZE;
    int col = (move - 1) % SIZE;
    return (move >= 1 && move <= 9 && board[row][col] != 'X' && board[row][col] != 'O');
}

void updateBoard(int move) {
    int row = (move - 1) / SIZE;
    int col = (move - 1) % SIZE;
    board[row][col] = currentPlayer;
}
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
bool checkDraw() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}
bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }
    return false;
}


int main(){
    cout << "Welcome to Tic Tac Toe!"<<endl;
    char playAgain;
    do{
        initializeBoard();
        char curplayer='X';
        bool gameWon = false, draw = false;
        while(!gameWon && !draw){
            displayBoard();
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            int move;cin >> move;
            
            while (!isValidMove(move)) {
                cout << "Invalid move. Try again: ";
                cin >> move;
            }

            updateBoard(move);
            gameWon = checkWin();
            if (!gameWon) draw = checkDraw();
            if (!gameWon && !draw) switchPlayer();
        }

        displayBoard();
        if (gameWon) {
            cout << "Player " << currentPlayer << " wins!\n";
        } else if (draw) {
            cout << "The game is a draw!\n";
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

        
    }while(playAgain=='y' || playAgain=='Y');

    return 0;
}