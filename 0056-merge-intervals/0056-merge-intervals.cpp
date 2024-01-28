class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Step 1: Sort the intervals by their start times
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        // Step 2: Initialize the result vector with the first interval
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        // Step 3: Merge overlapping intervals
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= merged.back()[1]) {
                // There is an overlap, update the end time of the last merged interval
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            } else {
                // No overlap, add a new merged interval
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};