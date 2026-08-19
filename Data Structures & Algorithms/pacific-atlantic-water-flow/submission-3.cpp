class Solution {
   public:
    int n = 0, m = 0;
    vector<vector<int>> pac;
    vector<vector<int>> atl;
    vector<vector<int>> ans;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        pac = vector<vector<int>>(n, vector<int>(m, 0));
        atl = vector<vector<int>>(n, vector<int>(m, 0));

        // top row + left column
        for (int k = 0; k < m; k++) {
            dfs(heights, 0, k, pac);
        }

        for (int i = 0; i < n; i++) {
            dfs(heights, i, 0, pac);
        }

        // bottom row + right column
        for (int k = 0; k < m; k++) {
            dfs(heights, n - 1, k, atl);
        }

        for (int i = 0; i < n; i++) {
            dfs(heights, i, m - 1, atl);
        }

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < m; k++) {
                if (pac[i][k] == 1 && atl[i][k] == 1) {
                    ans.push_back({i, k});
                }
            }
        }

        return ans;
    }

    void dfs(vector<vector<int>>& heights, int i, int k, vector<vector<int>>& vis) {
        if (i < 0 || i >= n || k < 0 || k >= m) return;
        if (vis[i][k] == 1) return;

        vis[i][k] = 1;

        if (i + 1 < n && heights[i + 1][k] >= heights[i][k]) dfs(heights, i + 1, k, vis);

        if (k + 1 < m && heights[i][k + 1] >= heights[i][k]) dfs(heights, i, k + 1, vis);

        if (i - 1 >= 0 && heights[i - 1][k] >= heights[i][k]) dfs(heights, i - 1, k, vis);

        if (k - 1 >= 0 && heights[i][k - 1] >= heights[i][k]) dfs(heights, i, k - 1, vis);
    }
};