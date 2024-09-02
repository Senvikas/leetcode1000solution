class Solution {
public:
    void twoSum(vector<int> &nums, int t, int s, int e, set<vector<int>> &st){
        // int s = 0, e = nums.size()-1;
            int indToLeave = s-1;
        while(s < e){
            // if(s == indToLeave){
            //     s++; continue;
            // }else if(e == indToLeave){
            //     e--; continue;
            // }

            int sum = nums[s] + nums[e];

            if(sum == t){
                vector<int> triplet = {nums[s], nums[e], nums[indToLeave]};
                sort(triplet.begin(), triplet.end());
                st.insert(triplet);
                s++; e--;
            }

            else if(sum > t) e--;
            else s++;


        }
        return;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            int target = -nums[i];
            twoSum(nums, target, i+1, n-1, st);
        }

        vector<vector<int>> ans;
        while(!st.empty()){
            auto vec = *(st.begin());
            st.erase(vec);
            ans.push_back(vec);
        }


        return ans;
    }
};