class Solution {

    public static int bs(int low, int high, int[] arr, long success, int spell) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long product = ((long) spell) * arr[mid];
            if (product >= success) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    public static int[] successfulPairs(int[] spells, int[] potions, long success) {
        Arrays.sort(potions);
        int[] ans = new int[spells.length];
        for (int i = 0; i < spells.length; i++) {
            int x = bs(0, potions.length - 1, potions, success, spells[i]);
            ans[i] = potions.length - x;
        }
        return ans;
    }
}
