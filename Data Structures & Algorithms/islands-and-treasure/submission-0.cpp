class Solution {
   public:
    int n = 0, m = 0, inf = 2147483647;
    queue<pair<int, int>> q;

    void islandsAndTreasure(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < m; k++) {
                if (grid[i][k] == 0) {
                    pair<int, int> p(i, k);
                    q.push(p);
                }
            }
        }
        while (!q.empty()) {
            pair<int, int> p = q.front();
            int i = p.first, k = p.second;
            int curr = grid[i][k] + 1;
            putValue(grid, i + 1, k, curr);
            putValue(grid, i, k + 1, curr);
            putValue(grid, i - 1, k, curr);
            putValue(grid, i, k - 1, curr);
            q.pop();
        }
    }

    void putValue(vector<vector<int>>& grid, int i, int k, int curr) {
        if (i < 0 || i >= n || k < 0 || k >= m) return;
        if(grid[i][k] != inf) return;
        grid[i][k] = curr;
        pair<int, int> p(i, k);
        q.push(p);
        return;
    }
};
