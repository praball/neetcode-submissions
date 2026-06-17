class Solution {
public:
    int maxArea(vector<int>& h) {
        int res = 0, n = h.size(), l = 0;
        int r = n-1;
        while(l<r) {
            res = max(res, (r - l) * (min(h[l], h[r])));
            if(h[r] > h[l]) {
                l++;
                continue;
            } else {
                r--;
            }
        }
        return res;
    }
};
