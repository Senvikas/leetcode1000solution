class Solution {
public:
    map<string, int> m ; 
    string cal(TreeNode* root , vector<TreeNode* > &ans)
    {
        if(root==NULL)
            return "" ;
        
        string l  = cal(root->left , ans) ; 
        string r  = cal(root->right , ans) ; 

        if( m[to_string(root->val)+"-"+l+"-"+r]==1)
            ans.push_back(root) ;
        
        m[to_string(root->val)+"-"+l+"-"+r]++ ;
        
        return to_string(root->val)+"-"+l+"-"+r ; 
            
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    
        vector<TreeNode*> ans ; 
        cal(root ,  ans  ) ; 
        return ans; 
    }
};