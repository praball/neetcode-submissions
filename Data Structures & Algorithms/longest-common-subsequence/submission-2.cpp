class Solution {
public:

    vector<vector<int>> dp = vector<vector<int>> (1001, vector<int>(1001, -1));

    int rec(string t1, string t2, int n, int m) {
        if(dp[n][m]!=-1) return dp[n][m];
        if(n == t1.size()-1) {
            if(m == t2.size()-1) {
                if(t1[n]==t2[m]) {
                    return 1;
                }
                return 0;
            } else {
                if(t1[n]==t2[m]) {
                    return 1;
                } else {
                    return rec(t1, t2, n, m+1);
                }
            }
        }
        if(m == t2.size()-1) {
            if(t1[n]==t2[m]) {
                return 1;
            }
            return rec(t1, t2, n+1, m);
        }
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
