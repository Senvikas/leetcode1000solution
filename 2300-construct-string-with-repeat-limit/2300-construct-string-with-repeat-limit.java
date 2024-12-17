class Solution {
    public String repeatLimitedString(String s, int repeatLimit) {
        int[] freq = new int[26];
        for (char ch : s.toCharArray()) {
            freq[ch - 'a']++;
        }

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        for (int i = 25; i >= 0; i--) {
            if (freq[i] > 0) {
                pq.add(new int[] {i, freq[i]});
            }
        }

        StringBuilder ans = new StringBuilder();
        while (!pq.isEmpty()) {
            int[] first = pq.poll();
            char ch1 = (char) ('a' + first[0]);
            int cnt1 = first[1];

            int addCount = Math.min(repeatLimit, cnt1);
            for (int i = 0; i < addCount; i++) {
                ans.append(ch1);
            }
            cnt1 -= addCount;

            if (cnt1 > 0 && !pq.isEmpty()) {
                int[] second = pq.poll();
                char ch2 = (char) ('a' + second[0]);
                int cnt2 = second[1];

                ans.append(ch2);
                cnt2--;

                pq.add(new int[] {first[0], cnt1});
                if (cnt2 > 0) {
                    pq.add(new int[] {second[0], cnt2});
                }
            }
        }

        return ans.toString();
    }
}
