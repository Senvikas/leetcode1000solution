class Solution {
public:

    unordered_map<string, unordered_map<string, double>> buildGraph(vector<vector<string>>& equations, vector<double>& values){
        unordered_map<string, unordered_map<string, double>> graph;

        for(int i=0; i<equations.size(); i++){
            string dividend = equations[i][0];
            string divisor = equations[i][1];
            double value = values[i];

            graph[dividend][divisor] = value;
            graph[divisor][dividend] = 1.0/value;
        }
        return graph;
    }


    void dfs(string node, string& dest, unordered_map<string, unordered_map<string, double>>& graph, unordered_set<string>& visited, double& ans, double temp ){
        if(visited.find(node) != visited.end()){
            return;
        }

        visited.insert(node);
        if(node == dest){
            ans = temp;
            return;
        }

        for(auto nbr : graph[node]){
            dfs(nbr.first, dest, graph, visited, ans, temp * nbr.second);
        }
    }


    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph = buildGraph(equations, values);
        vector<double> finalAns;

        for(auto query : queries){
            string dividend = query[0];
            string divisor = query[1];

            if(graph.find(dividend) == graph.end() || graph.find(divisor) == graph.end()){
                finalAns.push_back(-1.0);
            }
            else{
                unordered_set<string> visited;
                double ans = -1, temp = 1.0;
                dfs(dividend, divisor, graph, visited, ans, temp);
                finalAns.push_back(ans);
            }
        }
        return finalAns;
    }
};