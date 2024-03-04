/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        unordered_map<Node*, Node*> mp;
        auto tmp = head;
        
        while(tmp){
            Node* copyNode = new Node(tmp->val);
            mp[tmp] = copyNode;
            tmp = tmp->next;
        }
        
        Node* dummyNode = new Node(-1);
        Node* tmpd = dummyNode;
        tmp = head;
        
        while(tmp){
            Node* copyNode = mp[tmp];
            Node* tmpRan = tmp->random;
            
            Node* copyRan = nullptr; 
            if(tmpRan) copyRan = mp[tmpRan];
            
            tmpd->next = copyNode;
            copyNode->random = copyRan;
            
            tmpd = tmpd->next;
            tmp = tmp->next;
        }
        
        return dummyNode->next;
        
    }
};