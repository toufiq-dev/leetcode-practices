class Solution {
public:
    int findHighest (int index, vector<int>& arr) {
        int highest = arr[index];
        for (int i = index + 1; i < arr.size(); i++) {
            if (highest < arr[i])
                highest = arr[i];
        }

        return highest;
    }

    vector<int> replaceElements(vector<int>& arr) {
        if (arr.size() == 1)
            return {-1};
        
        for (int i = 0; i < arr.size() - 1; i++) {
            int highest = findHighest(i + 1, arr);
            arr[i] = highest;
        }

        arr[arr.size() - 1] = -1;
        return arr;
    }
};