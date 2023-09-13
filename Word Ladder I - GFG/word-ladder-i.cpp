//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    int wordLadderLength(string s, string t, vector<string>& l) {
        unordered_set<string> st;
        for (auto it : l) st.insert(it);
        
        if (st.find(t) == st.end()) return 0; // If target word 't' is not in the word list, return 0.
        
        queue<pair<string, int>> q;
        q.push({s, 1});
        
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            string w = p.first;
            int cnt = p.second;
            
            for (int i = 0; i < w.size(); i++) {
                string nw = w;
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    nw[i] = ch;
                    
                    if (nw == t) return cnt + 1;
                    
                    if (st.find(nw) != st.end()) {
                        q.push({nw, cnt + 1});
                        st.erase(nw); // Remove the word from the set to avoid revisiting.
                    }
                }
            }
        }
        
        return 0;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends