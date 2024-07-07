class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        vector<int> left(heights.size()), right(heights.size());
    
        // fill left
        for (int i = 0; i < heights.size(); i++) {
            if (s.empty()) {
                left[i] = 0;
                s.push(i);
            }
            else {
                while (!s.empty() and heights[s.top()] >= heights[i]) {
                    s.pop();
                }
                
                left[i] = s.empty() ? 0 : s.top() + 1;
                s.push(i);
            }
        }
    
        while (!s.empty()) {
            s.pop();
        }
        
        // fill right
        for (int i = heights.size() - 1; i >= 0; i--) {
            if (s.empty()) {
                right[i] = heights.size() - 1;
                s.push(i);
            } 
            else {
                while (!s.empty() and heights[s.top()] >= heights[i]) {
                    s.pop();
                }
                
                right[i] = s.empty() ? heights.size() - 1 : s.top() - 1;
                s.push(i);
            }
        }
    
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            maxArea = max(maxArea, heights[i] * (right[i] - left[i] + 1));
        }

        return maxArea;
    }
};