class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ret;
        stack<TreeNode*> target_path;
        bool found = find_target_path(root,target,target_path);

        //find distance k nodes in target's subtree
        find_distance_k_nodes(target_path.top(),k,ret);
        //cout<<target_path.top()->val<<endl;
        target_path.pop();

        //find distance k nodes in target's ancestor
        int count = 1;
        while(!target_path.empty()){
            TreeNode* ancestor = target_path.top();
            target_path.pop();
            if(count == k){
                ret.push_back(ancestor->val);
                break;
            }
            if(ancestor->left == target){
                find_distance_k_nodes(ancestor->right,k-count-1,ret);
            }else{
                find_distance_k_nodes(ancestor->left,k-count-1,ret);
            }
            target = ancestor;
            count++;
        }

        return ret;
    }
    
    bool find_target_path(TreeNode* root, TreeNode* target, stack<TreeNode*>& target_path){
        if(root == nullptr) return false;
        if(root == target){
            target_path.push(root);
            return true;
        }
        target_path.push(root);
        if(find_target_path(root->left,target,target_path)){
            return true;
        }
        if(find_target_path(root->right,target,target_path)){
            return true;
        }
        target_path.pop();
        return false;
    }

    void find_distance_k_nodes(TreeNode* root, int k, vector<int>& ret){
        if(root == nullptr) return;
        if(k == 0){
            ret.push_back(root->val);
            return;
        }
        find_distance_k_nodes(root->left,k-1,ret);
        find_distance_k_nodes(root->right,k-1,ret);
    }

};