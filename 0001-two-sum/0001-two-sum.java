class Solution {
    public int[] twoSum(int[] nums, int target) {
      Map<Integer,Integer> mp = new HashMap<>();
        for(int i=0; i<nums.length; i++){
            int req = target - nums[i];
            if(mp.containsKey(req)){
                int []ans = {i, mp.get(req)};
                return ans;
            }
            mp.put(nums[i], i);
        }
        return new int [0];
    }
}