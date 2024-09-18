class Node {
public:
    Node* links[2];

    Node() {
        links[0] = nullptr;
        links[1] = nullptr;
    }

    bool containsBit(int bit) { return (links[bit] != nullptr); }

    Node* get(int bit) { return links[bit]; }

    void put(int bit, Node* node) { links[bit] = node; }
};

class Trie {
private:
    Node* root;

public:
    Trie() { root = new Node(); }

    void insert(int num) {
        int mask = 1 << 31;
        Node* node = root;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1; // (num & mask) ? 1 : 0;

            if (!node->containsBit(bit)) {
                node->put(bit, new Node());
            }

            node = node->get(bit);
            mask >>= 1;
        }
    }

    int findMaximumXOR(int num) {
        int mask = 1 << 31, ans = 0;
        Node* node = root;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1; //(num & mask) ? 1 : 0;

            if (node->containsBit(!bit)) {
                ans |= (1 << i);
                node = node->get(!bit);
            } else {
                node = node->get(bit);
            }

            mask >>= 1; // Shift the mask to the right
        }
        return ans;
    }
};

class Solution {
private:
    Trie trie;

public:
    static bool comp(pair<vector<int>, int>& a, pair<vector<int>, int>& b) {
        return a.first[1] < b.first[1];
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& qs) {
        int nq = qs.size(), n = nums.size();

        vector<int> ans(nq);
        sort(nums.begin(), nums.end());

        vector<pair<vector<int>, int>> qInd;

        // Populate qInd with pairs of query vectors and their indices
        for (int i = 0; i < nq; i++) {
            qInd.push_back({qs[i], i});
        }

        // Sort qInd using the custom comparator
        sort(qInd.begin(), qInd.end(), comp);

        int alreadyInserted = -1;

        for (auto qrp : qInd) { // qrp = qr pari -> qr, ind
            int ind = qrp.second;
            int x = qrp.first[0];
            int m = qrp.first[1];

            // vector<int> toXorWith;
            // for(int i=0; i<n; i++){
            //     if(nums[i] <= m) toXorWith.push_back(nums[i]);
            //     else break;
            // }

            int upperInd =
                upper_bound(nums.begin(), nums.end(), m) - nums.begin();

            int maxXor = -1;

            if (upperInd > 0) {
                // trie.insert(nums);
                for (int i = alreadyInserted + 1; i < upperInd && i < n; i++) {
                    int ele = nums[i];
                    trie.insert(ele);
                }
                
                alreadyInserted = upperInd-1;

                int xorr = trie.findMaximumXOR(x);
                maxXor = max(maxXor, xorr);
            }

            ans[ind] = maxXor;
        }

        return ans;
    }
};