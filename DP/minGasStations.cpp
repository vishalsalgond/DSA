//https://leetcode.com/problems/minimum-number-of-refueling-stops/

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        long N = stations.size();
        
        //with 0 refills we can go till startFuel
        long dp[505] = {startFuel}; 
        
        //dp[x] --> farthest we can go with x refills
        
        for(int i = 0; i < N; i++) {
            for(int x = i; x >= 0 && dp[x] >= stations[i][0]; x--) {
                //if with x refills we can reach ith station then
                //with x + 1 refills we can reach dp[x] + stations[i][1]
                dp[1 + x] = max(dp[1 + x], dp[x] + stations[i][1]);
            }
        }
        
        for(int i = 0; i <= stations.size(); i++) 
            if(dp[i] >= target) return i;

        
        return -1;
    }
};
