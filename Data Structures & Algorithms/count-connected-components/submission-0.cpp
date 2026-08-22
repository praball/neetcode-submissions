class Solution {
public:
    int countComponents(int n, vector<vector<int>>& vec) {
        vector<int> adj[n];
        int count = 0;
        for(int i=0;i<vec.size();i++) {
            adj[vec[i][0]].push_back(vec[i][1]);
            adj[vec[i][1]].push_back(vec[i][0]);
        }
        vector<int> vis(n, 0);
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                dfs(adj, vis, i);
                count++;
            }
        }
        return count;
    }

    void dfs(vector<int> adj[], vector<int>& vis, int i) {
        vis[i] = 1;
        for(auto itr : adj[i]) {
            if(vis[itr]) {
                continue;
            } else {
                dfs(adj, vis, itr);
            }
        }
    }
};
