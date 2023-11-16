class Solution {
public:
    string say(string str){
        string ans = "";
        int n = str.size();
        for(int i=0; i<n; i++){
            int cnt = 1, j = i+1;
            while(j < n && str[j] == str[j-1]){
                j++; cnt++; i++;
            }
            ans += char('0' + cnt);
            ans += str[i];
            
        }
        return ans;
    }
    string cs(int n){
        if(n==1) return "1";
        string ans = cs(n-1);
        return say(ans);
    }
    string countAndSay(int n) {
        return cs(n);
    }
};

