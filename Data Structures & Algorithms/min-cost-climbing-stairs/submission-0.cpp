class Solution {
public:

    vector<int> t = vector<int>(100,-1);

    int rec(vector<int>& c, int i) {
        if(i>=c.size()) return 0;
        if(t[i]!=-1) return t[i];
        return t[i] = min(c[i]+rec(c,i+1), c[i]+rec(c,i+2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        return min(rec(cost, 0),rec(cost, 1));
    }
};
