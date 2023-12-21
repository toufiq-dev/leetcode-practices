class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<int> pointSet;  // To store unique points in a set for efficient lookup
        int result = INT_MAX;

        // Add all points to the set for constant time lookup
        for (const auto& point : points) {
            pointSet.insert(point[0] * 40001 + point[1]);
        }

        // Iterate through each pair of points
        for (const auto& p1 : points) {
            for (const auto& p2 : points) {
                if (p1[0] != p2[0] && p1[1] != p2[1]) {  // Ensure points are not on the same line
                    // Check if the opposite diagonal points exist
                    if (pointSet.count(p1[0] * 40001 + p2[1]) && pointSet.count(p2[0] * 40001 + p1[1])) {
                        int area = abs((p1[0] - p2[0]) * (p1[1] - p2[1]));
                        result = min(result, area);
                    }
                }
            }
        }

        return result == INT_MAX ? 0 : result;
    }
};