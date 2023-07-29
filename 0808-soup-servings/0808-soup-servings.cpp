#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    double memo[200][200];
    
    double dfs(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1;
        if (b <= 0) return 0;
        
        if (memo[a][b] != -1) return memo[a][b];
        
        double prob = 0.0;
        prob += 0.25 * dfs(a - 4, b);
        prob += 0.25 * dfs(a - 3, b - 1);
        prob += 0.25 * dfs(a - 2, b - 2);
        prob += 0.25 * dfs(a - 1, b - 3);
        
        memo[a][b] = prob;
        return prob;
    }
    
    double soupServings(int n) {
        // If n is large, the probability approaches 1, so we return 1 directly.
        if (n >= 5000) return 1.0;
        
        // Convert the problem to use integers by dividing by 25.
        int m = ceil(n / 25.0);
        
        // Initialize the memoization table with -1 (not calculated yet).
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= m; j++) {
                memo[i][j] = -1;
            }
        }
        
        // Call the recursive function and multiply the result by 0.25 (probability of each operation).
        return dfs(m, m);
    }
};
