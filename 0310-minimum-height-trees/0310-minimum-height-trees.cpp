class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<pair<int, int>> graph(n);
        for(auto &edge:edges){
            graph[edge[0]].first += edge[1];
            graph[edge[1]].first += edge[0];
            graph[edge[0]].second++;
            graph[edge[1]].second++;
        }
        vector<int> cur_leaves;
        for(int i=0;i<n;i++){
            if(graph[i].second==1){
                cur_leaves.push_back(i);
            }
        }
        vector<int> next_leaves;
        int neighbor = 0;
        while(n>2){
            n -= cur_leaves.size();
            next_leaves.clear();
            for(int &leaf:cur_leaves){
                neighbor = graph[leaf].first;
                graph[neighbor].first -= leaf;
                graph[neighbor].second--;
                if(graph[neighbor].second==1){
                    next_leaves.push_back(neighbor);
                }
            }
            cur_leaves = next_leaves;
        }
        return cur_leaves;
    }
};