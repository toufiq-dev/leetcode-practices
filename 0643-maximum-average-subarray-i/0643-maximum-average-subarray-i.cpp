class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        vector<double> arr;
        double sum = 0;
        double min = INT_MIN;

        for(int i = 0; i < k; i++) {
            sum += nums[i];
        }

        for(int i = 0; i <= nums.size() - k; i++) {
            double avg = sum / k;
            arr.push_back(avg);

            if(i != nums.size() - k) {
                sum -= nums[i];
                sum += nums[k + i];
            }
        }

        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] > min) {
                min = arr[i];
            }
        }

        return min;
    }
};