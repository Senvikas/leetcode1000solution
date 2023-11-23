public class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, Comparator.comparingInt(point -> point[0]));
        int l = points[0][0], h = points[0][1];
        int cnt = 1;
        for(int i = 1; i < points.length; i++) {
            if(points[i][0] <= h) {
                l = points[i][0];
                h = Math.min(points[i][1], h);
            } else {
                cnt++;
                l = points[i][0];
                h = points[i][1];
            }
        }
        return cnt;
    }
}
