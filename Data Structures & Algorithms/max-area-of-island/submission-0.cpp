class Solution {
public:

    vector<vector<int>> vis = vector<vector<int>> (51, vector<int>(51,0));
    int res = 0, n = 0, m = 0;

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        for(int i=0;i<n;i++) {
            for(int k=0;k<m;k++) {
                if(grid[i][k]==0) {
                    continue; // TO CHECK
                } else {
                    if(vis[i][k]==0) {
                        int tmp = 0;
                        dfs(grid, i, k, tmp);
                        res = max(tmp, res);
                    }
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& grid, int i, int k, int& tmp) {
        if(i<0 || i>=n || k<0 || k>=m) return;
        if(vis[i][k] == 1) return;
        if(grid[i][k] == 0) return;
        else {
            vis[i][k] = 1;
            tmp++;
            dfs(grid, i+1, k, tmp);
            dfs(grid, i, k+1, tmp);
            dfs(grid, i-1, k, tmp);
            dfs(grid, i, k-1, tmp);
        }
    }
};
