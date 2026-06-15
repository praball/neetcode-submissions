class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m, mp;
        for(int i=0;i<s.size();i++) {
            m[s[i]]++;
        }
        for(int i=0;i<t.size();i++) {
            mp[t[i]]++;
        }
        if(m == mp) return true;
        return false;
    }
};
