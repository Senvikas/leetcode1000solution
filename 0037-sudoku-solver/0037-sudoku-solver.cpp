class Solution {
public:
    bool isSafe(char num, int row, int col, vector<vector<char>>& board)
    {
        // row and col check
        for(int i=0; i<9; i++)
        {
            if(board[row][i] == num || board[i][col] == num)
                return false;
        }

        // 3*3 grid check
        int srow = (row/3)*3, scol = (col/3)*3;
        for(int i=srow; i<srow+3; i++)
        {
            for(int j=scol; j<scol+3; j++)
            {
                if(board[i][j] == num)
                    return false;
            }
        }

        return true;
    }

    bool solve(int row, int col, vector<vector<char>>& board)
    {
        // if all the cols are filled
        if(col == 9)
        {
            return solve(row+1, 0, board);
        }

        // if all the rows are filled
        if(row == 9)
            return true;

        // if empty cell
        if(board[row][col] == '.')
        {
            for(char num = '1'; num <= '9'; num++)
            {
                bool safe = isSafe(num, row, col, board);
                if(safe)
                {
                    board[row][col] = num;

                    if(solve(row, col+1, board) == true)
                        return true;

                    board[row][col] = '.';
                }
            }

            // khali tha and you tried all the numbers and sudoku is not filled
            return false;
        }

        return solve(row, col + 1, board); // move to the next cell
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(0, 0, board);
        return;
    }
};