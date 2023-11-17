
public class Solution {
    public int[][] merge(int[][] intervals) {
        List<int[]> ans = new ArrayList<>();
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        int s = intervals[0][0];
        int e = intervals[0][1];

        for (int i = 0; i < intervals.length; i++) {
            int ns = intervals[i][0];
            int ne = intervals[i][1];

            // in range of previous interval
            if (ns <= e) {
                e = Math.max(e, ne);
            } else {
                ans.add(new int[]{s, e});
                s = ns;
                e = ne;
            }
        }
        ans.add(new int[]{s, e});


        int[][] result = new int[ans.size()][2];
        for (int i = 0; i < ans.size(); i++) {
            result[i] = ans.get(i);
        }

        return result;
    
    }
}
