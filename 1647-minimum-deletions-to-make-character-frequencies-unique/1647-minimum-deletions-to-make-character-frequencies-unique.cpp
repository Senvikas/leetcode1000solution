class Solution {
public:
    int minDeletions(string s) {
        int a[26]={0},n=s.size(),c=0;
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            a[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(a[i]==0) continue;
            while(st.count(a[i])){
                a[i]--;
                c++;
            }
            if(a[i]) st.insert(a[i]);
        }
        return c;
    }
};