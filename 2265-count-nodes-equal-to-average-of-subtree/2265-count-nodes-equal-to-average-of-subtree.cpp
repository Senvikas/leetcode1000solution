class Solution {
public:
    pair<int,int> solution(TreeNode* root ,int &ans){
        if(root==NULL) return {0,0};
        pair<int,int>left=solution(root->left, ans);
        pair<int,int>right=solution(root->right, ans);

        int count=left.first+right.first+1;
        int sum=left.second+right.second+root->val;
        if((sum/count)==root->val) ans++;
        return {count,sum};
       
    }
    int averageOfSubtree(TreeNode* root) {

        int count=0,sum=0,ans=0;
        solution(root,ans);
        return ans;
        
    }
};