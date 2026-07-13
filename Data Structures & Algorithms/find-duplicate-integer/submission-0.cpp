class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[nums[0]], meet = 0;
        while(nums[slow]!=nums[fast]) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        while(nums[meet]!=nums[slow]) {
            meet = nums[meet];
            slow = nums[slow];
        }
        return nums[meet];
    }
};
