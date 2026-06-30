class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto c : s) {
            if(c == '(' || c == '{' || c == '[') stk.push(c);
            else {
                if(stk.empty()) return false;
                char tmp = stk.top();
                if(!check(c, tmp)) return false;
                stk.pop();
            }
        }
        if(stk.empty()) return true;
        return false;
    }

    bool check(char t, char c) {
        if(c =='(' && t == ')' || c =='[' && t == ']' || c =='{' && t == '}') return true;
        return false;
    }
};
