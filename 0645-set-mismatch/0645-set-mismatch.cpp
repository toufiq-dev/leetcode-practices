class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> seen;
        int duplicate = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            if (seen.count(nums[i]))
                duplicate = nums[i];
            
            seen[nums[i]] = i;
        }

        int missing = -1;
        unordered_map<int, int> nTable;
        for (int i = 1; i <= nums.size(); i++) {
            nTable[i]++;
        }

        for (auto x : nTable) {
            if (!seen.count(x.first))
                missing = x.first;
        }
        

        return {duplicate, missing};
    }
};