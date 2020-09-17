//https://leetcode.com/problems/minimum-window-substring


class Solution {
public:
    string minWindow(string s, string t) {
        
        int p1 = 0, p2 = 0, found = 0;
        string ans = "";
        int minn = INT_MAX;
        map <char, int> mp, till;
        int n = t.length(), m = s.length();
        
        if(n == 0 || m == 0 || n > m) return ans;
        
        //store occurences of all characters
        for(char x : t) {
            mp[x]++;
        }
        
        //find the first postion to start from
        while(p1 < m) {
            if(mp[s[p1]] > 0) {
                p2 = p1;
                break;
            }
            p1++;
        }
        
        
        while(p2 < m) {
            
            //if char is part of t, add to hashmap
            if(mp[s[p2]] > 0) {
                if(till[s[p2]] < mp[s[p2]]) {
                    found++;
                }
                till[s[p2]]++;
            } 
            
            //push the left side of the window
            while(found == n) {
                if(p2 - p1 + 1 < minn) {
                    ans = s.substr(p1, p2 - p1 + 1);
                    minn = p2 - p1 + 1;
                }
                till[s[p1]]--;
                
                if(till[s[p1]] < mp[s[p1]]) found--;
                p1++;
                
                //if after removing element from left side check if
                //we still have a potential ans without pushing right window
                while(p1 < m && mp[s[p1]] == 0) p1++;
            }
            
            //push the right side of the window
            if(p2 < m) p2++;
           
        }

        return ans;
        
    }
};
