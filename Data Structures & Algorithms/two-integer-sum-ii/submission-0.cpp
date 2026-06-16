class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tar) {
        int l = 0, r = nums.size() - 1, n = nums.size();
        vector<int> res;
        for(int i=0;i<n;i++) {
            int s = nums[l] + nums[r];
            if(s==tar) {
                res.push_back(l+1);
                res.push_back(r+1);
                return res;
            } else if (s > tar) {
                r--;
            } else {
                l++;
            }
        }
        return res;
    }
};
