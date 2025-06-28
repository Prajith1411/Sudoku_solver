#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

bool isValid(vector<vector<char>> &board, int row, int col, char c) {
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == c) return false;
        if (board[row][i] == c) return false;
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
    }
    return true;
}

bool solveSudoku(vector<vector<char>> &board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                for (char c = '1'; c <= '9'; c++) {
                    if (isValid(board, i, j, c)) {
                        board[i][j] = c;
                        if (solveSudoku(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    if (!input.is_open()) {
        cerr << "Could not open input.txt" << endl;
        return 1;
    }
    if (!output.is_open()) {
        cerr << "Could not open output.txt" << endl;
        return 1;
    }

    vector<vector<char>> board(9, vector<char>(9));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            string val;
            input >> val;
            board[i][j] = (val == ".") ? '.' : val[0];
        }
    }

    if (solveSudoku(board)) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                output << board[i][j] << " ";
            output << endl;
        }
    } else {
        output << "No solution exists" << endl;
    }

    input.close();
    output.close();
    return 0;
}
