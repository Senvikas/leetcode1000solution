import java.util.*;

class Solution {
    private int minSteps(List<Integer> level) {
        int n = level.size();
        List<int[]> eleInd = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            eleInd.add(new int[]{level.get(i), i});
        }

        eleInd.sort(Comparator.comparingInt(a -> a[0]));
        boolean[] vis = new boolean[n];
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || eleInd.get(i)[1] == i) continue;

            int cycle = 0, j = i;
            while (!vis[j]) {
                vis[j] = true;
                j = eleInd.get(j)[1];
                cycle++;
            }
            ans += cycle - 1;
        }

        return ans;
    }

    public int minimumOperations(TreeNode root) {
        if (root == null) return 0;

        int ans = 0;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);

        while (!q.isEmpty()) {
            int sz = q.size();
            List<Integer> level = new ArrayList<>();

            while (sz-- > 0) {
                TreeNode node = q.poll();
                level.add(node.val);

                if (node.left != null) q.add(node.left);
                if (node.right != null) q.add(node.right);
            }

            ans += minSteps(level);
        }

        return ans;
    }
}
