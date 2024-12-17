class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);

        for(auto &ch: s)
        {
            freq[ch - 'a']++;
        }

        priority_queue< pair<char, int>> pq;
        for(int i=25; i>=0; i--)
        {
            if(freq[i] == 0)
                continue;
            
            pq.push({'a'+i, freq[i]});
        }

        string ans = "";
        while(!pq.empty())
        {
            auto [ch1, cnt1] = pq.top();
            pq.pop();

            int addCnt = min(repeatLimit, cnt1);
            ans.append(addCnt, ch1);

            cnt1 -= addCnt;

            if(cnt1 > 0 && pq.empty() == false)
            {
                auto [ch2, cnt2] = pq.top();
                pq.pop();

                ans.push_back(ch2);
                cnt2--;

                pq.push({ch1, cnt1});
                if(cnt2 > 0)
                    pq.push({ch2, cnt2});
            }
        }

        return ans;
    }
};