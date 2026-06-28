class Solution {
public:

    vector<int> dp = vector<int>(1001, -1);

    bool rec(vector<int> nums, int i) {
        if(i>=nums.size()-1) return true;
        if(nums[i]==0) return false;
        if(dp[i]!=-1) return dp[i];
        int tmp = nums[i], j = 1;
        vector<bool> vec;
        while(tmp>0) {
            vec.push_back(rec(nums, i + j));
            j++;
            tmp--;
        }
        bool res = false;
        for(int j=0;j<vec.size();j++) {
            if(vec[j]==true) res = true;
        }
        return dp[i] = res;
    }

    bool canJump(vector<int>& nums) {
        return rec(nums, 0);
    }
};
