import java.util.*;

class Solution {
    public int maxTwoEvents(int[][] events) {
        List<int[]> time = new ArrayList<>();
        
        for (int[] event : events) {
            int st = event[0];
            int et = event[1];
            int val = event[2];
            
            time.add(new int[] {st, 0, val});
            time.add(new int[] {et, 1, val});
        }
        
        // Sort the timeline: by time, and for same time, prioritize end times (1) over start times (0)
        Collections.sort(time, (a, b) -> a[0] != b[0] ? Integer.compare(a[0], b[0]) : Integer.compare(a[1], b[1]));
        
        int prevMax = 0, ans = 0;
        
        for (int[] event : time) {
            int t = event[0];
            int end = event[1];
            int val = event[2];
            
            if (end == 1) {
                prevMax = Math.max(prevMax, val);
            } else {
                ans = Math.max(ans, prevMax + val);
            }
        }
        
        return ans;
    }
}
