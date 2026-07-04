class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        int n = nums.size()-1;
        stack<pair<int, int>> st;
        st.push({nums[n], n});
        for(int i=n-1;i>=0;i--) {

            while(!st.empty()) {
                  if(st.top().first>nums[i]) {
                res[i] = st.top().second - i;
                break;}

                else st.pop();

            }
                st.push({nums[i], i});

            // if(st.top().first>nums[i]) {
            //     res[i] = st.top().second - i;
            //     st.push(nums[i], i);
            // } else if(st.top().first == nums[i]) {

            // } else {
            //     st.pop();
            // }
        }
        return res;
    }
};
