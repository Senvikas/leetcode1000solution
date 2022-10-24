class Solution
{
    public:
        int maxLength(vector<string> &arr)
        {

            int maxlen = 0;
            int n = arr.size();
            for(int i=0; i<(1<<n); i++){
                vector<bool> vis(26, 0);
                string s = "";
                bool flag = true;
                for(int j=0; j<n; j++){
                    if(i & (1<<j)){
                        for(char c : arr[j])
                        {
                            if(vis[c-'a']){flag = false; break;}
                            vis[c-'a'] = 1;
                        }
                        if(flag==false) continue;
                        s+=arr[j];
                        maxlen = max(maxlen, (int)s.length());
                    }
                }
            }

            return maxlen;
        }
};