class Solution {
    public void solve(List<List<Integer>> ans, List<Integer> current, int[] nums, boolean[] freq){
        if(current.size() == nums.length){
            ans.add(new ArrayList(current));
            return;
        }
        for(int i=0; i<nums.length; i++){
            if(freq[i] == false){
                freq[i] = true;
                current.add(nums[i]);
                solve(ans, current, nums, freq);
                current.remove(current.size()-1);
                freq[i] = false;
            }
        }
        return;
    }
    
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> current = new ArrayList<>();
        boolean freq[] = new boolean[nums.length];
        solve(ans, current, nums, freq);
        return ans;
    }
}