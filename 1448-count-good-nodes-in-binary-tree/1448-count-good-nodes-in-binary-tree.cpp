class Solution {
public:
    int solve(TreeNode* root, int maxVal){
        //base case
        if(!root){
            return 0;
        }

        int thisNode = 0;
        if(root->val >= maxVal) {
            thisNode = 1;
            maxVal = root->val;
        }

        cout << "For node " << root->val << " " << thisNode << endl;

        int leftAns = solve(root->left, maxVal);
        int rightAns = solve(root->right, maxVal);

        return thisNode + leftAns + rightAns;
    }

    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        return solve(root, root->val);
    }
};
