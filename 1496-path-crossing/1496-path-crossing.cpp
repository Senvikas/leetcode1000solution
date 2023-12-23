#include <unordered_set>

class Solution {
public:
    bool isPathCrossing(string path) {
        int c1 = 0, c2 = 0;
        unordered_set<string> visited;
        visited.insert("0,0");  // Add the starting point to the set

        int n = path.size();
        for (int i = 0; i < n; ++i) {
            auto ch = path[i];
            if (ch == 'N') c1++;
            else if (ch == 'E') c2++;
            else if (ch == 'S') c1--;
            else c2--;

            // Check if the current point has been visited before
            string current_point = to_string(c1) + "," + to_string(c2);
            if (visited.count(current_point) > 0) {
                return true;
            }

            // Add the current point to the set
            visited.insert(current_point);
        }

        return false;
    }
};
