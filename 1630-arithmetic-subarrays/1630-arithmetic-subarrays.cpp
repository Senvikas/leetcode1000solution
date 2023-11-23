class Solution {
public:
    bool check(vector<int>& nums, int left, int right)
    {
        vector<int> t;
        int l=left;
        int r=right;

        while(l<=r)
        {
            t.push_back(nums[l++]);
        }

        sort(t.begin(),t.end());

        int diff=0;
        if(t.size()>=2)   diff=t[0]-t[1]; 

        int i=0;
        while(i+1<t.size())
        {
            if(t[i]-t[i+1]!=diff)   return false;
            i++;
        }
        return true;
    }
    void print(vector<int>& nums, int left, int right)
    {
        while(left<=right)
        {
            cout<<nums[left++];
        }
        cout<<endl;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>    result;

        int m=l.size();

        for(int i=0;i<m;i++)
        {
            if(check(nums, l[i], r[i]))    result.push_back(true);
            else    result.push_back(false);
        }

        return result;
    }
};