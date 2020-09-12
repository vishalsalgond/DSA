//https://leetcode.com/problems/decode-ways/


class Solution {
public:
//                     2564
//             564             64
                        
//         64      4       4       ""
//     4       ""
    vector <int> dp;
    int recur(string &s, int start) {
        
        if(start == s.length()) 
            return 1;
        
        if(s[start] == '0') return 0;
        
        if(dp[start] != 0)
            return dp[start];
        
        else {
            dp[start] += recur(s, start + 1);
        
            if(start + 2 <= s.length() && stoi(s.substr(start, 2)) < 27)  
                dp[start] += recur(s, start + 2);

            return dp[start];
        }
        
    }
    
    
    int numDecodings(string s) {
        
        dp.assign(s.length(), 0);
        recur(s, 0);
        
        // for(int x : dp) cout << x << " ";
        // cout << endl;
        
        return dp[0];
    }
};
