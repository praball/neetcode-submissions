class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& vec) {
        vector<int> adj[n];
        for(int i=0;i<vec.size();i++) {
            adj[vec[i][0]].push_back(vec[i][1]);
        }
        vector<int> ind(n, 0);
        for(int i=0;i<n;i++) {
            for(auto itr : adj[i]) {
                ind[itr]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++) {
            if(ind[i]==0) q.push(i);
        }
        int cnt = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
            for(auto itr : adj[node]) {
                ind[itr]--;
                if(ind[itr] == 0) q.push(itr);
            }
        }
        if(cnt == n) return true;
        return false;
    }
};
