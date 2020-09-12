/https://leetcode.com/problems/trapping-rain-water/


class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size(), ans = 0;
        int left = 0, right = n - 1;
        int maxLeft = 0, maxRight = 0;
        
        
        //keep track of maximum boundary you encountered
        //on the left side & on the right side
        //at every point area will be maximum on right or left minus curr
        while(left <= right) {
            if(height[left] <= height[right]) {
                if(height[left] >= maxLeft)
                    maxLeft = height[left];
                else
                    ans += maxLeft - height[left];
                left++;
            } 
            else {
                if(height[right] >= maxRight)
                    maxRight = height[right];
                else
                    ans += maxRight - height[right];
                right--;
            }
        }
        return ans;
    }
};
