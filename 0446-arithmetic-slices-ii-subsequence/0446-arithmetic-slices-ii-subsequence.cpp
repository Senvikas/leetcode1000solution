class Solution {
public:
bool check(vector<int>arr)
{
    int n = arr.size();
    if(arr.size() <= 2) return false;
    int diff = arr[1]-arr[0];
    for(int i=2; i<n; i++)
    {
        int newdiff = arr[i]-arr[i-1];
        if(newdiff != diff) return false;
    }
    return true;
}
void printSubsequences(vector<int>arr, int index,vector<int> &subarr,int n, int &ans)
{
    if (index == n)
    {
        if(check(subarr))ans++; 
        return;
    }
    else
    {
       //pick the current index into the subsequence.
        subarr.push_back(arr[index]);
       
 
         printSubsequences(arr, index + 1, subarr,n, ans);
 
         
        subarr.pop_back();
       
      //not picking the element into the subsequence.
        printSubsequences(arr, index + 1, subarr,n, ans);
    }
    
}
    int numberOfArithmeticSlices(vector<int>& nums) {
    /*  N*2^N Solution: TLE
        vector<int>vec;
        int n=nums.size();
        cout<<n<<endl;
        int ans = 0;
        printSubsequences(nums, 0, vec, n, ans);
        return ans;          */ 
        //intution hashing: common diff:number of aps with ele>2 at that point, use a map of int(cd) & vector(ele)
        
        int n = nums.size();
        
        // declare a dp array of unordered_map
        
        vector<unordered_map<long, long>> dp(n + 1);
        
        // dp[i][diff] will store the no. of subsequence with common difference of diff, till ith index
        
        long ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = i - 1; j >= 0; j--)
            {
                long cd = (long) nums[i] - long(nums[j]);
                
                //compute the ans for ith index
                ans += dp[j][cd];
                
                // update dp[i][cd]
                
                dp[i][cd] += dp[j][cd];
                
                dp[i][cd]++;
            }
        }
        
        return ans;

    }
};