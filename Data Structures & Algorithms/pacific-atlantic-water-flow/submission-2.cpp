class Solution {
public:

    int n = 0, m = 0;
    vector<vector<int>> vis = vector<vector<int>> (101, vector<int>(101, 0));
    vector<vector<int>> res;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        for(int i=0;i<n;i++) {
            cout<<"| ";
            for(int k=0;k<m;k++) {
                cout<<grid[i][k]<<" | ";
            }
            cout<<"\n";
        }

        for(int i=0;i<n;i++) {
            for(int k=0;k<m;k++) {
                int check = false;
                vector<vector<int>> vis1 = vector<vector<int>> (101, vector<int>(101, 0));
                vector<vector<int>> vis2 = vector<vector<int>> (101, vector<int>(101, 0));
                if(dfsPac(grid, i, k, vis1) && dfsAtl(grid, i, k, vis2)) check = true;
                if(check) {
                    vector<int> tmp;
                    tmp.push_back(i);
                    tmp.push_back(k);
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }

    bool dfsPac(vector<vector<int>>& grid, int i, int k, vector<vector<int>>& vis) {
        if(i == 0 || k == 0) return true;
        if(vis[i][k] == 1) return false;
        int check1 = false, check2 = false, check3 = false, check4 = false;
        vis[i][k] = 1;
        if(i-1 >= 0 && grid[i][k]>=grid[i-1][k]) {
            check1 = dfsPac(grid, i-1, k, vis);
        }
        if(k-1 >= 0 && grid[i][k]>=grid[i][k-1]) {
            check2 = dfsPac(grid, i, k-1, vis);
        }
        if(k+1<m && grid[i][k]>=grid[i][k+1]) {
            check3 = dfsPac(grid, i, k+1, vis);
        }
        if(i+1<n && grid[i][k]>=grid[i+1][k]) {
            check4 = dfsPac(grid, i+1, k, vis);
        }
        if(check1 || check2 || check3 || check4) return true;
        return false;
    }

    bool dfsAtl(vector<vector<int>>& grid, int i, int k, vector<vector<int>>& vis) {
        if(i == n-1 || k == m-1) return true;
        if(vis[i][k]) return false;
        int check1 = false, check2 = false, check3 = false, check4 = false;
        vis[i][k] = 1;
        if(i+1 < n && grid[i][k]>=grid[i+1][k]) {
            check1 = dfsAtl(grid, i+1, k, vis);
        }
        if(k+1 < m && grid[i][k]>=grid[i][k+1]) {
            check2 = dfsAtl(grid, i, k+1, vis);
        }
        if(k-1>=0 && grid[i][k]>=grid[i][k-1]) {
            check3 = dfsAtl(grid, i, k-1, vis);
        }
        if(i-1>=0 && grid[i][k]>=grid[i-1][k]) {
            check4 = dfsAtl(grid, i-1, k, vis);
        }
        if(check1 || check2 || check3 || check4) return true;
        return false;
    }
};
