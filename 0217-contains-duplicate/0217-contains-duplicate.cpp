class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> seen;

        for(int i = 0; i < nums.size(); ++i) {
            seen[nums[i]]++;
        }

        for(auto x : seen) {
            if(x.second > 1) {
                return true;
            }
        }

        return false;
    }
};