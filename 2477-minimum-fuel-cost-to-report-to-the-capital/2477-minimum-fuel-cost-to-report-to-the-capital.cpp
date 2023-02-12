using dvec = vector<vector<int>> ;
class Solution {
    class Container{
        public:
        long long people, liter;
        Container(int _people = 0, int _liter = 0){
            people = _people;
            liter = _liter ;
        }

        void merge(Container &b){
            people += b.people;
            liter += b.liter;
        }

        void increase_liter(int new_car_seats){
            people++ ;
            long long car_needed = (people / new_car_seats) +
                   !(people % new_car_seats == 0);
            liter += car_needed;
        }

        void print(){
            cout << "( " << people << " " << liter << " )" << endl;
        }

    };
    public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        // at first we need to construct our graph
        int n = roads.size() + 1 ;
        dvec graph(n) ;

        for(auto x : roads){
            for(auto c : {0, 1}){
                graph[x[c]].push_back(x[1-c]);
            }
        }
        return dfs(0, -1, seats, graph).liter ;
    }

    Container dfs(int node, int parent, int seats, dvec &graph){
        Container curr = Container();
        
        for(auto nextNode: graph[node]){
            if(nextNode == parent) continue ;
            Container temp = dfs(nextNode, node, seats, graph) ;
            curr.merge(temp);
        }

        if(node == 0) return curr ;
        curr.increase_liter(seats);

        return curr ;
    }


};