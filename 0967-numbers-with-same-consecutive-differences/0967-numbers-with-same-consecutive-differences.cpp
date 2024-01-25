class Solution {
public:
    void dfs(vector<string> &ans, string number, int n, int k){
        if(number.size() == n){
            ans.push_back(number);
            return;
        }
        
        for(char ch = '0'; ch <= '9'; ch++){
            if(number.size() == 0){
               for(char ch = '1'; ch <= '9'; ch++){
                   number.push_back(ch);
                   dfs(ans, number, n, k);
                   number.pop_back();
               } 
            }
            else{
                int diff = abs(ch - number.back());
                if(diff == k){
                    number.push_back(ch);
                   dfs(ans, number, n, k);
                   number.pop_back();
                }
            }
        }
        
        return;
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        string number = "";
        vector<string>ansStr;
        vector<int> ans;
        dfs(ansStr, number, n, k);
        
        set<int> st;
        for(auto &it : ansStr){
            st.insert(stoi(it));
        }
        for(auto &it : st){
            ans.push_back(it);
        }
        return ans;
    }
};