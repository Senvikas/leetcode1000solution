/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> modes;
        unordered_map<int, int> mp;
        queue<TreeNode* > q;
        q.push(root);
        int mode = 0;
        while(!q.empty()){
            if(q.front()!=NULL) mp[q.front()->val]++;
            if(mode < mp[q.front()->val]) mode = mp[q.front()->val];
            if(q.front()->left!=NULL) q.push(q.front()->left);
            if(q.front()->right!=NULL) q.push(q.front()->right);
            q.pop();
        }
        for(auto it:mp){
            if(it.second==mode) modes.push_back(it.first);
        }
        return modes;
    }
};