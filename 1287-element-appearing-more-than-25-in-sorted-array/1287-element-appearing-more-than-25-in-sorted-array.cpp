class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto it:arr){
            mp[it]++;
        }
        for(auto it:mp){
            if(it.second > 0.25 * arr.size()){
                return it.first;
            }
        }
        return -1;
    }
};