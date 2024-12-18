class Solution {
    public int[] finalPrices(int[] prices) {
        int n = prices.length;
        int[] ans = prices.clone();
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && prices[stack.peek()] >= prices[i]) {
                ans[stack.pop()] -= prices[i];
            }
            stack.push(i);
        }

        return ans;
    }
}
