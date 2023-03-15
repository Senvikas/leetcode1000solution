/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isCompleteTree(TreeNode root) {
        boolean end = false;
        Queue <TreeNode> queue = new LinkedList();
        queue.offer(root);

        while(!queue.isEmpty()){
            TreeNode cur_node = queue.poll();
            if(cur_node == null){
                end = true;
            }else{
                if(end) return false;
                queue.offer(cur_node.left);
                queue.offer(cur_node.right);
            }
        }

        return true;
    }
}