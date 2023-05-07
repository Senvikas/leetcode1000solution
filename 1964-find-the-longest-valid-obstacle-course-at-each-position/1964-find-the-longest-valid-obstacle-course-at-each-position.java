class Solution {
    public int[] longestObstacleCourseAtEachPosition(int[] obstacles) {
        int n=obstacles.length;
        int ans[]=new int[n];
        ArrayList<Integer> li=new ArrayList<>();
        for(int i=0;i<n;i++){
            int val=obstacles[i];

            if(li.size()==0 || li.get(li.size()-1)<=val){
                li.add(val);
                ans[i]=li.size();
            }else{
                int up=helper(li,val);
                li.set(up,val);
                ans[i]=up+1;
            }
        }
        return ans;
    }
    public int helper(ArrayList<Integer> li,int val){
        int i=0;
        int j=li.size()-1;
        int ans=-1;

        while(i<=j){
            int mid=(i+j)/2;
            if(li.get(mid)>val){
                ans=mid;
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        return ans;
    }
}