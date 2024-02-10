/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void deepClone(Node* node, Node* ans, unordered_map<int,Node*> &presentNodes){
        if(node == NULL || presentNodes.find(node->val) != presentNodes.end()) return;
        
        presentNodes[node->val] = ans;
        
        for(Node* adjNode: node->neighbors){
            if(ans->neighbors.empty()) ans->neighbors = vector<Node*>();
            
            if(presentNodes.find(adjNode->val) == presentNodes.end()){
                ans->neighbors.push_back(new Node(adjNode->val));
                
                deepClone(adjNode, ans->neighbors.back(), presentNodes);
            }else{
                ans->neighbors.push_back(presentNodes[adjNode->val]);
            }
            
        }
        
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL) return node;
        
        Node* ans = new Node(node->val);
        
        unordered_map<int,Node*> presentNodes;
        
        deepClone(node, ans, presentNodes);
        
        return ans;
    }
};