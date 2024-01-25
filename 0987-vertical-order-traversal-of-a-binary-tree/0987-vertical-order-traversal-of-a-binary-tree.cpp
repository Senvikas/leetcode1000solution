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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        
        map<int, map<int, vector<int> > >nodes;  // hd, level, list
        queue<pair<TreeNode*, pair<int,int>>> q;      // root, {horizontal dis, level}
        q.push({root, {0, 0}});
        
        while(!q.empty()){
            auto frontNode = q.front();
            q.pop();
            
            auto node = frontNode.first;
            int hd = frontNode.second.first;
            int level = frontNode.second.second;
            
            nodes[hd][level].push_back(node->val);
            
            if(node->left) q.push({node->left, {hd-1, level+1}});
            if(node->right) q.push({node->right, {hd+1, level+1}});
        }
        // cout << typeid(nodes).name() << endl;
        // cout << typeid(nodes.second).name() << endl;
        // cout << typeid(nodes.second.second).name() << endl;
        
        for (auto it : nodes) {
            vector<int> levelOrder;
            for (auto itr : it.second) {
                auto list = itr.second;
                sort(list.begin(), list.end());
                levelOrder.insert(levelOrder.end(), list.begin(), list.end());
            }
            ans.push_back(levelOrder);
        }
        return ans;
    }
};