class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int m = 1, flag = 0;
        for(int i=0; i<nums.size();i++) {
            if(nums[i]==0) {
                flag++;
                continue;
            }
            m *= nums[i];
        }
        if(flag == 0) {
            for(int i=0;i<nums.size();i++) {
                res.push_back(m/nums[i]);
            }
        } else if(flag == 1) {
            for(int i=0;i<nums.size();i++) {
                if(nums[i]!=0) res.push_back(0);
                else {
                    res.push_back(m);
                }
            }
        } else {
            for(int i=0;i<nums.size();i++) {
                res.push_back(0);
            }
        }
        return res;
    }
};
