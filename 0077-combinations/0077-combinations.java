class Solution {
    private void solve(List<List<Integer>> ans, List<Integer> path, int n, int k, int st) {
        if (path.size() >= k) {
            ans.add(new ArrayList<>(path)); // Add a copy of path to ans
            return;
        }
        for (int i = st; i <= n; i++) {
            path.add(i);
            solve(ans, path, n, k, i + 1);
            path.remove(path.size() - 1);
        }
    }

    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> ans = new ArrayList<>();
        solve(ans, new ArrayList<>(), n, k, 1);
        return ans;
    }
}
