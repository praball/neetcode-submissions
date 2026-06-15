class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        priority_queue<pair<int, int>>pq;
        for(int i=0;i<nums.size();i++) {
            m[nums[i]]++;
        }
        // m-> {1->1, 2->2, 3->3}
        vector<int> res;
        for(auto num : m) {
            pq.push({num.second, num.first});
        }
        // pq-> {[3,3] [2,2] [1,1]}
        while(k>0) {
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return res;
    }
};
