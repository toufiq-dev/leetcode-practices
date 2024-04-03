class Solution {
public:
    vector<int> cache;
    int countSquares(int n) {
        if (n == 0) return 0;
        if (cache[n] != -1) return cache[n];

        int res = INT_MAX / 2;
        for (int i = 1; i * i <= n; i++) {
            res = min(res, 1 + countSquares(n - (i * i)));
        }
        cache[n] = res;

        return res;
    }
    int numSquares(int n) {
        cache.clear();
        cache.resize(n + 1, -1);
        return countSquares(n);    
    }
};