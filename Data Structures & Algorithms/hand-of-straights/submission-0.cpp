class Solution {
   public:
    bool isNStraightHand(vector<int>& nums, int gp) {
        if (nums.size() % gp != 0) return false;
        unordered_map<int, int> mp;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) == mp.end()) continue;  // check if has freq
            if (mp[nums[i]] == 0 ) continue;
            mp[nums[i]]--;                                         // reduce self
            if (mp[nums[i]] == 0) mp.erase(nums[i]);                 // remove self if 0

            // check if gp exists
            int next = nums[i] + 1;  // set what to find 
            int count = 1;
            while (count < gp) { 
                if (mp.find(next) != mp.end()) {
                    cout<<nums[i]<< " here & next is " << next<<endl;
                    mp[next]--;
                    count++;
                    if (mp[next] <= 0) mp.erase(next);
                    cout<<next<<" "<<mp[next]<<endl;
                    next++;
                } else return false;
            } 
        }
        return true;
    }
};
