class Solution:
    def findTwice(self, s, special, ind):
        cnt = 2
        n = len(s)
        length = len(special)
        for j in range(ind, n - length + 1):
            if s[j:j + length] == special:
                cnt -= 1
                if cnt == 0:
                    return True
        return False

    def maximumLength(self, s):
        n = len(s)
        ans = -1

        for i in range(n):
            special = ""
            for j in range(i, n):
                if special and special[-1] != s[j]:
                    break
                special += s[j]
                if self.findTwice(s, special, i + 1):
                    ans = max(ans, len(special))

        return ans
