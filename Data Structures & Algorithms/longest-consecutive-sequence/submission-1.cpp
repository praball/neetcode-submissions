class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int res = 0, count = 1, f = 0, tmp = 0;
        set<int> s;
        for(int i=0;i<nums.size();i++) {
            s.insert(nums[i]);
        }
        for(auto st: s) {
            if(f==0) {
                tmp = st;
                f++;
                continue;
            }
            if(st == tmp+1) {
                count++;
                tmp++;
            } else {
                res = max(res, count);
                count = 1;
                tmp = st;
            }
        }
        res = max(res, count);
        return res;
    }
};
