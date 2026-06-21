class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int l = 0, r = 1, n = nums.size()-1, res = 0, lmin = 0, rmax = 0;
        if(nums.size() == 1) return 0;
        if(nums.size() == 2) {
            return (nums[0]>nums[1]) ? 0 : (nums[1]-nums[0]);
        }
        while(r<=n) {
            if(nums[l]<nums[r]) {
                res = max(res, (nums[r]-nums[l]));
                lmin = min(nums[lmin], nums[l]);
            } else {
                l = r;
                r++;
                continue;
            }
            r++;
        }
        return res;
    }
};
