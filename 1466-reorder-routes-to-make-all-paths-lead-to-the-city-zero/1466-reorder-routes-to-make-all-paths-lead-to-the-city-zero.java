class Solution {
    public int minReorder(int n, int[][] connections) {
        ArrayList<int[]>[] a = new ArrayList[n];
        for(int i=0;i<n;i++){
            a[i] = new ArrayList<>();
        }

        for(int[] x:connections){
            a[x[0]].add(new int[]{x[1],1});
            a[x[1]].add(new int[]{x[0],0}); 
        }

        boolean[] vis = new boolean[n];

        return dfs(a,0,vis);
    }

    private int dfs(ArrayList<int[]>[] a,int x,boolean[] vis){
        vis[x]=true;
        int change=0;
        for(int[] y:a[x]){
            if(!vis[y[0]]){
                change+=dfs(a,y[0],vis)+y[1];
            }
        }
        return change;
    }
}