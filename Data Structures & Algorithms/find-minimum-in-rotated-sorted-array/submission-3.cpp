class Solution {
public:
    int findMin(vector<int> &nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) {
            if(nums[0]>nums[1]) return nums[1];
            return nums[0];
        }
        if(nums[0]<nums[nums.size()-1]) return nums[0];
        int n = nums.size(), l = 0, r = nums.size()-1;
        while(l<=r) {
            // if(r==l) return nums[r];
            if(r==(l+1)) return min(nums[l], nums[r]);
            int m = l + (r-l)/2;
            if(nums[m]<nums[m-1]) return nums[m];
            if(nums[m]>nums[l]) { 
                if(nums[m]>nums[r]) {
                    l = m+1;
                } else {
                    r = m-1;
                }
            } else { 
                if(nums[m]<nums[r]) {
                    r = m-1;
                } else {
                    l = m+1;
                }
            }
        }
        return r;
    }
};
