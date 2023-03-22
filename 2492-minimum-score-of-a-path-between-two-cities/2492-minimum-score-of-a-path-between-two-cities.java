class Solution {
  public int minScore(int n, int[][] roads) {
    int vis[] = new int[n+1];
    Arrays.fill(vis, Integer.MAX_VALUE);

    ArrayList<int[]>[] g = new ArrayList[n+1];
    for(int i = 1; i != g.length; i++) g[i] = new ArrayList<>();
    for(int[]r : roads){
      g[r[0]].add(new int[]{r[1], r[2]});
      g[r[1]].add(new int[]{r[0], r[2]});
    }


    PriorityQueue<int[]> q = new PriorityQueue<>(n,(int[] o1, int[] o2) ->o1[0] - o2[0]);

    q.add(new int[]{Integer.MAX_VALUE-1,1});
    while(!q.isEmpty()){
      int[] t = q.poll();
      int dis = t[0], city = t[1];
      
      if(vis[city] <= dis) continue;
      vis[city] = dis;

      for(int[] next: g[city])
        q.add(new int[]{Math.min(dis,next[1]), next[0]});
    }

    return vis[n];    
  }
}