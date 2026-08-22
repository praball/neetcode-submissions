class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& vec) {
        vector<int> res;
        vector<int> adj[n];
        for(int i=0;i<vec.size();i++)
        {
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
            if(ind[i] == 0) q.push(i);
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(auto itr : adj[node]) {
                ind[itr]--;
                if(ind[itr] == 0) q.push(itr);
            }
        }
        reverse(res.begin(), res.end());
        if(res.size() == n) return res;
        vector<int> temp;
        return temp;
    }
};
