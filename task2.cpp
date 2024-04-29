#include <iostream>
#include <vector>

using namespace std;

// Function to display the Tic-Tac-Toe board with grid
void displayBoard(const vector<vector<char>>& board) {
    cout << "  1 2 3" << endl; // Column numbers
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << " "; // Row numbers
        for (int j = 0; j < 3; ++j) {
            if (j > 0) cout << "|"; // Separator
            cout << board[i][j]; // Cell content
        }
        cout << endl;
        if (i < 2) cout << "  -----" << endl; // Horizontal divider
    }
}

// Function to check if the game board is full (draw)
bool isBoardFull(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false; // Empty cell found, board is not full
            }
        }
    }
    return true; // No empty cell found, board is full
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns for win
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals for win
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize 3x3 board with empty cells
    char currentPlayer = 'X'; // Start with player X

    // Main game loop
    while (true) {
        // Display the board
        cout << "Current board:" << endl;
        displayBoard(board);

        // Prompt current player for input
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Validate input
        if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ') {
            // Update the board with player's move
            board[row - 1][col - 1] = currentPlayer;

            // Check for win
            if (checkWin(board, currentPlayer)) {
                cout << "Player " << currentPlayer << " wins!" << endl;
                break; // Game ends
            }

            // Check for draw
            if (isBoardFull(board)) {
                cout << "It's a draw!" << endl;
                break; // Game ends
            }

            // Switch players
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move. Please try again." << endl;
        }
    }

    return 0;
}