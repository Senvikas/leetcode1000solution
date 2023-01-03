//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:




vector<vector < string>> findLadders(string b, string e, vector<string> &l)
        {
            unordered_set<string> given(l.begin(), l.end());
            int n = b.length();
            queue<vector < string>> q;
            q.push({ b });
            int level = 0;
            vector<string> used;
            used.push_back(b);
            vector<vector < string>> ans;

            while (!q.empty())
            {
                vector<string> v = q.front();
                q.pop();
               	//erase the already used word from the set
                if (level < v.size())
                {
                    level++;
                    for (auto s: used)
                        given.erase(s);
                }
                auto word = v.back();
                if (word == e)
                {
                    if (ans.size() == 0) ans.push_back(v);
                    else if (ans[0].size() == v.size()) ans.push_back(v);
                }
                for (int i = 0; i < n; i++)
                {
                    char original = word[i];
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        word[i] = c;
                        if (given.count(word) > 0)
                        {
                            v.push_back(word);
                            q.push(v);
                            used.push_back(word);
                            v.pop_back();
                        }
                    }
                    word[i] = original;
                }
            }
            return ans;
        }





    vector<vector<string>> findSequences(string s, string t, vector<string>& l) {
        return findLadders(s, t, l);
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