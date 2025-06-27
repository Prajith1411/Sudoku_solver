# Sudoku_solver
The idea is to use **backtracking** and recursively generate all possible configurations of numbers from 1 to 9 to fill the empty cells of the board. To do so, for every unassigned cell, fill the cell with a number from 1 to 9 one by one. After filling the unassigned cell check if the board is valid or not. If valid, move to the next cell else backtrack for other cases. 

To check if it is safe to place value number in the cell of board[i][j], iterate through all the columns of row i, rows of column j and the 3*3 matrix containing   cell (i, j) and check if they already has value number, if so return false, else return true.

**Time Complexity**: O(9(n ^ 2)), in the worst case, for each cell in the n2 board, we have 9 possible numbers.

**Space Complexity**: O(1), since we are refilling the given board itself, there is no extra space required, so constant space complexity.
