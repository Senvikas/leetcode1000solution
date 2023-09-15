//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++



class Solution {
public:
    vector<vector<string>> findSequences(string b, string e, vector<string>& l) {
        set<string> st;
        for (auto word : l)
            st.insert(word);

        if (st.find(e) == st.end())
            return {};

        vector<vector<string>> ans;
        queue<vector<string>> q;
        q.push({b});

        bool found = false; // Flag to indicate if the target word is found

        while (!q.empty() && !found) {
            int size = q.size();
            unordered_set<string> visited; // Track visited words at this level

            for (int i = 0; i < size; i++) {
                auto v = q.front();
                q.pop();

                auto word = v.back();
                vector<string> words;

                for (int i = 0; i < word.size(); i++) {
                    auto nw = word;

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        nw[i] = ch;
                        if (st.find(nw) != st.end()) {
                            words.push_back(nw);
                        }
                        nw = word;
                    }
                }

                for (auto wordToAdd : words) {
                    vector<string> newSequence = v;
                    newSequence.push_back(wordToAdd);
                    
                    if (wordToAdd == e) {
                        ans.push_back(newSequence);
                        found = true; // Set the flag to stop when target word is found
                    }
                    q.push(newSequence);
                    visited.insert(wordToAdd);
                }
            }

            // Remove visited words from the set to avoid revisiting them
            for (const string& word : visited) {
                st.erase(word);
            }
        }
        return ans;
    }
};




//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

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
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends