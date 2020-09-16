//https://leetcode.com/problems/first-missing-positive


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        //put every number on its right position
        //neglect nummbers < 0 and duplicates
        for(int i = 0; i < n; i++) {
            while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) 
                swap(nums[i], nums[nums[i] - 1]);
        }
        
        //returb first missing number
        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1)
                return i + 1;
        }
        
        //if no number is missing return n + 1
        return n + 1;
    }
};
