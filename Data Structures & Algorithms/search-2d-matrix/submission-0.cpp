class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        int m = mat.size(), n = mat[0].size(), l = 0;
        int r = m-1, row = 0;
        while(l<=r) {
            int mid = l + (r-l)/2;
            vector<int> tmp = mat[mid];
            if(tmp[0] <= tar && tmp[n-1] >= tar) {
                row = mid;
                break;
            }
            if(tmp[0] > tar) { 
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        vector<int> res = mat[row];
        l = 0, r = n-1;
        while(l<=r) {
            int mid = l + (r-l)/2;
            if(res[mid] == tar) return true;
            if(res[mid] > tar) r = mid-1;
            else l = mid+1;
        }
        return false;
    }
};
