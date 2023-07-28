class Solution {
    map<pair<int, int>, int> memo;
    vector<int> arr;
    
    int solve(int L, int R, bool turn) {
        if (memo.find({L, R}) != end(memo))
            return memo[{L, R}];
        
        int difL = turn ? arr[L] : -arr[L];
        int difR = turn ? arr[R] : -arr[R];
        
        if (L == R) return difL;
        
        int chooseL = solve(L+1, R, !turn) + difL;
        int chooseR = solve(L, R-1, !turn) + difR;
        
        if (turn) return memo[{L, R}] = max(chooseL, chooseR);
        else      return memo[{L, R}] = min(chooseL, chooseR);
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        arr = nums;
        return solve(0, size(arr)-1, 1) >= 0;
    }
};