class Solution {
public:
    int search(vector<int>& nums, int tar) {
        int h = nums.size()-1, l = 0;
        while(h>=l) {
            int m = l + (h-l)/2;
            if(h==l) {
                if(nums[h] == tar) return h;
            }
            if(nums[m] == tar) return m;
            if(nums[m] > tar) {
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        return -1;
    }
};
