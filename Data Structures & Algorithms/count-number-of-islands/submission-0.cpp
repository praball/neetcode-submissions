class Solution {
   public:

    vector<vector<int>> vis = vector<vector<int>>(101, vector<int>(101, 0));
    // set all to not visited
    int res = 0, n = 0, m = 0;

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < grid.size(); i++) {
            for (int k = 0; k < grid[0].size(); k++) {
                if (grid[i][k] == '0')
                    continue;
                else {                     // if possible dfs available
                    if (vis[i][k] == 0) {  // if unvisited, dfs/island available
                        dfs(grid, i, k);
                        res++;
                    }
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, int i, int k) {
        if (i >= n || i < 0 || k < 0 || k >= m) return;  // Out of bounds
        if (grid[i][k] == '0') {
            return;
        } else {
            if(vis[i][k] == 1) {
                return;
            }
            vis[i][k] = 1;
            dfs(grid, i + 1, k);
            dfs(grid, i, k + 1);
            dfs(grid, i - 1, k);
            dfs(grid, i, k - 1);
        }
    }
};
