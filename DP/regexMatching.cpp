//https://leetcode.com/problems/regular-expression-matching/


class Solution {
public:
    
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();

        bool dp[n + 1][m + 1];

        dp[0][0] = true;  //empty string & empty pattern

        for(int i = 1; i <= n; i++) 
            dp[i][0] = false;

        for(int i = 1; i <= m; i++) {
            //if there is '*' in the pattern 
            //then empty string can be a potential match
            //in such case we take the previous value(before x*)
            if(p[i - 1] == '*') {
                dp[0][i] = dp[0][i - 2]; 
            } else {
                dp[0][i] = false;
            }
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                //normal case
                if(s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } 
                else if(p[j - 1] == '*') {
                    //considering 0 occurences
                    dp[i][j] = dp[i][j - 2];
                    //if current char in string is fullfils the pattern required for *
                    if(p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j] | dp[i - 1][j];
                    }
                } else {
                    dp[i][j]= false;
                }
            }
        }
        return dp[n][m];
    }
};
