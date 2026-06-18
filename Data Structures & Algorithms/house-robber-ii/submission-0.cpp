class Solution {
public:

    vector<vector<int>> dp = vector<vector<int>> (100, vector<int>(2,-1));

    int rec(vector<int>& nums, int i, int f) {
        if(i == nums.size()-1) {
            if(f == 1) return 0;
            return nums[i];
        }
        if(i >= nums.size()) return 0;
        if(dp[i][f] != -1) return dp[i][f];
        return dp[i][f] = max(nums[i] + rec(nums, i+2, f), rec(nums, i+1, f));
    }

    int rob(vector<int>& nums) {
        return max(nums[0] + rec(nums, 2, 1), rec(nums, 1, 0));
    }
};
