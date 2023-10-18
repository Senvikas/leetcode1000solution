class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> adjList[n], indegree(n);
        for(vector<int> edge: relations) {
            adjList[edge[0] - 1].push_back(edge[1] - 1);
            indegree[edge[1] - 1]++;
        }
        queue<int> Queue;
        vector<int> dist(n);
        for(int i = 0; i < n; i++) {
            if(!indegree[i]) {
                Queue.push(i);
                dist[i] = time[i];
            }
        }
        while(!Queue.empty()) {
            int curr = Queue.front();
            Queue.pop();
            for(int next: adjList[curr]) {
                dist[next] = max(dist[next], dist[curr] + time[next]);
                indegree[next]--;
                if(!indegree[next]) Queue.push(next);
            }
        }
        return *max_element(dist.begin(), dist.end());
    }
};