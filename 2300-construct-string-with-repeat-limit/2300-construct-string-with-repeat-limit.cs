public class Solution {
    public string RepeatLimitedString(string s, int repeatLimit) {
        int[] freq = new int[26];
        foreach (char ch in s) {
            freq[ch - 'a']++;
        }

        var pq = new PriorityQueue<char, int>();
        for (int i = 25; i >= 0; i--) {
            if (freq[i] > 0) {
                pq.Enqueue((char)(i + 'a'), -i);
            }
        }

        var ans = new StringBuilder();
        while (pq.Count > 0) {
            var ch1 = pq.Peek();
            pq.Dequeue();
            int cnt1 = freq[ch1 - 'a'];

            int addCount = Math.Min(repeatLimit, cnt1);
            ans.Append(new string(ch1, addCount));
            cnt1 -= addCount;

            if (cnt1 > 0 && pq.Count > 0) {
                var ch2 = pq.Peek();
                pq.Dequeue();
                ans.Append(ch2);
                freq[ch2 - 'a']--;

                pq.Enqueue(ch1, -(ch1 - 'a'));
                if (freq[ch2 - 'a'] > 0) {
                    pq.Enqueue(ch2, -(ch2 - 'a'));
                }
            }
            freq[ch1 - 'a'] = cnt1;
        }

        return ans.ToString();
    }
}
