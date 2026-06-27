class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], count = nums[0];
        for(int i=1;i<nums.size();i++) {
            count += nums[i];
            cout<<count<<" ";
            if(count<0) {
                if(i+1!=nums.size()){
                    count = 0;
                    continue;
                } else {
                    res = max(res, nums[i]);
                }
            }
            cout<<count<<"\n";
            res = max(res, count);
        }
        return res;
    }
};
