class Solution
{
    public:
        bool isToeplitzMatrix(vector<vector < int>> &matrix)
        {

            int n = matrix.size();
            int m = matrix[0].size();

            for (int i = 0; i < n; i++)
            {
                int k = i + 1;
                int j = 1;
                int ele = matrix[i][0];
                while (k < n && j < m)
                {
                    if (matrix[k][j] == ele)
                    {
                        k++;
                        j++;
                        continue;
                    }
                    else
                        return false;
                }
            }

            for (int j = 0; j < m; j++)
            {
                int k = j + 1;
                int i = 1;
                int ele = matrix[0][j];
                while (k < m && i < n)
                {
                    if (matrix[i][k] == ele)
                    {
                        k++;
                        i++;
                        continue;
                    }
                    else
                        return false;
                }
            }
            return true;
        }
};