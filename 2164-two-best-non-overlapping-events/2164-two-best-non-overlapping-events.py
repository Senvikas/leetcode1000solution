class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        time = []
        
        for event in events:
            st, et, val = event
            time.append((st, 0, val))  # 0 indicates start
            time.append((et, 1, val))  # 1 indicates end
        
        # Sort the timeline: by time, and for the same time, prioritize end times (1) over start times (0)
        time.sort(key=lambda x: (x[0], x[1]))
        
        prev_max = 0
        ans = 0
        
        for t, is_end, val in time:
            if is_end:  # If it's an end time
                prev_max = max(prev_max, val)
            else:  # If it's a start time
                ans = max(ans, prev_max + val)
        
        return ans
