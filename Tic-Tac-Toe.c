#include <stdio.h>

// Function to print the Tic Tac Toe board
void printBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
}

// Function to check if a player has won
int checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1; // Row win
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return 1; // Column win
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1; // Diagonal win
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1; // Diagonal win
    return 0; // No win
}

int main() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    int currentPlayer = 1; // Player 1 starts
    int moves = 0;

    printf("Tic Tac Toe\n");

    while (1) {
        // Print the current board
        printBoard(board);

        int row, col;
        printf("Player %d's turn. Enter row (0-2) and column (0-2): ", currentPlayer);
        scanf("%d %d", &row, &col);

        // Check if the move is valid
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        // Make the move
        board[row][col] = (currentPlayer == 1) ? 'X' : 'O';
        moves++;

        // Check for a win
        if (checkWin(board, board[row][col])) {
            printBoard(board);
            printf("Player %d wins!\n", currentPlayer);
            break;
        } else if (moves == 9) {
            printBoard(board);
            printf("It's a draw!\n");
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    return 0;
}
