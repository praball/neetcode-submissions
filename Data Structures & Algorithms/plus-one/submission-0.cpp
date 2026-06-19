class Solution {
public:
    vector<int> plusOne(vector<int>& n) {
        for(int i=n.size()-1;i>=0;i--) {
            if(i==0 & n[i]==9) {
                n[i] = 0;
                n.insert(n.begin(), 1);
                break;
            }
            if(n[i]!=9) {
                n[i] += 1;
                break;
            } else {
                n[i] = 0;
            }
        }
        return n;
    }
};
