class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if(ops.empty()) 
          return m * n;
        
        int firstMin = INT_MAX;
        int lastMin = INT_MAX;

        for(vector<int> v : ops) {
          if(v[0] < firstMin) firstMin = v[0];
          if(v[1] < lastMin) lastMin = v[1];
        }

        return firstMin * lastMin;
    }
};