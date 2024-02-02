class Node{
    private:
        Node* links[2];
    public:
        bool childPresent(int bit){
            return links[bit] != NULL;
        }
    
        void put(int bit, Node* node){
            links[bit] = node;
        }
    
        Node* get(int bit){
            return links[bit];
        }
};

class Trie{
    private:
        Node* root;
    public:
        Trie(){
            root = new Node();
        }
    
        void insert(int num){
            Node* node = root;
            for(int bit=31; bit>=0; bit--){
                int bitt = (num>>bit) & 1;
                
                bool present = node->childPresent(bitt);
                if(!present){
                    node->put(bitt, new Node());
                }
                
                node = node->get(bitt);
            }
        }
    
        int getMax(int num){
            Node* node = root;
            int maxi = 0;
            
            for(int bit=31; bit>=0; bit--){
                int bitt = (num >> bit) & 1;
                
                int toGetMax = 1-bitt;
                
                bool present = node->childPresent(toGetMax);
                if(present){
                    maxi = maxi | 1<<bit;
                    node = node->get(toGetMax);
                }else{
                    node = node->get(bitt);
                }
            }
            return maxi;
        }
};

class Solution {
public:
        vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector< pair<int, pair<int,int>>> oq;
        int n = queries.size();

        for(int ind = 0; ind < n; ind++){
            auto v = queries[ind];
            oq.push_back({v[1], {v[0], ind}});
        }

        sort(oq.begin(), oq.end());
        sort(nums.begin(), nums.end());

        vector<int>ans(n, -1);

        Trie* trie = new Trie();

        int ind = 0;
        for(int i = 0; i < n; i++) {
            int mi = oq[i].first;
            int xi = oq[i].second.first;
            int qi = oq[i].second.second;

            // Add numbers to the trie until the current maximum
            while (ind < nums.size() && nums[ind] <= mi) {
                trie->insert(nums[ind]);
                ind++;
            }

            if (ind != 0) ans[qi] = trie->getMax(xi);
        }
        return ans;
    }
};