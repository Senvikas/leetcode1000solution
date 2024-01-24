class Solution {
    int f(TreeNode* curr, vector<bool> &freq){
        freq[curr->val] = freq[curr->val] ^ 1;
        int ret = 0;
        
        if(curr->left == NULL && curr->right == NULL){    // Leaf node
            int oddElements = count(freq.begin(), freq.end(), 1);   // No. of elements occured odd times
            if(oddElements <= 1)    ret = 1;   // If 0 or 1 element occurs odd time then palindrome possible
            else    ret = 0;
        }
        else{
            ret = ( curr->left ? f(curr->left, freq) : 0 ) + ( curr->right ? f(curr->right, freq) : 0 );
        }

        freq[curr->val] = freq[curr->val] ^ 1;  // Remove occurence (Backtrack)
        return ret;
    }

public:
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<bool> freq(10, 0);  // Count of occurence of elements in a path (Just need count of occurence is even or odd)
        return f(root, freq);
    }
};