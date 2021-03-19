//https://leetcode.com/problems/partition-array-for-maximum-sum/


class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int n = arr.size();
        vector<int> dp(n + 1);
        
        dp[i] = 0;
        
        //assume we have made an optimal partition before index i
        //start a new interval from index i
        //and add sum till ith index to this new interval
        
        for(int i = 0; i < n; ++i) {
            int interval_max = arr[i];
            for(int j = i; j < n && j - i + 1 <= k; j++) {
                interval_max = max(arr[j], interval_max);
                dp[j + 1] = max(dp[j + 1], dp[i] + (j - i + 1) * interval_max);
            }
        }
        
        return dp[n];
    }
};
