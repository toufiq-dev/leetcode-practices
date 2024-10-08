class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) return false;

        int peak = INT_MIN;
        int index = -1;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > peak) {
                peak = arr[i];
                index = i;
            }
        }
    
        if (index == 0 || index == arr.size() - 1) 
            return false;
        
        // check before peak
        int beforeIndex = index - 1;
        int beforePeak = peak;
        while(beforeIndex >= 0) {
            if (arr[beforeIndex] >= beforePeak)
                return false;

            beforePeak = arr[beforeIndex];
            beforeIndex--;
        }

        // check after peak
        int afterIndex = index + 1;
        int afterPeak = peak;
        while(afterIndex < arr.size()) {
            if (arr[afterIndex] >= afterPeak)
                return false;
            
            afterPeak = arr[afterIndex];
            afterIndex++;
        }

        return true;
    }
};