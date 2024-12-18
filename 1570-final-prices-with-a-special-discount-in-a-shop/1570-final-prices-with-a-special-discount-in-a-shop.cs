public class Solution {
    public int[] FinalPrices(int[] prices) {
        int n = prices.Length;
        int[] ans = (int[])prices.Clone();
        Stack<int> stack = new Stack<int>();

        for (int i = 0; i < n; i++) {
            while (stack.Count > 0 && prices[stack.Peek()] >= prices[i]) {
                ans[stack.Pop()] -= prices[i];
            }
            stack.Push(i);
        }

        return ans;
    }
}
