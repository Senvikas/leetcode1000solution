class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map< vector<int>, vector<string> > freq;
        
        for(auto str: strs){
            vector<int> fre(26, 0);
            for(auto ele: str){
                fre[ele - 'a']++;
            }
            freq[fre].push_back(str);
        }
        
        for(auto it=freq.begin(); it != freq.end(); it++){
            ans.push_back(it->second);
        }
        
        return ans;
    }
};