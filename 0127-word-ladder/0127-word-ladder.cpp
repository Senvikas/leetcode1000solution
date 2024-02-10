using psi = pair<string,int>;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        auto it = find(wordList.begin(), wordList.end(), endWord);
        if (it == wordList.end()) return 0; // endWord not found in wordList

        //Prepare a set of given words, to find in o(log n) time.
        set<string> st(wordList.begin(), wordList.end());

        queue<psi> q;
        q.push({beginWord, 1});

        while(!q.empty()){
            psi frontNode = q.front();
            q.pop();

            string originalw = frontNode.first;
            int len = frontNode.second;

            
            for(int i=0; i<originalw.size(); i++){
                auto word = originalw;

                for(auto ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;

                    if(word == endWord) return len + 1;

                    if(st.find(word) != st.end())
                    {
                        st.erase(word);
                        q.push({word, len+1});
                    }
                }

            }
            // st.erase(originalw);  // removing a bit above to resolve TLE
        }

        return 0; // Flow should not come till here.
    }
};