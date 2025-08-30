class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row checks
        for(int j = 0; j<9; j++)
        {
            vector<int> freq(10, 0);
            for(int i = 0; i < 9; i++)
            {
                if(board[i][j] == '.')
                    continue;
                int num = board[i][j] - '0';
                if(freq[num])
                    return false;
                freq[num] = 1;
            }
        }

        // col checks
        for(int i = 0; i<9; i++)
        {
            vector<int> freq(10, 0);
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.')
                    continue;
                int num = board[i][j] - '0';
                if(freq[num])
                    return false;
                freq[num] = 1;
            }
        }
        

        for(int row = 0; row < 9; row+=3)
        {
            for(int col = 0; col < 9; col+=3)
            {
                vector<int> freq(10, 0);
                for(int i=row; i<row+3; i++)
                {
                    for(int j=col; j<col+3; j++)
                    {
                        if(board[i][j] == '.')
                            continue;
                        int num = board[i][j] - '0';
                        if(freq[num])
                            return false;
                        freq[num] = 1;
                    }
                }
            }
        }

        return true;
    }
};