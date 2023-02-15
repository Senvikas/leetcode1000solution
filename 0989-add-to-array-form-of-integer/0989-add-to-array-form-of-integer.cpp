class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) 
    {
        vector<int> ans;
        int c = 0;

        for(int i=num.size()-1; i>=0; i--)
        {
            int sum = num[i] + (k%10) + c;
            ans.push_back(sum%10);
            c = sum/10;
            k = k/10;

        }
        
        while(k != 0)       //if length of k is more than the array length
        {
            int sum = (k%10) + c;
            ans.push_back(sum%10);
            c = sum/10;
            k = k/10;

        }

        if(c == 1)      //adding the last carry if any
            ans.push_back(c);

        reverse(ans.begin(), ans.end());

        return ans;
        
    }
};