class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        if (firstList.size() == 0 || secondList.size() == 0) 
            return {};

        int pt1 = 0, pt2 = 0;
        vector<vector<int>> result;
        while (pt1 < firstList.size() and pt2 < secondList.size()) {
            int start1 = firstList[pt1][0];
            int end1 = firstList[pt1][1];
            int start2 = secondList[pt2][0];
            int end2 = secondList[pt2][1];

            if (start1 > end2) {
                ++pt2;
            } else if (start2 > end1) {
                ++pt1;
            } else {
                vector<int> interval;
                // interval.push_back(max(start1, start2));
                // interval.push_back(min(end1, end2));
                result.push_back({max(start1, start2), min(end1, end2)});
                if (end1 < end2) {
                    ++pt1;
                } else {
                    ++pt2;
                }
            }
        }

        return result;
    }
};