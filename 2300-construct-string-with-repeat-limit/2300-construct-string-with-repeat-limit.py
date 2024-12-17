import heapq

class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        freq = [0] * 26
        for ch in s:
            freq[ord(ch) - ord('a')] += 1

        pq = []
        for i in range(25, -1, -1):
            if freq[i] > 0:
                heapq.heappush(pq, (-i, freq[i]))

        ans = []
        while pq:
            i1, cnt1 = heapq.heappop(pq)
            ch1 = chr(-i1 + ord('a'))
            addCount = min(repeatLimit, cnt1)
            ans.append(ch1 * addCount)
            cnt1 -= addCount

            if cnt1 > 0 and pq:
                i2, cnt2 = heapq.heappop(pq)
                ch2 = chr(-i2 + ord('a'))
                ans.append(ch2)
                cnt2 -= 1

                heapq.heappush(pq, (i1, cnt1))
                if cnt2 > 0:
                    heapq.heappush(pq, (i2, cnt2))

        return ''.join(ans)
