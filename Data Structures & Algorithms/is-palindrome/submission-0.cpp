class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()==1) return true;
        int l=0, r=s.size()-1;
        while(l<r) {
            if(!alphaNum(s[l])) {
                l++;
                continue;
            }
            if(!alphaNum(s[r])) {
                r--;
                continue;
            }          
            if (tolower(s[l]) == tolower(s[r])) {}
            else {return false;}
            l++;
            r--;
        }
        return true;
    }
    bool alphaNum(char c) {
        return (c >= 'A' && c <= 'Z' ||
                c >= 'a' && c <= 'z' ||
                c >= '0' && c <= '9');
    }
};
