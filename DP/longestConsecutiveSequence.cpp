//https://leetcode.com/problems/longest-consecutive-sequence/


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map <int, int> mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i]] = 1;
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {

            if(mp[nums[i]] > 1) continue;

            int curr = nums[i] + 1;
            while(mp[curr]) {
                if(mp[curr] > 1) {
                    mp[nums[i]] = mp[curr] = mp[nums[i]] + mp[curr];
                    break;
                }
                mp[nums[i]] = mp[curr] = mp[nums[i]] + 1;
                curr++;
            }
            
            ans = max(ans, mp[nums[i]]);
        }

    

        return ans;
        
    }
};
