//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
void solve(vector<string> &ans, string s, int i, string tmp)
{
    string str;
    //base case
    if(i>= s.size())
    {
        ans.push_back(tmp);
        return ;
    }
    solve(ans, s, i+1, tmp+s[i]);
    tmp = tmp +" "+s[i];
    solve(ans, s, i+1, tmp);
    return;
    
}

    vector<string> permutation(string S){
       vector<string>ans;
       string tmp(1,S[0]);
       solve(ans, S, 1, tmp);
       sort(ans.begin(), ans.end());
       return ans;
    }
};

//{ Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}

// } Driver Code Ends