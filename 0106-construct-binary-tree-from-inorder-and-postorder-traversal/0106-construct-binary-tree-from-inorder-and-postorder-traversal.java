class Solution {

    private Map<Integer,Integer> map = new HashMap<>();

    private int postIdx;

    public TreeNode buildTree(int[] inorder, int[] postorder) {
        int n = inorder.length;
        for(int i=0; i<n; i++)
            map.put(inorder[i],i);
        postIdx = n-1;
        return build(inorder, postorder, 0, n-1);
    }

    private TreeNode build(int[] inorder, int[] postorder, int l, int r){
        if(l > r) 
            return null;
        TreeNode root = new TreeNode(postorder[postIdx--]);
        int index = map.get(root.val);
        root.right = build(inorder, postorder, index+1, r);
        root.left  = build(inorder, postorder, l, index-1);
        return root;
    }
}