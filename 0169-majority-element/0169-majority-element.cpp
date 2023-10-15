class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> frequency;

        for(int i = 0; i < nums.size(); i++) {
            if(frequency.count(nums[i]) == 0) frequency[nums[i]];

            frequency[nums[i]]++;
        }

        for(auto x : frequency) {
            if(x.second > floor(nums.size() / 2)) return x.first;
        }

        return -1;
    }
};