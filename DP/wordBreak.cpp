//https://leetcode.com/problems/word-break/

//Time: O(N^2)
//Space: O(N)


class Solution {
public:
    unordered_map <string, bool> mp;

    bool backtrack(string &s, int start, int dp[]) {
        int n = s.length();
        if(start == n) 
            return true;
        
        if(dp[start] != -1) {
            return dp[start];
        }

        for(int end = start; end < n; end++) {
            if(mp[s.substr(start, end - start + 1)]) {
                if(backtrack(s, end + 1, dp)) {
                    dp[start] = 1;
                    return true;
                }
                
            }
        }
        
        dp[start] = 0;
        return false;
    }


    bool wordBreak(string s, vector<string>& wordDict) {
        for(string x : wordDict)
            mp[x] = true;
        
        int n = s.length();
        int dp[n];
        for(int i = 0; i < n; i++) 
            dp[i] = -1;
        
        return backtrack(s, 0, dp);
        
    }
};
