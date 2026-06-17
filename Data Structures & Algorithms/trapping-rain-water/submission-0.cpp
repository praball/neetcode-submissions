class Solution {
public:
    int trap(vector<int>& h) {
        int l = 0, r = h.size()-1, n = h.size(), res = 0;
        int lm = h[0], rm = h[n-1];
        while(r > l) {
            if(lm < rm) {
                l++;
                lm = max(lm, h[l]);
                res += lm-h[l];
            } else {
                r--;
                rm = max(rm, h[r]);
                res += rm-h[r];
            }
        }
        return res;
    }
};
