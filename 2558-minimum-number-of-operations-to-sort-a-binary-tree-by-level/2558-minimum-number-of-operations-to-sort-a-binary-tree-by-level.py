from collections import deque

class Solution:
    def minSteps(self, level):
        n = len(level)
        eleInd = [(val, i) for i, val in enumerate(level)]
        eleInd.sort()

        vis = [0] * n
        ans = 0

        for i in range(n):
            if vis[i] or eleInd[i][1] == i:
                continue

            cycle = 0
            j = i

            while not vis[j]:
                vis[j] = 1
                j = eleInd[j][1]
                cycle += 1

            ans += cycle - 1

        return ans

    def minimumOperations(self, root):
        if not root:
            return 0

        ans = 0
        q = deque([root])

        while q:
            level = []
            for _ in range(len(q)):
                node = q.popleft()
                level.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)

            ans += self.minSteps(level)

        return ans
