class Solution {
public:
       
      vector<TreeNode*> solve(int n){
            vector<TreeNode*> res;
            if(n%2==0)return res;
             if(n==1) {
                 TreeNode* root= new TreeNode(0);
                 res.push_back(root);
                 return res;
             }
            for(int i=1;i<=n-2;i+=2){
                vector<TreeNode*> l= solve(i);
                vector<TreeNode*> r= solve(n-i-1);
                for(int k=0;k<l.size();k++){
                    for(int p=0;p<r.size();p++){
                        TreeNode* root=new TreeNode(0);
                        root->left=l[k];
                        root->right=r[p];
                        res.push_back(root);
                    }
                }
            }
          return res;
      }
    vector<TreeNode*> allPossibleFBT(int n) {
          
      
        return solve(n) ;
    }
};