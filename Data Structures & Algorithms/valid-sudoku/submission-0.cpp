class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& nums) {
        // unordered_map<int, int> m;
        for (int r = 0; r < 9; r++) {
            unordered_map<char, int> mp;
            for (int c = 0; c < 9; c++) {
                if (nums[r][c] == '.') continue;
                mp[nums[r][c]]++;
                if (mp[nums[r][c]] > 1) return false;
            }
        }
        for (int c = 0; c < 9; c++) {
            unordered_map<char, int> mp;
            for (int r = 0; r < 9; r++) {
                if (nums[r][c] == '.') continue;
                mp[nums[r][c]]++;
                if (mp[nums[r][c]] > 1) return false;
            }
        }
        for (int rm = 0; rm < 9; rm += 3) {
            for (int cm = 0; cm < 9; cm += 3) {
                unordered_map<char, int> mp;
                for (int r = rm; r < rm + 3; r++) {
                    for (int c = cm; c < cm + 3; c++) {
                        // cout<<"2 ";
                        // cout<<nums[r][c]<<" "<<r<<" "<<c<<"\n";
                        if (nums[r][c] =='.') { // dont make single equals here
                            continue;
                        }
                        // cout<<"3";
                        mp[nums[r][c]]++;
                        cout<<mp[nums[r][c]]<<" "<<nums[r][c]<<"\n";
                        if (mp[nums[r][c]] > 1) return false;
                    }
                }
            }
        }
        return true;
    }
};
