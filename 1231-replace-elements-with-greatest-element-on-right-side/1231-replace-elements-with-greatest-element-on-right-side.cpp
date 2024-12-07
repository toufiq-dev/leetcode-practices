class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int rightMax = -1;

        for (int i = arr.size() - 1; i >= 0; i--) {
            int newMax = max(rightMax, arr[i]);
            arr[i] = rightMax;
            rightMax = newMax;
        }

        return arr;
    }
};