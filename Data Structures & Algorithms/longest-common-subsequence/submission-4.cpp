class Solution {
public:

    vector<vector<int>> dp = vector<vector<int>> (1001, vector<int>(1001, -1));

    int rec(const string& t1, const string& t2, int n, int m) {
        if(n == t1.size() || m == t2.size()) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(t1[n]==t2[m]) {
            return dp[n][m] = 1 + rec(t1, t2, n+1, m+1);
        }
        return dp[n][m] = max(rec(t1, t2, n+1, m), rec(t1, t2, n, m+1));
    }

    int longestCommonSubsequence(string t1, string t2) {
        if(t1.size()==0 || t2.size()==0) return 0;
        return rec(t1, t2, 0, 0);
    }
};
