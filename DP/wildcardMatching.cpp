//https://leetcode.com/problems/wildcard-matching/


class Solution {
public:
    
    bool isMatch(string s, string p) {
        
        int n = s.length(), m = p.length();

        vector <vector<bool>> dp(n + 1, vector <bool> (m + 1, false));

        dp[0][0] = true;  //empty string & empty pattern

        if(p[0] == '*' && m == 1) {
            dp[0][1] = true;
        } 

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                //normal case
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } 
                else if(p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j - 1] || dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j]= false;
                }
            }
        }
        return dp[n][m];
    }
};
