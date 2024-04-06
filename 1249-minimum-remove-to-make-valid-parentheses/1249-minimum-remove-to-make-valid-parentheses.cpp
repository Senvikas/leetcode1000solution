class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> st;
        int n = s.length();

        for(int i=0; i<n; i++){
            if(!st.empty() && st.top().first == '(' && s[i]==')'){
                st.pop();
                continue;
            }
            if(s[i]=='(' || s[i]==')'){
                st.push({s[i],i});
            }
        }

        cout<<st.size();
        while(!st.empty()){
            s[st.top().second]='*';
            st.pop();
        }

        string ans="";

        for(int i=0;i<n;i++){
            if(s[i]!='*'){
                ans+=s[i];
            }
        }

        return ans;
    }
};