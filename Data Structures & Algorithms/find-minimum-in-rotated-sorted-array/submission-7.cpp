class Solution {
public:
    int findMin(vector<int> &nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        if(nums.size() == 2) {
            if(nums[0] < nums[1]) return nums[0];
            return nums[1];
        }
        if(nums[0]<nums[nums.size()-1]) return nums[0];
        int n = nums.size(), l = 0, r = nums.size()-1, res = 0, pivot = 0;
        while(l<=r) {
            if(l+1==r) return min(nums[l], nums[r]);
            int m = l + (r-l)/2;
            if(nums[m]<nums[m-1]) {
                pivot = m;
                break;
            }
            if(nums[m] > nums[r]) {
                l = m+1;
            } else {
                r = m-1;
            }
        }
        return nums[pivot];
    }
};
