class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        vector<string> v;
        vector<vector<string>> res;
        int n = s.size();
        if(n==0 || n==1) {
            if(s.size()==1) v.push_back(s[0]);
            res.push_back(v);
            return res;
        }
        // {act,bct,act,bct,wert}
        // m = {act->atc,cta,cat}
        unordered_map<string, vector<string>> m;
        for(int i=0;i<n;i++) {
            string tmp = s[i];
            sort(tmp.begin(), tmp.end());
            m[tmp].push_back(s[i]);
        }
        for(auto& i : m) {
            res.push_back(i.second);
        }
        return res;
    }
};
