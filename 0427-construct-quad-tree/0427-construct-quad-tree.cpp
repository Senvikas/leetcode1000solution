class Solution {
public:
    Node *construct(vector<vector<int>> &grid) {
        return dfs(grid, 0, 0, grid.size());
    }

    Node *dfs(vector<vector<int>> &grid, int x, int y, int n) {
        if (n == 1) {
            return new Node(grid[x][y] == 1, true);
        }
        Node *topLeft = dfs(grid, x, y, n / 2);
        Node *topRight = dfs(grid, x, y + n / 2, n / 2);
        Node *bottomLeft = dfs(grid, x + n / 2, y, n / 2);
        Node *bottomRight = dfs(grid, x + n / 2, y + n / 2, n / 2);
        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf &&
            topLeft->val == topRight->val && topRight->val == bottomLeft->val && bottomLeft->val == bottomRight->val) {
            return new Node(topLeft->val, true);
        }
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }

};