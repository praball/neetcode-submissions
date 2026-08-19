class Solution {
   public:
    int n = 0, m = 0;
    vector<vector<int>> vis = vector<vector<int>>(201, vector<int>(201, 0));

    void solve(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < m; k++) {
                if (i == 0 || k == 0 || i == n - 1 || k == m - 1) {
                    if(grid[i][k] == 'O') {
                        dfs(grid, i, k);
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < m; k++) {
                if(grid[i][k] == 'O') grid[i][k] = 'X';
            }
        }
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < m; k++) {
                if(grid[i][k] == 'A') grid[i][k] = 'O';
            }
        }
    }

    void dfs(vector<vector<char>>& grid, int i, int k) {
        if(i<0 || i>=n || k<0 || k>=m) return;
        if(grid[i][k] == 'X') return;
        if(vis[i][k] == 1) return;
        vis[i][k] = 1;
        grid[i][k] = 'A';
        dfs(grid, i+1, k);
        dfs(grid, i, k+1);
        dfs(grid, i-1, k);
        dfs(grid, i, k-1);
    }
};
