class Solution {
    vector<int> helper(TreeNode* root, int level){
        if(!root) return {-1,level};
        vector<int> left;
        if(root->left){
           left = helper(root->left,level+1);
        } else{
            left = {root->val,level};
        }
            
        vector<int> right;
        if(root->right) {
            right =  helper(root->right,level+1) ;
        }else {
             right = {root->val,level};
         }
        return left[1]>=right[1] ?left:right;

    }
public:
    int findBottomLeftValue(TreeNode* root) {
        vector<int> res = helper(root, 0);
        return res[0];
    }
};