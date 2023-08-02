class Solution {
public:
    void solve(int ind,vector<int>& arr, vector<vector<int>> &ans,vector<int>&tmp)
    {
        //base case
        if(ind == arr.size())
        {ans.push_back(tmp);
         return ;
        }
        for(int i=ind; i<arr.size(); i++)
        {
            swap(arr[i], arr[ind]);
            tmp.push_back(arr[ind]);
            solve(ind+1, arr, ans, tmp);
            tmp.pop_back();
            swap(arr[i], arr[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        solve(0, nums, ans, tmp);
        return ans;
        
    }
};