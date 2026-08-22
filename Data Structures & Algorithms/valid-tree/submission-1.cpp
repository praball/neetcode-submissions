class Solution {
   public:
    bool validTree(int n, vector<vector<int>>& vec) {
        vector<int> adj[n];
        for (auto itr : vec) {
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);
        }
        vector<int> vis(n, 0);
        bool check = dfs(vis, adj, 0, -1);
        for(int i=0;i<n;i++) {
            if(vis[i]==0) return false;
        }
        return check;
    }

    bool dfs(vector<int>& vis, vector<int> adj[], int i, int parent) { 
        vis[i] = 1;
        for(auto itr : adj[i]) {
            if(vis[itr]) {
                if(itr == parent) {
                    continue;
                } else {
                    return false;
                }
            } else {
                if(dfs(vis, adj, itr, i)  == false) return false;
            }
        }
        return true;
    }
};

