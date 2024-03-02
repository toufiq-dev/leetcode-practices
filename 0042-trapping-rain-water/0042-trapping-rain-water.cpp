class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
  vector<int> leftMax;
  vector<int> rightMax;
  
  int left = height[0];
  leftMax.push_back(left);
  for (int i = 1; i < height.size(); i++) {
    if (height[i] > left) {
      left = height[i];
    }
    leftMax.push_back(left);
  }
  
  int right = height[height.size() - 1];
  rightMax.resize(height.size(), 0);
  rightMax[height.size() - 1] = right;
  for (int i = height.size() - 2; i >= 0; i--) {
    if (height[i] > right) {
      right = height[i];
    }
    rightMax[i] = right;
  }
  
  for (int i = 0; i < height.size(); i++) {
    int waterLevel = min(leftMax[i], rightMax[i]);
    ans += waterLevel - height[i];
  }
  
  return ans;
    }
};