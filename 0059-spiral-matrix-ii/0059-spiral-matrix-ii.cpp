class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> arr(n, vector<int>(n));
        int startingCol=0, endingCol=n-1;
        int startingRow=0, endingRow=n-1, cnt=1;
        //startingCol<endingCol && startingRow<endingRow &&
        while(startingCol<=endingCol && startingRow<=endingRow &&cnt<=n*n)
        {
            //first row(col fixed)
            for(int index=startingCol; index<=endingCol; index++)
            {
                arr[startingRow][index] = cnt;
                cnt++;
            }
            startingRow++;
            
        //ending col(row fixed- endingrow)(startingRow se ending row tak)
            for(int index = startingRow; index<=endingRow; index++)
            {
                arr[index][endingCol] = cnt;
                cnt++;
            }
            endingCol--;
            
        //ending row(col fixed)(ending col se starting col tak)
            for(int index = endingCol; index>=startingCol; index--)
            {
                arr[endingRow][index] = cnt;
                cnt++;
            }
            endingRow--;
            
        //starting col(row fixed)(endign row se starting row tak)
            for(int index = endingRow; index>=startingRow; index--)
            {
                arr[index][startingCol] = cnt; 
                cnt++;
            }
            startingCol++;
        }
        return arr;
    }
};