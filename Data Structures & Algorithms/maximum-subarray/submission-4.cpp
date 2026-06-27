class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], count = nums[0];
        for(int i=1;i<nums.size();i++) {
            count += nums[i];
            res = max(res, nums[i]);
            if(count<0) {
                count = 0;
                continue;
            }
            res = max(res, count);
        }
        return res;
    }
};
