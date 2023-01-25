class Solution {
    class Comparator {
        public:
        bool operator()(pair<int,int>&a, pair<int,int>&b){
            if(a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        }
    };

public:
    vector<int> djikstra(int node, map<int,vector<pair<int,int>>>&graph, int N){
        vector<int> dist(N,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dist[node] = 0;
        pq.push({node,0});

        while(!pq.empty()){
            int maxNode = pq.top().first;
            pq.pop();

            for(auto it: graph[maxNode]){
                int distance = it.second;
                int node = it.first;

                if(dist[maxNode]+distance < dist[node]){
                    dist[node] = dist[maxNode] + distance;
                    pq.push({node,dist[node]});
                }
            }
        }

        return dist;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        map<int,vector<pair<int,int>>> graph;
        for(int i=0; i<edges.size(); i++){
            if(edges[i] == -1) continue;
            graph[i].push_back({edges[i],1});
        }

        int N = edges.size();
        vector<int> dist1 = djikstra(node1,graph,N);
        vector<int> dist2 = djikstra(node2,graph,N);
        priority_queue<pair<int,int>,vector<pair<int,int>>,Comparator> pq;


        for(int i=0; i<edges.size(); i++){
            int distFromNode1 = dist1[i];
            int distFromNode2 = dist2[i];
            pq.push({max(distFromNode1,distFromNode2),i});
        }

        return pq.top().first != INT_MAX ? pq.top().second : -1;
    }
};