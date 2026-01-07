class Solution {
public:
    vector<vector<int>> children;
    vector<long long> subtreeSize;
    int n;
    long long maxScore = 0;
    int count = 0;

    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size();
        children.assign(n, {});
        subtreeSize.assign(n, 0);

        // Build children list
        for(int i=1; i<n; i++) {
            children[parents[i]].push_back(i);
        }

        dfs(0); // compute subtree sizes and scores

        return count;
    }

    long long dfs(int node) {
        long long size = 1; // count self
        long long score = 1;

        for(int child : children[node]) {
            long long childSize = dfs(child);
            size += childSize;
            score *= childSize;
        }

        long long rest = n - size;
        if(rest > 0) score *= rest;

        // update maxScore and count
        if(score > maxScore) {
            maxScore = score;
            count = 1;
        } else if(score == maxScore) {
            count++;
        }

        subtreeSize[node] = size;
        return size;
    }
};
