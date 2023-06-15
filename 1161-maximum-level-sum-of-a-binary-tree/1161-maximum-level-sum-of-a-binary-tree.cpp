class Solution {
public:
    
    int bfs(TreeNode* root){
        int ans=1;
        if(!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int sum=-10e5;//sum at curr level
        int presum=root->val;  //sum at previous level
        int level=1;  //current level
        while(!q.empty()){
            TreeNode* t=q.front();
            q.pop();
            if(t==NULL){
                if(sum>presum){
                    presum=sum;
                    ans=level;
                }
                sum=0;
                level++;
                if(q.size()>0)
                    q.push(NULL);
            }
            else{
                if(t->left)     q.push(t->left);
                if(t->right)    q.push(t->right);
                sum+=t->val;
            }
        }
        return ans;
    }

    int maxLevelSum(TreeNode* root) {
        return bfs(root);
    }
};