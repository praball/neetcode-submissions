class Solution {
public:
    int lastStoneWeight(vector<int>& nums) {
        int res = 0;
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++) {
            pq.push(nums[i]);
        }
        while(pq.size()>1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            pq.push(a-b);
        }
        return pq.top();
    }
};
