class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        map<int , int> mp;
        for(int i=0; i<n; i++)
            mp[arr[i]]++;

        set<int>st;
        for(auto it: mp)
            st.insert(it.second);

        return st.size() == mp.size();
    }
};