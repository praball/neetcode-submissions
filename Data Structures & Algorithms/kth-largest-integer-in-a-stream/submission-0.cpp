class KthLargest {
   public:

    int tar = 0;
    vector<int> nums;
    priority_queue<int> pq;

    KthLargest(int k, vector<int>& nums) {
        tar = k;
        for (int i = 0; i < nums.size(); i++) {
            this->nums.push_back(nums[i]);
            pq.push(nums[i]);
        }
    }

    int add(int val) { 
        nums.push_back(val);
        pq.push(val);
        vector<int> vec;
        for(int i=0;i<tar-1;i++) {
            vec.push_back(pq.top());
            pq.pop();
        }
        int res = pq.top();
        for(int i=0;i<vec.size();i++) {
            pq.push(vec[i]);
        }
        return res;
    }
};
