class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long speed = 1, n = piles.size();
        while(true) {
            long long totalTime = 0;
            for(long long pile : piles) {
                totalTime += (pile + speed - 1)/speed;
            }
            if(totalTime <= h) return speed;
            speed++;
        }
    }
};
