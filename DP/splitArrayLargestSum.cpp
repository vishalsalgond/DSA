//https://leetcode.com/problems/split-array-largest-sum

class Solution {
public:
    bool is_valid(vector<int> &nums, int target, int m) {

        int curr_sum = 0, count = 1;

        for(int num : nums) {
            curr_sum += num;

            if(curr_sum > target) {
                count++;
                curr_sum = num;
                if(count > m)
                    return false;
            }
        }

        return true;
    }

    int splitArray(vector<int>& nums, int m) {
        
        int n = nums.size();
        int sum = 0, maxx = INT_MIN;

        for(int num : nums) {
            sum += num;
            maxx = max(maxx, num);
        }

        if(m == 1) return sum;

        int low = maxx, high = sum;

        while(low <= high) {

            int mid = (low + high) / 2;

            if(is_valid(nums, mid, m)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return high + 1;
    }
};

