https://leetcode.com/problems/maximum-profit-in-job-scheduling


class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        map<int,int> start_times;
        unordered_map<int, vector<pair<int,int>>> jobs;

        for(int i = 0; i < startTime.size(); i++) {
            //store max_profit for each start time, initially 0
            start_times[startTime[i]] = 0;
            
            //store jobs information in unordered_map
            jobs[startTime[i]].push_back({endTime[i], profit[i]});
        }

        int max_profit = 0;
        //start from the last job (starting last)
        for(auto it = rbegin(start_times); it != rend(start_times); it++) {
            for(auto job : jobs[it -> first]) {
                //find the next jonb which starts immediately after this job ends
                auto next_start = start_times.lower_bound(job.first);
                
                int temp = (next_start == start_times.end() ? 0 : next_start -> second) + job.second;
                max_profit = max(max_profit, temp);
                
                //update the max_profit at current starting point
                it -> second = max_profit;
            }
        }

        return max_profit;
    }
};
