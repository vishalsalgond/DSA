//https://leetcode.com/problems/burst-balloons/


class Solution {
public:
    int maxCoins(vector<int>& A) {
        if(A.empty()) return 0;
        
        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(n));
        
        //Think about the last balloon that will be destroyed in the interval  L ... R
        for(int L = n - 1; L >= 0; L--) {
            for(int R = L; R < n; R++) {
                for(int i = L; i <= R; i++) {
                    int coins = (L? A[L - 1] : 1) * A[i] * (R + 1 < n ? A[R + 1] : 1);
                    int res = coins + (L <= i - 1 ? dp[L][i - 1] : 0) + (R >= i + 1 ? dp[i + 1][R] : 0);
                    dp[L][R] = max(dp[L][R], res);
                }
            }
        }

        return dp[0][n - 1];
    }
};
