class Solution {
public:
    int evalRPN(vector<string>& nums) {
        if(nums.size()==1) return stoi(nums[0]);
        stack<int> stk;
        for(int i=0;i<nums.size();i++) {
            string tmp = nums[i];
            if(tmp == "+" || tmp == "-" || tmp == "*" || tmp == "/") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                cout<<a<<" "<<b<<"\n";
                int res = check(tmp, a, b);
                stk.push(res);
            } else {
                stk.push(stoi(nums[i]));
            }
        }
        return stk.top();
    }

    int check(string t, int a, int b) {
        if(t == "+") {
            return a+b;
        } else if(t == "-") {
            return b-a;
        } else if(t == "*") {
            return a*b;
        } else {
            return b/a;
        }
    }
};
