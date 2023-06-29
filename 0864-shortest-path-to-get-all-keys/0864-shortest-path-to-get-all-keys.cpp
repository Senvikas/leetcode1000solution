class Solution {
public:
    vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    bool hasKey(unordered_set<char> keys, char lock) {
        for(char key : keys) {
            if(key - 32 == lock) {
                return true;
            }
        }
        return false;
    }
    string checkSeen(unordered_set<char> keys) {
        string ans = "";
        for(char key : keys) {
            ans += key;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size(), m = grid[0].size();
        int totalKeys = 0;
        queue<pair<vector<int>,unordered_set<char>>> q;
        vector<int> start;
        unordered_map<string, set<pair<int,int>>> seen;
        // vector<vector<int>> visited(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '@') {
                    start = {i,j,0};
                }
                if(grid[i][j] >= 'a' && grid[i][j] <= 'z') {
                    totalKeys++;
                }
            }
        }
        q.push({start, {}});
        while(!q.empty()) {
            pair<vector<int>, unordered_set<char>> cur = q.front(); q.pop();
            int curX = cur.first[0], curY = cur.first[1], steps = cur.first[2];
            unordered_set<char> keys = cur.second;
            if(seen[checkSeen(keys)].count({curX, curY})) {
                continue;
            }
            seen[checkSeen(keys)].insert({curX, curY});
            if(keys.size() == totalKeys) {
                return steps;
            }
            for(auto& dir : dirs) {
                int newX = curX + dir.first, newY = curY + dir.second;
                if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] != '#') {
                    char curPos = grid[newX][newY];
                    if(curPos >= 'A' && curPos <= 'Z') {
                        if(hasKey(keys, curPos)) {
                            q.push({{newX, newY, steps + 1}, keys});
                        }
                    }
                    else {
                        if(curPos >= 'a' && curPos <= 'z') {
                            // is key
                            unordered_set<char> newKeys(keys);
                            newKeys.insert(curPos);
                            q.push({{newX, newY, steps + 1}, newKeys});
                        }
                        else {
                            q.push({{newX, newY, steps + 1}, keys});
                        }
                    }
                }
            }
        }
        return -1;
    }
};