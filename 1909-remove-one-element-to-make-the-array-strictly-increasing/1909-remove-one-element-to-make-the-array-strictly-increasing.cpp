class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int index = detectIndex(nums);
        cout << index;
        if (index != -1) {
            vector<int> newNums = constructNewNums(nums, index);
            bool ans = isIncreasing(newNums);
            if (ans) 
                return true;
            else {
                vector<int> newNums = constructNewNums(nums, index + 1);
                bool ans = isIncreasing(newNums);
                if (ans) 
                    return true;
                else 
                    return false;
            }            
        }
        
        if(index == -1)
            return true;

        return false;
    }
private:
    int detectIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] <= nums[i]) {
                return i;
            }
        }

        return -1;
    }

    bool isIncreasing(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] <= nums[i]) {
                return false;
            }
        }

        return true;
    }

    vector<int> constructNewNums(vector<int>& nums, int index) {
        vector<int> newNums;
            for (int i = 0; i < nums.size(); i++) {
                if (i == index)
                    continue;
                
                newNums.push_back(nums[i]);   
            }
        return newNums;
    }
};