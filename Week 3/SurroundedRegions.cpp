// SURROUNDED REGIONS

/*  PROBLEM:
    Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
    A region is captured by flipping all 'O's into 'X's in that surrounded region.

    Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the 
    board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 
    'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells 
    connected horizontally or vertically.
*/

/*  EXAMPLE:

    Input:
    X X X X
    X O O X
    X X O X
    X O X X

    Output:
    X X X X
    X X X X
    X X X X
    X O X X      
*/

/*  APPROACH: Depth First Search
    1. Iterate over the row and column boundaries of the board until an 'O' is encountered.
    2. Perform depth-first-search using the DFS helper function every time an 'O' is encountered, from its position.
    3. Convert all of the encountered 'O's during the DFS operation to '#' in order to mark the cells that cannot be converted to 'X'.
    4. When the DFS has been completed, there are three elements remaining on the board:
        a. 'X' - Do not make any changes.
        b. 'O' - Convert to 'X', since they are not connected to any boundary and therefore can be converted to 'X'.
        c. '#' - Convert back to 'O' since they are connected to some boundary and therefore cannot be converted to 'X'.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;
 
class Solution {
public:
    // DFS Helper Function
    void check(vector<vector<char>>& board, int i, int j, int row, int col) {
        // Invalid conditions
        if(i < 0 || j < 0 || i >= row || j >= col || board[i][j] != 'O') 
            return;
        // Cells with the value '#' cannot be converted to 'O'
        board[i][j] = '#';
        // Check all adjacent cells
        check(board, i - 1, j, row, col);
        check(board, i + 1, j, row, col);
        check(board, i, j - 1, row, col);
        check(board, i, j + 1, row, col);
    }
    
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        // Empty board
        if(row == 0)
            return;
        int col = board[0].size();
        
        // Border column check
        for(int i = 0; i < row; i++) {
            // Move over the first column
            if(board[i][0] == 'O') {
                check(board, i, 0, row, col);
            }
            // Move over the last column
            if(board[i][col - 1] == 'O') {
                check(board, i, col - 1, row, col);
            }
        }
        
        // Border row check
        for(int j = 0; j < col; j++) {
            // Move over the first row
            if(board[0][j] == 'O') {
                check(board, 0, j, row, col);
            }
            // Move over the last row
            if(board[row - 1][j] == 'O') {
                check(board, row - 1, j, row, col);
            }
        }
        
        // Convert to 'X'
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                // If the cell has remained as 'O', we can convert to 'X'
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                // If the cell has changed to '#', we cannot convert to 'X'
                if(board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};