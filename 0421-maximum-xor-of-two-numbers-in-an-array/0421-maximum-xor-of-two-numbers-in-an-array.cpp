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
    int findMaximumXOR(vector<int>& nums) {
        Trie* trie = new Trie();
        for(auto ele: nums) trie->insert(ele);
        
        int maxi = 0;
        for(auto &ele: nums){
            maxi = max(maxi, trie->getMax(ele));
        }
        
        return maxi;
    }
};