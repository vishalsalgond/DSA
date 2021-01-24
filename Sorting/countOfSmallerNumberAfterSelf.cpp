//https://leetcode.com/problems/count-of-smaller-numbers-after-self/
//Application of Merge sort


class Solution {
public:
    void merge(int left, int mid, int right, vector<int> &nums, vector<int> &index, vector<int> &count) {

        vector<int> temp(right - left + 1), tempIdx(right - left + 1);
        int i = left, j = mid + 1;
        int ptr = 0, greaterElements = 0;

        while(i <= mid && j <= right) {
            if(nums[i] > nums[j]) {
                greaterElements++;
                tempIdx[ptr] = index[j]; 
                temp[ptr++] = nums[j++];
            } else {
                count[index[i]] += greaterElements;
                tempIdx[ptr] = index[i];
                temp[ptr++] = nums[i++];
            }
        }

        while(i <= mid) {
            count[index[i]] += greaterElements;
            tempIdx[ptr] = index[i]; 
            temp[ptr++] = nums[i++]; 
        }

        while(j <= right) {
            tempIdx[ptr] = index[j];
            temp[ptr++] = nums[j++]; 
        }

        ptr = 0;
        for(int i = left; i <= right; i++) {
            index[i] = tempIdx[ptr];
            nums[i] = temp[ptr++];
        }

    }

    void mergeSort(int left, int right, vector<int> &nums, vector<int> &index, vector<int> &count) {

        if(left < right) {

            int mid = (left + right) / 2;

            mergeSort(left, mid, nums, index, count);
            mergeSort(mid + 1, right, nums, index, count);
            merge(left, mid, right, nums, index, count);
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> count(n, 0), index(n, 0);

        for(int i = 0; i < n; i++) index[i] = i;
        mergeSort(0, n - 1, nums, index, count);


        return count;
    }
};
