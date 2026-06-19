class Solution {
public:

    vector<int> dp = vector<int>(100, -1);

    int rec(vector<int>& nums, int i) {
        if(i==(nums.size()-1)) return nums[i];
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = max(nums[i]+rec(nums, i+2), rec(nums, i+1));
    }

    int rob(vector<int>& nums) {
        return rec(nums, 0);
    }
};
