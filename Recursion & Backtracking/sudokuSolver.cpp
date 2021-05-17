//https://leetcode.com/problems/sudoku-solver/

class Solution {
public:
    bool is_safe(int row, int col, char val, vector<vector<char>>& board) {
        
        //check in row
        for(int c = 0; c < 9; c++) {
            if(board[row][c] == val)
                return false;
        }
        
        //check in col
        for(int r = 0; r < 9; r++) {
            if(board[r][col] == val)
                return false;
        }
        
        //check in subgrid
        int x = row / 3, y = col / 3;
        for(int i = 3 * x; i < 3 * x + 3; i++) {
            for(int j = 3 * y; j < 3 * y + 3; j++) {
                if(board[i][j] == val)
                    return false;
            }
        }
        
        return true;
    }
    
    bool sudokuHelper(int x, int y, vector<vector<char>> &board) {
        
        //we are done solving
        if(x == 9) return true;
        
        if(board[x][y] == '.') {
            for(int i = 1; i <= 9; i++) {
                
                //current value
                char val = '0' + i;
                
                //check if this value is safe
                if(is_safe(x, y, val, board)) {
                    board[x][y] = val;
                    
                    //check if this value will cause any conflict in future
                    if(sudokuHelper((y == 8 ? x + 1 : x), (y + 1) % 9, board)) 
                        return true;
                    
                    //reset the cell
                    board[x][y] = '.';
                }
            }
        }
        else return sudokuHelper((y == 8 ? x + 1 : x), (y + 1) % 9, board);
        
        //if we could not find any value for the current position 
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        sudokuHelper(0, 0, board);
    }
};
