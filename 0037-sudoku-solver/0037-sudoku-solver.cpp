class Solution {
public:
    bool isSafe(vector<vector<char>> &board, int row, int col, int num){
        //check for row and column
        for(int i=0; i<9; i++){
            if(board[row][i] == char(num+'0')) return false;
            if(board[i][col] == char(num+'0')) return false;
        }
        //check for 3*3 grid
        int sr = (row/3) * 3;
        int sc = (col/3) * 3;
        
        for(int i=sr; i<sr+3; i++){
            for(int j=sc; j<sc+3; j++){
                if(board[i][j] == char(num+'0')) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>> &board, int row, int col){
    if(row >= 9) return true;
    if(col >= 9) return solve(board, row+1, 0); // Added return statement
    
    //if any cell is empty, fill; else skip
    
    if(board[row][col] == '.'){
        //try filling out this cell with any number from 1-9
        for(int num = 1; num < 10; num++){
            if(isSafe(board, row, col, num)){
                board[row][col] = char(num + '0');
                if(solve(board, row, col+1)) return true;
                board[row][col] = '.';
            }
        }
    }
    else{
        return solve(board, row, col+1);
    }
        
    return false;
}

    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};