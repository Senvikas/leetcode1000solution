
    function minSteps(level) {
        const n = level.length;
        const eleInd = level.map((val, i) => [val, i]);
        eleInd.sort((a, b) => a[0] - b[0]);

        let vis = Array(n).fill(false);
        let ans = 0;

        for (let i = 0; i < n; i++) {
            if (vis[i] || eleInd[i][1] === i) continue;

            let cycle = 0, j = i;
            while (!vis[j]) {
                vis[j] = true;
                j = eleInd[j][1];
                cycle++;
            }
            ans += cycle - 1;
        }

        return ans;
    }

    function minimumOperations(root) {
        if (!root) return 0;

        let ans = 0;
        let q = [root];

        while (q.length) {
            const level = [];
            const nextLevel = [];

            for (const node of q) {
                level.push(node.val);
                if (node.left) nextLevel.push(node.left);
                if (node.right) nextLevel.push(node.right);
            }

            q = nextLevel;
            ans += minSteps(level);
        }

        return ans;
    };