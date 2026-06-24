class Solution {
public:

    vector<vector<int>> dp = vector<vector<int>> (101, vector<int>(101, -1));

    int rec(int m, int n, int d, int r) {
        if(d==m && r==n) return 0;
        if(d==m) return 1;
        if(r==n) return 1;
        if(dp[d][r] != -1) return dp[d][r];
        return dp[d][r] = rec(m, n, d+1, r) + rec(m, n, d, r+1);
    }

    int uniquePaths(int m, int n) {
        if(m == 1 && n == 1) return 1;
        return rec(m, n, 1, 1);
    }
};
