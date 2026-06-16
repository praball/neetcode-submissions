class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> vec = nums;
        sort(vec.begin(), vec.end());
        //vec -> {-4,-1,-1,0,1,2}
        vector<vector<int>> res;
        int n = vec.size();
        for(int i=0; i<n-2; i++) {
            //check if i is not getting duplicated.
            if(i>0 && vec[i] == vec[i-1]) continue;
            int a = vec[i], b = i+1, c = n-1;
            while(b<c) {
                if(a+vec[b]+vec[c] == 0) {
                    vector<int> t;
                    //vec->{-1,-1,0,1,1,2,7}
                    t.push_back(a);
                    t.push_back(vec[b]);
                    t.push_back(vec[c]);
                    res.push_back(t);
                    // how to move b and c indices now?
                    // a is fixed, n 'b' can only pair with 'c',
                    // hence need to move both.
                    b++;
                    c--;
                    // remove recurring b's and c's.
                    while (b<c && vec[b] == vec[b-1]) b++;
                    while (b<c && vec[c] == vec[c+1]) c--;
                } else if (a + vec[b] + vec[c] > 0) {
                    c--;
                } else {
                    b++;
                }
            }
        }
        return res;
    }
};
