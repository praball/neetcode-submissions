class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==1) return 1;
        if(s.size()==0) return 0;
        unordered_map<char,int> m;
        int res = 0, temp = 0, l = 0, n = s.size() - 1;
        for(int i=0;i<s.size();i++) {
            if(m.find(s[i]) != m.end()) {
                // res = max(res, temp);
                while(m[s[i]] > 0) {
                    m[s[l]]--;
                    l++;
                    temp -=1;
                }
                temp++;
                res = max(res, temp);
                m[s[i]]++;
            } else {
                m[s[i]]++;
                temp++;
                res = max(res, temp);
            }
        }
        return res;
    }
};
