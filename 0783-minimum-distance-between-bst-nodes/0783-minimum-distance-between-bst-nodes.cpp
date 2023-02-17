class Solution {
public:

   
   void dfs(TreeNode *root,vector<int> &ans){

      if(root==NULL) return;

      dfs(root->left,ans);
      ans.push_back(root->val);
      dfs(root->right,ans);

   }


    int minDiffInBST(TreeNode* root) {
        //property BST inorder always give an ascending data:
        vector<int> ans;
        dfs(root,ans);

        int mini = INT_MAX;
        for(int i=1;i<ans.size();++i){
            mini = min(mini,ans[i]-ans[i-1]);
        }
        return mini;
    }
};